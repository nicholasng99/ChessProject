#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(const Pos pos, const Player owner);
	const bool validMove(const Pos target) const override;
};

