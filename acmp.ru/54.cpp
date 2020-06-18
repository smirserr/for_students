#include <iostream>
#include <set>
using namespace std;




int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m];

	int min_row, max_min_row = -1001;
	int max_col, min_max_col = 1001;

	for(int i = 0; i < n; i++)
	{
		min_row = 1001;
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] < min_row) min_row = a[i][j];
		}
		if (min_row > max_min_row) max_min_row = min_row;
	}

	for(int j = 0; j < m; j++)
	{
		max_col = -1001;
		for(int i = 0; i < n; i++)
		{
			if (a[i][j] > max_col) max_col = a[i][j];
		}
		if (max_col < min_max_col) min_max_col = max_col;
	}

	cout << max_min_row << ' ' << min_max_col << endl;




    return 0;
}
