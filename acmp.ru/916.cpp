#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	long long int sum = 0;

	int p = 0;
	for(int i = 0; i < n; i++)
	{
		if (i % k == 0) p ++;
		sum += a[n-1-i] * p;
	}

	cout << sum << endl;
	

	

    return 0;
}
