#include <iostream>

char** create_squard(const int n)
{
	char **m = (char **)malloc((n + 1) * sizeof(char *));
	for (int i = 0; i < n; i++)
		m[i] = (char *)malloc((n + 1) * sizeof(char));
	m[n] = nullptr;

	return m;
}

char** copy_squard(char** m, char **m1, const int n)
{
	int i = 0;
	while (m[i])
	{
		for (int j = 0; j <= n; j++)
			m1[i][j] = m[i][j];
		i++;
	}
	return m1;
}

char** new_copy(char** m, const int n)
{
	char** m1 = create_squard(n);
	m1 = copy_squard(m, m1, n);

	return m1;
}