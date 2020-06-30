#include <iostream> 
#include <math.h>
using namespace std; 
#define MAX_SIZE 100



void input(string *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void copy(string *src, string *dst, int n)
{
    for(int i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}


void step(string *a, string *b, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int l = j-1, r = j+1, u = i-1, d = i+1;
            if (l == -1) l = m-1;
            if (r == m)  r = 0;
            if (u == -1) u = n-1;
            if (d == n)  d = 0;
            int k = (a[u][l] == '*') + (a[u][j] == '*') + (a[u][r] == '*') + (a[i][l] == '*') +
                    (a[i][r] == '*') + (a[d][l] == '*') + (a[d][j] == '*') + (a[d][r] == '*');
            if (k == 3) b[i][j] = '*';
            if ((k < 2) || (k > 3)) b[i][j] = '.';
        }
    }
    copy(b, a, n);
}



void print(string *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}


int main()
{
    int  n, m, k;
    cin >> n >> m >> k;
    string a[n];
    string b[n];
    input(a,n);
    copy(a, b, n);
    

    for(int i = 0; i < k; i ++)
    {   
        step(a,b,n,m);
    }
    print(a, n);



    return 0;
}