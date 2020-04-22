#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <ctime>
#include "sha256.h"
using namespace std;


int str_to_int(string s)
{
    int x;
    istringstream(s) >> x;
    return x;
}

vector<string> split(string s, char c)
{
    vector<string> r;
    int k = s.find(c);
    while (k != string::npos)
    {
        r.push_back(s.substr(0, k));
        s = s.substr(k + 1, s.size() - k);
        k = s.find(c);
    }
    r.push_back(s);

    return r;
}




class Conf
{
    vector <vector <string>> records;
public:
    bool load_conf_file(string file_name)
    {
        ifstream fin(file_name);

        if (!fin.is_open()) 
        {
            return false;
        }
        string s;
        while (getline(fin,s))
        {

            if ((s[0] == '#') || (s[0] == ';') || (s == ""))
            {
                vector <string> r = {s};
                records.push_back(r);
            }
            else records.push_back(split(s,' '));
        }
        fin.close();
        return true;
    }

    void print_conf(ostream &out)
    {
        for (vector<string> i : records)
        {
            for (string j : i)
            {
                out << j << ' ';
            }
            out << endl;
        }
    }

    int get_param(string key, vector <string> &param)
    {
        for(vector<string> i : records)
        {
            if (i[0] == key) 
            {
                param = i;
                return i.size();
            }
        }
        return -1;
    }

    bool change_param(vector <string> param)
    {
        for (int i = 0; i < records.size(); i++)
        {
            if (records[i][0] == param[0])
            {
                records[i] = param;
                return true;
            }
        }
        return false;
    }

    void overwrite(string file_name)
    {
        ofstream fout(file_name);
        for(vector <string> i : records)
        {
            for(int j = 0; j < i.size(); j++)
            {
                fout << i[j];
                if (j != i.size() - 1) fout << ' ';
            }
            fout << endl;
        }
        fout.close();
    }
};


bool authentication(string login, string password, string path_to_password_file)
{
    string s;
    ifstream fin(path_to_password_file);
    while (fin >> s)
    {
        if(s == "") continue;
        vector <string> pass = split(s,':');
        if (pass.size() != 2) continue;
        if ((pass[0] == "") || (pass[1] == "")) continue;
        if ((login == pass[0]) && (sha256(password) == pass[1]))
        {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;

}

string time_to_str()
{
    time_t lt;
    lt = time(NULL);
    return ctime(&lt); 
}

void logging(ofstream &log, string mess)
{
    string time = time_to_str();
    time.pop_back(); 
    log << time << ":::" << mess << endl;
}



int main()
{
    cout << time_to_str();
    Conf r;
    string login;
    string password;
    string path_to_password_file = "pass";
    string path_to_config_file = "1.conf";
    string path_to_log_file = "log.txt";

    ofstream log(path_to_log_file,ios::app);

    do{
        cout << "Enter login: ";
        getline(cin, login);
        cout << "enter password: ";
        getline(cin, password);
        logging(log, "login: "+ login);

    }while(!authentication(login, password, path_to_password_file));

    cout << "**************************" << endl;
    cout << "*sucsessful autorization!*" << endl;
    cout << "**************************" << endl;
    logging(log,login + " sucsessful autorization");

    //cout << "Enter path to conf file: ";
    //getline(cin,path_to_config_file);
    if (!r.load_conf_file(path_to_config_file)) cout << "Error!" << endl  ;
    //r.print_conf(cout);

    string s;
    vector <string> param;
    do 
    {
        cout << "*******************************************" << endl;
        cout << "enter command: " << endl;
        cout << "get param [param] " << endl;
        cout << "set param [param] " << endl;
        cout << "print" << endl;
        cout << "exit " << endl;
        cout << "*******************************************" << endl;
        cout << "#>";
        getline(cin, s);
        logging(log,"[" + login + "] " + s);
        cout << "*******************************************" << endl;
        vector <string> commands = split(s,' ');
        if (commands[0] == "get")
        {
            if (commands[1] == "param") 
            {
                int k = r.get_param(commands[2],param);
                if (k == -1) cout << "key not found" << endl;
                if (k == 0) cout << "key without parameters"<< endl;
                if (k > 0)
                {
                    cout << param[0] << " : ";
                    for (int i = 1; i < param.size(); i++)
                    {
                        cout << param[i] << ' ';
                    }
                    cout << endl;
                }
            }   
        }
        if (commands[0] == "set")
        {
            if (commands[1] == "param") 
            {
                vector <string> param;
                for(int i = 2; i < commands.size(); i++) 
                    param.push_back(commands[i]);
                r.change_param(param);
                r.overwrite(path_to_config_file);
            }   
        }
        if (commands[0] == "print")
        {
            r.print_conf(cout);
        }

    }while(s != "exit");

    log.close();
    return 0;
}