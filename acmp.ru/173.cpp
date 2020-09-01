#include <iostream>
#include <vector>
using namespace std;

string f(int n, int k)
{
    string s = "";
    while(n != 0)
    {
        int d = n % k;
        if (d < 10) s = char('0' + d) + s;
        else s = char('A' + d - 10) + s;
        n /= k;
    }
    //cout << k << ' ' << s << endl;
    return s;
}


bool is_palindrome(string s)
{
    for(int i = 0; i < s.size()/2; i++)
    {
        if (s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}


int main()
{
    vector <int> v;
    int n;
    cin >> n;

    for(int i = 2; i <= 36; i++)
    {
        if (is_palindrome(f(n,i))) v.push_back(i);
    }

    if(v.size() == 0)
    {
        cout << "none" << endl;
        return 0;
    }
    if(v.size() == 1)
    {
        cout << "unique" << endl << v[0] << endl;
        return 0;
    }
    cout << "multiple" << endl;
    for(int i : v)
    {
        cout << i << " ";
    } 
    cout << endl;


    
    return 0;
}
