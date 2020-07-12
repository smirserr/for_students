#include <iostream>
using namespace std; 
#define K 10


int main()
{
    int a[K][K];
    for(int i = 0; i < K; i++)
        for(int j = 0; j < K; j++)
            a[i][j] = 1;
    
    int n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[x][y] = 0;
    }
    int p = 0;
    for(int i = 0; i < K; i++)
        for(int j = 0; j < K; j++)
            if (a[i][j] == 0)
                p += a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1];
    cout << p << endl;

    return 0;
}