#include "Board.h"
#include <iostream>

Board::Move::Move(const Player player, const Piece::PieceType pieceType, const Pos origin, const Pos destination)
	: player(player), pieceType(pieceType), origin(origin), destination(destination)
{
}

/*string translation of the player move*/
const std::string Board::Move::string() const
{
	return  playerS() + pieceTypeS() + " " + posS(origin) + " to " + posS(destination);
}

/*string conversion of player colour*/
const std::string Board::Move::playerS() const
{
	return (player == Player::WHITE ? "White" : "Black");
}

/*string conversion of enum piece type*/
const std::string Board::Move::pieceTypeS() const
{
	switch (pieceType) {
	case Piece::PieceType::KING:
		return "king";
	case Piece::PieceType::QUEEN:
		return "queen";
	case Piece::PieceType::BISHOP:
		return "bishop";
	case Piece::PieceType::ROOK:
		return "rook";
	case Piece::PieceType::KNIGHT:
		return "knight";
	case Piece::PieceType::PAWN:
		return "pawn";
	}
}
/*string of chess coords from array index*/
const std::string Board::Move::posS(Pos pos) const
{
	const std::string letters = "ABCDEFGH";
	return letters[pos.x] + std::to_string(pos.y + 1);
}

Board::Round::Round(const Move whiteMove, const Move blackMove) : whiteMove(whiteMove), blackMove(blackMove)
{
}

/*prints white and black's move*/
void Board::Round::print() const
{
	std::cout << whiteMove.string();
	std::cout << blackMove.string();
}

/*handles:
-moving a piece not yours
lacking:
-moves that cause yourself to be under checkmate*/
const bool Board::move(const Pos pos, const Pos target)
{
	if (pieces.at(pos).getOwner() != turn) // if the piece being moved is not yours
		return false;
	return pieces.at(pos).move(target, pieces);
}

/*prints the board layout of pieces*/
void Board::print() const
{

}

// returns a vector of all possible legal moves
const std::vector<Pos> Board::possibleMoves(const Pos& pos) const
{
	return std::vector<Pos>();
}

//returns an evaluation value of the current board position + favouring white
const int Board::evaluation() const
{
	return 0;
}

//returns true if board is under check for player
const bool Board::check(Player player) const
{
	return false;
}

//returns true if board is under checkmate for player
const bool Board::checkMate(Player player) const
{
	return false;
}

//prints history of moves
void Board::printHistory() const
{
}

//prints the round of index i
void Board::printRound(const int index) const
{
}

//returns all pieces on the board
const std::map<Pos, Piece> Board::getPieces() const
{
	return std::map<Pos, Piece>();
}

//returns all white pieces on the board
const std::map<Pos, Piece> Board::getWhitePieces() const
{
	return std::map<Pos, Piece>();
}

//returns all black pieces on the board
const std::map<Pos, Piece> Board::getBlackPieces() const
{
	return std::map<Pos, Piece>();
}

//sets up the board to starting position
void Board::setup()
{
}

//flips the turn, increment turn count, and adds the move to the round and the round to the history
void Board::endTurn()
{
}
