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
	char str[][20] = { "Next    ", "New    ", "Game", 
					   "Back    ", "Delete ", "Save", 
					   "Solution", "Correct", "Exit" 
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

Sudoku *menu(Sudoku* list, int& index)
{
	int i = 0, j = 0, point = 0, n = 9;

	for (;;)
	{
		j = change_menu(list[i], j, point);

		if (j == 0 && i + 1 < index)
			i++;
		if (j == 3 && i - 1 >= 0)
			i--;
		if (j == 6)
			sudoku_result(list[i]);
		if (j == 7)
		{
			free(list[i].result);
			list[i].result = nullptr;
			correct_sudoku(list[i], n, 0, false);
		}
		if (j == 2)
			list[i].task = correct_sudoku(list[i], n, 0, true);
		if (j == 5)
			save(list, index);
		if (j == 1)
		{
			list = new_item(list, index);
			i = index - 1;
			correct_sudoku(list[i], n, 0, false);
		}
		if (j == 4)
		{
			list = del_item(list, index, i);
			if (!list)
				list = new_item(list, index);
			if (i > 0)
				i--;
		}
		if (j == 8)
			break;
	}

	return list;
}