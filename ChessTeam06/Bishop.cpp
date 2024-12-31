#include "Bishop.h"
#include <cmath>


bool Bishop::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destCol = dest.getCol();
    int srcCol = this->getCol();
    int destRow = dest.getRow();
    int srcRow = this->getRow();

    if (abs(destCol - srcCol) != abs(destRow - srcRow))
    {
        return false;
    }

    int xDirection = (destCol - srcCol) / abs(destCol - srcCol);
    int yDirection = (destRow - srcRow) / abs(destRow - srcRow);

    for (int x = srcCol + xDirection, y = srcRow + yDirection; x != destCol or y != destRow; x += xDirection, y += yDirection)
    {
        if (!board[y][x]->isEmpty())
        {
            return false;
        }
    }

    return true;
}
