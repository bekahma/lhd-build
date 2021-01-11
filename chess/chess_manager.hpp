#ifndef CHESS_MANAGER_HPP
#define CHESS_MANAGER_HPP
#include <string>

using namespace std;

class ChessPiece{
    char type;
    bool team;
public:
    ChessPiece() : type(' '), team(false) {}
    ChessPiece(char newType, bool newTeam) : type(newType), team(newTeam) {}
    string getPiece();
};


class ChessBoard {
    ChessPiece* board[8][8];
    void setPiece(string location, ChessPiece* piece);
    ChessPiece* getPiece(string location);
public:
    ChessBoard();
    void move(string input);
    string toString();
    void outputBoard();
};

#endif