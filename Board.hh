#pragma once

#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

#include "BoardPosition.hh"

struct Board
{
    void Input(const std::string& input);

    const std::vector<BoardPosition> FindLetter(const char letter) const;
    const std::vector<BoardPosition> FindNeighbour(const BoardPosition pos, const char letter) const;

private:
    const char GetLetter(const BoardPosition& pos) const;

    char m_Data[4][4];
};
