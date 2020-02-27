#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const Pos pos, const Player owner);
	const bool validMove(const Pos target) const;
};

