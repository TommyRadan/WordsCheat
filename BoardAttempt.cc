#include "BoardAttempt.hh"
#include <cstdint>

BoardAttempt::BoardAttempt(void) :
    m_isVisited { 0 }
{}

void BoardAttempt::SetVisited(const BoardPosition& pos)
{
    const uint32_t row = pos.GetRow();
    const uint32_t column = pos.GetColumn();
    m_isVisited[row][column] = true;
}

const bool BoardAttempt::GetVisited(const BoardPosition& pos) const
{
    const uint32_t row = pos.GetRow();
    const uint32_t column = pos.GetColumn();
    return m_isVisited[row][column];
}
