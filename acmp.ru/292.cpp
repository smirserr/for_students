#include <iostream>
#include <math.h>
using namespace std;


bool prime(long long int n)
{
    for(long long int i = 2; i < int(sqrt(n))+1; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long int sum_cif(long long int n)
{
    long long int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}


long long int pck(long long int n)
{
    if ((n == 1) || (n == 4) || (n == 6) || (n == 8) || (n == 9))
        return 0;
    if (prime(n))
        return n;
    return pck(sum_cif(n));
}

 
int main()
{
   
    int n;
    cin >> n;
    cout << pck(n) << endl;

    return 0;
}

