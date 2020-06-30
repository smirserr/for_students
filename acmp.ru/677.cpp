#include <iostream> 
using namespace std; 


int main()
{
    int k, n, m, d, x, y;
    cin >> k >> n >> m >> d;
    x = k * n + k * m + n * m;
    y = n * m * k;
    if (( x >= y ) || ( n == 1) || (m == 1) || (k == 1)) 
    {
        cout << -1 << endl;
        return 0;
    }
    if (d*y % (y-x) != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int t = d*y / (y-x);
    if ((t % k != 0) || (t % n != 0) || (t % m != 0)) cout << -1 << endl;
    else cout << t << endl;


    return 0;
}