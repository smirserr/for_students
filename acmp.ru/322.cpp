#include <iostream>
using namespace std;
#define N 22




int main()
{
	int fib[22] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657};  
	
	string s;
	cin >> s;

	for(int i = 0; (i < N) && (fib[i]-1 < s.size()); i++)
	{
		cout << s[fib[i]-1];
	}
	cout << endl;


    return 0;
}
