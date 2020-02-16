#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(const Pos pos, const Player owner); // in cpp : Piece(pos,owner,PieceType::KNIGHT)
	const bool validMove(const Pos pos, const std::map<Pos, Piece> pieces) const;
private:
};

