#include <iostream>
using namespace std; 




int main()
{
    int n,sum = 0, t, t1, t2, v;
    cin >> n;
    int a[100001] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> t1 >> t2 >> v;
        for(int j = t1; j < t2; j++)
            a[j] += v;
    }
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        sum += a[i];
        if (sum < 0) sum = 0;
    }
    cout << sum << endl;

    return 0;
}