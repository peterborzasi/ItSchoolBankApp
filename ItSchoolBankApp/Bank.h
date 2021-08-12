#pragma once

#include <vector>
#include <iostream>

#include "ContBancar.h"

class Bank
{
	std::vector<ContBancar*> m_ConturiBancare;
	std::string createIBAN();
public:
	Bank();
	~Bank();
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();
};