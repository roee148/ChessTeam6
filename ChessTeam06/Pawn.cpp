#include "Pawn.h"
#define WHITE false
#define BLACK true
#include <cmath>

bool Pawn::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destX = dest.getX();
    int srcX = this->getX();

    int destY = dest.getY();
    int srcY = this->getY();

    int distanceY = destY - srcY;
    int distanceX = destX - srcX;

    if (this->getColor() == WHITE && distanceY > 0 || abs(distanceX) > 1)
    {
        return false;
    }
    else if (this->getColor() == BLACK && distanceY < 0)
    {
        return false;
    }
   
    if (isFirstTurn)
    {
        if (abs(distanceY) != 1 && abs(distanceY) != 2)
        {
            return false;
        }
    }
    else if (abs(distanceY) != 1)
    {
        return false;
    }

    if (distanceX != 0 && !(this->getColor() != dest.getColor()))
    {
        return false;
    }
    else if (distanceX == 0 && !(this->getColor() == dest.getColor()))
    {
        return false;
    }

    
}
