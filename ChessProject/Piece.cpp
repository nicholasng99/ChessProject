#include "Piece.h"

Pos::Pos(const int x, const int y)
{
	this->x = x;
	this->y = y;
}

const Pos Pos::operator+(const Pos& rhs) const
{
	return Pos(this->x + rhs.x, this->y + rhs.y);
}

const Pos Pos::operator-(const Pos& rhs) const
{
	return Pos(this->x - rhs.x, this->y - rhs.y);
}

const bool Pos::operator==(const Pos& rhs) const
{
	return this->x == rhs.x && this->y == rhs.y;
}

const bool Pos::onboard() const
{
	return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

Piece::Piece(const Pos pos, const Player owner, const PieceType type)
{
}

const bool Piece::move(const Pos pos)
{
	return false;
}

const Player Piece::getOwner() const
{
	return Player();
}
