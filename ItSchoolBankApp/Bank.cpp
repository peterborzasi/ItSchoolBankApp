#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

void Bank::adaugareCont()
{
	system("CLS");
	std::cout << "Introduceti numele: ";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele: ";
	std::string prenume;
	std::cin >> prenume;
	std::string IBAN = createIBAN();
	ContBancar* cont = new ContBancar(nume, prenume, IBAN);
	m_ConturiBancare.push_back(cont);
	std::cout << "Cont adaugat cu succes.\n";
	std::cout << "1 -> Creare cont nou\n";
	std::cout << "2 -> Vizualizare conturi\n";
	std::cout << "3 -> Modificare conturi\n";
	std::cout << "9 -> Meniu principal\n";
	std::cout << "Alegeti o optiune: ";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		adaugareCont();
		break;
	case '2':
		vizualizareConturi();
		break;
	case '3':
		modificareCont();
		break;
	default:
		break;
	}
}

std::string Bank::createIBAN()
{
	//sa generam IBAN unic
	std::string codIBAN = "KZ446687489624793376";
	return codIBAN;
}

void Bank::vizualizareConturi()
{
	system("CLS");
	std::cout << "Nr. conturi bancare active: " << m_ConturiBancare.size() << std::endl;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Cont " << i+1 << ": " << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << " - IBAN: " << m_ConturiBancare[i]->getIBAN() << std::endl;
	}
	std::cout << "1 -> Creare cont nou\n";
	std::cout << "2 -> Modificare cont existent\n";
	std::cout << "9 -> Meniu principal\n";
	std::cout << "Alegeti o optiune: ";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		adaugareCont();
		break;
	case '2':
		modificareCont();
		break;
	case '9':
		break;
	default:
		break;
	}

}

//cautare cont
		// - daca exista intrebam ce modificari facem
		// - daca nu exista spunem ca nu exista si dam urmatoarele optiuni
			// return to main
			// creati un cont
			// cautati alt cont

void Bank::modificareCont()
{
	system("CLS");
	//intrebati operatorul care cont doreste sa il modifice
	std::cout << "Ce cont doriti sa modificati? Introduceti datele:\n";
	std::cout << "Introduceti numele: ";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele: ";
	std::string prenume;
	std::cin >> prenume;

	ContBancar* temp = nullptr;

	//cautare cont
	
	//int foundIndex = 0;
	//for (int i = 0; i < m_ConturiBancare.size(); i++)
	//{
	//	if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume())
	//	{
	//		temp = m_ConturiBancare[i];
	//		foundIndex = i;
	//		break;
	//	}
	//}

	std::vector<ContBancar*>::iterator it;

	for (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{
			temp = *it;
			std::cout << "Cont gasit: " << temp->getNume() << " " << temp->getPrenume() << std::endl;
			break;
		}
	}




	//cont negasit
	if (temp == nullptr)
	{
		std::cout << "Contul nu a fost gasit\n";
		std::cout << "1 -> Vizualizare conturi\n";
		std::cout << "2 -> Creati un cont\n";
		std::cout << "3 -> Cautare noua\n";
		std::cout << "9 -> Meniu principal\n";
		std::cout << "Selectati o optiune: ";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			vizualizareConturi();
			break;
		case '2':
			adaugareCont();
			break;
		case '3':
			modificareCont();
			break;
		default:
			break;
		}
	}
	else
		//cont gasit
	{
		std::cout << "Ce modificari vreti sa faceti?\n";
		std::cout << "1 - Modificare nume\n";
		std::cout << "2 - Modificare prenume\n";
		std::cout << "6 - Stergere cont (*nu poate fi revocat)\n";
		std::cout << "8 - Cautare noua\n";
		std::cout << "9 - Inapoi la meniul principal\n";
		std::cout << "Selectati o optiune: ";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			{std::string schimbareNume;
			std::cout << "Introduceti NUME nou: ";
			std::cin >> schimbareNume;
			temp->setNume(schimbareNume);
			break;
			}
		case '2':
			{std::string schimbarePrenume;
			std::cout << "Introduceti PRENUME nou: ";
			std::cin >> schimbarePrenume;
			temp->setNume(schimbarePrenume);
			break;
			}
		case '6':
			m_ConturiBancare.erase(it);
			break;
		case '8':
			modificareCont();
			break;
		case '9':
			std::cout << "Going back...";
			break;
		default:
			break;
		}
		
		
		/*
		1 - modificare nume
		2 - modificare prenume
		3 - modificati etc
		6 - stergere cont
		*/
	}
	
}

//void schimbareNume()
//{
//	std::string schimbareNume;
//	std::cout << "Introduceti nume nou: ";
//	std::cin >> schimbareNume;
//	temp->setNume(schimbareNume);
//}