#include <iostream> 
#include <math.h>
using namespace std; 


int main()
{
    double r1, r2, h, b, s, l, p;
    cin >> r1 >> r2 >> h >> b;

    p = (2*r1+2*r2)/2;
    s = sqrt(p*(p-r1)*(p-r1)*(p-2*r2));
    l = s/r2;

    if (l + (b-r2) >= h) cout << "YES";
    else cout << "NO";
    cout << endl;



    return 0;
}