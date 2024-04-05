#pragma once
#include "locatar.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class ExceptieValidare {
	vector <string> mesaj_eroare;
public:
	ExceptieValidare(vector<string> errorMessages) : mesaj_eroare{ errorMessages } {};
	string get_msg_eroare_validare() {
		string mesaj = "";
		for (const string eroare : mesaj_eroare) {
			mesaj = mesaj + eroare + "\n";
		}
		return mesaj;
	}
};

class ValidatorLocatar {
public:
	void valideaza(const Locatar& l);
};
