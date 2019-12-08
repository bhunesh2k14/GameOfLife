#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int alive_neighbours(vector<vector<int>> grid,int i, int j)
{
	int count = 0;
	count = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + grid[i][j - 1] + grid[i][j + 1] + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
	return count;
}

void display(vector<vector<int>> grid)
{
	system("cls");//clear screen
	cout << "\nSimulation (X: alive) :\n\n";
	int row = grid.size();
	int col = grid[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1)
			{
				cout << " X ";
			}
			else
			{
				cout << "   ";
			}
			//cout << " " << grid[i][j] << " ";
			
		}
		cout << "\n";
	}
	Sleep(1);//delay in milliseconds.
}

int main()
{
	vector<vector<int>> grid;
	vector<vector<int>> next_grid;
	int row, col, choice;
	srand(time(NULL));
	cout << "\nEnter Rows & Column: ";
	cin >> row >> col;
	cout << "\nChoose: 1. Random Start 2. Custom Input: ";
	cin >> choice;
	
	if (choice == 1)
	{
		for (int i = 0; i < row; i++)
		{
			vector<int> temp;
			for (int j = 0; j < col; j++)
			{
				
				int random = rand() % 10 + 1;
				int val = (random > 5) ? 1 : 0;
				temp.push_back(val);
			}
			grid.push_back(temp);
		}
	}

	if (choice == 2)
	{
		cout << "\nInput Start Sequence (1: Alive 0: Dead): ";
		//input start sequence
		for (int i = 0; i < row; i++)
		{
			vector<int> temp;
			for (int j = 0; j < col; j++)
			{
				int val;
				cin >> val;
				temp.push_back(val);
			}
			grid.push_back(temp);
		}
	}
	
	
	//make next_grid as colony
	for (int i = 0; i < grid.size()+2; i++)
	{
		vector<int> temp;
		temp.push_back(0);
		if (i == 0 || i == grid.size()+1)
		{
			for (int j = 0; j < grid[0].size(); j++) {
				temp.push_back(0);
			}
		}
		else
		{
			for (int j = 0; j < grid[0].size(); j++) {
				temp.push_back(grid[i-1][j]);
			}
		}
		temp.push_back(0);
		next_grid.push_back(temp);
	}

	//initial colony
	display(next_grid);

	//loop until colony gets stable
	while (next_grid!=grid)
	{
		grid = next_grid;
		//for each cell
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++) {
				int neighbours = alive_neighbours(grid, i, j);//get alive neighbours
				if (neighbours < 2 || neighbours > 3)
				{
					next_grid[i][j] = 0; //cell dies due to under/over population
				}
				else
				{
					if (neighbours == 3)
					{
						next_grid[i][j] = 1; //cell Alive
					}
					else
					{
						next_grid[i][j] = grid[i][j]; //cell stable
					}
				}
			}
		} 
		display(grid);//display current colony
	}
	return 0;
}