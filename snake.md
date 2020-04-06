*******************************************************************
Snake
*******************************************************************

Proszę napisać grę w "węża", np. wzorowaną na tym filmie:
``https://www.youtube.com/watch?v=kTIPpbIbkos``

Termin: **2020-04-30**

Przydatne linki:
* https://www.youtube.com/watch?v=MML7i-MYHtk
* https://youtu.be/zUlpq8K1WGQ

Projekt oddajemy w następujący sposób:
* tworzymy prywatne repozytorium na github,
* dodajemy mnie jako collaborator (w swoim prywatnym repozytorium klikamy w `Settings` -> `Manage access` -> `Invite a collaborator`)

Osoby, które korzystają z https://zts.ita.pwr.wroc.pl/ - stosują się do instrukcji, która znajduje się na forum wykładu.

Proszę zacząć od opracowania "logiki biznesowej"
- jak reprezentować planszę po której porusza się wąż ?
- jak reprezentować węża (jego kolejne segmenty, kierunek ruchu, prędkość) ?
- jak uwzględnić dodatkowe elementy na planszy (jedzonko, przeszkody)

Po stworzeniu modelu proszę dodać funkcje
- debug_display()  - wyświetlającą stan planszy w dowolny wygodny dla Was sposób
- update() - aktualizuje model
- turn ( LEFT | RIGHT ) - "skręca" wężem w lewo lub prawo

Następnie proszę dodać graficzną wizualizację stanu planszy.
Proszę ją przetestować bez implementacji całej rozgrywki

Po przetestowaniu widoku możecie przejść do implementacji obsługi klawiatury i myszy.



Efektem końcowym powinna być gra, w której będziecie mieli

1. Ekran powitalny z możliwością wyboru poziomu (decyzję o tym w jaki sposób ten poziom trudności zaimplementować pozostawiam Wam - może to być np. prędkość węża, to jak szybko zwiększa się jego długość, dodatkowe przeszkody na planszy)

2. Właściwa rozgrywka

3. Ekran z wynikami - na ekranie końcowym powinno wyświetlać się 10 najlepszych wyników. Wyniki powinny być przechowywane w pliku.


Przypominamy, że programy piszecie samodzielnie. Wszelkie "zapożyczenia" MUSZĄ być udokumentowane w kodzie.

W przypadku Sapera nie zwracaliśmy na to wiekszej uwagi, bo z powodu bardzo ściśle zdefiniowanej specyfikacji było spore prawdopodobieństwo, iż kilka osób wpadnie na ten sam pomysł (czasem nawet z dokładnością do nazw zmiennych, dodatkowych funkcji, kolejności testowanych warunków, liczby wcięć w kodzie i błędów ortograficznych w komentarzach ;P ). Taka sytuacja nie może się jednak pojawić w kolejnych projektach.

Na potrzeby projektu drugiego tworzycie sobie nowe repozytoria. Proszę o skonfigurowane ich w następujący sposób:

* nazwa: **snake_PP_DDHH_nrindeksu**, gdzie
- PP - inicjały prowadzącego (np. MW, AN, BG, MW ...)
- DDHH - dwuliterowy symbol dnia tygodnia (PN, WT, SR, CZ, PT) i godzina rozpoczęcia zajęć (07, 09, 11, 13, 15, 17)
* Przykładowo: snake_BG_SR15_123456
* typ projektu - prywatny + dostęp dla Waszego prowadzącego


Nie będziemy na siłę doszukiwać się podobieństw, ale jeśli zaczniemy zauważać że się pojawiają - wszystkie projekty zostaną przetestowane w systemie antyplagiatowym ( https://theory.stanford.edu/~aiken/moss/ ).

W przypadkach oczywistych plagiatów - nie będziemy wnikać kto od kogo ściągał. Oba projekty ocenimy na zero punktów.
