#include <iostream>
using namespace std;

void remove_house(string a[], int n, int m, int x, int y)
{
    for (int i = x; i < n; i++)
    {
        if (a[i][y] == '.')
            break;
        for (int j = y; j < m; j++)
        {
            if (a[i][j] == '#')
                a[i][j] = '.';
            else
                break;
        }
    }
   
}

int main()
{
    int n, m;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                k++;
                remove_house(a, n, m, i, j);
            }
        }
    }
    cout << k << endl;

    return 0;
}