#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

int main()
{
	int n = 9;
	char buff[100];
	FILE* f;
	if ((f = fopen("example.txt", "r")) != NULL)
	{
		while (!feof(f))
		{
			fgets(buff, sizeof(buff), f);
			if (check_str(buff, n))
				sudoku(buff);
		}
		fclose(f);
	}
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



