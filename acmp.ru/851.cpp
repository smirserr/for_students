#include <iostream> 
#include <algorithm>
using namespace std; 





int count_active(string s)
{
    int count = 0;
    s = s[s.size()-1] + s;
    s += s[0];
    for(int i = 1; i < s.size()-1; i++)
    {
        if(s[i] == 'B')
        {
            if ((s[i-1] == 'G') && (s[i+1] == 'G')) count ++;
        } 
        else
        {
            if (s[i-1] != s[i+1]) count ++;
        }
    }
    return 0;
}



string f(int m, int n, string s)
{
    if(m == 0) 
    {
        for(int i = 0; i < n; i++) s += 'G';
        return s;
    }  
    if (n == 0)
    {
        for(int i = 0; i < m; i++) s += 'B';
        return s;
    }
    if (s.size() == 0)
    {
        string s1 = f(m-1,n,"B");
        string s2 = f(m,n-1,"G");
        int c1 = count_active(s1);
        int c2 = count_active(s2);
        if (c1 > c2) return s1;
        else return s2;
    }

    if (s[s.size()-1] == 'G')
    {
        if (s.size() == 1) 
        {
            string s1 = f(m-1,n,"GB");
            string s2 = f(m,n-1,"GG"); 
            int c1 = count_active(s1);
            int c2 = count_active(s2);
            if (c1 > c2) return s1;
            else return s2;
        }
        else
        {
            if (s[s.size()-2] == 'G') return f(m-1,n,s+'B');
            else return f(m, n-1, s+'G');
        }
    }
    else
    {
        return f(m,n-1,s+'G');
    }
    return s;
}





int main()
{
    int n, m;
    cin >> m >> n;

    cout << f(m, n, "") << endl;


    return 0;
}