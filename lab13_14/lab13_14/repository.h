#pragma once
#include "locatar.h"
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using std::vector;
using std::string;

class ExceptieRepo {
private:
	string errorMsg;
public:
	ExceptieRepo(const string& errorMsg) : errorMsg{ errorMsg } {};
	string get_mesaj_eroare_repo() const {
		return this->errorMsg;
	}
};

class RepoAbstract {
public:
	virtual ~RepoAbstract() = default;

	virtual void adauga(const Locatar& l) = 0;

	virtual void sterge(const Locatar& l) = 0;

	virtual void modifica(const Locatar& l) = 0;

	virtual const vector<Locatar> get_all_locatari() = 0;

	virtual const Locatar& cauta(int nr_ap) = 0;

	virtual bool exista(const Locatar& l) = 0;
};

class RepoLab : public RepoAbstract {
private:
	float probabilitate;
	bool arunca_exceptie();
	std::map<string, vector<Locatar> > lab_all_locatari;
public:
	RepoLab(float probabilitate) : RepoAbstract(), probabilitate{ probabilitate }{}
	RepoLab(const RepoLab& ot) = delete;
	virtual ~RepoLab() = default;

	void adauga(const Locatar& l);

	void sterge(const Locatar& l);

	void modifica(const Locatar& l);

	const vector<Locatar> get_all_locatari();

	const Locatar& cauta(int nr_ap);

	bool exista(const Locatar& l);
};

class RepoLocatar : public RepoAbstract {
private:
	vector<Locatar> all_locatari;
public:
	RepoLocatar() : RepoAbstract() {}

	RepoLocatar(const RepoLocatar& ot) = delete; //ca sa nu faca copie
	virtual ~RepoLocatar() = default;
	/*
	* adauga un locatar in lista
	* param l: locatar de adaugat (Locatar)
	* throws: ExceptieRepo daca exista un apartament cu acel numar
	*/
	virtual void adauga(const Locatar& l);

	/*
	* sterge un locatar din lista
	* param l: locatar de sterge (Locatar)
	* throws: ExceptieRepo daca nu exista un apartament cu acel numar
	*/
	virtual void sterge(const Locatar& l);

	/*
	* modifica un locatar in lista
	* param l: locatar de modificat (Locatar)
	* throws: ExceptieRepo daca nu exista un apartament cu acel numar
	*/
	virtual void modifica(const Locatar& l);

	/*
	* returneaza o lista cu toti locatarii
	* returns: lista cu toti locatarii (vector de obiecte Locatar)
	*/
	const vector<Locatar> get_all_locatari();

	/*
	* cauta un locatar cu nr dat de apartament
	* param nr_ap: numarul apartamentului de cautat (int)
	* returns: obiectul Locatar cu nr dat de apartament
	* throws: ExceptieRepo daca nu exista un apartament cu nr dat
	*/
	const Locatar& cauta(int nr_ap);

	/*
	* verifica daca un locatar exista deja in lista
	* param l: locatarul cautat
	* retruns: true daca exista locatarul, false altfel
	*/
	bool exista(const Locatar& l);
};

class RepoLocatarFile :public RepoLocatar {
private:
	string nume_fis;
	void load_from_file();
	void write_to_file();
public:
	RepoLocatarFile(string nume_fis) : RepoLocatar(), nume_fis{ nume_fis }{
		load_from_file();
	}
	void adauga(const Locatar& l) override {
		RepoLocatar::adauga(l);
		write_to_file();
	}
	void sterge(const Locatar& l) override {
		RepoLocatar::sterge(l);
		write_to_file();
	}
	void modifica(const Locatar& l) override {
		RepoLocatar::modifica(l);
		write_to_file();
	}
};
