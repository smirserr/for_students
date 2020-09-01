#include <iostream>
using namespace std;



int main()
{
    long long int n;
    cin >> n;
    if (n < 2) 
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3) 
    {
        cout << 2 << endl;
        return 0;
    }
    cout << n << endl;


    return 0;
}

