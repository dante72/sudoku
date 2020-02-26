#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include "header.h"

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
		
		if (m1 && n_space(m, nn) == -1)
		{
			printf("\tYOU WIN!!\n\tPress ENTER...");
			ft_free(m);
			m = m1;
			getchar();
			enter = true;
		}
		else
			printf("\tUse Space, Up, Dowp, Left, Right\n\tPress ESC to exit...");

		x = _getch();
		if (x >= Button0 && x <= Button9)
		{
			char ch = x - Button0 + '0';
			if (ch == '0')
				m[i][j] = '.';
			else
				if (check_sq(m, i, j, ch))
					m[i][j] = ch;
		}
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
		case (Space):
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
				ft_free(m);
				m = m1;
			}
				enter = true;	
				break;
		}
		point = nn * i + j;
	} while (!enter);

	return m;
}

Sudoku* load(Sudoku* list, int& index)
{
	char buff[100];
	FILE* f;
	int n = 9;

	if ((f = fopen("example.txt", "r")) != NULL)
	{
		while (!feof(f))
		{
			fgets(buff, sizeof(buff), f);
			if (check_str(buff, n))
			{
				list = (Sudoku*)realloc(list, sizeof(Sudoku) * (index + 1));
				list[index].task = create_squard(n);
				list[index].result = nullptr;
				list[index].n_result = -1;
				list[index].task = str_to_squard(list[index].task, n, buff);
				list[index].index = index;
				index++;
			}
		}
		fclose(f);
	}

	return list;
}

void free_list(Sudoku* list, int index)
{
	for (int i = 0; i < index; i++)
	{
			ft_free(list[i].task);
			ft_free(list[i].result);
	}
	free(list);
}

void save(Sudoku* list, int index)
{
	FILE* f;
	int i = 0;

	if ((f = fopen("example.txt", "w")) != NULL)
	{
		while (i < index)
		{
			int j = 0;
			while (list[i].task[j])
			{
				fprintf(f, "%s ", list[i].task[j]);
				j++;
			}
			fprintf(f, "\n");
			i++;
		}
		fprintf(f, "\n");
		fclose(f);
	}
}

Sudoku* new_item(Sudoku* list, int& index)
{
	int n = 9;

	list = (Sudoku*)realloc(list, sizeof(Sudoku) * (index + 1));
	list[index].task = create_squard(n);
	list[index].task = empty_squard(list[index].task, n);
	list[index].result = nullptr;
	list[index].n_result = -1;
	list[index].index = index;
	index++;

	return list;
}

Sudoku* del_item(Sudoku* list, int& index, int k)
{
	int n = 9, i = 0, j = 0;
	Sudoku* temp_list;

	if (index == 1)
		temp_list = nullptr;
	else
		temp_list = (Sudoku*)malloc(sizeof(Sudoku) * index);

	while (i < index)
	{
		if (i != k)
		{
			temp_list[j].task = new_copy(list[i].task, n);
			temp_list[j].result = new_copy(list[i].result, n);
			temp_list[j].n_result = list[i].n_result;
			temp_list[j].index = j;
			j++;
		}
		i++;
	}
	free_list(list, index);
	index--;
	list = temp_list;

	return list;
}