#include <iostream> 
#include <algorithm>
using namespace std;    
 
bool inside(int x, int y, double r)
{
    return x*x + y*y <= r*r;
}
 
 
int main()
{
    double r;
    int l;
    cin >> r >>l;
 
    int count = 0, max_x = 0;
    long long int sum = 0;
    for(int y = int(r)/l * l; y-l >= 0; y-= l)
    {
        for(int x = max_x + l; inside(x,y,r); x+= l)
        {
            count ++;
            max_x = x;
        }
        sum += count;
    }
    cout << sum*4 << endl;
 
    return 0;
}
