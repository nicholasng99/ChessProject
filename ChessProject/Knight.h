#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(const Pos pos, const Player owner); 
	const bool validMove(const Pos target) const override;
private:
};

