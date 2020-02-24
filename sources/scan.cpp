#include <conio.h>
#include "header.h"

enum Buttons {
	ESC = 27,
	Enter = 13,
	Down = 80,
	Up = 72,
	Right = 77,
	Left = 75,
	Space = 32
};

char **correct_sudoku(Sudoku item, const int nn, int point, bool game)
{
	int i = point / nn;
	int j = point % nn;
	int x;
	bool enter = false;
	char** m1 = nullptr, **m = item.task;
	
	if (game)
	{
		item.result = new_copy(m, nn);
		m1 = item.result;
	}
	do {
		system("cls");
		print_sudoku(item, nn, point);
		if (n_space(m, nn) == -1)
		{
			printf("\tYOU WIN!!\n\tPress ENTER...");
			free(m);
			m = m1;
			getchar();
			enter = true;
		}
		x = _getch();
		switch (x)
		{
		case Down:
			if (i + 1 < nn)
				i++;
			break;
		case Right:
			if (j + 1 < nn)
				j++;
			break;
		case Up:
			if (i - 1 >= 0)
				i--;
			break;
		case Left:
			if (j - 1 >= 0)
				j--;
			break;
		case Space:
			if(!game || m1[i][j] == '.')
			do {
				if (m[i][j] == '9')
					m[i][j] = '.';
				else
					if (m[i][j] == '.')
						m[i][j] = '1';
					else
						m[i][j]++;
				if (m[i][j] == '.')
					break;
			} while (!check_sq(m, i, j, m[i][j]));
			break;
		case ESC:
			if (game)
			{
				free(m);
				m = m1;
				enter = true;
				break;
			}
		case Enter:
			if(!game)
				enter = true;
			break;
		}

		point = nn * i + j;
	} while (!enter);

	return m;
}