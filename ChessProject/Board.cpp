#include "Board.h"

Board::Move::Move(const Player player, const Piece::PieceType pieceType, const Pos origin, const Pos destination)
{
}

const std::string Board::Move::print() const
{
	return std::string();
}

const std::string Board::Round::print() const
{
	return std::string();
}

void Board::print() const
{
}

const std::vector<Pos> Board::possibleMoves(const Pos& pos) const
{
	return std::vector<Pos>();
}

const int Board::evaluation() const
{
	return 0;
}

const bool Board::check() const
{
	return false;
}

const bool Board::checkMate() const
{
	return false;
}

void Board::printHistory() const
{
}

void Board::printRound(const int index) const
{
}

const std::map<Pos, Piece> Board::getPieces() const
{
	return std::map<Pos, Piece>();
}

const std::map<Pos, Piece> Board::getWhitePieces() const
{
	return std::map<Pos, Piece>();
}

const std::map<Pos, Piece> Board::getBlackPieces() const
{
	return std::map<Pos, Piece>();
}

void Board::setup()
{
}

void Board::endTurn()
{
}
