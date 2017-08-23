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

#include "Board.hpp"

const uint32_t BOARD_SIZE = 16u;
const uint32_t ROW_NUM = 4u;
const uint32_t COLUMN_NUM = 4u;

Board::Board() :
    m_Data {0}
{}

void Board::Input(const std::string& input)
{
    if (input.size() != BOARD_SIZE)
    {
        throw std::length_error("Input string is of wrong size");
    }

    memcpy(m_Data, input.c_str(), BOARD_SIZE * sizeof(char));
}

const std::vector<BoardPosition> Board::FindLetter(const char letter) const
{
    std::vector<BoardPosition> positions;

    for (uint32_t i = 0u; i < ROW_NUM; ++i)
    {
        for (uint32_t j = 0u; j < COLUMN_NUM; ++j)
        {
            BoardPosition pos(i, j);
            if (this->GetLetter(pos) == letter)
            {
                positions.push_back(pos);
            }
        }
    }

    return positions;
}

const std::vector<BoardPosition> Board::FindNeighbour(const BoardPosition& pos, const char letter) const
{
    std::vector<BoardPosition> positions;

    for (uint32_t i = 0u; i < ROW_NUM; ++i)
    {
        for (uint32_t j = 0u; j < COLUMN_NUM; ++j)
        {
            BoardPosition tempPos(i, j);
            if (this->GetLetter(tempPos) == letter && tempPos >> pos)
            {
                positions.push_back(tempPos);
            }
        }
    }

    return positions;
}

const char Board::GetLetter(const BoardPosition& pos) const
{
    uint32_t row = pos.GetRow();
    uint32_t column = pos.GetColumn();
    return m_Data[row][column];
}
