#include "administrator.h"
using std::shuffle;

void Administrator::adauga_locatar_admin(const Locatar& l) {
	this->administrator_bloc.push_back(l);
	notify();
}

void Administrator::goleste_admin() {
	this->administrator_bloc.clear();
	notify();
}

void Administrator::adauga_random_admin(vector<Locatar> bloc, int nr) {
	shuffle(bloc.begin(), bloc.end(), std::default_random_engine(std::random_device{}()));
	while (administrator_bloc.size() < nr && bloc.size() > 0) {
		administrator_bloc.push_back(bloc.back());
		bloc.pop_back();
	}
	notify();
}

const vector<Locatar>& Administrator::get_all_locatari_admin() {
	//notify();
	return this->administrator_bloc;
}
