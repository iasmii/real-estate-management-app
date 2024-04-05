#pragma once
#include "repository.h"
#include "validator.h"
#include "administrator.h"
#include "undo.h"
#include "export.h"
#include <functional>
#include <memory>
#include <unordered_map>
using std::function;
using std::unique_ptr;

class Bloc {
	RepoAbstract& repo;
	ValidatorLocatar& val;

	Administrator admin_bloc;
	vector<unique_ptr<ActiuneUndo>> undoActiuni;
public:
	Bloc(RepoAbstract& repo_loc, ValidatorLocatar& val_loc) :repo{ repo_loc }, val{ val_loc }{};
	~Bloc();
	Bloc(const Bloc& ot) = delete;
	void operator=(const Bloc& ot) = delete;
	/*
	* adauga un locatar in lista
	* param nr_ap: numarul apartamenului detinut de locatar (int)
	* param nume: numele locatarului (string)
	* param suprafata: suprafata apartamentului locatarului (int)
	* param tip: tipul apartamentului (garsoniera, studio, standard, penthouse)
	* throws: ExceptieRepo daca exista deja un apartament cu acelasi nr ca si nr_ap
	*		  ExceptieValidare daca locatarul nu e valid
	*/
	void adauga_locatar(int nr_ap, string nume, int suprafata, string tip);

	/*
	* sterge un locatar dat
	* param nr_ap: nr apartamentului care trebuie sters
	* throws: ExceptieRepo daca nu exista niciun un apartament cu acelasi nr ca si nr_ap
	*		  ExceptieValidare daca nr apartamentului nu e valid
	*/
	void sterge_locatar(int nr_ap);

	/*
	* sterge un locatar dat
	* param nr_ap: nr apartamentului care trebuie modificat
	* param nume_nou: noul nume al proprietarului
	* throws: ExceptieRepo daca nu exista niciun un apartament cu acelasi nr ca si nr_ap
	*		  ExceptieValidare daca nr apartamentului sau noul nume al proprietarului nu e valid
	*/
	void modifica_locatar(int nr_ap, string nume_nou);

	/*
	* returneaza un vector cu toti locatarii din lista
	* retruns:lista cu toti locatarii
	*/
	const vector<Locatar> get_all_locatari() {
		return this->repo.get_all_locatari();
	}

	/*
	* returneaza lista de locatari cu apartamentul de tipul dat
	* param tip: tipul cu care se filtreaza (string)
	* returns: lista de locatari cu apartamentul de tipul dat
	*/
	vector<Locatar> filtreaza_tip(string tip);

	/*
	* returneaza lista de locatari cu suprafata apartamentului din intervalul [supr_min, supr_max]
	* param supr_min: limita inferioara pt suprafata (int)
	* param supr_max: limita superioara pt suprafata (int)
	* returns: lista de locatari cu suprafata apartamentului intre supr_min si supr_max
	*/
	vector<Locatar> filtreaza_suprafata(int supr_min, int supr_max);

	/*
	* sorteaza lista de locatari dupa nume
	* returns: lista cu locatari filtrata dupa nume
	*/
	vector<Locatar> sorteaza_nume();

	/*
	* sorteaza lista de locatari dupa suprafata
	* returns: lista cu locatari filtrata dupa suprafata
	*/
	vector<Locatar> sorteaza_suprafata();

	/*
	* sorteaza lista de locatari dupa tip si suprafata
	* returns: lista cu locatari filtrata dupa tip si suprafata
	*/
	vector<Locatar> sorteaza_tip_suprafata();

	/*
	* adauga un locatar in lista
	* param nr_ap: nr apartamentului locatarului de adaugat (int)
	* throws: ExceptieRepo daca nu exista apartament cu acel nr
	*/
	void adauga_locatar_admin_service(int nr_ap);

	/*
	* goleste lista
	*/
	void goleste_admin_service();

	/*
	* adauga un nr random de locatari in lista
	* param nr: nr locatari care se adauga
	* returns: nr de locatari adaugati in lista
	*/
	int adauga_random_admin_service(int nr);

	/*
	* returneaza un vector cu toti locatarii din lista
	*/
	const vector<Locatar>& get_all_locatari_admin_service();

	/*
	* pregateste refacerea ultimei actiuni (adaugare, stergere, modificare)
	*/
	void undo();

	/*
	* scrie lista admin in fisier de tip comma separated values
	*/
	void exporta_admin_CVS(string nume_fis) const;

	/*
	* scrie lista admin in fisier de tip html
	*/
	void exporta_admin_HTML(string nume_fis) const;

	const vector<Locatar>& lista_admin() const;

	const Locatar& cauta_locatar(int nr_ap);

	std::unordered_map<string, vector<Locatar>> admin_tipruri();
};
