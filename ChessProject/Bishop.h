#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const Pos pos, const Player owner); // in cpp : Piece(pos,owner,PieceType::BISHOP)
	const bool validMove(const Pos pos, const std::map<Pos, Piece> pieces) const;
private:
};

