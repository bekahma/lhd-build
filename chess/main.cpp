/*
 Rebecca Ma
 Joseph Ma
 Teemo
 2021/01/10
*/

#include <iostream>
#include "chess_manager.hpp"
using namespace std;

int main(){
    ChessBoard* test = new ChessBoard();
    test -> outputBoard();
    string input = "";
    cin >> input;
    while(input.compare("end") != 0){
        test -> move(input);
        test -> outputBoard();
        cin >> input;
    }
}