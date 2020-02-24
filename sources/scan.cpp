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

char **scan_point(char** m, const int nn, int point)
{
	int i = point / nn;
	int j = point % nn;
	int x;
	bool enter = false;

	do {
		system("cls");
		print_sudoku(m, nn, point);
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
			//bool flag = false;
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

		case Enter:
			//if (!p[1].m[i][j].status)
				enter = true;
			break;
		}
		point = nn * i + j;
	} while (!enter);

	return m;
}