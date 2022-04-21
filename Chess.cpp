#include <iostream>
#include "SFML/Graphics.hpp"
#include "position.hpp"
#include "defines.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game!");
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	int changeWhite = 0, changeBlack = 0;
	int pieceMoved = 0;

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

					if (board[y][x] != 0)
					{
						dx = pos.x - x * size;
						dy = pos.y - y * size;
						if (board[y][x] == BLACK_PAWN && move == 1)
						{
							pieceMoved = BLACK_PAWN;
							movedSprite = BlackPawn;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_PAWN && move == 0)
						{
							pieceMoved = WHITE_PAWN;
							movedSprite = WhitePawn;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_ROOK && move == 0)
						{
							pieceMoved = WHITE_ROOK;
							movedSprite = WhiteRook;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_ROOK && move == 1)
						{
							pieceMoved = BLACK_ROOK;
							movedSprite = BlackRook;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_KNIGHT && move == 0)
						{
							pieceMoved = WHITE_KNIGHT;
							movedSprite = WhiteKnight;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_KNIGHT && move == 1)
						{
							pieceMoved = BLACK_KNIGHT;
							movedSprite = BlackKnight;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_BISHOP && move == 0)
						{
							pieceMoved = WHITE_BISHOP;
							movedSprite = WhiteBishop;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_BISHOP && move == 1)
						{
							pieceMoved = BLACK_BISHOP;
							movedSprite = BlackBishop;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_QUEEN && move == 0)
						{
							pieceMoved = WHITE_QUEEN;
							movedSprite = WhiteQueen;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_QUEEN && move == 1)
						{
							pieceMoved = BLACK_QUEEN;
							movedSprite = BlackQueen;
							board[y][x] = 0;
						}
						if (board[y][x] == WHITE_KING && move == 0)
						{
							pieceMoved = WHITE_KING;
							movedSprite = WhiteKing;
							board[y][x] = 0;
						}
						if (board[y][x] == BLACK_KING && move == 1)
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
					int ok = 0;
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