/*
 * MIT License
 *
 * Copyright (c) 2017 Tomislav Radanovic
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>

#include <Board.hpp>

TEST(BoardTest, EmptyContruction)
{
    Board board;

    for (char c = 'A'; c != 'Z'; c++)
    {
        std::vector<BoardPosition> results;
        results = board.FindLetter(c);

        EXPECT_EQ(results.size(), 0);
    }
}

TEST(BoardTest, BadConstruction)
{
    Board board;

    // Input too short
    EXPECT_ANY_THROW(board.Input("ABCDEFG"));

    // Input too long
    EXPECT_ANY_THROW(board.Input("QWERTYUIOPASDFGHJKLZXCVBNM"));
}

TEST(BoardTest, FindLetter)
{
    std::string input {"QWERTYUIOPASDFGH"};
    Board board;

    EXPECT_NO_THROW(board.Input(input));

    for (auto& c : input)
    {
        std::vector<BoardPosition> results;
        results = board.FindLetter(c);

        EXPECT_EQ(results.size(), 1);
    }
}
