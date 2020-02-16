#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const Pos pos, const Player owner); // in cpp : Piece(pos,owner,PieceType::QUEEN)
	const bool validMove(const Pos pos, const std::map<Pos, Piece> pieces) const;
private:
};

