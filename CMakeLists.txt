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
