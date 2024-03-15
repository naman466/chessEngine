#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

#define NAME "ENGINE 1"
#define BOARD_SQUARE_NUMBER 120

enum class Piece {

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

enum class Files {

    /* 
      enum containing all the files 

      FILE_NONE = no file associated (out of bounds?)
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

enum class Colors {
    /* 
      enum containing the colors 
    */

   WHITE,
   BLACK, 
   ALL,
};

enum class Squares {

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
    */
};

#endif
