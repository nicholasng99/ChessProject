#include "Rook.h"

Rook::Rook(const Pos pos, const Player owner) : Piece(pos, owner, PieceType::ROOK)
{
}

const bool Rook::validMove(const Pos target) const
{
	Pos displacement = target - pos;
	//true if x=0 or y=0
	if (std::abs(displacement.x) == 0 || std::abs(displacement.y) == 0 )
		return true;
	return false;
}
