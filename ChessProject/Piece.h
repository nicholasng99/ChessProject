#pragma once
#include <map>
#include <string>

enum class Player : bool { WHITE, BLACK };

struct Pos {
	int x, y;
	Pos();
	Pos(const int x, const int y); /*{ this->x = x;	this->y = y; } limit to board size*/
	const Pos operator+(const Pos& rhs) const;
	const Pos operator-(const Pos& rhs) const;
	const bool operator==(const Pos& rhs) const; /*{ return x == pos.x && y == pos.y; }*/
	const std::string chessPos() const; //convert 0,0 to A1 and 7,7 to h8 etc.
};

class Piece
{
public:
	enum class PieceType : int { KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN };
	
	Piece(const Pos pos, const Player owner, const PieceType type);
	const bool move(const Pos pos);
	const Player getOwner() const;
	virtual const bool validMove(const Pos target, const std::map<Pos, Piece> pieces) const = 0;
private:
	Pos pos;
	Player owner;
	PieceType type;
};

