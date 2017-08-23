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

#include <iostream>
#include <vector>

#include "FileLoading.hpp"
#include "Board.hpp"
#include "BoardSearchAlgorithm.hpp"

static auto LoadDictionary(const std::string& file) -> std::vector<std::string>
{
    std::vector<std::string> dictionary;
    std::cout << "Loading words ..." << std::endl;
    dictionary = LoadFile(file);
    std::cout << "Done (Loaded " << dictionary.size() << " words)" << std::endl;
    return std::move(dictionary);
}

int main(int argc, char** argv)
{
    std::vector<std::string> dictionary;

    try
    {
        dictionary = LoadDictionary(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "USAGE: " << argv[0] << " [Dictionary Path]" << std::endl;
        return EXIT_FAILURE;
    }

    while (true)
    {
        Board board;
        std::string boardString;

        std::cout << "Type the board: ";
        std::cin >> boardString;

        // Transform board to uppercase
        std::transform(boardString.begin(), boardString.end(), boardString.begin(), ::toupper);

        // Program end condition
        if (boardString == "END")
        {
            break;
        }

        try
        {
            board.Input(boardString);
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }

        // Searching every word
        std::vector<std::string> matchedWords;
        for (auto& word : dictionary)
        {
            if (SearchForWord(board, word))
            {
                matchedWords.push_back(word);
            }
        }

        // Sorting matched words based on length
        auto function = [&](const std::string& str1, const std::string& str2)
        {
            return str1.length() < str2.length();
        };
        std::sort(matchedWords.begin(), matchedWords.end(), function);

        // Printing out sorted matched words
        for (auto& word : matchedWords)
        {
            std::cout << word << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
