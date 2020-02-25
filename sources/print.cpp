#include <iostream>
#include <Windows.h>
#include "header.h"

enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void draw_item(char item, int color, int bg)
{
	SetColor(color, bg);
	printf(" %c", item);
	SetColor(White, Black);
}

void print_squard(char** m)
{
	for (int i = 0; m[i]; i++)
		printf("%s\n", m[i]);
	printf("\n");
}

void print_sudoku(Sudoku item, const int n, int point)
{
	int u = point / n;
	int v = point % n;
	char** m = item.task, **m1 = item.result;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == u && j == v)
				draw_item(m[i][j], Black, LightGreen);
			else
				if (m1 && check_num(m1[i][j]))
					draw_item(m[i][j], Black, LightGray);
				else
					printf(" %c", m[i][j]);
			if ((j + 1) % 3 == 0)
				printf("|");
		}
		if (item.n_result == 0 && i == 4)
			printf("\tDoesn't have a solution!");
		printf("\n");
		if ((i + 1) % 3 == 0)
		{
			for (int k = 0; k < n * 2 + 3; k++)
				printf("-");
			printf("\n");
		}
	}
	printf("Task %d\n\n", item.index + 1);
}

void double_print_sudoku(Sudoku item, const int n)
{
	char** m = item.task, ** m1 = item.result;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" %c", m[i][j]);
			if ((j + 1) % 3 == 0)
				printf("|");
		}
		printf("\t");
		for (int j = 0; j < n; j++)
		{
			if (check_num(m[i][j]))
				draw_item(m1[i][j], Black, LightGray);
			else
				printf(" %c", m1[i][j]);
			if ((j + 1) % 3 == 0)
				printf("|");
		}
		if ((i + 1) % 3 == 0)
		{
			printf("\n");
			for (int k = 0; k < n * 2 + 3; k++)
				printf("-");
			printf("\t");
			for (int k = 0; k < n * 2 + 3; k++)
				printf("-");
		}
		printf("\n");
	}
	printf("Task %d", item.index + 1);
	if (item.n_result > 1)
		printf("\t\t\tDoesn't have a single solution!!!");
	printf("\n\n");
}