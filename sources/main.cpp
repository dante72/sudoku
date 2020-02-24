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
				list[index].task = str_to_squard(list[index].task, n, buff);
				list[index].index = index;
				index++;
			}
		}
		fclose(f);
	}
	if (!list)
		list = new_item(list, index);

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
		if (j == 6)
		{
			list = new_item(list, index);
			i = index - 1;
			correct_sudoku(list[i], n, 0, false);
		}
		if (j == 7)
		{
			list = del_item(list, index, i);
			if (i > 0)
				i--;
		}
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

Sudoku *new_item(Sudoku* list, int &index)
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
	int n = 9;

	Sudoku *temp_list = (Sudoku*)malloc(sizeof(Sudoku) * index);
	int i = 0, j = 0;
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
	index--;
	free(list);
	list = temp_list;

	return list;
}


