#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std; 

bool f(int x)
{
    return (x % 2 == 0) && ((x / 64) % 2 == 1);
}



int main()
{
    int n, a;
    vector <int> v;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if (f(a)) v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i : v) cout << i << ' ';
    cout << endl;


    return 0;
}