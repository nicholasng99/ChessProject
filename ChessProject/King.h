#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(const Pos pos, const Player owner); // in cpp : Piece(pos,owner,PieceType::KING)
	const bool validMove(const Pos pos, const std::map<Pos, Piece> pieces) const;
private:
};

