#include "Knight.h"

bool Knight::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destCol = dest.getCol();
    int srcCol = this->getCol();
    int destRow = dest.getRow();
    int srcRow = this->getRow();

    if ((destCol + 2 == srcCol and destRow + 1 == srcRow) or
        (destCol + 2 == srcCol and destRow - 1 == srcRow) or
        (destCol - 2 == srcCol and destRow + 1 == srcRow) or
        (destCol - 2 == srcCol and destRow - 1 == srcRow) or
        (destCol + 1 == srcCol and destRow + 2 == srcRow) or
        (destCol + 1 == srcCol and destRow - 2 == srcRow) or
        (destCol - 1 == srcCol and destRow + 2 == srcRow) or
        (destCol - 1 == srcCol and destRow - 2 == srcRow))
    {
        return true;
    }
    return false;
}
