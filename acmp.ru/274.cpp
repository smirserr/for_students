#include <iostream> 
#include <fstream>
using namespace std; 

int main()
{

    ifstream fin ("INPUT.TXT");

    int a, max, min;

    fin >> min >> max;

    for(int i = 3; fin >> a; i++)
    {
        if ((i % 2 == 0) && (a > max)) max = a;
        if ((i % 2 != 0) && (a < min)) min = a;
    }
    cout << min + max << endl;
    

    fin.close();

    return 0;
}