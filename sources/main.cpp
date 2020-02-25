#include "header.h"

int main()
{
	Sudoku *list = nullptr;
	int index = 0;

	list = load(list, index);

	if (!list)
		list = new_item(list, index);
	list = menu(list, index);
	free(list);

	return 0;
}


