#
# MIT License
#
# Copyright (c) 2017 Tomislav Radanovic
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

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
