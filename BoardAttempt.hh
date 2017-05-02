#pragma once

#include "BoardPosition.hh"

class BoardAttempt
{
public:
    BoardAttempt(void);

    void SetVisited(const BoardPosition& pos);
    const bool GetVisited(const BoardPosition& pos) const;

private:
    bool m_isVisited[4][4];
};