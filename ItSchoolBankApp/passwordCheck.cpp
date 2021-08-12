#include <string>
#include <iostream>

#include "passwordCheck.h"

const std::string username="user";
const std::string password="1234";


bool passwordCheck()
{
    bool loginSuccesful = 0;
    std::cout << "Bine ati venit in aplicatia IT School Bank!\n";
    std::cout << "Va rugam sa va autentificati.\n";

    //setam numarul de incercari posibile pentru login
    const int numarIncercari = 3;

    //verificam username, 3 incercari posibile
    std::cout << "Username: ";
    std::string inputUsername;
    std::cin >> inputUsername;

    int incercariRamase = numarIncercari;
    for (int i = numarIncercari; i > 0; i--)
    {
        if (inputUsername == username) {
            std::cout << "Username corect.\n";
            break;
        }
        else {
            std::cout << "Username incorect. ";
            incercariRamase--;
            if (incercariRamase == 0)
            {
                std::cout << "Nu mai aveti incercari. Contul este blocat. Sunati la 112." << std::endl;
                loginSuccesful = 0;
                return loginSuccesful;
            }
            else
            {
                std::cout << "Username incorect. Introduceti inca o data. (Incercari ramase: " << incercariRamase << ")\n";
                std::cout << "Username: ";
                std::cin >> inputUsername;
            }
        }
    }

    //verificam parola, 3 incercari posibile
    std::cout << "Parola: ";
    std::string inputPassword;
    std::cin >> inputPassword;

    incercariRamase = numarIncercari;
    for (int i = numarIncercari; i > 0; i--)
    {
        if (inputPassword == password) {
            std::cout << "Password corect.\n";
            loginSuccesful=1;
            return loginSuccesful;
        }
        else {
            std::cout << "Parola incorecta. ";
            incercariRamase--;
            if (incercariRamase == 0)
            {
                std::cout << "Nu mai aveti incercari. Contul este blocat. Sunati la 112." << std::endl;
                break;
            }
            else
            {
                std::cout << "Username incorect. Introduceti inca o data. (Incercari ramase: " << incercariRamase << ")\n";
                std::cout << "Parola: ";
                std::cin >> inputPassword;
            }
        }
    }
}