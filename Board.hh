#pragma once

#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

#include "BoardPosition.hh"

const uint32_t BOARD_SIZE = 16u;
const uint32_t ROW_NUM = 4u;
const uint32_t COLUMN_NUM = 4u;

struct Board
{
    Board() = default;

    void Input(const std::string& input);

    const char GetLetter(const BoardPosition& pos) const;

    const std::vector<BoardPosition> FindLetter(const char letter) const;

    const std::vector<BoardPosition> FindNeighbour(const BoardPosition pos, const char letter) const;

    const bool ContainsLetter(const char letter) const;

private:
    char m_Data[4][4];
};
