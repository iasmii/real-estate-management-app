#pragma once
#include "locatar.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "observer.h"

using std::vector;
class Administrator :public Observable {
private:
	vector<Locatar> administrator_bloc;
public:
	Administrator() = default;

	/*
	* adauga un locatar in lista administrator_bloc
	* param l: locatarul de adaugat (Locatar)
	*/
	void adauga_locatar_admin(const Locatar& l);

	/*
	* goleste lista
	*/
	void goleste_admin();

	/*
	* adauga un nr random de locatari in lista
	* param bloc: lista de locatari din care se aleg cei care sunt adaugati (vector<Locatar>)
	* param nr: nr locatari care se adauga
	*/
	void adauga_random_admin(vector<Locatar> bloc, int nr);

	/*
	* returneaza un vector cu toti locatarii din lista
	*/
	const vector<Locatar>& get_all_locatari_admin();

	const vector<Locatar>& lista() const {
		return this->administrator_bloc;
	}
};