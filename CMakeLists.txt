cmake_minimum_required(VERSION 3.16)

project(projet VERSION 0.1 LANGUAGES CXX)

# Optional: Vcpkg toolchain
# set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Optional: OpenCV path
# set(OpenCV_DIR "C:/opencv/build")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt modules
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts PrintSupport Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts PrintSupport Core)

# Find Python
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Try to find OpenCV (optional)
find_package(OpenCV QUIET)

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
    stat.h
    stat.cpp
    stat.ui
)

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
    Python3::Python
)

# Link OpenCV if found
if(OpenCV_FOUND)
    target_link_libraries(projet PRIVATE ${OpenCV_LIBS})
    message(STATUS "OpenCV found and linked")
else()
    message(WARNING "OpenCV not found - some features may be limited")
endif()

# Copy Python + model files after build
add_custom_command(TARGET projet POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/aimodel.py
        ${CMAKE_CURRENT_BINARY_DIR}/aimodel.py
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/yolov8n.pt
        ${CMAKE_CURRENT_BINARY_DIR}/yolov8n.pt
    COMMENT "Copying AI model files"
)

# Handle Python DLLs on Windows
if(WIN32)
    get_target_property(PYTHON_LIB_PATH Python3::Python IMPORTED_LOCATION)
    get_filename_component(PYTHON_BIN_PATH "${PYTHON_LIB_PATH}" DIRECTORY)
    add_custom_command(TARGET projet POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PYTHON_BIN_PATH}"
            $<TARGET_FILE_DIR:projet>
        COMMENT "Copying Python DLLs"
    )
endif()

# Finalization
set_target_properties(projet PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projet)
endif()
