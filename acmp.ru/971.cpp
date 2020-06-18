#include <iostream>
#include <set>
using namespace std;




int main()
{
	long long int x,y;
	cin >> x >> y;
	long long int x1, y1 = y, 
				  x2 = x, y2 = y + 1;

	if (x < 0) x1 = x-1;
	else x1 = x + 1;
	if (y < 0) y2 = y-1;
	else y2 = y+1;

	long long int x3 = x*3-x1-x2,
				  y3 = y*3 - y1-y2;

	if ((abs(x) >= 1000000000) || (abs(y) >= 1000000000))
	{
		cout << "NO" << endl;
		return 0; 
	}
	cout << "YES" << endl;
	cout << x1 << ' ' << y1 << endl;
	cout << x2 << ' ' << y2 << endl;
	cout << x3 << ' ' << y3 << endl;
	

	




    return 0;
}
