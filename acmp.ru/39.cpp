#include <iostream>
using namespace std;

int ind_max(int *a, int n)
{
    int ind = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= a[ind])
            ind = i;
    return ind;
}

int f(int *a, int n)
{
    if (n < 1)
        return 0;
    if (n == 1)
        return a[0];
    int ind = ind_max(a, n);
    return a[ind] * (ind + 1) + f(a + ind + 1, n - ind - 1);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << f(a, n) << endl;
    return 0;
}