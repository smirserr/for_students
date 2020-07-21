#include <iostream> 
using namespace std; 

int main()
{
    int n;
    cin >> n;
    int a[n];
    int count[201] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        count[a[i]+100]++;
    }
    int max = 0;
    for(int i = 0; i < 201; i++)
        if (count[i] > count[max]) max = i;

    for(int i = 0; i < n; i++)
        if (a[i] != max-100) cout << a[i] << ' ';
    for(int i = 0; i < count[max]; i++)
        cout << max-100 << ' ';
    cout << endl;
    
    return 0;
}