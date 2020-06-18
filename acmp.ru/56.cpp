#include <iostream>
#include <algorithm>
#include <set>
#include<vector>
using namespace std;


int main()
{
	int n, m;
    cin >> n;
    vector <string> v1;
    vector <string> v2;
    vector <string> v3;
	vector <string> v4;
    string s;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        v1.push_back(s);
    }
    sort(v1.begin(), v1.end());

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> s;
        v2.push_back(s);
    }
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
	sort(v3.begin(), v3.end());
	set_difference(v2.begin(), v2.end(), v3.begin(), v3.end(), back_inserter(v4));
	sort(v4.begin(), v4.end());
    cout << "Friends: ";
    for(int i = 0; i < v1.size(); i++) 
    {
        cout << v1[i];
        if (i != v1.size()-1) cout << ", ";
    }
    cout << endl;
    cout << "Mutual Friends: ";
    for(int i = 0; i < v3.size(); i++) 
    {
        cout << v3[i];
        if (i != v3.size()-1) cout << ", ";
    }
    cout << endl;
    cout << "Also Friend of: ";
    for(int i = 0; i < v4.size(); i++) 
    {
        cout << v4[i];
        if (i != v4.size()-1) cout << ", ";
    }
    cout << endl;
    

    return 0;
}
