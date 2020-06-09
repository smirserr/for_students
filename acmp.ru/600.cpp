#include <iostream> 
using namespace std; 	




bool check(string s)
{
	if (s.size() % 3 != 0) return false;
	for(int i = 0; i < s.size() / 3; i++) 
	{
		if (s[i] != '0') return false;
	}
	for(int i = s.size() / 3; i < 2*s.size() / 3; i++) 
	{

		if (s[i] != '1') return false;
	}
	for(int i = 2*s.size() / 3; i < s.size(); i++) 
	{
		if (s[i] != '2') return false;
	}
	return true;
}




int main()
{
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		if (check(s)) cout << "YES" << endl;
		else cout << "NO" << endl; 
	}
    return 0;
}