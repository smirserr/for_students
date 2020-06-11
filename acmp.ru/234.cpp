#include <iostream> 
using namespace std; 	

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int a[n+2][m+2];
	for(int i = 0; i < n+2; i++)
	{
		for(int j = 0; j < m+2; j++)
		{
			a[i][j] = 0;
		}
	}

	int x,y;
	for(int i = 0; i < k; i++)
	{
		cin >> x >> y;
		a[x][y] = 1; 
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if (a[i][j]) cout << '*';
			else
			{
				int s = 0;
				for(int i_ = 0; i_ < 3; i_ ++)
				{
					for(int j_ = 0; j_ <3; j_ ++)
					{
						if (a[i-1+i_][j-1+j_]) s++;
					}
				}
				if (s == 0) cout << '.';
				else cout << s;
			}
		}
		cout << endl;
	}

	return 0;
}
 
