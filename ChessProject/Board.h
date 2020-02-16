#pragma once
#include <string>
#include <vector>
#include <map>
#include "Piece.h"

using namespace std;

class Board
{
public:
	//variables
	static const int BOARD_SIZE = 8;
	struct Pos {
		int x, y;
		Pos(int x, int y); /*{ this->x = x;	this->y = y; } limit to board size*/
		const Pos operator+(const Pos& rhs) const;
		const Pos operator-(const Pos& rhs) const;
		const bool operator==(const Pos& rhs) const; /*{ return x == pos.x && y == pos.y; }*/
		const string chessPos() const; //convert 0,0 to A1 and 7,7 to h8 etc.
	};
	struct Round {
		string whiteMove, blackMove;
	};
	enum class Turn : bool { WHITE, BLACK };
	/*enum class PieceTypes : int { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY };*/
	//methods
	const bool move(const Pos pos);
	void print() const;
	//const methods
	const vector<Pos> possibleMoves(const Pos& pos) const;
	const int evaluation() const;
	const bool check() const;
	const bool checkMate() const;
	//get methods
	void printHistory() const;
	void printRound(const int index) const;

private:
	//variables
	vector<Round> history;
	map<Pos, Piece> whitePieces, blackPieces;
	//methods
	void setup(); // setup the initial chess positions and reset turncount and history
	void endTurn(); //flip Turn, increment turn count, add to history
};

