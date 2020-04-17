#include <iostream> 
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
namespace fs = std::filesystem;

string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
string week[7] =  {"Sun", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat"};


int str_to_int(string s)
{
    int x;
    istringstream(s) >> x;
    return x;
}

class Date
{
    int day;
    int month;
    int year;

    public:

    Date(int d, int m, int y):day(d),month(m),year(y){}; // Конструктор
    string month_to_string() {return months[month-1];}
    string day_of_the_week()
    {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12*a - 2;
        int r = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31*m)/12);
        return week[r % 7];
    }

    friend ostream& operator <<(ostream& out, Date x)
    {
        char prev = out.fill('0');
        out << x.day_of_the_week() << ' ' << setw(2) << x.day 
            << ' ' << x.month_to_string() << ' ' << x.year;
        out.fill(prev);
        return out;
    } 

    bool operator < (const Date &x)
    {
        if (year < x.year) return true;
        if (year > x.year) return false;
        if (month < x.month) return true;
        if (month > x.month) return false;
        if (day < x.day) return true;
        return false;
    }

};


class Time
{
    int hours;
    int minutes;
    int seconds;

    public:
    Time(int h, int m, int s = 0):hours(h),minutes(m),seconds(s){};
    void set_seconds(int s) {seconds = s;}

    friend ostream& operator <<(ostream& out, Time x)
    {
        char prev = out.fill('0');
        out << setw(2) << x.hours << ':' 
            << setw(2) << x.minutes << ':' 
            << x.seconds;
        out.fill(prev);
        return out;
    } 

    bool operator < (const Time &x)
    {
        if (hours < x.hours) return true;
        if (hours > x.hours) return false;
        if (minutes < x.minutes) return true;
        if (minutes > x.minutes) return false;
        if (seconds < x.seconds) return true;
        return false;
    }
};


class Record
{
    Date date;
    Time time;
    string device;
    int indication;
    public:
    Record(Date d, Time t, string dev, int ind):date(d),time(t),device(dev),indication(ind){};
    Date get_date(){return date;}
    Time get_time(){return time;}
    string get_device(){return device;}
    int get_indication(){return indication;}

    friend ostream& operator << (ostream& out, Record x)
    {
        out << x.date << ' ' << x.time << ' ' << x.device << ' ' << x.indication;
        return out;
    }

    bool operator < (Record x)
    {
        if (date < x.date) return true;
        if (x.date < date) return false;
        if(time < x.time) return true;
        return false;
    }
};




vector<string> split(string s, char c)
{
    vector<string> r;
    int k = s.find(c);
    while (k != string::npos)
    {
        r.push_back(s.substr(0,k));
        s = s.substr(k+1,s.size() - k);
        k = s.find(c);
    }
    r.push_back(s);
    
    return r;
}


vector <Record> load_logs(string path)
{
    vector <string> v;
    vector <Record> records;
    for (const auto & entry : fs::directory_iterator(path))
    {
        string s = entry.path().string();
        if (s.find("log_(") != string::npos)
        {
            string s_date = s.substr(s.size()-21, 10);
            string s_time = s.substr(s.size()-10,5);
            v = split(s_date,'-');
            Date d(str_to_int(v[2]), str_to_int(v[1]),str_to_int(v[0]));
            v = split(s_time,'-');
            Time t(str_to_int(v[0]),str_to_int(v[1]));
            ifstream fin(entry.path());
            while (fin >> s)
            {
                v = split(s,':');
                if (v[1] == "garbage") continue;
                t.set_seconds(str_to_int(v[0]));
                Record r(d,t,v[1],str_to_int(v[2]));
                records.push_back(r);
            }
            fin.close();
        }    
    }

    return records;

}


int main()
{
    string path, dev;
    cout << "enter path log folder: ";
    cin >> path;
    vector <Record> v = load_logs(path);
    sort(v.begin(),v.end());
    cout << "load logs completed" << endl; 
    
    cout << "enter device: ";
    cin >> dev;
    
    for (Record i : v)
        if (i.get_device() == dev)
            cout << i.get_date() << ' ' << i.get_time() << ' ' << " - " << i.get_indication() << endl; 

    return 0;
}