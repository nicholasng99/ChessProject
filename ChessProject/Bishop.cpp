#include "Bishop.h"

Bishop::Bishop(const Pos pos, const Player owner) : Piece(pos, owner, PieceType::BISHOP)
{
}

const bool Bishop::validMove(const Pos target) const
{
	Pos displacement = target - pos;
	//true if x=y
	if (std::abs(displacement.x) == std::abs(displacement.y))
		return true;
	return false;
}
