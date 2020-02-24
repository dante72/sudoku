bool check_num(char ch)
{
	if (ch > '0' && ch <= '9')
		return true;
	else
		return false;
}

bool check_horizont(char** m, int i, int j, char z)
{
	int index;

	index = 0;
	while (m[i][index])
	{
		if (z == m[i][index] && index != j)
			return false;
		index++;
	}

	return true;
}

bool check_vertical(char** m, int i, int j, char z)
{
	int index;

	index = 0;
	while (m[index])
	{
		if (m[index][j] == z && index != i)
			return false;
		index++;
	}

	return true;
}

bool check_squard(char** m, int i, int j, char z)
{
	int index1 = i / 3 * 3;
	int  index2 = j / 3 * 3;
	bool flag = true;

	while (index1 < i / 3 * 3 + 3)
	{
		while (index2 < j / 3 * 3 + 3)
		{
			if (m[index1][index2] == z && !(index1 == i && index2 == j))
				flag = false;
			index2++;
		}
		index2 = j / 3 * 3;
		index1++;
	}

	return flag;
}


bool check_sq(char** m, int i, int j, char z)
{
	if (check_horizont(m, i, j, z))
		if (check_vertical(m, i, j, z))
			if (check_squard(m, i, j, z))
				return true;
	return false;
}