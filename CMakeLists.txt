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

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/lib)
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

# OpenAuto dependencies - hopefully can remove one day
if (OPENAUTO_SUPPORT)
    message("Enabling OpenAuto support")

    include(${ROOT_DIR}/modules/OpenAuto/cmake_modules/functions.cmake)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules/OpenAuto/cmake_modules/")

    add_definitions(-DBOOST_ALL_DYN_LINK)

    find_package(Boost REQUIRED COMPONENTS system log)
    find_package(libusb-1.0 REQUIRED)
    find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets Bluetooth Qml Quick QuickWidgets WebSockets DBus Xml Svg REQUIRED)
    find_package(KF5BluezQt REQUIRED)
    find_package(Protobuf REQUIRED)
    find_package(OpenSSL REQUIRED)
    find_package(rtaudio REQUIRED)
    find_package(taglib REQUIRED)
    find_package(aasdk REQUIRED)
    find_package(openauto REQUIRED)

    # If building for RPi without GStreamer set paths to proprietary libraries
    if (RPI_BUILD AND NOT GST_BUILD)
        add_definitions(-DUSE_OMX -DOMX_SKIP64BIT)
        set(BCM_HOST_LIBRARIES "/opt/vc/lib/libbcm_host.so")
        set(BCM_HOST_INCLUDE_DIRS "/opt/vc/include")
        set(ILCLIENT_INCLUDE_DIRS "/opt/vc/src/hello_pi/libs/ilclient")
        set(ILCLIENT_LIBRARIES "/opt/vc/src/hello_pi/libs/ilclient/libilclient.a;/opt/vc/lib/libvcos.so;/opt/vc/lib/libvcilcs.a;/opt/vc/lib/libvchiq_arm.so")
    endif (RPI_BUILD AND NOT GST_BUILD)

    # If building with GStreamer check it exists and set defines accordingly
    if (GST_BUILD)
        find_package(Qt5GStreamer)
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(GST REQUIRED
            gstreamer-1.0>=1.4
            gstreamer-sdp-1.0>=1.4
            gstreamer-video-1.0>=1.4
            gstreamer-app-1.0>=1.4)
        add_definitions(-DUSE_GST)

        # If building for RPi get the Pi model
        if (RPI_BUILD)
            add_definitions(-DRPI)
            include(${CMAKE_CURRENT_SOURCE_DIR_2}/cmake_modules/functions.cmake)

            findRpiRevision( RPI_REVISION )
            math(EXPR RPI_MODEL "(0x${RPI_REVISION}>>4)&0xFF")
            if (RPI_MODEL EQUAL 17)
                message("Raspberry Pi 4 Found")
                add_definitions(-DPI4)
            endif (RPI_MODEL EQUAL 17)
        endif (RPI_BUILD)
    endif (GST_BUILD)

    # Include OpenAuto includes
    set(OPENAUTO_INCLUDES
        ${Qt5WebSockets_INCLUDE_DIRS}
        ${Qt5Multimedia_INCLUDE_DIRS}
        ${Qt5MultimediaWidgets_INCLUDE_DIRS}
        ${Qt5Bluetooth_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${LIBUSB_1_INCLUDE_DIRS}
        ${PROTOBUF_INCLUDE_DIR}
        ${OPENSSL_INCLUDE_DIR}
        ${RTAUDIO_INCLUDE_DIRS}
        ${AASDK_PROTO_INCLUDE_DIRS}
        ${AASDK_INCLUDE_DIRS}
        ${OPENAUTO_INCLUDE_DIRS}
        ${BCM_HOST_INCLUDE_DIRS}
        ${ILCLIENT_INCLUDE_DIRS}
        ${GST_INCLUDE_DIRS}
        ${QTGSTREAMER_INCLUDE_DIR}
        ${TAGLIB_INCLUDE_DIRS}
        )

    # Include OpenAuto libraries
    set(OPENAUTO_LIBS
        aasdk_proto
        aasdk
        openauto
        ${Boost_LIBRARIES}
        ${Qt5WebSockets_LIBRARIES}
        ${Qt5Multimedia_LIBRARIES}
        ${Qt5MultimediaWidgets_LIBRARIES}
        ${Qt5Bluetooth_LIBRARIES}
        KF5::BluezQt
        ${LIBUSB_1_LIBRARIES}
        ${PROTOBUF_LIBRARIES}
        ${BCM_HOST_LIBRARIES}
        ${ILCLIENT_LIBRARIES}
        ${WINSOCK2_LIBRARIES}
        ${RTAUDIO_LIBRARIES}
        ${GST_LIBRARIES}
        ${QTGLIB_LIBRARY}
        ${QTGLIB_LIBRARIES}
        ${QTGSTREAMER_LIBRARY}
        ${QTGSTREAMER_LIBRARIES}
        ${QTGSTREAMER_UI_LIBRARY}
        ${QTGSTREAMER_UI_LIBRARIES}
        ${Qt5QuickWidgets_LIBRARIES}
        ${QTGSTREAMER_QUICK_LIBRARIES}
        ${QTGSTREAMER_QUICK_LIBRARY}
        ${TAGLIB_LIBRARIES}
        )
endif (OPENAUTO_SUPPORT)

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
    ${OPENAUTO_INCLUDES}
    )

target_link_libraries(AutoDash
    ${Qt5Svg_LIBRARIES}
    ${Qt5Xml_LIBRARIES}
    ${Qt5DBus_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${OPENAUTO_LIBS}
    )

install(TARGETS AutoDash DESTINATION bin)