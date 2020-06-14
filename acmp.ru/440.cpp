#include <iostream>
using namespace std;
#define N 5
 
int x[N] = {0,25,50,75,100};
int y = 0;
int p[N] = {0,0,0,0,0};
 
 
void f(int xs, int ys)
{
    for(int i = 0; i < N; i++)
    {
        if ((x[i] - xs)*(x[i]-xs) + (y-ys)*(y-ys) <= 100)
        {
            p[i] = 1;
            return;
        }
    }
}
 
 
  
int main()
{
     
    int xs, ys;
 
    for (int i = 0; i < N; i++)
    {   
        cin >> xs >> ys;
        f(xs,ys);
    }
 
    int k = 0;
    for(int i = 0; i < N; i++) k += p[i];
    cout << k;
     
 
    return 0;
} 
