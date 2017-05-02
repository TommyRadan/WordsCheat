#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

#include "FileLoading.hh"
#include "Board.hh"
#include "BoardSearchAlgorithm.hh"

auto LoadDictionary(const std::string& file) -> std::vector<std::string>
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

    try {
        dictionary = LoadDictionary(argv[1]);
    }
    catch (const std::exception& e) {
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
        if (boardString == "END") break;

        try {
            board.Input(boardString);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            continue;
        }

        // Searching every word
        std::vector<std::string> matchedWords;
        for (auto& word : dictionary) {
            if (SearchForWord(board, word)) {
                matchedWords.push_back(word);
            }
        }

        // Sorting matched words based on length
        auto function = [&](const std::string& str1, const std::string& str2) {
            return str1.length() < str2.length();
        };
        std::sort(matchedWords.begin(), matchedWords.end(), function);

        // Printing out sorted matched words
        for(auto& word : matchedWords) {
            std::cout << word << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
