#include <iostream>
using namespace std;




int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {   
        cin >> a[i];
    }

    int b = 0;
    int sum = 0;
    int t = 1;
    for(int i = 0; i < n; i++)
    {
        b++;
        sum += a[i];
        if ((a[i] == 10) && (b == 1))
        {
            sum += a[i+1] + a[i+2];
            b = 0;
            t++;
        }
        else if(b == 2)
        {
            if (a[i] + a[i-1] == 10)
            {
                sum += a[i+1];
            }
            t++;
            b = 0;
        }
        if (t == 11) break;
    }

    cout << sum << endl;

    return 0;
}