# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)

cmake_policy(SET CMP0048 NEW)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION_TWEAK 0)
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK})

project(foobar
    VERSION ${PROJECT_VERSION}
)

add_subdirectory(bar)

add_executable(foo foo/foo.cpp)

target_link_libraries(foo bar)

# set the product dir
set(DEPLOY_DIR "/")

if(WIN32)
    set(DEPLOY_DIR $ENV{APPDATA} CACHE STRING "DEPLOY DIR")
    message(${DEPLOY_DIR})
endif()

# string(REPLACE "\\" "/" DEPLOY_DIR ${DEPLOY_DIR})

# option for testing binaries in windows w/o installing them
if(WIN32)
    option(DLL2BIN "Copy DLL into EXE dir on Windows" OFF)
endif()

# set_target_properties(foo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

if(WIN32 AND DLL2BIN)
    # copy dll
    add_custom_command(TARGET foo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:bar> $<TARGET_FILE_DIR:foo>
    )
endif()

install(TARGETS bar
    ARCHIVE LIBRARY
    DESTINATION lib
    COMPONENT libraries)

install(TARGETS foo
    RUNTIME
    DESTINATION bin
    COMPONENT applications)

install(FILES bar/bar.h
    DESTINATION include
    COMPONENT headers)

set(CPACK_GENERATOR NSIS)
# set(CPACK_PACKAGE_VENDOR "YourCom.com")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_SOURCE_DIR}/package")
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_INSTALL_ROOT ${DEPLOY_DIR})

INCLUDE(CPack)
