#include "locatar.h"
#include <assert.h>

int Locatar::get_nr_ap() const {
	return this->nr_ap;
}

string Locatar::get_nume() const {
	return this->nume;
}

int Locatar::get_suprafata() const {
	return this->suprafata;
}

string Locatar::get_tip() const {
	return this->tip;
}

void Locatar::set_nume(string nume_nou) {
	this->nume = nume_nou;
}

void Locatar::set_suprafata(int suprafata_noua) {
	this->suprafata = suprafata_noua;
}

void Locatar::set_tip(string tip_nou) {
	this->tip = tip_nou;
}

bool cmp_nume(const Locatar& l1, const Locatar& l2) {
	return l1.get_nume() < l2.get_nume();
}

bool cmp_suprafata(const Locatar& l1, const Locatar& l2) {
	return l1.get_suprafata() < l2.get_suprafata();
}

bool cmp_tip(const Locatar& l1, const Locatar& l2) {
	if (l1.get_tip() == l2.get_tip())
		return l1.get_suprafata() < l2.get_suprafata();
	else
		return l1.get_tip() < l2.get_tip();
}
