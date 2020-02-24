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
	char* change[4];

	for (int j = 0; j < n; j++)
		change[j] = empty;
	change[i] = point;
	//system("cls");
	for (int j = 0; j < n; j++)
		cout << "\t" << change[j] << str[j] << endl;
}

int change_menu(char **item, char **item2, int index, int &point)
{
	int i = point, x, n, next = 0;
	bool enter = false;
	char str[][20] = { "next", "preview", "result", "correct" };
	int count = 4;

	do
	{
		system("cls");
		if (!item2)
			print_sudoku(item, 9, -1);
		else
			double_print_sudoku(item, item2, 9);

		print_menu(str, count, point);
		n = count;
		x = _getch();
		switch (x)
		{
		case Down:
			if (point + 1 < n)
				point++;
			break;

		case Up:
			if (point - 1 >= 0)
				point--;
			break;
		case Enter:
			enter = true;
			break;
		}
	} while (!enter);

	return point;
}