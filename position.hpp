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

int board[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, };

///////////////////////////////////////// testing /////////////////////////////////////////

//program requires user input to activate sections of code, so in order to test various situations,
//the team implemented various boards to easily access states to test movement and denial of movement

//to change to a testing board, comment out the int board and uncomment any block of code that has been commented out
//then, follow directions to observe desired behavior

//test 1

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

//test 2

/*int board[8][8] =
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
//move the queen to b1 for checkmate*/

//test  3

/*int board[8][8] =
{ 2, 0, 4, 0, 6, 0, 0, 2,
  0, 1, 1, 0, 5, 1, 1, 1,
  1, 0, 1, 0, 0, 3, 0, 0,
  0, 0, 0, 0, 1, 0, -4, 0,
  0, 4, 0, 0, -1, 0, 0, 0,
  0, 0, -3, -1, 0, -5, 0, 0,
 -1,-1,-1, 0, 0,-1,-1,-1,
 -2, 0, 0, 0,-6, 0, -3,-2, };

//castling testing

//in this test, attempt with the white king to castle short (move the king to g1)
//then castle long (move king to c1)
//then with black, attempt to castle long (move the king to c8)
//then castle short (move the king to g8)*/

//test 4 

/*int board[8][8] =
{ -6, -2, 0, 0, 0, 0, 0, 0,
  0, 0, -1, -1, -1, -1, 0, 0,
  6, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  -1, -1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, };

//piece promotion, stalemate testing

//move rightmost pawn up, promote to bishop
//make only king move (a5)
//move rightmost pawn up, promote to knight
//make only king move (a6)
//move rightmost pawn up, promote to rook
//make only king move (a5)
//move last pawn up, promote to queen
//stalemate*/

//test 5

/*int board[8][8] =
{ 0, 6, 4, 0, 5, 0, 0, -2,
0, 0, 0, 0, 0, 0, 2, 0,
3, 0, 3, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, -3, 0, -3, 0, 0, 0, 0,
0, 0, 0, 0, -4, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -6, 0, 0, 0, };

//moving while in check testing

//use knight on b4 to take a6
//use bishop on c8 to take a6
//use knight on d4 to take c6
//attempt to take with queen, cannot because piece is pinned
//move king to c7 to remove check
//attempt to move bishop to f2, cannot because piece is pinned
//move king to d2
//use queen to take rook*/
