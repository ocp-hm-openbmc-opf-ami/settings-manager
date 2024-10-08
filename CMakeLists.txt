cmake_minimum_required (VERSION 3.1 FATAL_ERROR)
set (BUILD_SHARED_LIBRARIES OFF)
include (ExternalProject)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++fs -Werror")
set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-rtti")

option (YOCTO "Enable Building in Yocto" OFF)
option (USE_OVERLAYS "Enable Overlay Usage" ON)

if (NOT YOCTO)
    externalproject_add (
        Boost URL
        https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.gz
        URL_MD5 d275cd85b00022313c171f602db59fc5 SOURCE_DIR
        "${CMAKE_BINARY_DIR}/boost-src" BINARY_DIR
        "${CMAKE_BINARY_DIR}/boost-build" CONFIGURE_COMMAND "" BUILD_COMMAND ""
        INSTALL_COMMAND mkdir -p "${CMAKE_BINARY_DIR}/prefix/include/" && cp -R
        ${CMAKE_BINARY_DIR}/boost-src/boost ${CMAKE_BINARY_DIR}/prefix/include
    )

    externalproject_add (
        nlohmann-json GIT_REPOSITORY "https://github.com/nlohmann/json.git"
        GIT_TAG d2dd27dc3b8472dbaa7d66f83619b3ebcd9185fe SOURCE_DIR
        "${CMAKE_BINARY_DIR}/nlohmann-json-src" BINARY_DIR
        "${CMAKE_BINARY_DIR}/nlohmann-json-build" CONFIGURE_COMMAND ""
        BUILD_COMMAND "" INSTALL_COMMAND mkdir -p
        "${CMAKE_BINARY_DIR}/nlohmann/include/nlohmann" && cp -r
        "${CMAKE_BINARY_DIR}/nlohmann-json-src/single_include/nlohmann"
        "${CMAKE_BINARY_DIR}/nlohmann/include"
    )

    # requires apt install autoconf-archive and autoconf
    externalproject_add (sdbusplus-project PREFIX
                         ${CMAKE_BINARY_DIR}/sdbusplus-project GIT_REPOSITORY
                         https://github.com/openbmc/sdbusplus.git GIT_TAG
                         076d14af2b3e29e48471ffb7fab632317da0fc21 SOURCE_DIR
                         ${CMAKE_BINARY_DIR}/sdbusplus-src BINARY_DIR
                         ${CMAKE_BINARY_DIR}/sdbusplus-build CONFIGURE_COMMAND
                         "" BUILD_COMMAND cd ${CMAKE_BINARY_DIR}/sdbusplus-src
                         && ./bootstrap.sh && ./configure --enable-transaction
                         && make -j libsdbusplus.la INSTALL_COMMAND ""
                         LOG_DOWNLOAD ON)

    include_directories (${CMAKE_BINARY_DIR}/sdbusplus-src)
    include_directories (${CMAKE_BINARY_DIR}/nlohmann/include)
    include_directories (${CMAKE_BINARY_DIR}/nlohmann/include/nlohmann)

    link_directories (${CMAKE_BINARY_DIR}/sdbusplus-src/.libs)

    include_directories (${CMAKE_BINARY_DIR}/boost-src)
    set (CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/boost-src ${CMAKE_PREFIX_PATH})
endif ()

add_definitions (-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions (-DBOOST_SYSTEM_NO_DEPRECATED)
add_definitions (-DBOOST_ALL_NO_LIB)
add_definitions (-DBOOST_NO_RTTI)
add_definitions (-DBOOST_NO_TYPEID)
add_definitions (-DBOOST_ASIO_DISABLE_THREADS)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (settings src/main.cpp)

target_link_libraries (settings -lsystemd)
target_link_libraries (settings ${Boost_LIBRARIES})
target_link_libraries (settings stdc++fs)
target_link_libraries (settings sdbusplus)

if (NOT YOCTO)
    add_dependencies (settings nlohmann-json)
    add_dependencies (settings sdbusplus-project)
    add_dependencies (settings Boost)
endif ()

find_package (PkgConfig REQUIRED)
pkg_get_variable(SYSTEMD_SYSTEM_UNIT_DIR systemd systemdsystemunitdir)

install (TARGETS settings DESTINATION bin)
install (FILES xyz.openbmc_project.Settings.service DESTINATION
               "${SYSTEMD_SYSTEM_UNIT_DIR}")
