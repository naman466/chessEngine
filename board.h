#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

constexpr const char* NAME = "ENGINE 1"; // name of the engine 
constexpr int NUM_SQUARES = 120; // no of squares in our board (includes border)

constexpr int MAX_MOVES = 2048; // maximum number of plys allowed in a game

/*        LOOKUP TABLES      */

constexpr int map120to64[NUM_SQUARES] = {

    /*
    lookup table to map 120 square board co-ordinates to 64 square board co-ordinates 
    */

    // Mapping for first row (0-9)
    65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
    // Mapping for second row (10-19)
    65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
    // Mapping for third row (20-29)
    65, 0, 1, 2, 3, 4, 5, 6, 7, 65,
    // Mapping for fourth row (30-39)
    65, 8, 9, 10, 11, 12, 13, 14, 15, 65,
    // Mapping for fifth row (40-49)
    65, 16, 17, 18, 19, 20, 21, 22, 23, 65,
    // Mapping for sixth row (50-59)
    65, 24, 25, 26, 27, 28, 29, 30, 31, 65,
    // Mapping for seventh row (60-69)
    65, 32, 33, 34, 35, 36, 37, 38, 39, 65,
    // Mapping for eighth row (70-79)
    65, 40, 41, 42, 43, 44, 45, 46, 47, 65,
    // Mapping for ninth row (80-89)
    65, 48, 49, 50, 51, 52, 53, 54, 55, 65,
    // Mapping for tenth row (90-99)
    65, 56, 57, 58, 59, 60, 61, 62, 63, 65,
    // Mapping for eleventh row (100-109)
    65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
    // Mapping for twelth row (110-119)
    65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
};

constexpr int map64to120[64] = {
    21, 22, 23, 24, 25, 26, 27, 28,
    31, 32, 33, 34, 35, 36, 37, 38,
    41, 42, 43, 44, 45, 46, 47, 48,
    51, 52, 53, 54, 55, 56, 57, 58,
    61, 62, 63, 64, 65, 66, 67, 68,
    71, 72, 73, 74, 75, 76, 77, 78,
    81, 82, 83, 84, 85, 86, 87, 88,
    91, 92, 93, 94, 95, 96, 97, 98,

};




/*        MACROS      */

inline int file_rank_to_square120(int file, int rank) {

    /*
    takes file and rank numbers as input and returns their coordinate on 120 square board 
    */

    return ((21+file)+(rank*10));
}

/*        ENUMS       */

namespace Pieces {

    enum {

        /* 
        enum containing all the pieces 
        EMPTY = empty squares

        w = white 
        b = black 

        R = rook
        N = knight 
        B = bishop 
        K = king
        Q = queen
        P = pawn
        */
    
        EMPTY,
        wR,
        wN,
        wB,
        wK,
        wQ,
        wP,
        bR,
        bN,
        bB,
        bK,
        bQ,
        bP,
    };
}

namespace Files {

    enum {

        /* 
        enum containing all the files 

        A_FILE = 0
        B_FILE = 1
        C_FILE = 2
        D_FILE = 3
        E_FILE = 4
        F_FILE = 5
        G_FILE = 6
        H_FILE = 7
        FILE_NONE = 8; no file associated (out of bounds?)

        */

        A_FILE,
        B_FILE,
        C_FILE,
        D_FILE,
        E_FILE,
        F_FILE,
        G_FILE,
        H_FILE,
        NONE_FILE,
    };
}

namespace Ranks {

    enum {

        /*
        enum containing all the ranks 

        RANK_1 = 0
        RANK_2 = 1
        RANK_3 = 2
        RANK_4 = 3
        RANK_5 = 4
        RANK_6 = 5
        RANK_7 = 6
        RANK_8 = 7
        RANK_NONE = 8; no rank associated (out of bounds)
        */

        RANK_1,
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
    };
}

namespace Colors {

    enum {
        /* 
        enum containing the colors 
        */

        WHITE,
        BLACK, 
        ALL,
    };
}

namespace Squares {

    enum {

        /* 
        enum mapping the squares to their corresponding value on the board  
        (only giving value to the first square rest can be calculated manually later)
        */

        A1 = 21, A2, A3, A4, A5, A6, A7, A8,
        B1 = 31, B2, B3, B4, B5, B6, B7, B8,
        C1 = 41, C2, C3, C4, C5, C6, C7, C8,
        D1 = 51, D2, D3, D4, D5, D6, D7, D8,
        E1 = 61, E2, E3, E4, E5, E6, E7, E8,
        F1 = 71, F2, F3, F4, F5, F6, F7, F8,
        G1 = 81, G2, G3, G4, G5, G6, G7, G8,
        H1 = 91, H2, H3, H4, H5, H6, H7, H8,

        /* 
        values increase in order of 10 and not 8 because there are hidden border ranks and files 
        (similar reason for start from 21 and end at 98)

        The board looks like 

        0   1   2   3   4   5   6   7   8   9
        10  11  12  13  14  15  16  17  18  19
        20  21  22  23  24  25  26  27  28  29
        30  31  32  33  34  35  36  37  38  39
        40  41  42  43  44  45  46  47  48  49
        50  51  52  53  54  55  56  57  58  59
        60  61  62  63  64  65  66  67  68  69
        70  71  72  73  74  75  76  77  78  79
        80  81  82  83  84  85  86  87  88  89
        90  91  92  93  94  95  96  97  98  99
        100 101 102 103 104 105 106 107 108 109
        110 111 112 113 114 115 116 117 118 119

        Squares other than 21-98 represent extra border in the board and are insignifcant
        */
    };

}

namespace Castling {
    
    enum {

        /*
        enum containing casting rights for white and black 
        (both kingside and queenside)

        1 2 4 8 because its represented by a 4 bit number 
        */

        white_kingside = 1,
        white_queenside = 2,
        black_kingside = 4,
        black_queenside = 8,
    };
}

class Undo {

    /*
    restore the game to it's previous state 
    */

   int move; // move to undo 
   bool castle_cond; // castling condition before the move was made 
   int en_passent; // en passent condition before the move was made 
   int fifty_draw; // fifty draw rule condition before the move was made 
   uint64_t key; // unique key of the previous board state 
};

class Board {
  
    /* 
        class representing the board  
    */

    int pieces[NUM_SQUARES];
    uint64_t pawns[3]; // representing 3 colored (white, black, all) pawns in a 64 bit number 

    int kings[2]; //position of the kings (white, black in that order)

    bool move; // current side to move; 0 = white, and 1 = black
    int en_passent; // en passent square if possible

    int fifty_draw; // number of moves for the fifty move draw rule (100 for this as we're using ply)

    /*
    one move = 2 ply, each half move i.e. white moves or black moves = 1 ply 
    */

    int ply; // how deep we are in the current search 
    int hist_ply; // total number of ply in the game so far 

    uint64_t key; // unique key generate for each position (for checking 3 fold repetition)

    int rem_num_pieces[13]; // number of remaining pieces on the board (13 as there are 13 types of pieces in class Piece)
    int big_pieces[3]; // number of big pieces (non pawn pieces) remaining by color (3)
    int major_pieces[3]; // number of major pieces (rooks and queen)
    int minor_pieces[3]; // number of knights and bishops 

    Undo record[MAX_MOVES]; // array to store moves and information before the move was made 
};

/*        FUNCTIONS       */


#endif


