#include "Bishop.h"
#include <cmath>


bool Bishop::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destX = dest.getX();
    int srcX = this->getX();
    int destY = dest.getY();
    int srcY = this->getY();

    if (abs(destX - srcX) != abs(destY - srcY))
    {
        return false;
    }

    int xDirection = (destX - srcX) / abs(destX - srcX);
    int yDirection = (destY - srcY) / abs(destY - srcY);

    for (int x = srcX + xDirection, y = srcY + yDirection; x != destX and y != destY; x += xDirection, y += yDirection)
    {
        if (!board[x][y]->isEmpty())
        {
            return false;
        }
    }

    return true;
}
