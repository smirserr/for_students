#include <iostream>
using namespace std;


unsigned long long int from_3_to_10(unsigned long long int n)
{
    unsigned long long int r = 0;
    unsigned long long int p = 1;
    while (n > 0)
    {
        r += (n % 10) * p;
        p *= 3;
        n /= 10;
    }
    return r;
}



int main()
{
    unsigned long long int a, b;
    cin >> a >> b;
    cout << from_3_to_10(a) + from_3_to_10(b) << endl;
    
    return 0;
} 
