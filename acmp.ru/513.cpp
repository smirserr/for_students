#include <iostream> 
using namespace std; 

double fact(int n)
{
    double m = 1;
    for(int i = 1; i <= n; i++)
    {
        m *= i;
    }
    return m;
}

double c(int n, int k)
{
    double z = fact(n) / (fact(k) * fact(n-k));
    return z;
}

int main()
{
    int n;
    double x = 0;
    cin >> n;
    for(int k = 2; k <= n; k++)
    {
        x += c(n, k);
    }
    cout.precision(0);
    cout << fixed <<  x;
    return 0;
}