#include <iostream>
using namespace std;

int main()
{
    int n, k, x, y, i, min;
    int a[21];
    bool t;

    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> x;
        k = i = 0;
        min = 100;
        while (x % 2 == 0)
        {
            i++;
            x /= 2;
        }
        if (i > 0)
        {
            k++;
            a[k] = i;
            if (i < min)
                min = i;
        }
        y = 3;
        while ((x > 1) && (y * y <= x))
        {
            i = 0;
            while (x % y == 0)
            {
                i ++;
                x /= y;
            }
            if (i > 0)
            {
                k++;
                a[k] = i;
                if  (i < min)
                    min = i;
            }
            y += 2;
        }
        if (x > 1)
        {
            k ++;
            a[k] = 1;
            min = 1;
        }
        if (min == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            t = true;
            for(int i = 1; i <= k; i++)
            {
                t = t && (a[i] % min == 0); 
            }
            if (t)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }

    return 0;
}