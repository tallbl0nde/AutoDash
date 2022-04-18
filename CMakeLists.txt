cmake_minimum_required(VERSION 3.7.0)
project(AutoDash CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(RESOURCES_DIR ${ROOT_DIR}/resources)
set(SOURCE_DIR ${ROOT_DIR}/source)
set(INCLUDE_DIR ${ROOT_DIR}/include)
set(MODULES_DIR ${ROOT_DIR}/modules)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${ROOT_DIR}/bin)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -rdynamic)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -Wall -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-psabi")
endif()

find_package(Qt5 COMPONENTS Widgets DBus Xml Svg REQUIRED)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB_RECURSE source_files ${SOURCE_DIR}/*.cpp ${INCLUDE_DIR}/*.hpp ${RESOURCES_DIR}/*.qrc)

add_executable(AutoDash ${source_files})

target_include_directories(AutoDash PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    )

target_include_directories(AutoDash SYSTEM PRIVATE
    ${Qt5Svg_INCLUDE_DIRS}
    ${Qt5Xml_INCLUDE_DIRS}
    ${Qt5DBus_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${INCLUDE_DIR}
    )

target_link_libraries(AutoDash
    ${Qt5Svg_LIBRARIES}
    ${Qt5Xml_LIBRARIES}
    ${Qt5DBus_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    )

install(TARGETS AutoDash DESTINATION bin)
