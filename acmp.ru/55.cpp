#include <iostream>
#include <math.h>
using namespace std;
# define PI 3.14159265359

int main()
{
    double x1, y1, x2, y2, r, s;
    cin >> x1 >> y1 
        >> x2 >> y2 
        >> r  
        >> s;
    double d = sqrt((x1 - x2)*(x1 - x2) + (y1-y2)*(y1-y2));
    double s_new = 2*PI*r*r;
    if (d < 2*r)
    {
        double f = 2 * acos(d/2/r);
        s_new -= (r*r * (f - sin(f)));
    }

    //cout  << s_new << endl;
    if (s_new > s)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}