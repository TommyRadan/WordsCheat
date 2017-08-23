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

#include "BoardSearchAlgorithm.hpp"
#include "BoardAttempt.hpp"

static const bool RecursiveSearch(const Board& board,
                                  const std::string& word,
                                  const BoardPosition startPos,
                                  const BoardAttempt attempt)
{
    if (word.empty())
    {
        return true;
    }

    // Cut first letter from the string
    std::string nextWord = word.substr(1);

    std::vector<BoardPosition> positions;
    positions = board.FindNeighbour(startPos, word[0]);

    for (auto pos : positions)
    {
        if (!attempt.GetVisited(pos))
        {
            // TODO: A lot of copying is done here, need to optimize
            BoardAttempt newAttempt = attempt;
            newAttempt.SetVisited(pos);
            if (RecursiveSearch(board, nextWord, pos, newAttempt))
            {
                return true;
            }
        }
    }
    return false;
}

const bool SearchForWord(const Board& board, const std::string& word)
{
    if (word.size() < 5)
    {
        return false;
    }

    std::vector<BoardPosition> positions;
    positions = board.FindLetter(word[0]);

    BoardAttempt attempt;

    // Cut first letter from the string
    std::string nextWord = word.substr(1);

    for (auto& pos : positions)
    {
        attempt.SetVisited(pos);
        if (RecursiveSearch(board, nextWord, pos, attempt))
        {
            return true;
        }
    }

    return false;
}
