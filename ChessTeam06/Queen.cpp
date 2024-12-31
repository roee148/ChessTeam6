#include "Queen.h"

bool Queen::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    Rook rook(getX(), getY(), getColor());
    Bishop bishop(getX(), getY(), getColor());

    bool validAsRook = rook.isValidMovement(dest, board);
    bool validAsBishop = bishop.isValidMovement(dest, board);

    // Queen can move as Rook or Bishop
    return validAsRook || validAsBishop;
}
