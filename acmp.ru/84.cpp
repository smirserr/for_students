#include <iostream> 
using namespace std; 


int main()
{
    int  n, m;
    cin >> n >> m;
    string a[n];

    for(int i = 0; i < n; i++) cin >> a[i];


    int left = m, right = -1, up = n, down = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
            {
                if (i < up) up = i;
                if (i > down) down = i;
                if (j < left) left = j;
                if (j > right) right = j;
            }
        }
    } 


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (i >= up && i <= down && j >= left && j <= right) cout << '*';
            else cout << '.';
        }
        cout << endl;
    }

 
    return 0;
}