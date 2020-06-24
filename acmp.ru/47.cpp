#include <iostream>
using namespace std;
 

int sum_cif(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n, k = 1, s = 1;
    cin >> n;

    for(int i = 2; i <= n; i++)
    {
        if ((n % i == 0) && (sum_cif(i) > s))
        {
            k = i;
            s = sum_cif(i);
        }
    }
    cout << k << endl;



    return 0;
}