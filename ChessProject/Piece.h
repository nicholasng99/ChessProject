#pragma once
#include <map>
#include <string>

enum class Player : bool { WHITE, BLACK };

struct Pos {
	int x, y;
	Pos();
	Pos(const int x, const int y); /*{ this->x = x;	this->y = y; } limit to board size*/
	Pos operator+(const Pos& rhs) const;
	Pos operator-(const Pos& rhs) const;
	const bool operator==(const Pos& rhs) const; /*{ return x == pos.x && y == pos.y; }*/
	const bool operator!=(const Pos& rhs) const;
	const bool onboard() const; //true if piece is still on the board
};

class Piece
{
public:
	enum class PieceType : int { KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN };
	
	Piece(const Pos pos, const Player owner, const PieceType type);
	const Player getOwner() const;
	const bool move(const Pos target, const std::map<Pos, Piece> pieces);//returns true if piece moves
	virtual const bool validMove(const Pos target) const = 0;//returns true if move is acceptable based on PieceType
protected:
	Pos pos;
	Player owner;
	PieceType type;
	const bool blocked(const Pos target, const std::map<Pos, Piece> pieces) const;
};

