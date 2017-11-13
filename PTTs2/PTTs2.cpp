// PTTs2.cpp : Defines the entry point for the console application.
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