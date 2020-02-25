#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

enum Buttons {
	ESC = 27,
	Enter = 13,
	Down = 80,
	Up = 72,
	Right = 77,
	Left = 75,
	Space = 32
};


void print_menu(char str[][20], const int n, int i)
{
	char point[] = ">> ";
	char empty[] = "   ";
	char* change[9];

	for (int j = 0; j < n; j++)
		change[j] = empty;
	change[i] = point;
	for (int j = 0; j < n; j++)
	{
		printf("%s%s\t", change[j], str[j]);
		if ((j + 1) % 3 == 0)
			printf("\n");
	}
}

int change_menu(Sudoku item, int index, int &point)
{
	char** item1 = item.task, ** item2 = item.result;
	int x, k = 3, i = point / k, j = point % k, n = 9;
	bool enter = false;
	char str[][20] = { "Next  ", "New    ", "Game", 
					   "Back  ", "Delete ",	"Save", 
					   "Result", "Correct", "Exit" 
					};
	int count = 9;

	do
	{
		system("cls");
		if (!item2)
			print_sudoku(item, n, -1);
		else
			double_print_sudoku(item, n);
		print_menu(str, count, point);

		x = _getch();
		switch (x)
		{
		case Right:
			if (j < k - 1)
				j++;
			break;

		case Left:
			if (j > 0)
				j--;
			break;
		case Up:
			if (i > 0)
				i--;
			break;
		case Down:
			if (i < k - 1)
				i++;
			break;
		case Enter:
			enter = true;
			break;
		}
		point = i * k + j;
	} while (!enter);

	return point;
}