#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


int main()
{
	int n = 9;
	char buff[100];
	FILE* f;
	Sudoku *list = nullptr;
	//list.task = nullptr;
	//list.result= nullptr;
	//list.n_result = nullptr;
	int index = 0;
	if ((f = fopen("example.txt", "r")) != NULL)
	{
		while (!feof(f))
		{
			fgets(buff, sizeof(buff), f);
			if (check_str(buff, n))
			{
				list = (Sudoku*)realloc(list, sizeof(Sudoku) * (index + 1));
				//list.result = (char***)realloc(list.result, sizeof(char***) * (index + 1));
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
		//printf("Number example %d\n\n", i + 1);
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
	}
	free(list);
	/*char str[][100]{ "..716.3.8 42.78.91. 183.257.. .128.6.9. 37.491..2 69...2187 2.9.48.7. ..1657.4. 7452..8..",
	"8........ ..36..... .7..9.2.. .5...7... ....457.. ...1...3. ..1....68 ..85...1. .9....4.." };
	
	for (int i = 0; i < 2; i++)
	{
		if (check_str(str[i], n))
			sudoku(str[i]);
	}*/

	getchar();
	getchar();
	return 0;
}



