#include "BoardPosition.hh"

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
    return this->m_row;
}

const uint32_t BoardPosition::GetColumn() const noexcept
{
    return this->m_column;
}
