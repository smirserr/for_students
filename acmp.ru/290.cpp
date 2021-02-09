#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string b[n];
    for(int i = 0; i < n; i++)
        cin >>b[i];
   
    int x, y;
    cin >> x >> y;
    string a[x];
    for(int i = 0; i < x; i++)            
        cin >> a[i];
    int k = 0;
    
    for(int i = 0; i <= x-n; i++)
    {
        for(int j = 0; j <= y-m; j++)
        {
            bool t = true;
            for(int i2 = 0; i2 < n; i2++)
            {
                for(int j2 = 0; j2 < m; j2++)
                { 
                    if ((b[i2][j2] == '#') && (a[i+i2][j+j2] == '.'))
                    {
                        t = false;
                    }
                }
            }
            if (t)
                k ++;

        }
    }
    cout << k << endl;
    return 0;
}