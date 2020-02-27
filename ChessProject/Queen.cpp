#include "Queen.h"

Queen::Queen(const Pos pos, const Player owner) : Piece(pos, owner, PieceType::QUEEN)
{
}

const bool Queen::validMove(const Pos target) const
{
	Pos displacement = target - pos;
	//true if x=0 or y=0 or x=y
	if (std::abs(displacement.x) == 0 || std::abs(displacement.y) == 0 || std::abs(displacement.x) == std::abs(displacement.y))
		return true;
	return false;
}
