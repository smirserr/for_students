#include <iostream> 
#include <algorithm>
using namespace std; 





int main()
{
    int n, count_empty = 0;
    cin >> n;
    int k = n;
    int j = 1;
    while (n % 4 != 0) 
    {
        n++;
        count_empty ++;
    }
    
    

    int s = 1; 
    for(int i = 0; i < n / 2; i++)
    {
        if (k < j) return 0;
        cout << i / 2 + 1 << ' ' << s << ' ';
        if (s == 1) cout << (count_empty-- > 0 ? 0 : k--) << ' ' << j++;
        else cout << j++ << ' ' << (count_empty-- > 0 ? 0 : k--);
        s = (s == 1 ? 2 : 1);
        cout << endl;
    }

    return 0;
}