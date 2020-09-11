#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

void split(string s, string &name, int &t1, int &t2)
{
    int h1, m1, h2, m2;
    char c;
    stringstream ss;
    s.erase(0,1);         // Red Arrow" 23:55 07:55
    int k = s.find("\""); // 9
        
    string time;
    name = s.substr(0,k); // Red Arrow
    time = s.substr(k+2); // 23:55 07:55
    ss.clear();
    ss << time; 
    ss >> h1 >> c >> m1 >> h2 >> c >> m2;
    t1 = m1 + h1*60;
    t2 = m2 + h2*60;
}

int travel_time(int t1, int t2)
{
    if (t1 < t2) return t2 - t1;
    else return 24*60-t1 + t2;
}




int main()
{
    int n, t1, t2;
    string name, name_fastest;
    double max_speed = 0;
    cin >> n;
    getchar();
    string s;
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);      
        split(s, name, t1, t2);
        //cout << endl << travel_time(t1, t2) << endl;
        double speed = 650.0 * 60 /  travel_time(t1, t2) ;
        if (speed > max_speed)
        {
            max_speed = speed;
            name_fastest = name;
        }
    }

    cout << "The fastest train is \"" << name_fastest << "\"." << endl
         << "Its speed is " << round(max_speed) << " km/h, approximately." << endl;
  
    return 0;
}