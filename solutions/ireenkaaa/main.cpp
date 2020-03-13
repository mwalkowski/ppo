#include <iostream>
#include <stdlib.h>
#include<vector>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct student {
    string imie;
    string nazwisko;
    string plec;
    string pesel;
    string numer_ind;
};

struct bazaStudentow {
    vector<student> all_students = vector<student>();
    //int liczba_w_bazie = 100; niepotrzebna przy wektorze
};
void display_student(student &s);
void add_random(student &s);
void display_all_students(student s[], int n);
void display_all_students(vector<student> s, int n);
int find_student(bazaStudentow all, long double szukany_numer);
void add_student(bazaStudentow &all, student s);
void remove_student(bazaStudentow &all);
void load_students(bazaStudentow &base);
void save_students(bazaStudentow base);


int main()
{
    student irena;
    cout << "podaj imie" << endl;
    cin >> irena.imie;
    cout << "podaj nazwisko" << endl;
    cin >> irena.nazwisko;
    cout << "podaj plec ";
    cin >> irena.plec;
    cout << "podaj pesel ";
    cin >> irena.pesel;
    cout << "podaj nr indeksu ";
    cin >> irena.numer_ind;
    display_student(irena);
    int table_size=0;
    cout<<"wprowadź rozmiar tablicy"<<endl;
    cin>>table_size;
    student tablica[table_size];
    for (int i = 0; i < table_size; i++) {
        add_random(tablica[i]);
    }
    display_all_students(tablica, table_size);//wyświetla studentów z tablicy

    bazaStudentow base1;
    load_students(base1);
    display_all_students(base1.all_students, base1.all_students.size());//wyswietla zawartość bazy studentów z wektorem
    save_students(base1);
    cout<<endl;
    cout<<find_student(base1, 245)<<endl;
    add_student(base1, irena);
    cout<<endl;
    display_all_students(base1.all_students, 3);
    remove_student(base1);
    cout<<endl;
    display_all_students(base1.all_students, 3);
    return 0;
}




void display_student(student &s) {
    cout << s.imie << endl;
    cout << s.nazwisko << endl;
    cout << s.plec << endl;
    cout << s.pesel << endl;
    cout << s.numer_ind<<endl;
}
void add_random(student &s) {
    string rodzaj[2];
    rodzaj[0] = "kobieta";
    rodzaj[1] = "mezczyzna";

    s.imie = "irena";
    s.nazwisko = "nazwisko";
    s.numer_ind = "13940";
    s.plec = rodzaj[rand() % 2];
    s.pesel = "72829299200";

}
void display_all_students(student s[], int n) {
    for (int i = 0; i < n; i++) {
        display_student(s[i]);
        cout << endl;
    }
}
void display_all_students(vector<student> s, int n) {
    for (int i = 0; i < n; i++) {
        display_student(s.at(i));
        cout << endl;
    }
}
int find_student(bazaStudentow all, long double number_to_find) {
    for (int i = 0; i < all.all_students.size(); i++) {
        if (atoi(all.all_students.at(i).numer_ind.c_str()) == number_to_find) {
            return i;
        }

    }
    return -1;
}
void add_student(bazaStudentow &all, student s) {
    all.all_students.push_back(s);
}
void remove_student(bazaStudentow &all) {
    int n = 0;
    cout << "podaj numer studenta do usuniecia";
    cin >> n;
    all.all_students.erase(all.all_students.begin() + (n - 1));

}
void load_students(bazaStudentow &base)
{
    fstream file;
    file.open("C:\\Users\\irena\\rozgrzewka_testy\\file.txt");

    if(file.good()==false)
    {
        cout<<"plik nie istnieje";
        exit(0);
    }

    while (!file.eof()){
        student temp_student;
        for (int i = 1; i <=5; i++) {

            switch(i)
            {
                case 1: getline(file, temp_student.imie);
                    break;
                case 2: getline(file, temp_student.nazwisko);
                    break;
                case 3: getline(file, temp_student.plec);
                    break;
                case 4: getline(file,temp_student.numer_ind);
                    break;
                case 5: getline(file, temp_student.pesel);
                    break;

            }
        }

        add_student(base, temp_student);

    }

    file.close();
}
void save_students(bazaStudentow base) {
    string const file("C:\\Users\\irena\\rozgrzewka_testy\\saving.txt");
    ofstream stream(file.c_str());

    if (stream) {
        for (int i = 0; i < base.all_students.size(); i++) {
            stream << base.all_students.at(i).imie << endl;
            stream << base.all_students.at(i).nazwisko << endl;
            stream << base.all_students.at(i).plec << endl;
            stream << base.all_students.at(i).numer_ind << endl;
            stream << base.all_students.at(i).pesel << endl;

        }

    } else {
        cout << "Plik nie działa" << endl;
    }

}