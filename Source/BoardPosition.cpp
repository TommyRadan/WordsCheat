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

#include "BoardPosition.hpp"

static inline int32_t abs(const int32_t val)
{
    return val < 0 ? -val : val;
}

BoardPosition::BoardPosition(const uint32_t row, const uint32_t column) :
    m_row { row },
    m_column { column }
{ }

bool BoardPosition::operator>>(const BoardPosition& position) const
{
    int32_t rowDiff = abs(m_row - position.m_row);
    int32_t columnDiff = abs(m_column - position.m_column);

    return (rowDiff <= 1 && columnDiff <= 1);
}

const uint32_t BoardPosition::GetRow() const noexcept
{
    return m_row;
}

const uint32_t BoardPosition::GetColumn() const noexcept
{
    return m_column;
}
