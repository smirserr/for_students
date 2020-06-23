#include <iostream>
using namespace std;


void f(int n)
{
    int a[max(n,5)];
    int b[max(n,5)];
   
    a[0] = 2; a[1] = 3; 
    a[2] = 4; a[3] = 7; 
    a[4] = 13; b[0] = 1;
    b[1] = 5;  b[2] = 6;
    b[3] = 8;  b[4] = 9;
    b[5] = 10; b[6] = 11;
    b[7] = 12;
    int j = 8;

    for(int i = 5; i < n; i++)
    {
        a[i] = b[i-1] + b[i-3];
        for(int k = a[i-1]+1; (k < a[i]) && (j < n); k++)
        {
            b[j++] = k;
        }
    }
    cout << a[n-1] << endl << b[n-1] << endl;

}


int main()
{
    int n;
    cin >> n;
    f(n);



    return 0;
}