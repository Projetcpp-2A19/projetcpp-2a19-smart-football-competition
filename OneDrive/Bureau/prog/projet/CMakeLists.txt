cmake_minimum_required(VERSION 3.16)

project(projet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt modules, including QtSerialPort for Arduino communication
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts PrintSupport Core SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts PrintSupport Core SerialPort)

# Your project source files
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
    aimodel.h
    aimodel.cpp
    aimodel.ui
)

# Check for Qt version and add executable accordingly
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projet
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(projet ${PROJECT_SOURCES})
endif()

# Link necessary libraries
target_link_libraries(projet PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::SerialPort  # Link QtSerialPort for Arduino communication
)

# Finalization (Qt 6 only)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projet)
endif()

# Additional settings for Windows/macOS executable creation
set_target_properties(projet PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
