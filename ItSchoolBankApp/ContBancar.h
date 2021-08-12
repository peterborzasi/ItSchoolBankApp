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
	//constructor
	ContBancar(std::string nume,std::string prenume, std::string IBAN);
	
	//getters
	inline std::string getNume() {return nume;}
	inline std::string getPrenume() {return prenume;}
	inline int getBalance() { return sold; }
	inline std::string getIBAN() { return IBAN; }
	
	//setters
	inline void setNume(std::string nume) { this->nume = nume; }
	inline void setPrenume(std::string prenume) { this->prenume = prenume; }
	inline void setBalance(int value) { sold = value; }
	inline void setIBAN(std::string IBAN) { this->IBAN = IBAN; }
	inline void setTipCont(TIP_CONT tipCont) { eTipCont = tipCont; }

	//destructor
	~ContBancar();
};