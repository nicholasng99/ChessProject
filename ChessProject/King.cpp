#include "King.h"

King::King(const Pos pos, const Player owner) : Piece(pos, owner, PieceType::KING)
{
}

const bool King::validMove(const Pos target) const
{
	Pos displacement = target - pos;
	//cannot move more than 1 square
	if (std::abs(displacement.x) > 1 || std::abs(displacement.y) > 1)
		return false;
	return true;
}
