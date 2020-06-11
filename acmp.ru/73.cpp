#include <iostream> 
using namespace std; 	

int from_27(char c)
{
	if ((c >= '0') && (c <= '9')) return c - '0';
	return c - 'A' + 10;
}



int main()
{
	string s;
	getline(cin,s);

	for(int i = 0; i < s.size(); i++)
	{
		int k = from_27(s[i]);
		k -= i+1;
		while (k <= 0) k = 27 + k;
		if (k == 27) cout << ' ';
		else cout << char('a' + k - 1);
	}
	cout << endl;

	
    return 0;
} 
