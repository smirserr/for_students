#include <iostream> 
using namespace std; 




int main()
{
    string n, m;
    cin >> n >> m;
    if (m == "0") cout << "NO" << endl;
    else
    {
        n[n.size()-1] ++;
        cout << n << endl;
    }
    
    return 0;
}