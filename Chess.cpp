//Project Name: Chess Game
//Project Description: Basic version of chess
//Authors: Ethan Teh, Ethan Lyons
//Project Design: April 8, 2022 - April 27, 2022

//Rules of Chess
/***********************************************************************************/
//The chess board is divided into a 8 x 8 grid, labeled A through H
//	and 1 through 8, numbers being vertical and letters horizontal
//
//Set the board by distributing pieces on specific spots on the board
//	8 white pawns fill the 2nd row, 8 black pawns fill the 7th.
//	then, from left to right the white pieces are arranged on 1st row:
//		rook, knight, bishop, queen, king, bishop, knight, rook.
//	then, from left to right the black pieces are arranged on 8th row:
//		rook, knight, bishop, queen, king, bishop, knight, rook.
//
//Pieces are captured when a piece legally moves to the space the
//	opposing player was occupying with a piece. You cannot capture
//	your own pieces, and tiles cannot be occupied by more than one piece.
//Each piece has unique movement opportunities, but pieces can never
//	leave the board's tiles unless captured.
//	Pawn:
//		Pawns can only advance forward in one direction--towards
//			the opposing side of the board.
//		If a pawn is on its initial square, it can move two spaces
//			to advance directly forward.
//		Pawns can only advance one square directly forward otherwise.
//		Pawns can only capture opposing pieces directly one square  
//			diagonally in front while still advancing towards the 
//			opposing player's side.
//		If a pawn reaches the opposing player's side (row 1 for
//			black, row 8 for white), that player can exchange
//			the pawn for any non-pawn, non-king piece.
//		Pawns cannot take pieces directly in front of them, and
//			cannot advance forward if a piece is obstructing
//			its path.
//	Rook:
//		Rooks can move any amount of spaces in directly vertical or
//			horizontal direction. This includes forwards,
//			backwards, left, and right. Without capturing a piece,
//			it can only move to unobstructed squares in its path,
//			and cannot move through other pieces to reach a
//			destination.
//		Rooks can capture pieces anywhere along its path so long as
//			it is the first piece encountered. It cannot move
//			through pieces to reach a destination.
//	Knight:
//		Knights move in an "L" shaped pattern. This means it can move
//			two squares in any one direction except diagonal, and
//			an additional square in a perpendicular direction.
//			ie: moving forwards two, right one; moving forwards one,
//			left two; moving backwards two, right one, etc...
//		Knights can travel through pieces to reach their destination
//		Knights can only capture pieces they arrive at as a destination,
//			not any pieces in a potential path to the destination.
//	Bishop:
//		Bishops can move any amount of spaces diagonally in any direction.
//			This means it is moving in the horizontal direction the
//			same amount it is traveling vertically. Without capturing
//			a piece, it can only move to unobstructed squares in its
//			path, and cannot move through other pieces to reach a
//			destination.
//		Bishops can capture pieces anywhere along its path so long as
//			it is the first piece encountered. It cannot move
//			through pieces to reach a destination.
//	Queen:
//		Queens can move any amount of spaces in a diagonal, horizontal,
//			or vertical direction (similar to bishops and rooks).
//			Also similarly, without capturing a piece, it can only
//			moce to unobstructed squares in its path, and cannot move
//			through other pieces to reach a destination.
//		Queens can capture pieces anywhere along its path so long as it is
//			the first piece encountered. it cannot move through pieces
//			to reach a destination.
//	King:
//		Kings can move one space at a time in a diagonal, horizontal,
//			or vertical direction. It cannot move to spaces occupied
//			by your own pieces.
//		Kings cannot move to squares where it has the potential to be
//			directly captured by other pieces.
//		Kings can capture pieces around it, so long as it doesn't arrive
//			to a square where it has the potential to be directly
//			captured by other pieces.
//		Kings are considered in "Check" if on a player's turn, the king is
//			actively available to be captured by the opposing player's
//			next move.
//
//White will always move first.
//
//The objective of chess is to "Checkmate" the opponent.
//	This is achieved by putting the opposing king in Check, mentioned above.
//	If there is a Check, the opposing player must remove the check, or else
//		they lose the game, called a Checkmate. Checks can be removed by 
//		capturing a piece causing a check, obstructing the path of a piece 
//		causing a check, or moving the king out of the pieces path of a 
//		check.
//	If either player cannot make any legal moves, the game ends in an immediate 
//		draw. This is called a stalemate.
//
//There are other rules and play modes present in chess, however were not addressed 
//		for simplicity.
//These rules include:
//	En passant:
//		The capture by a pawn of a horizontally adjacent enemy 
//		pawn that has just made a two-square move.
//	3-fold repetition:
//		A tie caused by players repeating the same set of moves three times.
//	50-move rule:
//		A tie caused by neither player capturing a piece or moving a pawn
//		for fifty moves.
//	Dead position:
//		If neither player has the potential to reach a checkmate, the game
//		is tied.
//	Resignation:
//		When a player forfeits a game by choice.
//	Draw offer / Draw offer accepted.
//		To offer a tie to the opponent, then make a move. If the opponent
//		accepts, the game is tied, otherwise the game resumes.
//These game modes include:
//	Time control:
//		A mode where players have an alloted time bank. During a player's
//		turn, the time bank slowly expires until the player makes a legal
//		move, or the bank expires, causing an immediate loss.
//		Different time control varients have different starting time bank
//		amounts, and varying increases of banak time after a player moves.
/***********************************************************************************/

#include <iostream>
#include "SFML/Graphics.hpp"
#include "position.hpp"
#include "defines.hpp"
#include "Pieces.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game!");
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	
	t1.loadFromFile("images/Chessboard.png");
	t2.loadFromFile("images/Chess_Pieces/Chess_BlackPawn.png");
	t3.loadFromFile("images/Chess_Pieces/Chess_WhitePawn.png");
	t4.loadFromFile("images/Chess_Pieces/Chess_WhiteRook.png");
	t5.loadFromFile("images/Chess_Pieces/Chess_BlackRook.png");
	t6.loadFromFile("images/Chess_Pieces/Chess_WhiteKnight.png");
	t7.loadFromFile("images/Chess_Pieces/Chess_BlackKnight.png");
	t8.loadFromFile("images/Chess_Pieces/Chess_WhiteBishop.png");
	t9.loadFromFile("images/Chess_Pieces/Chess_BlackBishop.png");
	t10.loadFromFile("images/Chess_Pieces/Chess_WhiteQueen.png");
	t11.loadFromFile("images/Chess_Pieces/Chess_BlackQueen.png");
	t12.loadFromFile("images/Chess_Pieces/Chess_WhiteKing.png");
	t13.loadFromFile("images/Chess_Pieces/Chess_BlackKing.png");
	t14.loadFromFile("images/Chess_Pieces/Chess_WhiteTransformation.png");
	t15.loadFromFile("images/Chess_Pieces/Chess_BlackTransformation.png");

	sf::Sprite ChessBoard(t1);
	sf::Sprite BlackPawn(t2);
	sf::Sprite WhitePawn(t3);
	sf::Sprite WhiteRook(t4);
	sf::Sprite BlackRook(t5);
	sf::Sprite WhiteKnight(t6);
	sf::Sprite BlackKnight(t7);
	sf::Sprite WhiteBishop(t8);
	sf::Sprite BlackBishop(t9);
	sf::Sprite WhiteQueen(t10);
	sf::Sprite BlackQueen(t11);
	sf::Sprite WhiteKing(t12);
	sf::Sprite BlackKing(t13);
	sf::Sprite WhiteTrans(t14);
	sf::Sprite BlackTrans(t15);
	sf::Sprite movedSprite;
	
	while (window.isOpen())
	{
		sf::Vector2i pos = sf::Mouse::getPosition(window);
		x = pos.x / size;
		y = pos.y / size;

		sf::Event a;
		while (window.pollEvent(a))
		{
			if (a.type == sf::Event::Closed)
			{
				window.close();
			}
			window.clear();
			if (a.type == sf::Event::MouseButtonPressed)
			{
				if (a.key.code == sf::Mouse::Left)
				{
					if (changeWhite == 1)
					{
						if (pos.y >= transWhite.y * size && pos.y <= (transWhite.y + 1) * size && pos.x >= transWhite.x * size && pos.x <= (transWhite.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transWhite.y][transWhite.x] = WHITE_BISHOP;
								changeWhite = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transWhite.y][transWhite.x] = WHITE_QUEEN;
								changeWhite = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transWhite.y][transWhite.x] = WHITE_ROOK;
								changeWhite = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transWhite.y][transWhite.x] = WHITE_KNIGHT;
								changeWhite = 0;
							}
							if (changeWhite == 0)
							{
								KingBlackPos();
								int d = KingBlackChecker(blackKing.x, blackKing.y);
								if (d == 0)
								{
									checkBlack = 1;
								}
							}
						}
					}
					if (changeBlack == 1)
					{
						if (pos.y >= transBlack.y * size && pos.y <= (transBlack.y + 1) * size && pos.x >= transBlack.x * size && pos.x <= (transBlack.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transBlack.y][transBlack.x] = BLACK_BISHOP;
								changeBlack = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transBlack.y][transBlack.x] = BLACK_QUEEN;
								changeBlack = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transBlack.y][transBlack.x] = BLACK_ROOK;
								changeBlack = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transBlack.y][transBlack.x] = BLACK_KNIGHT;
								changeBlack = 0;
							}
							if (changeBlack == 0)
							{
								KingWhitePos();
								int d = KingWhiteChecker(whiteKing.x, whiteKing.y);
								if (d == 0)
								{
									checkWhite = 1;
								}
							}
						}
					}
					if (board[y][x] != 0)
					{
						dx = pos.x - x * size;
						dy = pos.y - y * size;
						if (board[y][x] == BLACK_PAWN && turn == 1)
						{
							pieceMoved = BLACK_PAWN;
							movedSprite = BlackPawn;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_PAWN && turn == 0)
						{
							pieceMoved = WHITE_PAWN;
							movedSprite = WhitePawn;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_ROOK && turn == 0)
						{
							pieceMoved = WHITE_ROOK;
							movedSprite = WhiteRook;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_ROOK && turn == 1)
						{
							pieceMoved = BLACK_ROOK;
							movedSprite = BlackRook;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_KNIGHT && turn == 0)
						{
							pieceMoved = WHITE_KNIGHT;
							movedSprite = WhiteKnight;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_KNIGHT && turn == 1)
						{
							pieceMoved = BLACK_KNIGHT;
							movedSprite = BlackKnight;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_BISHOP && turn == 0)
						{
							pieceMoved = WHITE_BISHOP;
							movedSprite = WhiteBishop;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_BISHOP && turn == 1)
						{
							pieceMoved = BLACK_BISHOP;
							movedSprite = BlackBishop;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_QUEEN && turn == 0)
						{
							pieceMoved = WHITE_QUEEN;
							movedSprite = WhiteQueen;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_QUEEN && turn == 1)
						{
							pieceMoved = BLACK_QUEEN;
							movedSprite = BlackQueen;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_KING && turn == 0)
						{
							pieceMoved = WHITE_KING;
							movedSprite = WhiteKing;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_KING && turn == 1)
						{
							pieceMoved = BLACK_KING;
							movedSprite = BlackKing;
							board[y][x] = 0;
						}
						if (board[y][x] == 0)
						{
							move = 1;
							oldPos.x = x;
							oldPos.y = y;
						}
					}
				}
			}
			if (a.type == sf::Event::MouseButtonReleased)
			{
				if (a.key.code == sf::Mouse::Left)
				{
					int b = 2;
					if (pieceMoved == WHITE_PAWN && move == 1)
					{
						b = PawnWhite(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == BLACK_PAWN && move == 1)
					{
						b = PawnBlack(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == WHITE_ROOK && move == 1)
					{
						b = RookWhite(oldPos.x, oldPos.y, x, y);
						if (b == 1 && lWhiteRookMoved == 0 && oldPos.y == 7 && oldPos.x == 0)
						{
							lWhiteRookMoved = 1;
						}
						if (b == 1 && rWhiteRookMoved == 0 && oldPos.y == 7 && oldPos.x == 7)
						{
							rWhiteRookMoved = 1;
							
						}
					}
					if (pieceMoved == BLACK_ROOK && move == 1)
					{
						b = RookBlack(oldPos.x, oldPos.y, x, y);
						if (b == 1 && lBlackRookMoved == 0 && oldPos.y == 0 && oldPos.x == 7)
						{
							lBlackRookMoved = 1;
						}
						if (b == 1 && rBlackRookMoved == 0 && oldPos.y == 0 && oldPos.x == 0)
						{
							rBlackRookMoved = 1;

						}
					}
					if (pieceMoved == WHITE_BISHOP && move == 1)
					{
						b = BishopWhite(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == BLACK_BISHOP && move == 1)
					{
						b = BishopBlack(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == WHITE_KNIGHT && move == 1)
					{
						b = KnightWhite(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == BLACK_KNIGHT && move == 1)
					{
						b = KnightBlack(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == WHITE_QUEEN && move == 1)
					{
						b = QueenWhite(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == BLACK_QUEEN && move == 1)
					{
						b = QueenBlack(oldPos.x, oldPos.y, x, y);
					}
					if (pieceMoved == WHITE_KING && move == 1)
					{
						b = KingWhite(oldPos.x, oldPos.y, x, y);
						if (b == 1 && wKingMoved == 0)
						{
							wKingMoved = 1;
						}
					}
					if (pieceMoved == BLACK_KING && move == 1)
					{
						b = KingBlack(oldPos.x, oldPos.y, x, y);
						if (b == 1 && bKingMoved == 0)
						{
							bKingMoved = 1;
						}
					}
					if (b == 1)
					{
						int c = board[y][x];
						board[y][x] = pieceMoved;
						if (y == 0 && pieceMoved == WHITE_PAWN)
						{
							changeWhite = 1;
							transWhite.x = x;
							transWhite.y = y;
							board[y][x] = 0;
						}
						if (y == 7 && pieceMoved == BLACK_PAWN)
						{
							changeBlack = 1;
							transBlack.x = x;
							transBlack.y = y;
							board[y][x] = 0;
						}
						if (turn == 0) 
						{
							if (checkWhite == 1)
							{
								KingWhitePos();
								int check = KingWhiteChecker(whiteKing.x, whiteKing.y);
								if (check == 0)
								{
									board[oldPos.y][oldPos.x] = pieceMoved;
									board[y][x] = c;
								}
								else
								{
									checkWhite = 0;
									KingBlackPos();
									int check = KingBlackChecker(blackKing.x, blackKing.y);
									if (check == 0)
									{
										checkBlack = 1;
									}
									turn = 1;
								}
							}
							else
							{
								KingWhitePos();
								int check = KingWhiteChecker(whiteKing.x, whiteKing.y);
								if (check == 0)
								{
									board[oldPos.y][oldPos.x] = pieceMoved;
									board[y][x] = c;
								}
								else
								{
									KingBlackPos();
									int check = KingBlackChecker(blackKing.x, blackKing.y);
									if (check == 0)
									{
										checkBlack = 1;
									}
									turn = 1;
								}
							}
						}
						else 
						{
							if (checkBlack == 1)
							{
								KingBlackPos();
								int check = KingBlackChecker(blackKing.x, blackKing.y);
								if (check == 0)
								{
									board[oldPos.y][oldPos.x] = pieceMoved;
									board[y][x] = c;
								}
								else
								{
									checkBlack = 0;
									KingBlackPos();
									int check = KingWhiteChecker(whiteKing.x, whiteKing.y);
									if (check == 0)
									{
										checkWhite = 1;
									}
									turn = 0;
								}
							}
							else
							{
								KingBlackPos();
								int check = KingBlackChecker(blackKing.x, blackKing.y);
								if (check == 0)
								{
									board[oldPos.y][oldPos.x] = pieceMoved;
									board[y][x] = c;
								}
								else
								{
									KingWhitePos();
									int check = KingWhiteChecker(whiteKing.x, whiteKing.y);
									if (check == 0)
									{
										checkWhite = 1;
									}
									turn = 0;
								}
							}
						}
					}
					else if (b == 0)
					{
						board[oldPos.y][oldPos.x] = pieceMoved;
					}
					move = 0;
				}
			}
		}

		window.clear();
		window.draw(ChessBoard);
		if (changeWhite == 1)
		{
			WhiteTrans.setPosition(transWhite.x * size, transWhite.y * size);
			window.draw(WhiteTrans);
		}
		if (changeBlack == 1)
		{
			BlackTrans.setPosition(transBlack.x * size, transWhite.y * size);
			window.draw(BlackTrans);
		}
		if (move == 1)
		{
			movedSprite.setPosition(pos.x - dx, pos.y - dy);
			window.draw(movedSprite);
		}

		for (int i = 0; i <= LENGTH; i++)
		{
			for (int j = 0; j <= LENGTH; j++)
			{
				if (board[i][j] != 0)
				{
					if (board[i][j] == BLACK_PAWN)
					{
						BlackPawn.setPosition(j * size, i * size);
						window.draw(BlackPawn);
					}
					if (board[i][j] == WHITE_PAWN)
					{
						WhitePawn.setPosition(j * size, i * size);
						window.draw(WhitePawn);
					}
					if (board[i][j] == BLACK_ROOK)
					{
						BlackRook.setPosition(j * size, i * size);
						window.draw(BlackRook);
					}
					if (board[i][j] == WHITE_ROOK)
					{
						WhiteRook.setPosition(j * size, i * size);
						window.draw(WhiteRook);
					}
					if (board[i][j] == BLACK_BISHOP)
					{
						BlackBishop.setPosition(j * size, i * size);
						window.draw(BlackBishop);
					}
					if (board[i][j] == WHITE_BISHOP)
					{
						WhiteBishop.setPosition(j * size, i * size);
						window.draw(WhiteBishop);
					}
					if (board[i][j] == BLACK_KNIGHT)
					{
						BlackKnight.setPosition(j * size, i * size);
						window.draw(BlackKnight);
					}
					if (board[i][j] == WHITE_KNIGHT)
					{
						WhiteKnight.setPosition(j * size, i * size);
						window.draw(WhiteKnight);
					}
					if (board[i][j] == BLACK_QUEEN)
					{
						BlackQueen.setPosition(j * size, i * size);
						window.draw(BlackQueen);
					}
					if (board[i][j] == WHITE_QUEEN)
					{
						WhiteQueen.setPosition(j * size, i * size);
						window.draw(WhiteQueen);
					}
					if (board[i][j] == BLACK_KING)
					{
						BlackKing.setPosition(j * size, i * size);
						window.draw(BlackKing);
					}
					if (board[i][j] == WHITE_KING)
					{
						WhiteKing.setPosition(j * size, i * size);
						window.draw(WhiteKing);
					}
				}
			}
		}
		window.display();
	}

	return 0;
}
