//
// Created by filip on 19.03.2020.
//

//
// Created by filip on 18.03.2020.
//

#include <iostream>
#include <cstdio>
#include <fstream>



struct Student{std::string imie; std::string nazwisko; std::string plec; std::string nr_pesel; std::string numer_indeksu;};
struct BazaStudentow{Student students[100]; unisnged int count=0}Baza;

std::fstream BazaDanych;
void Display_student(const Student& student);
void Display_all_students(const Student x[], int n);
int Find_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu);
int add_student(BazaStudentow &Baza);
void remove_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu);
void Display(const BazaStudentow& Baza);
void Save_students(BazaStudentow& Baza);
void load_students(BazaStudentow& Baza);

int main() {
    std::cout<<"     "<<" Wybierz opcje: \n _______________________\n [1] -Dodaj studenta \n [2] -Znajdz studenta \n [3] -Usun studenta \n [4] -Zapisz \n [5] -Wczytaj\n [6] -Wyswietl cala baze \n [k] -Wyjscie z programu"<<std::endl;
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
    }
    /*Student Filip;                                            //etap pierwszy
    int n=3;
    Student x[n]={
    {"Jan", "Kaluzny", "M", "00234568543", "253011"},
    {"Edyta", "Marzec", "K", "97324328756", "252015"},
    {"Eustachy", "Nowak", "M", "00261708543", "253024"}};
    std::cout<<"Imie: "<<std::endl;
    std::cin>>Filip.imie;
    std::cout<<"Nazwisko: "<<std::endl;
    std::cin>>Filip.nazwisko;
    std::cout<<"Plec: "<<std::endl;
    std::cin>>Filip.plec;
    std::cout<<"Nr pesel: "<<std::endl;
    std::cin>>Filip.nr_pesel;
    std::cout<<"Nr indeksu: "<<std::endl;
    std::cin>>Filip.numer_indeksu;
    Display_student(Filip);
    Display_all_students(x,n);*/
}

void Display_student(Student& Filip){
    std::cout<<"Imie: "<<Filip.imie<<std::endl;
    std::cout<<"Nazwisko: "<<Filip.nazwisko<<std::endl;
    std::cout<<"Plec: "<<Filip.plec<<std::endl;
    std::cout<<"Nr pesel: "<<Filip.nr_pesel<<std::endl;
    std::cout<<"Nr indeksu: "<<Filip.numer_indeksu<<std::endl;
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

void Display(BazaStudentow& Baza){                              //pokazuje cala baze z etapu 2
    for(int i=0;i<Baza.liczba;i++){
        std::cout<<"Imie: "<<Baza.imie[i]<<std::endl;
        std::cout<<"Nazwisko: "<<Baza.nazwisko[i]<<std::endl;
        std::cout<<"Plec: "<<Baza.plec[i]<<std::endl;
        std::cout<<"Nr pesel: "<<Baza.nr_pesel[i]<<std::endl;
        std::cout<<"Nr indeksu: "<<Baza.numer_indeksu[i]<<std::endl;
    }
}

int Find_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu){
    int polozenie;
    for(int i=0;i<Baza.liczba;i++){
        if(Baza.numer_indeksu[i].compare(poszukiwany_numer_indeksu)==0){
            polozenie=i;                            //za polozenie uznaje numer indeksu w tablicy
            break;
        }
        else polozenie=-1;
    }
    return polozenie;
}

int add_student(BazaStudentow& Baza){
    std::cout<<"Imie: "<<std::endl;
    std::cin>>Baza.imie[Baza.liczba];
    std::cout<<"Nazwisko: "<<std::endl;
    std::cin>>Baza.nazwisko[Baza.liczba];
    std::cout<<"Plec: "<<std::endl;
    std::cin>>Baza.plec[Baza.liczba];
    std::cout<<"Nr pesel: "<<std::endl;
    std::cin>>Baza.nr_pesel[Baza.liczba];
    std::cout<<"Nr indeksu: "<<std::endl;
    std::cin>>Baza.numer_indeksu[Baza.liczba];
    Baza.liczba++;
}

void remove_student(BazaStudentow &Baza, std::string poszukiwany_numer_indeksu){
    int to_delete;
    to_delete=Find_student(Baza, poszukiwany_numer_indeksu);
    std::cout<<to_delete;
    for (int i = to_delete; i<= Baza.liczba;i++) {
        Baza.imie[i] = Baza.imie[i+1];
        Baza.nazwisko[i] = Baza.nazwisko[i+1];
        Baza.plec[i] = Baza.plec[i+1];
        Baza.nr_pesel[i] = Baza.nr_pesel[i+1];
        Baza.numer_indeksu[i] = Baza.numer_indeksu[i+1];
    }
    Baza.liczba-=1;
    if(to_delete!=-1)std::cout<<"Pomyslnie usunieto studenta z bazy danych!"<<std::endl;
}

void Save_students(BazaStudentow& Baza){
    BazaDanych.open("BazaStudentow.txt", std::ios::out);
    for(int i=0;i<Baza.liczba;i++){
        BazaDanych<<Baza.imie[i]<<std::endl;
        BazaDanych<<Baza.nazwisko[i]<<std::endl;
        BazaDanych<<Baza.plec[i]<<std::endl;
        BazaDanych<<Baza.nr_pesel[i]<<std::endl;
        BazaDanych<<Baza.numer_indeksu[i]<<std::endl;
        BazaDanych<<Baza.liczba<<std::endl;
    }
    BazaDanych.close();
}

void load_students(BazaStudentow& Baza) {
    std::string linia;
    int ilosc_linii;
    std::ifstream BazaDanych("BazaStudentow.txt");
    while(std::getline(BazaDanych,linia)) ilosc_linii++;
    Baza.liczba=ilosc_linii/6;
    BazaDanych.close();
    BazaDanych.open("BazaStudentow.txt", std::ios::in);
    while (getline(BazaDanych, linia)) {
        for (int i = 0; i < Baza.liczba; i++) {
            Baza.imie[i]=linia;
            BazaDanych>>linia;
            Baza.nazwisko[i]=linia;
            BazaDanych>>linia;
            Baza.plec[i]=linia;
            BazaDanych>>linia;
            Baza.nr_pesel[i]=linia;
            BazaDanych>>linia;
            Baza.numer_indeksu[i]=linia;
            BazaDanych>>linia;
            BazaDanych>>linia;
        }
        BazaDanych.close();
    }
}
