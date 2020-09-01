#include <iostream>
using namespace std;
int a[8][8];

void g(int x, int y)
{
    if(x < 0 || x > 7) return;
    if(y < 0 || y > 7) return;
    if(a[x][y] == 0) a[x][y] = 2;
}

int main()
{
    const int N = 8;
    string f, l, k;
    cin >> f >> l >> k;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = 0;

    int x = f[0] - 'A';
    int y = f[1] - '1';
    a[x][y] = 1;
    for(int i = 0; i < N; i++)
    {
        g(x,i);
        g(i,y);
        g(x-i,y-i);
        g(x-i,y+i);
        g(x+i,y+i);
        g(x+i,y-i);
    }


    x = l[0] - 'A';
    y = l[1] - '1';
    a[x][y] = 1;
    for(int i = 0; i < N; i++)
    {
        g(x,i);
        g(i,y);
    }

    x = k[0] - 'A';
    y = k[1] - '1';
    a[x][y] = 1;
    g(x+2,y+1);
    g(x+2,y-1);
    g(x+1,y+2);
    g(x+1,y-2);
    g(x-1,y+2);
    g(x-1,y-2);
    g(x-2,y+1);
    g(x-2,y-1);

    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (a[i][j] == 2) count++;
            //cout << a[i][j] << ' ';
        }
        //cout << endl;
    }       
    cout << count << endl;

    
    return 0;
}
