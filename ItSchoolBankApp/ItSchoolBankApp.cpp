#include <iostream>

int main()
{
    std::cin >> optiune;
    switch (optiune)
    {
    case '1':
        system("CLS");
        itSchoolBank->adaugareCont();
        break;
    case '2':
        system("CLS");
        itSchoolBank->vizualizareCont();
        break;

    }

    return 0;
}
