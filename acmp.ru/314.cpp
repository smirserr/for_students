#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector <string> v;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        v.push_back(to_string(i));
    sort(v.begin(), v.end());


    cout << find(v.begin(), v.end(), to_string(k)) - v.begin() + 1 << endl;
    

    return 0;
}