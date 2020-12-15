#include <iostream>
#include <set>
using namespace std;



 
int main()
{
    int n;
    cin >> n;
    int a[2*n] = {};
    int l,r;
    l = n;
    r = n+1;

    for(int i = 0; i < n; i++)
    {
        int t, d;
        cin >> t;
        if (t == 1)
        {
            cin >> d;
            a[l--] = d;
        }
            
        if (t == 2)
        {
            cin >> d;
            a[r++] = d;
        }
        if (t == 3)
            cout << a[++l] << ' ';
        if (t == 4)
            cout << a[--r] << ' ';

    }



    return 0;
}

