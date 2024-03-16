#include "board.h"

#include <iostream>

using namespace std;

void printBB(Bitboard PawnBB) {

    /*
    takes a bitboard as input and prints X if piece is present on that square and - if it isn't 
    */

    Bitboard shift = 1; // to get 1 to the current square in the loop  

    int rank = 0;
    int file = 0;
    int square = 0;
    int square64 = 0;

    cout << " " << endl;
    for(rank = Ranks::RANK_8; rank >= Ranks::RANK_1; rank--) {
        for(file = Files::A_FILE; file <= Files::H_FILE; file++) {
            square = file_rank_to_square120(file, rank);
            square64 = map120to64[square];
            if ((shift << square64) & PawnBB) { // shifting 1 to the current co-ordinate and doing & operation with input BB, true if equal (piece present) false if not equal
                cout << "X";
            }
            else {
                cout << "-";
            }
        }
        cout << " " << endl;
    }
    cout << "\n" << endl;
}