#include <iostream>
#include <set>
using namespace std;

int main()
{
    set <string> a;
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n-m+1; i++)
    {
        a.insert(s.substr(i,m));
    }
    cout << a.size() << endl;
    return 0;
}