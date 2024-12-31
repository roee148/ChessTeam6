#include "Pawn.h"
#define WHITE false
#define BLACK true
#include <cmath>

bool Pawn::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destCol = dest.getCol();
    int srcCol = this->getCol();

    int destRow = dest.getRow();
    int srcRow = this->getRow();

    int distanceY = srcRow - destRow;
    int distanceX = srcCol - destCol;


//    // Determine the direction of movement based on pawn color
//    int direction = _color==BLACK ? -1 : 1;
//    // Normal forward move
//    if (!isEmpty() && srcCol == destCol) {
//        // Single square forward
//        if (destRow == srcRow + direction) {
//            return true;
//        }
//        // Double square forward (only from starting position)
//        if ((_color==BLACK && srcRow == 6) || (_color==WHITE && srcRow == 1)) {
//            if (destRow == srcRow + 2 * direction) {
//                return true;
//            }
//        }
//    }
//
//    // Capture move
//    if (!isEmpty() && std::abs(destCol - srcCol) == 1 && destRow == srcRow + direction) {
//        return true;
//    }
//
//    // Invalid move
//    return false;
//}


    //                                moving upward    moving sideways
    if (getColor() == WHITE && (distanceY > 0 || abs(distanceX) > 1))
    {
        return false;
    }
    else if (getColor() == BLACK && distanceY < 0) // black can only advance up
    {
        return false;
    }
    bool isFirstTurn = (getColor() == WHITE && srcRow == 1) || (getColor() == BLACK && srcRow == 6);
    if (isFirstTurn)
    {
        if (abs(distanceY) != 1 && abs(distanceY) != 2)
        {
            return false;
        }
        if (distanceX!=0) 
        {
            return false;
        }
    }
    else if (abs(distanceY) != 1)
    {
        return false;
    }

    if (distanceX != 0 && (getColor() == dest.getColor() || dest.isEmpty()))
    {
        return false;
    }
    if (distanceX == 0 && !dest.isEmpty())
    {
        return false;
    }
    return true;
}
