#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const Pos pos, const Player owner);
	const bool validMove(const Pos target) const;
};

