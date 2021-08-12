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
	inline std::string getName() {return nume;}
	inline std::string getPrenume() { return prenume; }
	inline int getBalance() { return sold; }
	inline std::string getIBAN() { return IBAN; }
	
	//setters
	inline void setBalance(int value) { sold = value; }
	
	//destructor
	~ContBancar();
};

