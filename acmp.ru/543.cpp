#include <iostream>
using namespace std;
 
 
int main()
{
    int n, w, d, p; // n - количество корзин
                    // w - вес настоящей монеты
                    // d - на сколько фальшивая монета легче
                    // p - вес всех монет
    cin >> n >> w >> d >> p;

    int count = n * (n-1) / 2;   // количество монет
    int weight_real = count * w; // вес, если все монеты настоящие
    int delta_weight = weight_real - p; // разница в весе
    int count_fake = delta_weight / d;  // количество фальшивых


    cout << (count_fake == 0 ? n : count_fake) << endl;


    return 0;
}