#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    s1 += s1;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int k = s1.find(s2);
    cout << k;
    return 0;
}
