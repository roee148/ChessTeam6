#include "Rook.h"
#include <math.h>

bool Rook::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destX = dest.getX();
    int srcX = this->getX();
    int destY = dest.getY();
    int srcY = this->getY();

    if (destX != srcX and destY != srcY)
    {
        return false;
    }

    if (destX == srcX)
    {
        if (destY > srcY)
        {
            for (int i = srcY + 1; i < destY; i++)
            {
                if (!board[srcX][i]->isEmpty())
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = srcY - 1; i > destY; i--)
            {
                if (!board[srcX][i]->isEmpty())
                {
                    return false;
                }
            }
        }
        return true;
    }

    if (destY == srcY)
    {
        if (destX > srcX)
        {
            for (int i = srcX + 1; i < destX; i++)
            {
                if (!board[i][srcY]->isEmpty())
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = srcX - 1; i > destX; i--)
            {
                if (!board[i][srcY]->isEmpty())
                {
                    return false;
                }
            }
        }
        return true;
    }
}
