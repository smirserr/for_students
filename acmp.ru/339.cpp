#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int day_of_month[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d1, m1, y1, d2, m2, y2;
    scanf("%d.%d.%d", &d1, &m1, &y1);
    scanf("%d.%d.%d", &d2, &m2, &y2);
    int k = 0;
    while ((d1 != d2) || (m1 != m2) || (y1 != y2))
    {
        if ((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 != 0)))
            day_of_month[1] = 29;
        else 
            day_of_month[1] = 28;
        d1++;
        if (d1 > day_of_month[m1-1])
        {
            d1 = 1;
            m1++;
            if (m1 > 12)
            {
                m1 = 1;
                y1 ++;
            }
        }
        k++;
    }

    cout << k+1 << endl;

    return 0;
}