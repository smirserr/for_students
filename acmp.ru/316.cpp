#include <iostream>
using namespace std; 


int price(int n)
{
    if (n % 100 == 0) return 7 * (n / 100);
    else return 7 * (n / 100 + 1); 
}



int main()
{
    int n,p;
    cin >> n;
    for(int i = n; i >= 0; i--)
    {
        p = price(i);
        if (p + i <= n) 
        {
            cout << i << ' ' << p << endl;
            return 0;
        } 
    }
    return 0;
}