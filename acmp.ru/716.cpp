#include <iostream> 
using namespace std; 



int main()
{
    int n;
    double l = 30, r = 4000, v1, v2;
    string s;

    cin >> n >> v1;
    for(int i = 1; i < n; i++)
    {
        cin >> v2 >> s;
        double m = (v1 + v2) / 2;
        if (s == "closer")
        {
            if (v2 > v1) l = max(m, l);
            if (v2 < v1) r = min(m, r);
        }
        else
        {
            if (v2 > v1) r = min(m, r);
            if (v2 < v1) l = max(m, l);
        }
        v1 = v2;
    }

    cout.precision(6);
    cout << fixed << l << ' ' << r << endl;
    return 0;
}

