#include <iostream>
#include <vector> 
using namespace std; 

vector <string> gen_cyclic_shift(string s)
{
    vector <string> v;
    for(int i = 0 ; i < s.size(); i++)
    {
        v.push_back(s);
        s += s[0];
        s.erase(0,1);
    }
    return v;
}



int main()
{
    string s, sub;
    cin >> s >> sub;
    vector <string> v = gen_cyclic_shift(sub);
    int k = 0;
    for(int i = 0; i < s.size() - sub.size()+1; i++)
    {
        string t = s.substr(i,sub.size());
        for (auto i : v)
        {
            if (i == t)
            {
                k++;
                break;
            }
        }
    }
    cout << k << endl;
    return 0;
}