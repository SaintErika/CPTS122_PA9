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