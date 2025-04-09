cmake_minimum_required(VERSION 3.16)

project(projet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 or Qt6 and include required modules
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        dialog.h 
        dialog.cpp 
        dialog.ui
        resc.qrc
        equipes.h 
        equipes.cpp
        connection.h 
        connection.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projet
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ../../../../Downloads/Atelier_Connexion.zip
    )
else()
    if(ANDROID)
        add_library(projet SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(projet
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link the Qt modules including PrintSupport
target_link_libraries(projet PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::PrintSupport
)

# Bundle and macOS/Windows specific properties
set_target_properties(projet PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS projet
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projet)
endif()