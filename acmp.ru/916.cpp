#include <iostream> 
#include <algorithm>
using namespace std;    
 
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
 
    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int t = (n-i) / k;
        if ((n-i) % k != 0) t++;
        sum += a[i]*t; 
    }
    cout << sum << endl;
 
    return 0;
}
