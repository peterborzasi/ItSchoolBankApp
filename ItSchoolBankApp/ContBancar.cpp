#include "ContBancar.h"

ContBancar::ContBancar(std::string nume, std::string prenume, std::string IBAN)
{
	this->nume = nume;
	this->prenume = prenume;
	this->IBAN = IBAN;
	sold = 0;
	eTipCont = TIP_CONT::RON;
}