#pragma once

#include <cstdint>

class BoardPosition
{
public:
    BoardPosition(const uint32_t row, const uint32_t column);
    bool operator>>(const BoardPosition& position) const;

    const uint32_t GetRow() const noexcept;
    const uint32_t GetColumn() const noexcept;

private:
    uint32_t m_row;
    uint32_t m_column;
};
