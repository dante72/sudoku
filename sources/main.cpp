#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

void save(Sudoku* list, int index);
int main()
{
	int n = 9;
	char buff[100];
	FILE* f;
	Sudoku *list = nullptr;
	int index = 0;

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
				str_to_squard(list[index].task, n, buff);
				index++;
			}
		}
		fclose(f);
	}

	int i = 0, j = 0, point = 0;
	for (;;)
	{
		j = change_menu(list[i], j, point);
		
		if (j == 0 && i + 1 < index)
			i++;
		if (j == 1 && i - 1 >= 0)
			i--;
		if (j == 2)
			sudoku_result(list[i]);
		if (j == 3)
		{	
			free(list[i].result);
			list[i].result = nullptr;
			correct_sudoku(list[i], n, 0, false);
		}
		if (j == 4)
			list[i].task = correct_sudoku(list[i], n, 0, true);
		if (j == 5)
			save(list, index);
	}
	free(list);

	getchar();
	getchar();
	return 0;
}

void save(Sudoku* list, int index)
{
	FILE* f;
	int i = 0;
	if ((f = fopen("example.txt", "w+")) != NULL)
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
		fclose(f);
	}
}


