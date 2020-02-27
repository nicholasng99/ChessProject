#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(const Pos pos, const Player owner);
	const bool move(const Pos target, const std::map<Pos, Piece> pieces);//returns true if piece moves
	const bool validMove(const Pos target) const;
protected:
	bool firstMove;
};

