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
		const std::string string() const;
		const std::string playerS() const;
		const std::string pieceTypeS() const;
		const std::string posS(Pos pos) const;
	};
	struct Round {
		Move whiteMove, blackMove;
		Round(const Move whiteMove, const Move blackMove);
		void print() const;
	};
	/*enum class PieceTypes : int { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY };*/
	//methods
	const bool move(const Pos pos, const Pos target);
	void print() const;
	//const methods
	const std::vector<Pos> possibleMoves(const Pos& pos) const;
	const std::vector<Move> allPossibleMoves() const;
	const int evaluation() const;
	const bool check(Player player) const;
	const bool checkMate(Player player) const;
	//get methods
	void printHistory() const;
	void printRound(const int index) const;
	const std::map<Pos, Piece> getPieces() const;
	const std::map<Pos, Piece> getWhitePieces() const;
	const std::map<Pos, Piece> getBlackPieces() const;
private:
	//variables
	Player turn = Player::WHITE;
	std::map<Pos, Piece> pieces;
	std::vector<Round> history;
	//methods
	void setup(); // setup the initial chess positions and reset turncount and history
	void endTurn(); //flip Turn, increment turn count, add to history
};

