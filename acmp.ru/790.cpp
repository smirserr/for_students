#include <iostream> 
using namespace std; 	


string from_10(int n, int k)
{
	string s = "";
	while (n > 0)
	{
		int cif = n % k;
		if (cif < 10) s = char(cif + '0') + s;
		else s = char(cif + 'A' - 10) + s;
		n /= k; 
	}
	return s;	
}

int main()
{
	int d,m,y;
	scanf("%d/%d/%d", &d, &m, &y);
	
	cout << from_10(d, d+1) << "/" << from_10(m,d+1) << "/" << from_10(y,d+1) << endl;

    return 0;
} 
