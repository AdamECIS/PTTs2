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


#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


int main()
{
	int rows = 3;
	int cols = 3;
	string level1[3][3];
	string border = "=====";
	string horGrid = "-----";
	string vertGrid = "|";
	// Top of Board
	cout << border << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << vertGrid;
		for (int j = 0; j < cols; j++)
		{
			cout << level1[i][j] << vertGrid;
		}
		if (i != rows - 1)
		{
			cout << endl << horGrid << endl;
		}
		else
		{
			cout << endl;
		}
		// Bottom of Board
	}
	cout << border << endl;



	system("pause");
	return 0;
}