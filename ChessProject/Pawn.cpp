#include "Pawn.h"

Pawn::Pawn(const Pos pos, const Player owner) : Piece(pos, owner, PieceType::PAWN)
{
	firstMove = true;
}

const bool Pawn::move(const Pos target, const std::map<Pos, Piece> pieces)
{
	if (Piece::move(target, pieces)) {
		firstMove = false;
		return true;
	}
	return false;
}

const bool Pawn::validMove(const Pos target) const
{
	Pos displacement = target - pos;
	if (displacement.x != 0)
		return false;
	//x is 0
	if (owner == Player::BLACK && displacement.y > 0)
		//pawn can only go down
		return false;
	else if (owner == Player::WHITE && displacement.y < 0)
		//owner is white, pawn can only go up
		return false;
	//direction is correct
	if (std::abs(displacement.y) > (firstMove ? 2 : 1))
		return false;
	//distance is correct
	return true;
}
