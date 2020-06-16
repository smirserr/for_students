#include <stdio.h>

int main()
{
	short n, m;
	scanf("%d %d", &n, &m);
	short a;
	short min_row[n];
	short max_col[m];

	for(short i = 0; i < n; i++) min_row[i] = 1001;
	for(short i = 0; i < m; i++) max_col[i] = -1001;

	for(short i = 0; i < n; i++)
	{
		for(short j = 0; j < m; j++)
		{
			scanf("%d", &a);
			if (a < min_row[i]) min_row[i] = a;
			if (a > max_col[j]) max_col[j] = a;
		}
	}


	int count = 0;
	for(short i = 0; i < n; i++)
	{
		for(short j = 0; j < m; j++)
		{
			if(min_row[i] == max_col[j]) count++;
		}
	}

	printf("%d", count);
	
    return 0;
}
