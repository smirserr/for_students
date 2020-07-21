#include <iostream> 
using namespace std; 

int main()
{
    int n, k;
    cin >> n >> k;
    for(long long int i = n; true; i++)
    {
        long long int t = i;
        for(int j = 0; j < n; j++)
        {
            if ((t-k) % n != 0) break;
            t = (t-k) - (t-k) / n;
            if (t <= 0) break;
            if (j == n-1)
            {
                cout << i << endl;
                return 0;
            }
        }

    }
    
    return 0;
}