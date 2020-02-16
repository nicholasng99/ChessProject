#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const Pos pos, const Player owner); // in cpp : Piece(pos,owner,PieceType::ROOK)
	const bool validMove(const Pos pos, const std::map<Pos, Piece> pieces) const;
private:
};

