#include <iostream>
#include <fstream>
using namespace std;

int my_min(int x, int y)
{
    if ((x != -1) && (y != -1))
        return min(x,y);
    if (x != -1)
        return x;
    return y;
}



int main()
{
    int h, w;
    string s;
    int p = 1;
    ifstream fin("INPUT.TXT");
    fin >> h >> w;
    //char c;
    //fin >> c;
    
    //cout << h << ' ' << w << endl;
    
    
    int a[h][w];
    
    for(int i = 0; i < h; i++)
    {
        a[i][0] = -1;
        a[i][w-1] = -1;
    }
    
    
    for(int i = 0; i < w; i++)
    {
        a[0][i] = -1;
        a[h-1][i] = -1;
    }
    
    
    for (int i = 0; i < h; i++)
    {

        getline(fin, s);
        if (s.size() == 0) 
        {
            i--;
            continue;
        }

        for(int j = 0; j < w; j++)
        {
            a[i][j] = (s[j] == ' ' ? 0 : -1);
        }
    }
/*
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cout << (a[i][j] == -1 ? '@' : ' ');
        }
        cout << endl;
    }
*/
    fin.close();

    int x,y;
    x = y = 1;
    a[y][x] = 1;
    unsigned long long int k = 0;
    while ((x != w-2) || (y != h-2))
    {
        int m = -1;
        m = my_min(a[y][x-1], m);
        m = my_min(a[y][x+1], m);
        m = my_min(a[y-1][x], m);
        m = my_min(a[y+1][x], m);
        if (m == -1)
        {
            cout << "Error" << endl;
            return 0;
        }
        if ((p == 1) && (m == a[y+1][x]))
            y ++;
        else if ((p == 2) && (m == a[y][x+1]))
            x ++;
        else if ((p == 3) && (m == a[y-1][x]))
            y --;
        else if ((p == 4) && (m == a[y][x-1]))
            x --;
        else if (m == a[y+1][x])
        {
            y ++;
            p = 1;
        }
        else if (m == a[y][x+1])
        {
            x ++;
            p = 2;
        }
        else if (m == a[y-1][x])
        {
            y --;
            p = 3;
        }
        else if (m == a[y][x-1])
        {
            x --;
            p = 4;
        }
        a[y][x] ++;
        k++;
        /*
        cout << y << ' ' << x << ' ' << m <<  endl;
        
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if ((y == i) && (x == j))
                    cout << "*";
                else if (a[i][j] == -1)
                    cout << '@';
                else 
                    cout << ' ';//a[i][j];
            }
            cout << endl;
        }
        getchar();
        */
        if (k == 3000000)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << k << endl;


    return 0;
}