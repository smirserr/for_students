#include <iostream> 
using namespace std; 
#define SIZE 201



int main()
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n;
    int a[SIZE] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> t;
        a[t+100]++;
    }
    string s = "";
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < a[i]; j++)
        {
            s += to_string(i-100) + ' ';
        }
    }
    cout << s << endl;
    
    return 0;
}