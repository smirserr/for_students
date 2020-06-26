#include <iostream>
using namespace std;

bool is_digit(char c)
{
    return (c >= '0') && (c <= '9');
}

bool is_up_alpha(char c)
{
    return (c >= 'A') && (c <= 'Z');
}



int main()
{
    
    
    string s;
    getline(cin,s);
    char max = s[0];

    for(char c : s)
    {
        if (is_up_alpha(c) || is_digit(c))
        {
            if (c > max) max = c;
        }
        else 
        {
            cout << -1 << endl;
            return 0;
        }
    }

    if (is_digit(max)) cout << (max == '0'? 2 : max - '0' + 1) << endl;
    else cout << max - 'A' + 11 << endl;
  

    return 0;
}