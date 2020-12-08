#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

string code = "the quick brown fox jumps over the lazy dog";

bool f(string s, string &uncode)
{

    if (s.size() != code.size())
        return false;
    uncode = "";
    if ((s[3] != ' ') || (s[9] != ' ') ||
        (s[15] != ' ') || (s[19] != ' ') ||
        (s[25] != ' ') || (s[30] != ' ') ||
        (s[34] != ' ') || (s[39] != ' '))
        return false;
    if (count(s.begin(), s.end(), ' ') != 8)
        return false;
    if (s[0] != s[31])
        return false;
    if (s[1] != s[32])
        return false;
    if (s[2] != s[33])
        return false;
    if (s[2] != s[28])
        return false;
    if (s[5] != s[21])
        return false;
    if (s[11] != s[29])
        return false;
    if (s[12] != s[17])
        return false;
    if (s[12] != s[26])
        return false;
    if (s[12] != s[41])
        return false;
    set<char> se(s.begin(), s.end());
    if (se.size() != 27)
        return false;

    uncode += s[36]; //a
    uncode += s[10]; //b
    uncode += s[7];  //c
    uncode += s[40]; //d
    uncode += s[2];  //e
    uncode += s[16]; //f
    uncode += s[42]; //g
    uncode += s[1];  //h
    uncode += s[6];  //i
    uncode += s[20]; //j
    uncode += s[8];  //k
    uncode += s[35]; //l
    uncode += s[22]; //m
    uncode += s[14]; //n
    uncode += s[41]; //o
    uncode += s[23]; //p
    uncode += s[4];  //q
    uncode += s[11]; //r
    uncode += s[24]; //s
    uncode += s[0];  //t
    uncode += s[5];  //u
    uncode += s[27]; //v
    uncode += s[13]; //w
    uncode += s[18]; //x
    uncode += s[38]; //y
    uncode += s[37]; //z
    return true;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    string s[n];
    bool key_found = false;
    string key = "";

    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
        if (not key_found)
            for (int j = 0; s[i].size() - j >= code.size(); j++)
                key_found = f(s[i].substr(j, code.size()), key);
    }

    if (not key_found)
        cout << "No solution" << endl;
    else
        for (int i = 0; i < n; i++)
        {
            for (char c : s[i])
                if ((c >= 'a') && (c <= 'z'))
                    cout << char(key.find(c) + 'a');
                else
                    cout << c;
            cout << endl;
        }
    return 0;
}