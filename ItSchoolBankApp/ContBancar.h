#pragma once
#include <string>

enum class TIP_CONT
{
	RON = 1, EUR, USD
};

class ContBancar
{
private:
	std::string nume;
	std::string prenume;
	int sold;
	TIP_CONT eTipCont;
	std::string IBAN;
public:
	ContBancar(std::string nume,std::string prenume, std::string IBAN);
	~ContBancar();
};

