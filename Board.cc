#include "Board.hh"

const uint32_t BOARD_SIZE = 16u;
const uint32_t ROW_NUM = 4u;
const uint32_t COLUMN_NUM = 4u;

void Board::Input(const std::string& input)
{
    if(input.size() != BOARD_SIZE) {
        throw std::length_error("Input string is of wrong size");
    }

    memcpy(m_Data, input.c_str(), BOARD_SIZE * sizeof(char));
}

const std::vector<BoardPosition> Board::FindLetter(const char letter) const
{
    std::vector<BoardPosition> positions;

    for (uint32_t i = 0u; i < ROW_NUM; ++i) {
        for (uint32_t j = 0u; j < COLUMN_NUM; ++j) {
            BoardPosition pos(i, j);
            if (this->GetLetter(pos) == letter) {
                positions.push_back(pos);
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

const std::vector<BoardPosition> Board::FindNeighbour(const BoardPosition pos, const char letter) const
{
    std::vector<BoardPosition> positions;

    for (uint32_t i = 0u; i < ROW_NUM; ++i) {
        for (uint32_t j = 0u; j < COLUMN_NUM; ++j) {
            BoardPosition tempPos(i, j);
            if (this->GetLetter(tempPos) == letter && tempPos >> pos) {
                positions.push_back(tempPos);
            }
        }
    }

    return positions;
}
