#include <iostream>
#include <vector>
using namespace std;


void f(string& s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') s[i] = 'Z';
        else s[i]--;
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < 26; i++)
    {
        if (s1.find(s2) != string::npos)
        {
            cout << s1 << endl;
            return 0;
        }
        f(s1);
    }
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}
