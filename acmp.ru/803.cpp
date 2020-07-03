#include <iostream> 
using namespace std; 



int main()
{
    int a, b, k;
    cin >>a  >> b >> k;
    if (a >= b) a %= b;
    for(int i = 0; i < k; i++)
    {
        a = (a % b) * 10;
    }
    cout << a/b;

    return 0;
}