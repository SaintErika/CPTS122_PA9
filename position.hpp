#pragma once
struct position
{
	int x, y;
} oldPos, whiteKing, blackKing, transWhite, transBlack;

int  size = 100, move = 0, x, y;
int rBlackRookMoved, lBlackRookMoved, bKingMoved;
int rWhiteRookMoved, lWhiteRookMoved, wKingMoved;
int changeWhite = 0, changeBlack = 0;
int pieceMoved = 0;
int turn = 0;
int checkWhite = 0, checkBlack = 0;

float dx = 0, dy = 0;

/*int board[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, };*/

///////////////////////////////////////// testing /////////////////////////////////////////

/*int board[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 0, 1, 0, 0, 1, 1, 1,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, -1, 1, 1, 0, 0, 0,
  0, 0, 0, -1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,0,0,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, };

//pawn testing, taking own piece, wrong turn

//in this test, attempt with white to take your own piece (d4 x c5) (fails)
//then take black's piece (d4 x e5)
//Then attempt to move pawn positioned 2 over and 3 down two spaces (pawn to b4) (fails)
//then with black, move the pawn positioned 6 over and 1 down two spaces (pawn to f5)
//then with black, attempt to move any piece, to show that it is indeed white's turn.
//then with white, attempt to move the king's pawn up one space (pawn e3)*/

int board[8][8] =
{ 0, 0, 0, 0, 2, 6, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 5, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, -1, 0, -4, 0,
  0, 0, 0, 0, 0,-1,-1,-1,
  0, 0, 0, 0, 0, 0,-6, 0, };

//checkmate testing

//in this test, attempt with white to put the king in check by moving to d6
//block the check with the rook (rook to e7)
//move the pawn from e3 to e4
//move the queen to b1



