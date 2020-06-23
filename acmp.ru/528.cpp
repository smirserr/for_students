#include <iostream>
#include <math.h>
using namespace std;




int main()
{
    long long int n, k;
    cin >> n >> k;

    long long int s = n;
    for(long long int i = 1; i < k; i++)
    {
        s += n*(i+1) - 3 - 2*(i-1);
    }

    cout << s << endl;


    return 0;
}