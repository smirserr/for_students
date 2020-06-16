#include <iostream>
using namespace std;
#define N 22

bool double_shot(int x1, int y1, int x2, int y2)
{
	return (x1*y2 == x2*y1) && ((x1 < 0) == (x2 < 0)) && ((y1 < 0) == (y2 < 0));
}



int main()
{
	int n;
	cin >> n;
	int x[n];
	int y[n];

	int count = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		bool t = false;
		for(int j = 0; (j < i) && !t; j++)
		{
			if (double_shot(x[j], y[j],x[i],y[i])) t = true; 
		} 
		if (not t) count ++; 
	}
	cout << count << endl;
    return 0;
}
