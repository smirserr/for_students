#include <iostream> 
using namespace std; 	
#define SIZE 1000001

int main()
{
	bool a[SIZE];
	for(int i = 0; i < SIZE; i++) a[i] = true;
	a[0] = a[1] = false;

	for(int i = 2; i <=  SIZE/2; i++)
	{
		for(int j = i*2; j < SIZE; j += i)
		{
			a[j] = false;
		}
	}

	int n, m;
	bool v = false;
	cin >> n >> m;
	for(int i = n; i <= m; i++)
	{
		if (a[i])
		{
			v = true;
			cout << i << endl;
		}
	}
	
	if (not v) cout << "Absent" << endl;


	return 0;
}