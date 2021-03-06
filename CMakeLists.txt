cmake_minimum_required(VERSION 3.15)
project(leetcode-cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak -Werror -Wreturn-type")

find_package(GTest REQUIRED)

include_directories(common)
include_directories(easy/include)
include_directories(medium/include)
include_directories(hard/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/easy)
add_subdirectory(${PROJECT_SOURCE_DIR}/medium)
add_subdirectory(${PROJECT_SOURCE_DIR}/hard)

set(COMMON_SRC
    common/linked_list.cc)

set(PROJECT_SRC
    ${EASY_SRC}
    ${MEDIUM_SRC}
    ${HARD_SRC}
    ${COMMON_SRC})

set(PROJECT_TEST
    ${EASY_TEST}
    ${MEDIUM_TEST}
    ${HARD_TEST})

add_executable(run_all_tests
    test/run_all_tests.cc
    ${PROJECT_TEST}
    ${PROJECT_SRC})

target_link_libraries(run_all_tests
    gtest
    pthread)
