cmake_minimum_required(VERSION 3.5)

project(c_lang_test VERSION 1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(
    SOURCE_FILES
    src/main.cxx
)

set(
    HEADER_FILES
    include/dependencies.hpp
    include/custom_string.hpp
)

set(
    EXECUTABLE_NAME
    c_test_out
)

add_executable(
    ${EXECUTABLE_NAME}
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
