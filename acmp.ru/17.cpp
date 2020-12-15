#include <iostream>
#include <set>
using namespace std;

bool f(int *a, int *b, int n)
{
    for(int i = 0; i < n; i++)
        if (a[i] != b[i]) 
            return false;
    return true;
    
}

 
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 1; i < n; i++)
    {
        bool b = true;
        if ((n-1) % i != 0) continue;
        for(int j = i; (i+j < n) && b; j += i)
            b = f(a, (a+j), i);
        if (b)
        {
            cout << i;
            break;
        }
    }
    

    return 0;
}