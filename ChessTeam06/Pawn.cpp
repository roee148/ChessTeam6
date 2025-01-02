#include "Pawn.h"
#include <cmath>

bool Pawn::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destCol = dest.getCol();
    int srcCol = this->getCol();

    int destRow = dest.getRow();
    int srcRow = this->getRow();

    int distanceY = srcRow - destRow;
    int distanceX = srcCol - destCol;

  
    if (getColor() == WHITE && distanceY > 0) // white can only advance down
    {
        return false;
    }
    
    if (getColor() == BLACK && distanceY < 0) // black can only advance up
    {
        return false;
    }

    if (abs(distanceY) != 1 && abs(distanceY) != 2) // can move only by 1 step or 2 steps vertically
    {
        return false;
    }

    if (abs(distanceX) > 1) // can move only by 1 step horizontally
    {
        return false;
    }

    bool isFirstTurn = (getColor() == WHITE && srcRow == 1) || (getColor() == BLACK && srcRow == 6);
    
    if (abs(distanceY) == 2 && (!isFirstTurn || distanceX != 0))
    {
        return false;
    }

    if (distanceX != 0 && (getColor() == dest.getColor() || dest.isEmpty())) // trying to capture my color/empty spot
    {
        return false;
    }
    if (distanceX == 0 && !dest.isEmpty()) // can't capture vertically
    {
        return false;
    }
    return true;
}
