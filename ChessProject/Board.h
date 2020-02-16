#pragma once
#include <string>
#include <vector>
#include <map>
#include "Piece.h"

class Board
{
public:
	//variables
	static const int BOARD_SIZE = 8;
	struct Move {
		const Player player;
		const Piece::PieceType pieceType;
		const Pos origin, destination;
		Move(const Player player, const Piece::PieceType pieceType, const Pos origin, const Pos destination);
		const std::string print() const;
	};
	struct Round {
		Move whiteMove, blackMove;
		const std::string print() const;
	};
	/*enum class PieceTypes : int { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY };*/
	//methods
	const bool move(const Pos pos);
	void print() const;
	//const methods
	const std::vector<Pos> possibleMoves(const Pos& pos) const;
	const int evaluation() const;
	const bool check() const;
	const bool checkMate() const;
	//get methods
	void printHistory() const;
	void printRound(const int index) const;
	const std::map<Pos, Piece> getPieces() const;
	const std::map<Pos, Piece> getWhitePieces() const;
	const std::map<Pos, Piece> getBlackPieces() const;
private:
	//variables
	std::map<Pos, Piece> Pieces;
	std::vector<Round> history;
	//methods
	void setup(); // setup the initial chess positions and reset turncount and history
	void endTurn(); //flip Turn, increment turn count, add to history
};

