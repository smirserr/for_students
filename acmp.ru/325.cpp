#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cell_check(string s)
{
    return (s[0] >= 'a') && (s[0] <= 'h') && (s[1] >= '1') && (s[1] <= '8');
}

vector<string> horse_move(string s)
{
    vector<string> v;
    string t = s;
    t[0] -= 2;
    t[1]--;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0] -= 2;
    t[1]++;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0]--;
    t[1] -= 2;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0]--;
    t[1] += 2;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0]++;
    t[1] -= 2;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0]++;
    t[1] += 2;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0] += 2;
    t[1]--;
    if (cell_check(t))
        v.push_back(t);
    t = s;
    t[0] += 2;
    t[1]++;
    if (cell_check(t))
        v.push_back(t);
    return v;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1.erase(2, 1);
    vector <string> v1 = horse_move(s1);
    for (string i : v1)
    {
        if (i == s2)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    for(string i : v1)
    {
        vector <string> v2 = horse_move(i);
        for(string j : v2)
        {
            if (j == s2)
            {
                cout << 2 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}