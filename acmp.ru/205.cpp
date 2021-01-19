#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int h1, m1, s1;
    int h2 = 0, m2 = 0, s2 = 0;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    cin >> s;
    int k = count(s.begin(), s.end(), ':');
    if (k == 0)
    {
        sscanf(s.c_str(), "%d", &s2);
    }
    if (k == 1)
    {
        sscanf(s.c_str(), "%d:%d", &m2, &s2);
    }
    if (k == 2)
    {
        sscanf(s.c_str(), "%d:%d:%d", &h2, &m2, &s2);
    }

    h1 += h2;
    m1 += m2;
    s1 += s2;

    m1 += s1 / 60;
    s1 %= 60;
    h1 += m1 / 60;
    m1 %= 60;
    int d = h1 / 24;
    h1 %= 24;

    cout.fill('0');
    cout << setw(2) << h1 << ":" << setw(2) << m1 << ":" << setw(2) << s1;
    if (d != 0) 
        cout << "+" << d << " days" << endl;
    
    return 0;
}