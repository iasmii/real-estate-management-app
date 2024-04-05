#pragma once
#include <string.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ExceptieLocatar {
	string msg;
public:
	ExceptieLocatar(const string& msg) : msg{ msg } {};
	string get_mesaj_eroare_locatar() const {
		return this->msg;
	}
};

class Locatar {
private:
	int nr_ap;
	string nume;
	int suprafata;
	string tip;
public:
	Locatar() = default;
	Locatar(int nr_ap, string nume, int suprafata, string tip) : nr_ap{ nr_ap }, nume{ nume }, suprafata{ suprafata }, tip{ tip }{};
	Locatar(const Locatar& ot) :nr_ap{ ot.nr_ap }, nume{ ot.nume }, suprafata{ ot.suprafata }, tip{ ot.tip }{
		//cout << "Constructorul de copiere Locatar a fost apelat.\n";
	};

	Locatar operator=(const Locatar& ot) {
		this->nr_ap = ot.nr_ap;
		this->nume = ot.nume;
		this->suprafata = ot.suprafata;
		this->tip = ot.tip;
		return(*this);
	}

	bool operator==(const Locatar& ot) {
		return nr_ap == ot.nr_ap;
	}

	int get_nr_ap() const;
	string get_nume() const;
	int get_suprafata() const;
	string get_tip() const;

	void set_nume(string nume_nou);
	void set_suprafata(int suprfata_noua);
	void set_tip(string tip_nou);
};

/*
* compara doi locatari in functie de numele lor
*
* returns: true daca numele locatarului l1 e in fata lui l2 in ordine alfabetica sau egal, false altfel
*/
bool cmp_nume(const Locatar& l1, const Locatar& l2);

/*
* compara doi locatari in functie de suprafata apartamentelor lor
*
* retruns: true daca suprafata de la apartamentlui al locatarului l1 e mai mica sau egala cu cea de la l2, false altfel
*/
bool cmp_suprafata(const Locatar& l1, const Locatar& l2);

/*
* compara doi locatari in functie de tipul apartamentelor lor
*
* retruns: true daca tipul apartamentului locatarului l1 e in fata lui l2 in ordine alfabetica, false daca l2 e mai mare, daca sunt egale se compara suprafetele
*/
bool cmp_tip(const Locatar& l1, const Locatar& l2);

//void teste_domeniu();