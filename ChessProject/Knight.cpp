#include "Knight.h"

Knight::Knight(const Pos pos, const Player owner) : Piece(pos, owner, PieceType::KNIGHT)
{
}

const bool Knight::validMove(const Pos target) const
{
	Pos displacement = target - pos;
	//true if (x=1 & y=2) or (x=2 & y=1)
	if ((std::abs(displacement.x) == 1 && std::abs(displacement.y) == 2) ||
		(std::abs(displacement.x) == 2 && std::abs(displacement.y) == 1))
		return true;
	return false;
}
