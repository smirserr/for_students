#include <iostream>     // ввод вывод
#include <fstream>      // файловый ввод вывод   
#include <vector>       // векторы (улучшенные массивы)
#include <sstream>      // строковые потоки 
#include <string>       // строки
#include <ctime>        // время
#include "sha256.h"     // создание sha256 hash
using namespace std;


int str_to_int(string s)   // перевод строки в int
{
    int x;
    istringstream(s) >> x;  
    return x;
}

vector<string> split(string s, char c)  // разбиение строки в вектор строк через символ-разделитель
{
    vector<string> r;
    int k = s.find(c);  // поиск символа-разделителя в строке     
    while (k != string::npos)  // пока найден симаол разделитель
    {
        r.push_back(s.substr(0, k));  // добавление в вектор подстроки до первого символа-разделителя
        s = s.substr(k + 1, s.size() - k);  // присваиваем исходной строке подстроку после символа разделителя
        k = s.find(c);  // поиск символа-разделителя в строке
    }
    r.push_back(s);  // // добавление в вектор "хвостика" после последнего символа-разделителя

    return r;  // вернуть вектор
}




class Conf    // класс для хранения конф файла
{
    vector <vector <string>> records; // вектор векторов строк
public:
    bool load_conf_file(string file_name)  // загрузка в вектор векторов строк конф файла
    {
        ifstream fin(file_name); // создаем файловый поток 

        if (!fin.is_open())  // если не удалось открыть конф файл
        {
            return false;  
        }
        string s; 
        while (getline(fin,s)) // считываем файл построчно
        {
            if ((s[0] == '#') || (s[0] == ';') || (s == "")) // если комментарий или пустая строка
            {
                vector <string> r = {s}; 
                records.push_back(r);
            }
            else records.push_back(split(s,' ')); // вызываем функцию split для разбиения строки в vector
        }
        fin.close();  // закрываем файловый поток
        return true; 
    }

    void print_conf(ostream &out) // метод для вывода конфигурации
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

    int get_param(string key, vector <string> &param) // метод что бы вернуть одну строку конфига по ключу
    {
        for(vector<string> i : records) // перебор всех строк
        {
            if (i[0] == key)  // если ключ совпадает
            {
                param = i;    
                return i.size();
            }
        }
        return -1; // строка не найдена
    }

    bool change_param(vector <string> param)     // изменение параметров ключа в объекте конфига
    {
        for (int i = 0; i < records.size(); i++)
        {
            if (records[i][0] == param[0]) // находим строку по ключу
            {
                records[i] = param; // заменяем строку
                return true;
            }
        }
        return false; // если не нашли строку с таким ключом
    }

    void overwrite(string file_name) // перезапись файла
    {
        ofstream fout(file_name);  // открываем файловый поток
        for(vector <string> i : records)  // итерируем вектор векторов
        {
            for(int j = 0; j < i.size(); j++) // перебираем вектор строк
            {
                fout << i[j];  // записываем строки в файл
                if (j != i.size() - 1) fout << ' '; // если не последнее слово в строке, то пробел
            }
            fout << endl;
        }
        fout.close();
    }
};

                     
bool authentication(string login, string password_hash, string path_to_password_file) // проверка ауткетификации пользователя
{                                                                                // по логину и паролю
    string s;
    ifstream fin(path_to_password_file);
    while (fin >> s) // читаем все строки из файла с паролями
    {
        if(s == "") continue; // пропуск пустых строк
        vector <string> pass = split(s,':');  // разделяем строку на логин и пароль(в sha256)
        if (pass.size() != 2) continue; // если в строке не два "слова"
        if ((pass[0] == "") || (pass[1] == "")) continue; // если логин или пароль - пустая строка
        if ((login == pass[0]) && (password_hash == pass[1])) // если логин и пароль совпадают
        {
            fin.close(); // закрываем файл
            return true; 
        }
    }

    fin.close();  // закрываем файл
    return false;  // не нашли пару логин / пароль

}

string time_to_str()  // перевод времени в строковое представление
{
    time_t lt;
    lt = time(NULL);
    return ctime(&lt); 
}

void logging(ofstream &log, string mess)  // запись сообщения в лог файл
{
    string time = time_to_str();
    time.pop_back(); 
    log << time << ":::" << mess << endl;
}



int main()
{
    cout << time_to_str();
    Conf r; // создаем объект класса конф файл
    string login;
    string password;
    string path_to_password_file = "pass";
    string path_to_config_file = "1.conf";
    string path_to_log_file = "log.txt";

    ofstream log(path_to_log_file,ios::app); // окрываем лог файл

    do{ // цикл аутентификации
        cout << "Enter login: ";
        getline(cin, login);
        cout << "enter password: ";
        getline(cin, password);
        logging(log, "login: "+ login);

    }while(!authentication(login, sha256(password), path_to_password_file)); // пока authentication не true

    cout << "**************************" << endl;
    cout << "*sucsessful autorization!*" << endl;
    cout << "**************************" << endl;
    logging(log,login + " sucsessful autorization"); // запись в лог файл

    //cout << "Enter path to conf file: ";
    //getline(cin,path_to_config_file);
    if (!r.load_conf_file(path_to_config_file)) 
    {
        cout << "Error!" << endl;
        logging(log,login + "Error!");
    } 
    //r.print_conf(cout);

    string s; 
    vector <string> param;
    do 
    { // меню пользователя
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
        if (commands[0] == "get")   // разбираем комманду 
        {
            if (commands[1] == "param") 
            {
                int k = r.get_param(commands[2],param);
                if (k == -1) cout << "key not found" << endl;
                if (k == 1) cout << "key without parameters"<< endl;
                if (k > 1)
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