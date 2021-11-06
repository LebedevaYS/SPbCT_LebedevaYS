#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
using namespace std;
class Course
{
private:
    int date;
    double time;
    string subject;
    int auditory;
public:


    Course(int, double, string, int);

    string to_string() {                                        //формирование строки вывода
        string out = "\n\tdate: " + std::to_string(date) +
            "\n\ttime: " + std::to_string(time) +
            "\n\tsubject: " + subject +
            "\n\tauditory: " + std::to_string(auditory);
        return out;
    }
    string to_string_ff() {                                     //формирование строки вывода в файл
        string out = std::to_string(date) +
            "\n" + std::to_string(time) +
            "\n" + subject +
            "\n" + std::to_string(auditory);
        return out;
    }

    bool is_req_date(int c_date){                               //проверка на дату
        return c_date == date;
    }

    
    

    
   

};

Course::Course(int c_date, double c_time, string c_subject, int c_auditory) {
    date = c_date;
    time = c_time;
    subject = c_subject;
    auditory = c_auditory;
}

class Schedule 
{

    list <Course> courses;                              //создаем список list

    public:
    void add_course(Course c) {                   //добавляем новый урок к уже имеющимся в списке уроков
        courses.push_back(c);
    }
    string to_string_all() {                        //вывод имеющихся в списке уроков           
        string str = "";  
        int i;
        list <Course>::iterator pos_begin;
        for (pos_begin = courses.begin(), i = 1; pos_begin != courses.end(); ++pos_begin, i++) {
            Course c = *pos_begin;
            str += "\nCourse[" + std::to_string(i) + "]";
            str += c.to_string();
            
        }
            

        return str;
    }

    string to_string_all_ff() {                        //вывод уроков в файл
        string str = "";
        int i;
        list <Course>::iterator pos_begin;
        for (pos_begin = courses.begin(), i = 1; pos_begin != courses.end(); ++pos_begin, i++) {
            Course c = *pos_begin;
            str += c.to_string_ff();

        }


        return str;
    }

    void list_clear() {                                 //очистка списка
        courses.clear();
    }
    string to_string_by_date(int date) {                  //вывод уроков, которые проходят в определенный день

        string str = "";
        int i;
        list <Course>::iterator pos_begin;
        for (pos_begin = courses.begin(), i = 1; pos_begin != courses.end(); ++pos_begin, i++) {
            
            Course c = *pos_begin;
            if (c.is_req_date(date)) {
                str += "\nCourse[" + std::to_string(i) + "]";
                str += c.to_string();
            }
        }
        return str;
    }

};

int main()
{

    Schedule schedule = Schedule();
    
   
    int c_date, num, req_date;
    double c_time;
    string c_subject;
    int c_auditory;

    cout << "menu: [0]-exit, [1]-input, [2]-import, [3]-print, [4]-print by date, [5]-delete all, [6]-upload into file, [7]-delete all from file";
    cout << "\nplease enter number: ";
    cin >> num;
    
    for (; num != 0;) {
        switch (num) {
        case(0): break;                                         //выход
        case(1):                                                //запись ногого урока в список

            cout << "date[int]: ";
            cin >> c_date;
            //newCourse.set_date(c_date);

            cout << "\n time[double]: ";
            cin >> c_time;
            //newCourse.set_time(c_time);

            cout << "\n subject[str]: ";
            cin >> c_subject;
            //newCourse.set_subject(c_subject);

            cout << "\n auditory[int]: ";
            cin >> c_auditory;
            //newCourse.set_auditory(c_auditory);

            schedule.add_course(Course(c_date, c_time, c_subject, c_auditory));
            break;

        case(2): {                                                //загрузка записей из файла
            ifstream file("../a.txt");
            if (!file.is_open()) {
                cout << "File not found";
                break;
            };
            if (file.eof()) {
                cout << "File is empty";
                break;
            };
            for (; !file.eof();) {
                string date_str, time_str, auditory_str;
                getline(file, date_str);
                cout << date_str << endl;
                getline(file, time_str);
                cout << time_str << endl;
                getline(file, c_subject);
                cout << c_subject << endl;
                getline(file, auditory_str);
                cout << auditory_str << endl;
                c_date = stoi(date_str);
                c_time = stod(time_str);
                c_auditory = stoi(auditory_str);

                schedule.add_course(Course(c_date, c_time, c_subject, c_auditory));
            };
            cout << "\nImport has been succeed.";


            file.close();
            break;
        };
        case(3):                                             //вывод всех записей, имеющихся в списке
            cout << "\nresult: " << schedule.to_string_all();
            break;
        case(4):           //вывод всех уроков, которые заисаны на день, который был введен пользователем
            cout << "\nplease enter date:"; cin >> req_date;
            cout << "\nresult: " << schedule.to_string_by_date(req_date);
            break;
        case(5):                                                //удаление всех записей из списка
            schedule.list_clear();
            cout << "\n List has been cleared";
            break;
        case(6):                                                 //загрузка всего списка в файл
        {
            ofstream out;
            out.open("../a.txt");
            if (out.is_open())
            {
                out << schedule.to_string_all_ff();
            }
            cout << "records have been uploaded";
            out.close();
            break;
        };
        case(7):                                                  //удаление всех записей из файла
        {
            ofstream out;
            out.open("../a.txt");
            if (out.is_open())
            {
                out << " " << std::endl;
            }
            cout << "records have been deleted ";
            out.close();
            break;
        };
        };



        cout << "\nplease enter number: ";
        cin >> num;

    };
};
