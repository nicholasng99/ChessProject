#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(const Pos pos, const Player owner); // in cpp : Piece(pos,owner,PieceType::PAWN)
	const bool validMove(const Pos pos, const std::map<Pos, Piece> pieces) const;
private:
};

