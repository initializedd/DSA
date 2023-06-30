cmake_minimum_required(VERSION 3.25.1)
set(CMAKE_CXX_STANDARD 20)

project(DSA)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "DSA/*.cpp")

add_executable("${PROJECT_NAME}" "${SOURCES}")