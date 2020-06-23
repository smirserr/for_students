#include <iostream>
#include <math.h>
using namespace std;


double f(int a, int b, int c)
{
    if ((a >= b+c) || (b >= a+c) || (c >= a+b)) return -1;
    double p = double(a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    int i_, j_, k_;
    double m = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                double p = f(a[i],a[j],a[k]);
                if (p > m) 
                {
                    m = p;
                    i_ = i;
                    j_ = j;
                    k_ = k;
                }
            }
        }
    }

    if (m == -1) cout << -1 << endl;
    else
    {
        cout.precision(8);
        cout << fixed << m << endl;
        cout << i_+1 << ' ' << j_+1 << ' ' << k_+1 << endl;
    }


    return 0;
}