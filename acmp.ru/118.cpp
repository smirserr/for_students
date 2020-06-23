#include <iostream>
#include <math.h>
using namespace std;




int main()
{
    int n, k;
    cin >> n >> k;
    bool a[n] = {};

    int d = 0;
    int t = 0;
    int i = 0;
    while (d < n-1)
    {
        if (!a[i]) 
        {
            t++;
            if (t == k) 
            {
                a[i] = true;
                t = 0;
                d++;
            }
        }
        i++;
        if (i == n) i = 0;
    }
    for(int i = 0; i < n; i++)
    {
        if (!a[i]) 
        {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}