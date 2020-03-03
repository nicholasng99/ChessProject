#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const Pos pos, const Player owner);
	const bool validMove(const Pos target) const override;
};

