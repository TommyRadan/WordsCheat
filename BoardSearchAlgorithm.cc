#include "BoardSearchAlgorithm.hh"
#include "BoardAttempt.hh"
#include "BoardPosition.hh"

// Prototype
static const bool RecursiveSearch(const Board& board, const std::string& word, const BoardPosition startPos, const BoardAttempt attempt);

const bool SearchForWord(const Board& board, const std::string& word)
{
    if(word.size() < 5) {
        return false;
    }

    for(auto& c : word) {
        if(!board.ContainsLetter(c)) {
            return false;
        }
    }

    std::vector<BoardPosition> positions;
    positions = board.FindLetter(word[0]);

    BoardAttempt attempt;

    // Cut first letter from the string
    std::string nextWord = word.substr(1);

    for (auto& pos : positions) {
        attempt.SetVisited(pos);
        if (RecursiveSearch(board, nextWord, pos, attempt)) {
            return true;
        }
    }

    return false;
}

static const bool RecursiveSearch(const Board& board, const std::string& word, const BoardPosition startPos, const BoardAttempt attempt)
{
    if (word.empty())
    {
        return true;
    }

    // Cut first letter from the string
    std::string nextWord = word.substr(1);

    std::vector<BoardPosition> positions;
    positions = board.FindNeighbour(startPos, word[0]);

    for(auto pos : positions)
    {
        if(!attempt.GetVisited(pos))
        {
            // TODO: A lot of copying is done here, need to optimize
            BoardAttempt newAttempt = attempt;
            newAttempt.SetVisited(pos);
            if(RecursiveSearch(board, nextWord, pos, newAttempt))
            {
                return true;
            }
        }
    }
    return false;
}
