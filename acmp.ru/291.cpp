#include <iostream>
#include <algorithm>
using namespace std;


bool f(string s1, string s2)
{
    for(int i : s1)
        if (count(s1.begin(), s1.end(), i) > count(s2.begin(), s2.end(), i))
            return false;
    return true;
}


int main()
{
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int k = 0;
    for(string i : a)
        k += f(i, s);
    cout << k << endl;
    
    return 0;
}
