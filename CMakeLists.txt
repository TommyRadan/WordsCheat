cmake_minimum_required(VERSION 3.6)
project(RijecalicaHack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Board.hh
        Board.cc
        BoardAttempt.hh
        BoardAttempt.cc
        BoardPosition.hh
        BoardPosition.cc
        FileLoading.hh
        BoardSearchAlgorithm.hh
        BoardSearchAlgorithm.cc)

add_executable(WordsCheat ${SOURCE_FILES})