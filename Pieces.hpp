//Project Name: Chess Game
//Project Description: Basic version of chess
//Authors: Ethan Teh, Ethan Lyons
//Project Design: April 8, 2022 - April 27, 2022

/*
There is no polymorphism present. 
The team had planned for using polymorphism for a class "piece", 
creating classes that inherit from piece for each of the individual pieces. 
The subclasses of piece would then be instantiated and arranged in a 2-D array and manipulated that way, 
the functions for checking pieces movements being unique to each subclass of piece, 
and functions relegated to a class with the board to check the state of other pieces.
It would operate very similar to the code implemented currently, in that positions would be passed between
the functions in the order of:
	checking if correct move type
	checking if piece can move to the square legall
	checking if piece causes a Check state on yourself
	checking if piece causes a Check state on opponent (to generate board state)
The class would also hold data like if pieces are in their original positions, etc.

However, due to time constraints the team wanted to focus on creating a program that worked, 
focusing on the rules and usability of the game alongside the graphics and user inputs, 
ensuring that the game is playable.
*/

#pragma once
#include "position.hpp"
#include "defines.hpp"

int PawnWhite(int oldx, int oldy, int newx, int newy)
{
	if (oldPos.y == 6)
	{
		if ((newy == oldy - 1 && newx == oldx && board[oldy - 1][oldx] == 0) || (newy == oldy - 2 && newx == oldx && board[oldy - 1][oldx] == 0 && board[oldy - 2][oldx] == 0))
		{
			return 1;
		}
	}
	else if (newy == oldy - 1 && newx == oldx && board[oldy - 1][oldx] == 0)
	{
		return 1;
	}
	if (board[oldy - 1][oldx - 1] > 0)
	{
		if (newy == oldy - 1 && newx == oldx - 1)
		{
			return 1;
		}
	}
	if (board[oldy - 1][oldx + 1] > 0)
	{
		if (newy == oldy - 1 && newx == oldx + 1)
		{
			return 1;
		}
	}
	return 0;
}
int PawnBlack(int oldx, int oldy, int newx, int newy)
{
	if (oldPos.y == 1)
	{
		if ((newy == oldy + 1 && newx == oldx && board[oldy + 1][oldx] == 0) || (newy == oldy + 2 && newx == oldx && board[oldy + 1][oldx] == 0 && board[oldy + 2][oldx] == 0))
		{
			return 1;
		}
	}
	else if (newy == oldy + 1 && newx == oldx && board[oldy + 1][oldx] == 0)
	{
		return 1;
	}
	if (board[oldy + 1][oldx - 1] < 0)
	{
		if (newy == oldy + 1 && newx == oldx - 1)
		{
			return 1;
		}
	}
	if (board[oldy + 1][oldx + 1] < 0)
	{
		if (newy == oldy + 1 && newx == oldx + 1)
		{
			return 1;
		}
	}
	return 0;
}

int RookWhite(int oldx, int oldy, int newx, int newy)
{
	for (int i = oldx - 1; i >= 0; i--) 
	{
		if (board[oldy][i] >= 0 && (newx == i && newy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] >= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i <= 7; i++) 
	{
		if (board[oldy][i] >= 0 && (newy == oldy && newx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][oldx] >= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	return 0;
}
int RookBlack(int oldx, int oldy, int newx, int newy)
{
	for (int i = oldx - 1; i >= 0; i--) 
	{
		if (board[oldy][i] <= 0 && (newx == i && newy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] <= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i <= 7; i++) 
	{
		if (board[oldy][i] <= 0 && (newy == oldy && newx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i <= 7; i++)
	{
		if (board[i][oldx] <= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	return 0;
}

int BishopWhite(int oldx, int oldy, int newx, int newy)
{
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}
int BishopBlack(int oldx, int oldy, int newx, int newy)
{
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int KnightWhite(int oldx, int oldy, int newx, int newy)
{
	if (oldy - 2 >= 0 && oldx - 1 >= 0 && newy == oldy - 2 && newx == oldx - 1 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy - 2 >= 0 && oldx + 1 < LENGTH && newy == oldy - 2 && newx == oldx + 1 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && oldx + 2 < LENGTH && newy == oldy - 1 && newx == oldx + 2 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy + 1 >= 0 && oldx + 2 < LENGTH && newy == oldy + 1 && newx == oldx + 2 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy + 2 < LENGTH && oldx + 1 < LENGTH && newy == oldy + 2 && newx == oldx + 1 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy + 2 < LENGTH && oldx - 1 >= 0 && newy == oldy + 2 && newx == oldx - 1 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy + 1 < LENGTH && oldx - 2 >= 0 && newy == oldy + 1 && newx == oldx - 2 && board[newy][newx] >= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && oldx - 2 >= 0 && newy == oldy - 1 && newx == oldx - 2 && board[newy][newx] >= 0)
	{
		return 1;
	}
	return 0;
}
int KnightBlack(int oldx, int oldy, int newx, int newy)
{
	if (oldy - 2 >= 0 && oldx - 1 >= 0 && newy == oldy - 2 && newx == oldx - 1 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy - 2 >= 0 && oldx + 1 < LENGTH && newy == oldy - 2 && newx == oldx + 1 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && oldx + 2 < LENGTH && newy == oldy - 1 && newx == oldx + 2 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy + 1 >= 0 && oldx + 2 < LENGTH && newy == oldy + 1 && newx == oldx + 2 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy + 2 < LENGTH && oldx + 1 < LENGTH && newy == oldy + 2 && newx == oldx + 1 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy + 2 < LENGTH && oldx - 1 >= 0 && newy == oldy + 2 && newx == oldx - 1 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy + 1 < LENGTH && oldx - 2 >= 0 && newy == oldy + 1 && newx == oldx - 2 && board[newy][newx] <= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && oldx - 2 >= 0 && newy == oldy - 1 && newx == oldx - 2 && board[newy][newx] <= 0)
	{
		return 1;
	}
	return 0;
}

int QueenWhite(int oldx, int oldy, int newx, int newy)
{
	for (int i = oldx - 1; i >= 0; i--)
	{
		if (board[oldy][i] >= 0 && (newx == i && newy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] >= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i <= 7; i++) 
	{
		if (board[oldy][i] >= 0 && (newy == oldy && newx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][oldx] >= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}
int QueenBlack(int oldx, int oldy, int newx, int newy)
{
	for (int i = oldx - 1; i >= 0; i--) 
	{
		if (board[oldy][i] <= 0 && (newx == i && newy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] <= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i <= 7; i++)
	{
		if (board[oldy][i] <= 0 && (newy == oldy && newx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][oldx] <= 0 && (newy == i && newx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++)
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] <= 0 && (newy == i && newx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//-----------------------------------------------------------------------
int PawnWhiteCheck(int posx, int posy, int kingx, int kingy)
{
	if (board[posy - 1][posx - 1] >= 0)
	{
		if (posy - 1 == kingy && posx - 1 == kingx)
		{
			return 1;
		}
	}
	if (board[posy - 1][posx + 1] >= 0)
	{
		if (posy - 1 == kingy && posx + 1 == kingx)
		{
			return 1;
		}
	}
	return 0;
}
int PawnBlackCheck(int posx, int posy, int kingx, int kingy)
{
	if (board[posy + 1][posx - 1] <= 0)
	{
		if (kingy == posy + 1 && kingx == posx - 1)
		{
			return 1;
		}
	}
	if (board[posy + 1][posx + 1] <= 0)
	{
		if (kingy == posy + 1 && kingx == posx + 1)
		{
			return 1;
		}
	}
	return 0;
}

int RookWhiteCheck(int oldx, int oldy, int kingx, int kingy)
{
	for (int i = oldx - 1; i >= 0; i--)
	{
		if (board[oldy][i] >= 0 && (kingx == i && kingy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] >= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i < LENGTH; i++) 
	{
		if (board[oldy][i] >= 0 && (kingy == oldy && kingx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i < LENGTH; i++)
	{
		if (board[i][oldx] >= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	return 0;
}
int RookBlackCheck(int oldx, int oldy, int kingx, int kingy)
{
	for (int i = oldx - 1; i >= 0; i--)
	{
		if (board[oldy][i] <= 0 && (kingx == i && kingy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] <= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i < LENGTH; i++)
	{
		if (board[oldy][i] <= 0 && (kingy == oldy && kingx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i < LENGTH; i++) 
	{
		if (board[i][oldx] <= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	return 0;
}

int BishopWhiteCheck(int oldx, int oldy, int kingx, int kingy)
{
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}
int BishopBlackCheck(int oldx, int oldy, int kingx, int kingy)
{
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int KnightWhiteCheck(int oldx, int oldy, int kingx, int kingy)
{
	if (oldy - 2 >= 0 && oldx - 1 >= 0 && kingy == oldy - 2 && kingx == oldx - 1 && board[kingy][kingx] >= 0)
	{
		return 1; 
	}
	if (oldy - 2 >= 0 && oldx + 1 < LENGTH && kingy == oldy - 2 && kingx == oldx + 1 && board[kingy][kingx] >= 0)
	{
		return 1; 
	}
	if (oldy - 1 >= 0 && oldx + 2 < LENGTH && kingy == oldy - 1 && kingx == oldx + 2 && board[kingy][kingx] >= 0)
	{
		return 1; 
	}
	if (oldy + 1 >= 0 && oldx + 2 < LENGTH && kingy == oldy + 1 && kingx == oldx + 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldy + 2 < LENGTH && oldx + 1 < LENGTH && kingy == oldy + 2 && kingx == oldx + 1 && board[kingy][kingx] >= 0)
	{
		return 1; 
	}
	if (oldy + 2 < LENGTH && oldx - 1 >= 0 && kingy == oldy + 2 && kingx == oldx - 1 && board[kingy][kingx] >= 0)
	{
		return 1; 
	}
	if (oldy + 1 < LENGTH && oldx - 2 >= 0 && kingy == oldy + 1 && kingx == oldx - 2 && board[kingy][kingx] >= 0)
	{
		return 1; 
	}
	if (oldy - 1 >= 0 && oldx - 2 >= 0 && kingy == oldy - 1 && kingx == oldx - 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	return 0;
}
int KnightBlackCheck(int oldx, int oldy, int kingx, int kingy)
{
	if (oldy - 2 >= 0 && oldx - 1 >= 0 && kingy == oldy - 2 && kingx == oldx - 1 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy - 2 >= 0 && oldx + 1 < LENGTH && kingy == oldy - 2 && kingx == oldx + 1 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy - 1 >= 0 && oldx + 2 < LENGTH && kingy == oldy - 1 && kingx == oldx + 2 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy + 1 >= 0 && oldx + 2 < LENGTH && kingy == oldy + 1 && kingx == oldx + 2 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy + 2 < LENGTH && oldx + 1 < LENGTH && kingy == oldy + 2 && kingx == oldx + 1 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy + 2 < LENGTH && oldx - 1 >= 0 && kingy == oldy + 2 && kingx == oldx - 1 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy + 1 < LENGTH && oldx - 2 >= 0 && kingy == oldy + 1 && kingx == oldx - 2 && board[kingy][kingx] <= 0)
	{
		return 1; 
	}
	if (oldy - 1 >= 0 && oldx - 2 >= 0 && kingy == oldy - 1 && kingx == oldx - 2 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	return 0;
}

int QueenWhiteCheck(int oldx, int oldy, int kingx, int kingy)
{
	for (int i = oldx - 1; i >= 0; i--) 
	{
		if (board[oldy][i] >= 0 && (kingx == i && kingy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] >= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i < LENGTH; i++)
	{
		if (board[oldy][i] >= 0 && (kingy == oldy && kingx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i < LENGTH; i++) 
	{
		if (board[i][oldx] >= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i < LENGTH; i++) 
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}
int QueenBlackCheck(int oldx, int oldy, int kingx, int kingy)
{
	for (int i = oldx - 1; i >= 0; i--) 
	{
		if (board[oldy][i] <= 0 && (kingx == i && kingy == oldy))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][oldx] <= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	for (int i = oldx + 1; i < LENGTH; i++) 
	{
		if (board[oldy][i] <= 0 && (kingy == oldy && kingx == i))
		{
			return 1;
		}
		else if (board[oldy][i] != 0)
		{
			break;
		}
	}
	for (int i = oldy + 1; i < LENGTH; i++) 
	{
		if (board[i][oldx] <= 0 && (kingy == i && kingx == oldx))
		{
			return 1;
		}
		else if (board[i][oldx] != 0)
		{
			break;
		}
	}
	int j = oldx - 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy - 1; i >= 0; i--) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = oldx - 1;
	for (int i = oldy + 1; i <= 7; i++) 
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = oldx + 1;
	for (int i = oldy + 1; i < LENGTH; i++)  
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int KingWhiteCheck(int oldx, int oldy, int kingx, int kingy)
{
	if (oldx - 1 >= 0 && oldy - 1 >= 0 && kingy == oldy - 1 && kingx == oldx - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && kingx == oldx && kingy == oldy - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && oldx + 1 < LENGTH && kingx == oldx + 1 && kingy == oldy - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldx + 1 < LENGTH && kingy == oldy && kingx == oldx + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldx + 1 < LENGTH && oldy + 1 < LENGTH && kingy == oldy + 1 && kingx == oldx + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldy + 1 < LENGTH && kingy == oldy + 1 && kingx == oldx && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldx - 1 >= 0 && oldy + 1 < LENGTH && kingx == oldx - 1 && kingy == oldy + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oldx - 1 >= 0 && kingy == oldy && kingx == oldx - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	return 0;
}
int KingBlackCheck(int oldx, int oldy, int kingx, int kingy)
{
	if (oldx - 1 >= 0 && oldy - 1 >= 0 && kingy == oldy - 1 && kingx == oldx - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && kingx == oldx && kingy == oldy - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldy - 1 >= 0 && oldx + 1 < LENGTH && kingx == oldx + 1 && kingy == oldy - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldx + 1 < LENGTH && kingy == oldy && kingx == oldx + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldx + 1 < LENGTH && oldy + 1 < LENGTH && kingy == oldy + 1 && kingx == oldx + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldy + 1 < LENGTH && kingy == oldy + 1 && kingx == oldx && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldx - 1 >= 0 && oldy + 1 < LENGTH && kingx == oldx - 1 && kingy == oldy + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oldx - 1 >= 0 && kingy == oldy && kingx == oldx - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	return 0;
}

int KingWhiteChecker(int kingx, int kingy)
{
	int check = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] > 0)
			{
				if (board[i][j] == BLACK_PAWN)
				{
					check = PawnBlackCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == BLACK_ROOK)
				{
					check = RookBlackCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == BLACK_KNIGHT)
				{
					check = KnightBlackCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == BLACK_BISHOP)
				{
					check = BishopBlackCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == BLACK_QUEEN)
				{
					check = QueenBlackCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == BLACK_KING)
				{
					check = KingBlackCheck(j, i, kingx, kingy);
				}
				if (check == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int KingWhite(int oldx, int oldy, int newx, int newy)
{
	if (oldx - 1 >= 0 && oldy - 1 >= 0 && newy == oldy - 1 && newx == oldx - 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx - 1, oldy - 1);
		if (check == 1)
		{
			return 1;  
		}
	}
	if (oldy - 1 >= 0 && newx == oldx && newy == oldy - 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx, oldy - 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldy - 1 >= 0 && oldx + 1 < LENGTH && newx == oldx + 1 && newy == oldy - 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx + 1, oldy - 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx + 1 < LENGTH && newy == oldy && newx == oldx + 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx + 1, oldy);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx + 1 < LENGTH && oldy + 1 < LENGTH && newy == oldy + 1 && newx == oldx + 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx + 1, oldy + 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldy + 1 < LENGTH && newy == oldy + 1 && newx == oldx && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx, oldy + 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx - 1 >= 0 && oldy + 1 < LENGTH && newx == oldx - 1 && newy == oldy + 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx - 1, oldy + 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx - 1 >= 0 && newy == oldy && newx == oldx - 1 && board[newy][newx] >= 0)
	{
		int check = KingWhiteChecker(oldx - 1, oldy);
		if (check == 1)
		{
			return 1;
		}
	}
	if (wKingMoved == 0 && rWhiteRookMoved == 0 && board[7][5] == 0 && board[7][6] == 0 && newy == 7 && newx == 6)
	{
		int check = 1;
		check = KingWhiteChecker(4, 7);
		if (check == 1)
		{
			check = KingWhiteChecker(5, 7);
			if (check == 1)
			{
				check = KingWhiteChecker(6, 7);
				if (check == 1)
				{
					board[7][7] = 0;
					board[7][5] = WHITE_ROOK;
					wKingMoved = 1;
					rWhiteRookMoved = 1;
					return 1;
				}
			}
		}
	}
	if (wKingMoved == 0 && lWhiteRookMoved == 0 && board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && newy == 7 && newx == 2)
	{
		int check = 1;
		check = KingWhiteChecker(4, 7);
		if (check == 1)
		{
			check = KingWhiteChecker(3, 7);
			if (check == 1)
			{
				check = KingWhiteChecker(2, 7);
				if (check == 1)
				{
					check = KingWhiteChecker(1, 7);
					if (check == 1)
					{
						board[7][0] = 0;
						board[7][3] = WHITE_ROOK;
						wKingMoved = 1;
						lWhiteRookMoved = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int KingBlackChecker(int kingx, int kingy)
{
	int check = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] < 0)
			{
				if (board[i][j] == WHITE_PAWN)
				{
					check = PawnWhiteCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == WHITE_ROOK)
				{
					check = RookWhiteCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == WHITE_KNIGHT)
				{
					check = KnightWhiteCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == WHITE_BISHOP)
				{
					check = BishopWhiteCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == WHITE_QUEEN)
				{
					check = QueenWhiteCheck(j, i, kingx, kingy);
				}
				if (board[i][j] == WHITE_KING)
				{
					check = KingWhiteCheck(j, i, kingx, kingy);
				}
				if (check == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int KingBlack(int oldx, int oldy, int newx, int newy)
{
	if (oldx - 1 >= 0 && oldy - 1 >= 0 && newy == oldy - 1 && newx == oldx - 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx - 1, oldy - 1);
		if (check == 1)
		{
			return 1;  
		}
	}
	if (oldy - 1 >= 0 && newx == oldx && newy == oldy - 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx, oldy - 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldy - 1 >= 0 && oldx + 1 < LENGTH && newx == oldx + 1 && newy == oldy - 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx + 1, oldy - 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx + 1 < LENGTH && newy == oldy && newx == oldx + 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx + 1, oldy);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx + 1 < LENGTH && oldy + 1 < LENGTH && newy == oldy + 1 && newx == oldx + 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx + 1, oldy + 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldy + 1 < LENGTH && newy == oldy + 1 && newx == oldx && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx, oldy + 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx - 1 >= 0 && oldy + 1 < LENGTH && newx == oldx - 1 && newy == oldy + 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx - 1, oldy + 1);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (oldx - 1 >= 0 && newy == oldy && newx == oldx - 1 && board[newy][newx] <= 0)
	{
		int check = KingBlackChecker(oldx - 1, oldy);
		if (check == 1)
		{
			return 1; 
		}
	}
	if (rBlackRookMoved == 0 && bKingMoved == 0 && board[0][5] == 0 && board[0][6] == 0 && newy == 0 && newx == 6)
	{
		int check = KingBlackChecker(4, 0);
		if (check == 1)
		{
			check = KingBlackChecker(5, 0);
			if (check == 1)
			{
				check = KingBlackChecker(6, 0);
				if (check == 1)
				{
					bKingMoved = 1;
					rBlackRookMoved = 1;
					board[0][7] = 0;
					board[0][5] = BLACK_ROOK;
					return 1;
				}
			}
		}
	}
	if (lBlackRookMoved == 0 && bKingMoved == 0 && board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && newy == 0 && newx == 2)
	{
		int check = KingBlackChecker(4, 0);
		if (check == 1)
		{
			check = KingBlackChecker(3, 0);
			if (check == 1)
			{
				check = KingBlackChecker(2, 0);
				if (check == 1)
				{
					check = KingBlackChecker(1, 0);
					if (check == 1)
					{
						bKingMoved = 1;
						lBlackRookMoved = 1;
						board[0][0] = 0;
						board[0][3] = BLACK_ROOK;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void KingWhitePos()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] == WHITE_KING)
			{
				whiteKing.x = j;
				whiteKing.y = i;
				break;
			}
		}
	}
}
void KingBlackPos()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] == BLACK_KING)
			{
				blackKing.y = i;
				blackKing.x = j;
				break;
			}
		}
	}
}
