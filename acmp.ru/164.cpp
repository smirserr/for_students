#include <iostream> 
using namespace std; 


int digit_root(string s)
{
    int k = 0;
    for(char i : s)
        k += i - '0';
    
    if (k < 10) return k;
    return digit_root(to_string(k));
    
}


int main()
{
    
    string s,s1,s2;
    cin >> s;

    for (int i = 1; i < s.size(); i++)
    {
        s1 = s.substr(0,i);
        s2 = s.substr(i);
        if (digit_root(s1) == digit_root(s2))
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}

