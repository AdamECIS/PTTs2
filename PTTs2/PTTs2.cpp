//<<<<<<< HEAD
// PTTs2.cpp : Defines the entry point for the console application.
// Jared Stemeye
// Rachel Adams
// Adam Everett
//=======
//CIS150-01 - Team Purple Turtle Turtles
//Start date: 11/12/2017
//Description: This game is designed to create a maze for the user to run through. The maze walls will be invisibile, and the
// user has the posibility of running into bombs that will end their life and extra lifes which will add an addition life
// to their life counter. Finishing the first level will allow the user to move on to the next level, where the size of the
// maze and number of items increases.


//10 levels in difficulty, more bombs and more coins, set bomb spawn points per level so we have a kay map to use
//level 1: 3x3 maze, 1 bomb, 1 coin
//level 2: exponential increaming, number of bombs = number of coins, bomb ratio is 3 boms to 1 coin
//bombs are not displayed to user, but the number of bombs will be told to the user
//pro level: coin surrounded by bombs except on one side, one way in one way out
//potentially bombs moving with every user move
//text file: saving player names and scores in a text file, old school arcade style high score list

//>>>>>>> 32827cde7b4869d6ef7e63a1117233ce607e5383
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;



void intro()
{
	const int coin = 233;
	const int bomb = 235;
	cout << "Welcome to The Maze! The obvective is to get from the enterance to the exit alive. Sound simple, right?" << endl;
	cout << "Maybe, maybe not." << endl;
	cout << "You see, there will be obstacles in your way, ones that might be invisible. Well, yeah, they're invisible." << endl;
	cout << "They're bombs." << endl;
	cout << "Oops." << endl;
	cout << (char)bomb << " " << (char)bomb << " " << (char)bomb << " " << (char)bomb << " " << (char)bomb << " " << (char)bomb << endl;
	cout << "The good news though, is that there are non-invisible coins to make your journey worthwhile." << endl;
	cout << "For every coin you collect, 100 points are added to your score." << endl;
	cout << (char)coin << " " << (char)coin << " " << (char)coin << " " << (char)coin << " " << (char)coin << " " << (char)coin << endl;
	cout << "Speaking of scores, taking less steps can also help you out. Make a lot of unnessary moves and your score" << endl;
	cout << "might not be as high as you'd like it. Be efficient and collect your coins and you might just find your name" << endl;
	cout << "on our high score list.";
	cout << endl;
	cout << "Use WASD to move: W will take you up, S will take you down, A and D will take you left and right." << endl;
	cout << "Watch out for those bombs, and Good Luck!" << endl;
	cout << endl;
}

// displayBoard (Jared and Adam)
void displayBoard(int rows, int cols, char board[5][5])
{
	const int wall = 178;
	for (int i = 0; i < (rows + 26); i++)
	{
		cout << (char)wall;
	}
	for (int i = 0; i < rows; i++)
	{
		// cell divider
		cout << endl << (char)wall;
		for (int j = 0; j < cols; j++)
		{
			cout << " _" << board[i][j] << "_ ";
			if (j < (cols - 1))
			{
				cout << "|";
			}
		}
		if (i != rows - 1)
		{
			cout << (char)wall;
		}
		else
		{
			
		}
	}
	cout << endl;
	for (int i = 0; i < (rows + 26); i++)
	{
		cout << (char)wall;
	}
	cout << endl;
}

// Move Functions (Adam and Jared)

int downLeft(int move)
{
	move = move + 1;
	return move;

}

int upRight(int move)
{
	move = move - 1;
	return move;
}

int main()
{
	const int wall = 178;
	const int vertGrid = 179;
	const int horGrid = 196;
	const int player = 206;
	const int exit = 175;
	const int coin = 233;
	int points = 0;
	int lives = 3;
	int moveCount;
	int nextLevel = 1;

	int inc = 0;
	char input;
	char mine = 255;
	bool contP = true;
	
	intro();

	//===================================== Level 1 ==========================================================================
	moveCount = 15;
	int r = 0, c = 0;
	const int rows = 5;
	const int cols = 5;
	while (contP && lives > 0 && nextLevel == 1)
	{
		cout << "LEVEL " << nextLevel << endl;
		int arraySize = rows*cols;
		char board[rows][cols] = {
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ '  ' , '  ' , '  ' , '  ', (char)exit }
		};

		char bombBoard[rows][cols] = {
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ '  ' , '  ' , '  ' , '  ', ' x ' },
			{ '  ' , '  ' , '  ' , '  ', '  ' },
			{ ' x ' , '  ' , '  ' , '  ', (char)exit }
		};

		board[2][2] = (char)coin;
		board[r][c] = (char)player;
		

		displayBoard(rows, cols, board);
		
		cout << moveCount << " moves left. Enter a move: ";
		cin >> input;
		system("CLS");

		if (input == 's' || input == 'S')
		{
			downLeft(r);
			r = downLeft(r);
			board[r][c] = (char)player;
			board[r - 1][c] = '  ';
			moveCount--;
			points += 10;
			if (bombBoard[r][c] == ' x ')
			{
				lives--;
				cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
			}
			cout << "Total Points: " << points << endl;			
		}
		else if (input == 'w' || input == 'W')
		{
			upRight(r);
			r = upRight(r);
			board[r][c] = (char)player;
			board[r + 1][c] = '  ';
			moveCount--;
			points += 10;
			if (bombBoard[r][c] == ' x ')
			{
				lives--;
				cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
			}
			cout << "Total Points: " << points << endl;
		}
		else if (input == 'd' || input == 'D')
		{
			downLeft(c);
			c = downLeft(c);
			board[r][c] = (char)player;
			board[r][c - 1] = '  ';
			moveCount--;
			points += 10;
			if (bombBoard[r][c] == ' x ')
			{
				lives--;
				cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
			}
			cout << "Total Points: " << points << endl;			
		}
		else if (input == 'a' || input == 'A')
		{
			upRight(c);
			c = upRight(c);
			board[r][c] = (char)player;
			board[r][c + 1] = '  ';
			moveCount--;
			points += 10;
			if (bombBoard[r][c] == ' x ')
			{
				lives--;
				cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
			}
			cout << "Total Points: " << points << endl;			
		}
		else if (input == 'p' || input == 'P')
		{
			contP = false;
		}
		else
		{
			cout << "Invalid input. " << endl;
			cout << "Total Points: " << points << endl;
		}
		if (bombBoard[r][c] == ' x ')
		{
			lives--;
			cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
		}
		if (moveCount <= 0)
		{
			cout << "You ran out and moves and lost a limb. " << endl;
			lives--;
			cout << lives << " limbs left. On to the next Level" << endl;
			cout << "Total Points: " << points << endl;
			while (r > 0)
			{
				r--;
			}
			while (c > 0)
			{
				c--;
			}
			moveCount = 15;
			nextLevel++;
		}
		for (int i = 0; i < arraySize; i++)
		{
			if (board[r][c] == board[rows - 1][cols - 1])
			{
				system("CLS");
				cout << "You reached the Exit. On to the next Level. " << endl;
				cout << "Total Points: " << points << endl;
				while (r > 0)
				{
					r--;
				}
				while (c > 0)
				{
					c--;
				}
				moveCount = 15;
				nextLevel++;
			}
			else
			{

			}
		}
	}
		//=================================================== Level 2 ==========================================================
	//const int rows2 = 6;
	//const int cols2 = 6;
	//while (contP && lives > 0 && nextLevel == 2)
	//{
	//	cout << "LEVEL " << nextLevel << endl;
	//	int arraySize = rows2*cols2;
	//	char board2[rows2][cols2] = {
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , (char)exit }
	//	};

	//	char bombBoard[rows2][cols2] = {
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , '  ' },
	//		{ '  ' , '  ' , '  ' , '  ', '  ' , (char)exit }
	//	};

	//	board2[2][2] = (char)coin;
	//	board2[r][c] = (char)player;


	//	displayBoard(rows2, cols2, board2);

	//	cout << moveCount << " moves left. Enter a move: ";
	//	cin >> input;
	//	system("CLS");

	//	if (input == 's' || input == 'S')
	//	{
	//		downLeft(r);
	//		r = downLeft(r);
	//		board[r][c] = (char)player;
	//		board[r - 1][c] = '  ';
	//		moveCount--;
	//		points += 10;
	//		if (bombBoard[r][c] == ' x ')
	//		{
	//			lives--;
	//			cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
	//		}
	//		cout << "Total Points: " << points << endl;
	//	}
	//	else if (input == 'w' || input == 'W')
	//	{
	//		upRight(r);
	//		r = upRight(r);
	//		board[r][c] = (char)player;
	//		board[r + 1][c] = '  ';
	//		moveCount--;
	//		points += 10;
	//		if (bombBoard[r][c] == ' x ')
	//		{
	//			lives--;
	//			cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
	//		}
	//		cout << "Total Points: " << points << endl;
	//	}
	//	else if (input == 'd' || input == 'D')
	//	{
	//		downLeft(c);
	//		c = downLeft(c);
	//		board[r][c] = (char)player;
	//		board[r][c - 1] = '  ';
	//		moveCount--;
	//		points += 10;
	//		if (bombBoard[r][c] == ' x ')
	//		{
	//			lives--;
	//			cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
	//		}
	//		cout << "Total Points: " << points << endl;
	//	}
	//	else if (input == 'a' || input == 'A')
	//	{
	//		upRight(c);
	//		c = upRight(c);
	//		board[r][c] = (char)player;
	//		board[r][c + 1] = '  ';
	//		moveCount--;
	//		points += 10;
	//		if (bombBoard[r][c] == ' x ')
	//		{
	//			lives--;
	//			cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
	//		}
	//		cout << "Total Points: " << points << endl;
	//	}
	//	else if (input == 'p' || input == 'P')
	//	{
	//		contP = false;
	//	}
	//	else
	//	{
	//		cout << "Invalid input. " << endl;
	//		cout << "Total Points: " << points << endl;
	//	}
	//	if (bombBoard[r][c] == ' x ')
	//	{
	//		lives--;
	//		cout << "You hit a mine! Limb lost! " << endl << lives << " left! " << endl;
	//	}
	//	if (moveCount <= 0)
	//	{
	//		cout << "You ran out and moves and lost a limb. " << endl;
	//		lives--;
	//		cout << lives << " limbs left. On to the next Level" << endl;
	//		while (r > 0)
	//		{
	//			r--;
	//		}
	//		while (c > 0)
	//		{
	//			c--;
	//		}
	//		moveCount = 15;
	//		nextLevel++;
	//	}
	//	for (int i = 0; i < arraySize; i++)
	//	{
	//		if (board[r][c] == board[rows - 1][cols - 1])
	//		{
	//			system("CLS");
	//			cout << "You reached the Exit. On to the next Level. " << endl;
	//			cout << "Total Points: " << points << endl;
	//			while (r > 0)
	//			{
	//				r--;
	//			}
	//			while (c > 0)
	//			{
	//				c--;
	//			}
	//			moveCount = 15;
	//			nextLevel++;
	//		}
	//		else
	//		{

	//		}
	//	}
	}


	cout << endl << "You're done Buddy! " << endl;
	

	system("pause");
	return 0;
}

