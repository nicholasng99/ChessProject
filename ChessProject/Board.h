#pragma once
#include <string>
#include <vector>
#include <map>
#include "Piece.h"

using namespace std;

class Board
{
public:
	static const int BOARD_SIZE = 8;
	struct Pos {
		int x, y;
		Pos(int x, int y); /*{ this->x = x;	this->y = y; } limit to board size*/
		Pos operator+(const Pos& rhs) const;
		Pos operator-(const Pos& rhs) const;
		bool operator==(const Pos& rhs) const; /*{ return x == pos.x && y == pos.y; }*/
	};
	struct Round {
		string whiteMove, blackMove;
	};
	enum class Turn : bool { WHITE, BLACK };
	/*enum class PieceTypes : int { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY };*/
	//variables
	vector<Round> history;
	map<Pos, Piece> whitePieces, blackPieces;
	//methods
	const bool move(const Pos pos);
	void print() const;
	//const methods
	const vector<Pos> possibleMoves(const Pos& pos) const;
	const int evaluation() const;
	const bool check() const;
	const bool checkMate() const;
private:
	void setup(); // setup the initial chess positions and reset turncount and history
	void endTurn(); //flip Turn, increment turn count, add to history
};

