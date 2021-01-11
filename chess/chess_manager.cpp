#include "chess_manager.hpp"
#include <string>
#include <iostream>
// #include <format>

/*
p - pawn
r - rook
n - knight
b - bishop
q - queen
k - king 
*/

string ChessPiece::getPiece(){
    if(team){
        string s(1,toupper(type));
        s = "\x1b[33m" + s + "\x1b[0m";
        return s;
    }
    string s(1,type);
    s = "\x1b[36m" + s + "\x1b[0m";
    return s;
}

void ChessBoard::setPiece(string location, ChessPiece* piece) {
    int x = location[0] - 'a';
    int y = '8' - location[1];
    board[x][y] = piece;
}

ChessPiece* ChessBoard::getPiece(string location){
    int x = location[0] - 'a';
    int y = '8' - location[1];
    return board[x][y];
}

ChessBoard::ChessBoard() {
    // setting up the initial board

    //first team
    setPiece("a1", new ChessPiece('r',true));
    setPiece("b1", new ChessPiece('n',true));
    setPiece("c1", new ChessPiece('b',true));
    setPiece("d1", new ChessPiece('q',true));
    setPiece("e1", new ChessPiece('k',true));
    setPiece("f1", new ChessPiece('b',true));
    setPiece("g1", new ChessPiece('n',true));
    setPiece("h1", new ChessPiece('r',true));

    setPiece("a2", new ChessPiece('p',true));
    setPiece("b2", new ChessPiece('p',true));
    setPiece("c2", new ChessPiece('p',true));
    setPiece("d2", new ChessPiece('p',true));
    setPiece("e2", new ChessPiece('p',true));
    setPiece("f2", new ChessPiece('p',true));
    setPiece("g2", new ChessPiece('p',true));
    setPiece("h2", new ChessPiece('p',true));
    
    //second team
    setPiece("a8", new ChessPiece('r',false));
    setPiece("b8", new ChessPiece('n',false));
    setPiece("c8", new ChessPiece('b',false));
    setPiece("d8", new ChessPiece('q',false));
    setPiece("e8", new ChessPiece('k',false));
    setPiece("f8", new ChessPiece('b',false));
    setPiece("g8", new ChessPiece('n',false));
    setPiece("h8", new ChessPiece('r',false));

    setPiece("a7", new ChessPiece('p',false));
    setPiece("b7", new ChessPiece('p',false));
    setPiece("c7", new ChessPiece('p',false));
    setPiece("d7", new ChessPiece('p',false));
    setPiece("e7", new ChessPiece('p',false));
    setPiece("f7", new ChessPiece('p',false));
    setPiece("g7", new ChessPiece('p',false));
    setPiece("h7", new ChessPiece('p',false));
}

// assuming proper input
void ChessBoard::move(string input) {
    string start = input.substr(0,2);
    string end = input.substr(2,2);

    delete getPiece(end);
    setPiece(end, getPiece(start));
    setPiece(start, NULL);
}

string ChessBoard::toString() {
    string headerfooter = " |a|b|c|d|e|f|g|h|\n";
    // string filler = " +-+-+-+-+-+-+-+-+\n";
    string filler = " -----------------\n";
    string output = headerfooter;
    for(int i = 0; i < 8; i++){
        // output += filler;
        output += to_string(8-i);
        for(int j = 0; j < 8; j++){
            if(board[j][i])
                output += "|" + board[j][i] -> getPiece();
            else
                output += "| ";
        }
        output += "|\n";
    }
    // output += filler;
    output += headerfooter;
    return output;
}

void ChessBoard::outputBoard() {
    cout << toString() << endl;
}

// HUGGO HUGGO HUGGO HUGGO HUGGO 