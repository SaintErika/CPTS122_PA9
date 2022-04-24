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