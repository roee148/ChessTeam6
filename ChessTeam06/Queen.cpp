#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

bool Queen::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
    Rook rook(getRow(), getCol(), getColor());
    Bishop bishop(getRow(), getCol(), getColor());

    bool validAsRook = rook.isValidMovement(dest, board);
    bool validAsBishop = bishop.isValidMovement(dest, board);

    // Queen can move as Rook or Bishop
    return validAsRook || validAsBishop;
}
