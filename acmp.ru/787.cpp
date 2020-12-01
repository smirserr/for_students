#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
        cout << a[0] << endl;
    else if (n % 2 == 0)
        cout << max(a[n / 2 - 1], a[n / 2]) << endl;
    else
        cout << max(min(a[n / 2 - 1], a[n / 2]), min(a[n / 2], a[n / 2 + 1])) << endl;

    return 0;
} 
