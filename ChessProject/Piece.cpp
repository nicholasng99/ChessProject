#include "Piece.h"

Pos::Pos()
{
	this->x = 0;
	this->y = 0;
}

Pos::Pos(const int x, const int y)
{
	this->x = x;
	this->y = y;
}

Pos Pos::operator+(const Pos& rhs) const
{
	return Pos(this->x + rhs.x, this->y + rhs.y);
}

Pos Pos::operator-(const Pos& rhs) const
{
	return Pos(this->x - rhs.x, this->y - rhs.y);
}

const bool Pos::operator==(const Pos& rhs) const
{
	return this->x == rhs.x && this->y == rhs.y;
}

const bool Pos::operator!=(const Pos& rhs) const
{
	return !(*this == rhs);
}

const bool Pos::onboard() const
{
	return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

Piece::Piece(const Pos pos, const Player owner, const PieceType type)
{
	this->pos = pos;
	this->owner = owner;
	this->type = type;
}

const Player Piece::getOwner() const
{
	return owner;
}

const bool Piece::move(const Pos target, const std::map<Pos, Piece> pieces)
{
	if (!target.onboard() ||
		(pieces.count(target) > 0 && pieces.at(target).getOwner() == owner) ||
		(!validMove(target)) ||
		(type != PieceType::KNIGHT && blocked(target, pieces))
		)
		return false;
	pos = target;
	return true;
}

const bool Piece::blocked(const Pos target, const std::map<Pos, Piece> pieces) const
{
	Pos displacement = target - pos;
	if (displacement.x == 1 || displacement.y == 1) // a displacement of 1 is impossible to be blocked
		return false;
	Pos direction;//initializes at 0
	if (displacement.x > 0)
		direction.x = 1;
	else if (displacement.x < 0)
		direction.x = -1;
	if (displacement.y > 0)
		direction.y = 1;
	else if (displacement.y < 0)
		direction.y = -1;
	while (displacement.x != 0 && displacement.y != 0) {
		displacement = displacement - direction;
		if (pieces.count(pos + displacement) == 1)
			return true;
	}
	return false;
}
