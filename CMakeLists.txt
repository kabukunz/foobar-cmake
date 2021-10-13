# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)

project(foobar)

add_subdirectory(bar)

add_executable(foo foo/foo.cpp)

target_link_libraries(foo bar)

# set_target_properties(foo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# if(WIN32)
#     # copy dll
#     add_custom_command(TARGET foo POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:bar> $<TARGET_FILE_DIR:foo>
#     )
# endif()

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
set(CPACK_PACKAGE_NAME "foobar")
set(CPACK_PACKAGE_VENDOR "CMake.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "foobar (CPack)")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "foobar")
SET(CPACK_NSIS_MODIFY_PATH ON)

INCLUDE(CPack)
