#include "Bank.h"


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
	std::cout << "Intoduceti numele si prenumele contului\n";
	std::cout << "Introduceti numele de familie\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele\n";
	std::string prenume;
	std::cin >> prenume;

	ContBancar* temp = nullptr;

	//cautare cont
	int foundIndex = 0;
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
			break;
		}
	}

	//std::cout << "Numele contului cautat: " << temp->getNume << std::endl;
	

	//cont negasit
	if (temp == nullptr)
	{
		std::cout << "Contul nu a fost gasit\n";
		std::cout << "1 -> Intoarcere la meniu principal\n";
		std::cout << "2 -> Creati un cont\n";
		std::cout << "3 -> Cautare noua\n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			std::cout << "Meniu principal...";
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
	{
		std::cout << "Ce modificari vreti sa faceti?\n";
		std::cout << "1 - Modificare nume\n";

		m_ConturiBancare.erase(it);
		/*
		1 - modificare nume
		2 - modificare prenume
		3 - modificati etc
		6 - stergere cont
		*/
	}
	
}