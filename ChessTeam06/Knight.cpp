#include "Knight.h"

bool Knight::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destX = dest.getX();
    int srcX = this->getX();
    int destY = dest.getY();
    int srcY = this->getY();

    if ((destX + 2 == srcX and destY + 1 == srcY) or
        (destX + 2 == srcX and destY - 1 == srcY) or
        (destX - 2 == srcX and destY + 1 == srcY) or
        (destX - 2 == srcX and destY - 1 == srcY) or
        (destX + 1 == srcX and destY + 2 == srcY) or
        (destX + 1 == srcX and destY - 2 == srcY) or
        (destX - 1 == srcX and destY + 2 == srcY) or
        (destX - 1 == srcX and destY - 2 == srcY))
    {
        return true;
    }
    return false;
}
