#include "repository.h"
#include <assert.h>
#include <fstream>

void RepoLocatarFile::load_from_file() {
	std::ifstream in(nume_fis);
	if (!in.is_open()) {
		throw ExceptieLocatar{ "Nu se poate deschide fisierul " + nume_fis };
	}
	while (!in.eof()) {
		int nr_ap, suprafata;
		string nume, tip;
		in >> nr_ap;
		if (in.eof()) {
			break;
		}
		//in.getline(nume);
		//getline(in, nume);
		in >> nume;
		in >> suprafata;
		in >> tip;
		Locatar l{ nr_ap, nume.c_str(), suprafata, tip.c_str() };
		RepoLocatar::adauga(l);
	}
	in.close();
}

void RepoLocatarFile::write_to_file() {
	std::ofstream out(nume_fis);
	if (!out.is_open()) {
		throw ExceptieLocatar{ "Nu se poate deschide fisierul " + nume_fis };
	}
	for (auto& l : get_all_locatari()) {
		//out << l.get_nr_ap() << " " << l.get_nume() << " " << l.get_suprafata() << " " << l.get_tip() << std::endl;
		out << l.get_nr_ap() << std::endl;
		out << l.get_nume() << std::endl;
		out << l.get_suprafata() << std::endl;
		out << l.get_tip() << std::endl;
	}
	out.close();
}

bool RepoLocatar::exista(const Locatar& l) {
	try {
		cauta(l.get_nr_ap());
		return true;
	}
	catch (ExceptieRepo&) {
		return false;
	}
}

void RepoLocatar::adauga(const Locatar& l) {
	if (exista(l)) {
		throw ExceptieRepo{ "Exista deja locatar cu nr apartamentului egal cu cel dat!\n" };
	}
	else {
		this->all_locatari.push_back(l);
	}
}

void RepoLocatar::sterge(const Locatar& l) {
	if (!(exista(l))) {
		throw ExceptieRepo{ "Nu exista un locatar cu nr apartamentului egal cu cel dat!\n" };
	}
	else {
		for (int i = 0; i < this->all_locatari.size(); i++) {
			Locatar aux = this->all_locatari[i];
			if (aux.get_nr_ap() == l.get_nr_ap()) {
				this->all_locatari.erase(all_locatari.begin() + i);
			}
		}
	}
}

void RepoLocatar::modifica(const Locatar& l) {
	if (!(exista(l))) {
		throw ExceptieRepo{ "Nu exista un locatar cu nr apartamentului " + l.get_nr_ap() };
	}
	else {
		for (int i = 0; i < this->all_locatari.size(); i++) {
			Locatar aux = this->all_locatari[i];
			if (aux.get_nr_ap() == l.get_nr_ap()) {
				this->all_locatari[i] = l;
			}
		}
	}
}

const Locatar& RepoLocatar::cauta(int nr_ap) {
	vector<Locatar>::iterator f = std::find_if(this->all_locatari.begin(), this->all_locatari.end(), [=](const Locatar& l) {
		return l.get_nr_ap() == nr_ap;
		});
	if (f != this->all_locatari.end())
		return (*f);
	else
		throw ExceptieRepo{ "Nu exista niciun locatar cu nr apartamentului egal cu cel dat" };
}

const vector<Locatar> RepoLocatar::get_all_locatari() {
	return this->all_locatari;
}

bool RepoLab::arunca_exceptie() {
	int nr_random = rand() % 11;
	float rez = float(nr_random) / 10;
	return rez < probabilitate;
}

void RepoLab::adauga(const Locatar& l) {
	if (arunca_exceptie()) {
		throw ExceptieRepo{ "Probabilitate de eroare prea mare!" };
	}
	if (exista(l)) {
		throw ExceptieRepo{ "Exista deja locatar cu nr apartamentului egal cu cel dat!\n" };
	}
	else {
		this->lab_all_locatari[l.get_tip()].push_back(l);
	}
}

bool RepoLab::exista(const Locatar& l) {
	try {
		cauta(l.get_nr_ap());
		return true;
	}
	catch (ExceptieRepo&) {
		return false;
	}
}

void RepoLab::sterge(const Locatar& l) {
	if (arunca_exceptie()) {
		throw ExceptieRepo{ "Probabilitate de eroare prea mare!" };
	}
	if (!(exista(l))) {
		throw ExceptieRepo{ "Nu exista un locatar cu nr apartamentului egal cu cel dat!\n" };
	}
	else {
		for (int i = 0; i < this->lab_all_locatari[l.get_tip()].size(); i++) {
			Locatar aux = this->lab_all_locatari[l.get_tip()][i];
			if (aux.get_nr_ap() == l.get_nr_ap()) {
				this->lab_all_locatari[l.get_tip()].erase(lab_all_locatari[l.get_tip()].begin() + i);
			}
		}
	}
}

void RepoLab::modifica(const Locatar& l) {
	if (arunca_exceptie()) {
		throw ExceptieRepo{ "Probabilitate de eroare prea mare!" };
	}
	if (!(exista(l))) {
		throw ExceptieRepo{ "Nu exista un locatar cu nr apartamentului " + l.get_nr_ap() };
	}
	else {
		for (int i = 0; i < this->lab_all_locatari[l.get_tip()].size(); i++) {
			Locatar aux = this->lab_all_locatari[l.get_tip()][i];
			if (aux.get_nr_ap() == l.get_nr_ap()) {
				this->lab_all_locatari[l.get_tip()][i] = l;
			}
		}
	}
}

const Locatar& RepoLab::cauta(int nr_ap) {
	vector<Locatar>::iterator f = std::find_if(this->lab_all_locatari["garsoniera"].begin(), this->lab_all_locatari["garsoniera"].end(), [=](const Locatar& l) {
		return l.get_nr_ap() == nr_ap;
		});
	if (f != this->lab_all_locatari["garsoniera"].end())
		return (*f);
	f = std::find_if(this->lab_all_locatari["penthouse"].begin(), this->lab_all_locatari["penthouse"].end(), [=](const Locatar& l) {
		return l.get_nr_ap() == nr_ap;
		});
	if (f != this->lab_all_locatari["penthouse"].end())
		return (*f);
	f = std::find_if(this->lab_all_locatari["standard"].begin(), this->lab_all_locatari["standard"].end(), [=](const Locatar& l) {
		return l.get_nr_ap() == nr_ap;
		});
	if (f != this->lab_all_locatari["standard"].end())
		return (*f);
	f = std::find_if(this->lab_all_locatari["studio"].begin(), this->lab_all_locatari["studio"].end(), [=](const Locatar& l) {
		return l.get_nr_ap() == nr_ap;
		});
	if (f != this->lab_all_locatari["studio"].end())
		return (*f);
	throw ExceptieRepo{ "Nu exista niciun locatar cu nr apartamentului egal cu cel dat" };
}

const vector<Locatar> RepoLab::get_all_locatari() {
	vector<Locatar> locatari;
	for (int i = 0; i < this->lab_all_locatari["garsoniera"].size(); i++)
		locatari.push_back(lab_all_locatari["garsoniera"][i]);
	for (int i = 0; i < this->lab_all_locatari["penthouse"].size(); i++)
		locatari.push_back(lab_all_locatari["penthouse"][i]);
	for (int i = 0; i < this->lab_all_locatari["standard"].size(); i++)
		locatari.push_back(lab_all_locatari["standard"][i]);
	for (int i = 0; i < this->lab_all_locatari["studio"].size(); i++)
		locatari.push_back(lab_all_locatari["studio"][i]);
	return locatari;
}