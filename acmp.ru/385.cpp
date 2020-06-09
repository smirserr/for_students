#include <iostream> 
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std; 	

double length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int main()
{
	int n;
	set <double> s; 
	cin >> n;
	double x[n];
	double y[n];

	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			s.insert(length(x[i],y[i],x[j],y[j]));
		}
	}
	vector <double> v(s.begin(), s.end());
	sort(v.begin(), v.end());
	cout << v.size() << endl;

	cout.precision(9);
	for(auto i : v)
	{
		cout << fixed << i << endl;
	}

    return 0;
} 
