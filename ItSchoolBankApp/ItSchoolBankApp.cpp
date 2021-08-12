#include <iostream>

#include "passwordCheck.h"
#include "Bank.h"



int main()
{
    //login: verificam username si parola
    //passwordCheck();
    if (!passwordCheck()){
        std::cout << "Login failed.\n";
    }
    else
    {

        //instantam o banca
        Bank* itSchoolBank = new Bank();
        bool isRunning = true;

        //meniu principal
        do
        {
            system("CLS");
            std::cout << "Meniu principal\n";
            std::cout << "1 -> Adaugare cont nou\n";
            std::cout << "2 -> Vizualizare conturi\n";
            std::cout << "3 -> Modificare conturi\n";
            std::cout << "9 -> Exit\n";
            std::cout << "Alegeti o optiune: ";
            char optiune;
            std::cin >> optiune;

            switch (optiune)
            {
            case '1':
                system("CLS");
                itSchoolBank->adaugareCont();
                break;
            case '2':
                system("CLS");
                itSchoolBank->vizualizareConturi();
                break;
            case '3':
                system("CLS");
                itSchoolBank->modificareCont();
                break;
            case '9':
                std::cout << "La revedere!\n";
                isRunning = false;
                break;
            default:
                system("CLS");
                std::cout << "Optiune invalida\n";
                break;
            }
        } while (isRunning);

        delete itSchoolBank;
    }
   return 0;
}




//1. O clasa cont bancar ce trebuie sa aibe atribute precum nume, prenume, sold, tip de cont(valuta sau lei) IBAN
//Un cont trebuie neaparat sa aibe un nume, prenume si un IBAN care trebuie sa fie unic
//
//2.in maine se afla terminalul principal al bancii in care trebuie sa avem urmatoarele optiunii
//2.1 numar de conturi-- > ce ne da numarul de conturi inregistrate in banca
//2.2 creare cont-- > cu aceasta optiune se poate crea un cont nou
//2.2.1 -- > ar trebui un scrren diferit si un set de optiuni in care
//operatorul bancii sa introduca datele pentru crearea contului.(trebuie ca aceasta procedura sa verifice daca exista deja contul ce
//    se doreste creat iar daca da sa anunte opreatorul)
//    2.2.2 -- > o optiune de return la main screen(ecranul cu optiunie principale)
//    2.3 O optiune de modificare cont->in care operatorul poate sa modifice date despre cont(ex schimbare nume, schimbare sume etc)
//    2.4 O optiune prin care un cont se poate sterge din sistemul bancii
//    2.5 O optiune prin care un cont poate sa extraga sume - > vrei sa adaugi sau sa extragi o suma de bani
//    2.6 O optiune prin care un cont sa vada care este suma din cont
//    Trebuie cautat contul intordus iar daca exista se poate vizualiza
//    Daca nu exista putem incepe o procedura de creare cont
//
//    3. Un sistem in care putem sa salvam datele acestea intr - un fisier local(CSV file)