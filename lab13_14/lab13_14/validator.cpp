#pragma once
#include "validator.h"
#include <assert.h>

void ValidatorLocatar::valideaza(const Locatar& l) {
	vector<string> errors;
	if (l.get_nr_ap() < 1)
		errors.push_back("Numarul apartamentului trebuie sa fie mai mare sau egal cu 1!");
	if (l.get_nume().length() < 2)
		errors.push_back("Numele trebuie sa aiba cel putin doua 2 caractere!");
	if (l.get_suprafata() < 10)
		errors.push_back("Suprafata trebuie sa fie de cel putin 10 mp!");
	if (l.get_tip() != "garsoniera" && l.get_tip() != "studio" && l.get_tip() != "standard" && l.get_tip() != "penthouse")
		errors.push_back("Tipurile valide pt apartamente sunt: \"garsoniera\", \"studio\", \"standard\", \"penthouse\"!");
	if (errors.size() > 0)
		throw ExceptieValidare(errors);
}
