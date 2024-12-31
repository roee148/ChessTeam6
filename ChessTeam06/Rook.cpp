#include "Rook.h"
#include <math.h>

bool Rook::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    int destCol = dest.getCol();
    int srcCol = this->getCol();
    int destRow = dest.getRow();
    int srcRow = this->getRow();

    if (destCol != srcCol and destRow != srcRow) // moving in different row and col
    {
        return false;
    }

    if (destCol == srcCol) // moving in same col
    {
        if (destRow > srcRow)
        {
            for (int i = srcRow + 1; i < destRow; i++)
            {
                if (!board[i][srcCol]->isEmpty())
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = srcRow - 1; i > destRow; i--)
            {
                if (!board[i][srcCol]->isEmpty())
                {
                    return false;
                }
            }
        }
        return true;
    }

    if (destRow == srcRow)  // moving in same row
    {
        if (destCol > srcCol)
        {
            for (int i = srcCol + 1; i < destCol; i++)
            {
                if (!board[srcRow][i]->isEmpty())
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = srcCol - 1; i > destCol; i--)
            {
                if (!board[srcRow][i]->isEmpty())
                {
                    return false;
                }
            }
        }

    }
    return true;
}
