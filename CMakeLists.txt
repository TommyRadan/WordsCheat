cmake_minimum_required(VERSION 3.2)
project(WordsCheat)

set(CMAKE_CXX_STANDARD 11)

###################################################################
# Application Main Build
###################################################################

include_directories(Include/)

set(INCLUDE_FILES
        Include/Board.hpp
        Include/BoardAttempt.hpp
        Include/BoardPosition.hpp
        Include/BoardSearchAlgorithm.hpp
        Include/FileLoading.hpp)

set(SOURCE_FILES
        Source/Board.cpp
        Source/BoardAttempt.cpp
        Source/BoardPosition.cpp
        Source/BoardSearchAlgorithm.cpp
        Source/FileLoading.cpp)

add_executable(WordsCheat
        ${SOURCE_FILES}
        ${INCLUDE_FILES}
        Source/EntryPoint.cpp)

###################################################################
# Application Tests
###################################################################

include(ExternalProject)
ExternalProject_Add(gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        TIMEOUT 10
        INSTALL_COMMAND "")

ExternalProject_Get_Property(gtest
        source_dir
        binary_dir)

add_executable(RunUnitTest
        Test/BoardTest.cpp
        ${SOURCE_FILES}
        ${INCLUDE_FILES})

find_package (Threads)
add_dependencies(RunUnitTest gtest)
include_directories(${source_dir}/googletest/include)
target_link_libraries(RunUnitTest
        ${binary_dir}/googlemock/gtest/libgtest.a
        ${binary_dir}/googlemock/gtest/libgtest_main.a
        ${CMAKE_THREAD_LIBS_INIT})
