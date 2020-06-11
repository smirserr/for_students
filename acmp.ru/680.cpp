#include <iostream> 
using namespace std; 	

int main()
{
	long long int p = 3;
	int n;
	cin >> n;
	
	for(int i = 0; i < n-1; i++)
	{
		p *= 2;
	}
	cout << p << endl;
	
    return 0;
}


print(3*(2**(int(input())-1)))