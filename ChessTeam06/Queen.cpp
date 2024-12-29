#include "Queen.h"

bool Queen::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    if (Rook::isValidMovement(dest, board) or Bishop::isValidMovement(dest, board))
    {
        return true;
    }
    return false;
}
