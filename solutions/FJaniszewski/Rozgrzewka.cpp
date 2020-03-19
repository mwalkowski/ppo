//
// Created by filip on 18.03.2020.
//

#include <iostream>
#include <fstream>



struct Student{std::string imie; std::string nazwisko; std::string plec; std::string nr_pesel; std::string numer_indeksu;}student;
struct BazaStudentow{Student student[100]; unsigned int count=0;}Baza;

void Display_student(Student& student);
void Display_all_students(Student x[], int n);
int Find_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu);
void add_student(BazaStudentow &Baza);
void remove_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu);
void Display(BazaStudentow& Baza);
void Save_students(BazaStudentow& Baza);
void load_students(BazaStudentow& Baza);
std::fstream BazaDanych;

int main() {
    std::cout<<"     "<<" Wybierz opcje: \n _______________________\n [1] -Dodaj studenta \n [2] -Znajdz studenta \n [3] -Usun studenta \n "
                        "[4] -Zapisz \n [5] -Wczytaj\n [6] -Wyswietl cala baze \n [k] -Wyjscie z programu"<<std::endl;
    char opcja;
    while(opcja!='k') {
        std::cin >> opcja;
        switch (opcja) {
            case '1': {
                add_student(Baza);
                break;
            }
            case '2': {
                std::string poszukiwany_numer_indeksu;
                std::cout << "Podaj numer indeksu poszukiwanego studenta: ";
                std::cin >> poszukiwany_numer_indeksu;
                std::cout <<"Polozenie poszukiwanego studenta to: "<<Find_student(Baza, poszukiwany_numer_indeksu);
                break;
            }
            case '3': {
                std::string poszukiwany_numer_indeksu;
                std::cout<<"Podaj numer indeksu poszukiwanego studenta: ";
                std::cin>>poszukiwany_numer_indeksu;
                remove_student(Baza,poszukiwany_numer_indeksu);
                break;
            }
            case '4': {
                Save_students(Baza);
                break;
            }
            case '5': {
                load_students(Baza);
                break;;
            }
            case '6': {
                Display(Baza);
                break;;
            }
            default: {
                if (opcja != 'k') {
                    std::cout << "Wybrales nieistniejaca opcje! Wybierz wlasciwa opcje!" << std::endl;
                }
                break;
            }
        }
    }                                       //etap pierwszy
    int n=3;
    Student x[n]={
    {"Jan", "Kaluzny", "M", "00234568543", "253011"},
    {"Edyta", "Marzec", "K", "97324328756", "252015"},
    {"Eustachy", "Nowak", "M", "00261708543", "253024"}};
    std::cout<<"Imie: "<<std::endl;
    std::cin>>student.imie;
    std::cout<<"Nazwisko: "<<std::endl;
    std::cin>>student.nazwisko;
    std::cout<<"Plec: "<<std::endl;
    std::cin>>student.plec;
    std::cout<<"Nr pesel: "<<std::endl;
    std::cin>>student.nr_pesel;
    std::cout<<"Nr indeksu: "<<std::endl;
    std::cin>>student.numer_indeksu;
    Display_student(student);
    Display_all_students(x,n);
}

void Display_student(Student& Filip){
    std::cout<<"Imie: "<<Filip.imie<<std::endl;
    std::cout<<"Nazwisko: "<<Filip.nazwisko<<std::endl;
    std::cout<<"Plec: "<<Filip.plec<<std::endl;
    std::cout<<"Nr pesel: "<<Filip.nr_pesel<<std::endl;
    std::cout<<"Nr indeksu: "<<Filip.numer_indeksu<<std::endl;
}

void Display(BazaStudentow& Baza){                              //pokazuje cala baze z etapu 2
    for(int i=0;i<Baza.count;i++){
        std::cout<<"Imie: "<<Baza.student[i].imie<<std::endl;
        std::cout<<"Nazwisko: "<<Baza.student[i].nazwisko<<std::endl;
        std::cout<<"Plec: "<<Baza.student[i].plec<<std::endl;
        std::cout<<"Nr pesel: "<<Baza.student[i].nr_pesel<<std::endl;
        std::cout<<"Nr indeksu: "<<Baza.student[i].numer_indeksu<<std::endl;
    }
}

void Display_all_students(Student x[], int n){
    for(int i=0;i<n;i++){
        std::cout<<"Imie: "<<x[i].imie<<std::endl;
        std::cout<<"Nazwisko: "<<x[i].nazwisko<<std::endl;
        std::cout<<"Plec: "<<x[i].plec<<std::endl;
        std::cout<<"Nr pesel: "<<x[i].nr_pesel<<std::endl;
        std::cout<<"Nr indeksu: "<<x[i].numer_indeksu<<std::endl;
    }
}

int Find_student(BazaStudentow &Baza, const std::string poszukiwany_numer_indeksu){
    int polozenie = 0;
    for(int i=0;i<Baza.count;i++){
        if(Baza.student[i].numer_indeksu.compare(poszukiwany_numer_indeksu)==0){
            break;
        }
        else polozenie=-1;
    }
    return polozenie;
}

void add_student(BazaStudentow& Baza){
    std::cout<<"Imie: "<<std::endl;
    std::cin>>Baza.student[Baza.count].imie;
    std::cout<<"Nazwisko: "<<std::endl;
    std::cin>>Baza.student[Baza.count].nazwisko;
    std::cout<<"Plec: "<<std::endl;
    std::cin>>Baza.student[Baza.count].plec;
    std::cout<<"Nr pesel: "<<std::endl;
    std::cin>>Baza.student[Baza.count].nr_pesel;
    std::cout<<"Nr indeksu: "<<std::endl;
    std::cin>>Baza.student[Baza.count].numer_indeksu;
    Baza.count++;
}

void remove_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu){
    int to_delete;
    to_delete=Find_student(Baza, poszukiwany_numer_indeksu);
    std::cout<<to_delete;
    for (int i = to_delete; i<= Baza.count;i++) {
        Baza.student[i].imie = Baza.student[i+1].imie;
        Baza.student[i].nazwisko = Baza.student[i+1].nazwisko;
        Baza.student[i].plec = Baza.student[i+1].plec;
        Baza.student[i].nr_pesel = Baza.student[i+1].nr_pesel;
        Baza.student[i].numer_indeksu = Baza.student[i+1].numer_indeksu;
    }
    Baza.count-=1;
    if(to_delete!=-1)std::cout<<"Pomyslnie usunieto studenta z bazy danych!"<<std::endl;
}

void Save_students(BazaStudentow& Baza){
    BazaDanych.open("BazaStudentow.txt", std::ios::out);
    for(int i=0;i<Baza.count;i++){
        BazaDanych<<Baza.student[i].imie<<std::endl;
        BazaDanych<<Baza.student[i].nazwisko<<std::endl;
        BazaDanych<<Baza.student[i].plec<<std::endl;
        BazaDanych<<Baza.student[i].nr_pesel<<std::endl;
        BazaDanych<<Baza.student[i].numer_indeksu<<std::endl;
        BazaDanych<<Baza.count<<std::endl;
    }
    BazaDanych.close();
}

void load_students(BazaStudentow& Baza) {
    std::string linia;
    int ilosc_linii=0;
    std::ifstream BazaDanych("BazaStudentow.txt");
    while(std::getline(BazaDanych,linia)) ilosc_linii++;
    Baza.count=ilosc_linii/6;
    BazaDanych.close();
    BazaDanych.open("BazaStudentow.txt", std::ios::in);
    while (getline(BazaDanych, linia)) {
        for (int i = 0; i < Baza.count; i++) {
            Baza.student[i].imie=linia;
            BazaDanych>>linia;
            Baza.student[i].nazwisko=linia;
            BazaDanych>>linia;
            Baza.student[i].plec=linia;
            BazaDanych>>linia;
            Baza.student[i].nr_pesel=linia;
            BazaDanych>>linia;
            Baza.student[i].numer_indeksu=linia;
            BazaDanych>>linia;
            BazaDanych>>linia;
        }
        BazaDanych.close();
    }
}
