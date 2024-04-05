#pragma once
#include "service.h"
#include "undo.h"
#include <vector>
#include <assert.h>
#include <functional>
#include <algorithm>
#include <unordered_map>
using std::sort;
using std::unordered_map;
using std::make_unique;

unordered_map<string, vector<Locatar>> Bloc::admin_tipruri() {
	unordered_map<string, vector<Locatar>>dictionar;
	dictionar["garsoniera"] = filtreaza_tip("garsoniera");
	dictionar["penthouse"] = filtreaza_tip("penthouse");
	dictionar["standard"] = filtreaza_tip("standard");
	dictionar["studio"] = filtreaza_tip("studio");
	return dictionar;
}

void Bloc::undo() {
	if (undoActiuni.empty()) {
		throw ExceptieLocatar{ "Nu se mai poate face undo!" };
	}
	undoActiuni.back()->do_undo();
	undoActiuni.pop_back();
}

Bloc::~Bloc() {

}

void Bloc::adauga_locatar(int nr_ap, string nume, int suprafata, string tip) {
	Locatar l1{ nr_ap, nume, suprafata, tip };
	val.valideaza(l1);
	repo.adauga(l1);
	undoActiuni.push_back(make_unique<UndoAdaugare>(repo, l1));
}

void Bloc::sterge_locatar(int nr_ap) {
	Locatar l{ nr_ap, "Ana", 20, "garsoniera" };
	val.valideaza(l);
	l = repo.cauta(nr_ap);
	repo.sterge(l);
	undoActiuni.push_back(make_unique<UndoStergere>(repo, l));
}

void Bloc::modifica_locatar(int nr_ap, string nume_nou) {
	Locatar l{ nr_ap, nume_nou, 20, "garsoniera" };
	val.valideaza(l);
	l = repo.cauta(nr_ap);
	Locatar l_nou{ nr_ap, nume_nou, l.get_suprafata(), l.get_tip() };
	repo.modifica(l_nou);
	undoActiuni.push_back(make_unique<UndoModificare>(repo, l));
}

vector<Locatar> Bloc::sorteaza_nume() {
	vector<Locatar> copie_sortata{ repo.get_all_locatari() };
	sort(copie_sortata.begin(), copie_sortata.end(), cmp_nume);
	return copie_sortata;
}

vector<Locatar> Bloc::sorteaza_suprafata() {
	vector<Locatar> copie_sortata{ repo.get_all_locatari() };
	sort(copie_sortata.begin(), copie_sortata.end(), cmp_suprafata);
	return copie_sortata;
}

vector<Locatar> Bloc::sorteaza_tip_suprafata() {
	vector<Locatar> copie_sortata{ repo.get_all_locatari() };
	sort(copie_sortata.begin(), copie_sortata.end(), cmp_tip);
	return copie_sortata;
}

vector<Locatar> Bloc::filtreaza_tip(string tip) {
	const vector<Locatar>& all_locatari = get_all_locatari();
	vector<Locatar> filtrata;
	std::copy_if(all_locatari.begin(), all_locatari.end(), back_inserter(filtrata), [tip](const Locatar& l) {
		return l.get_tip() == tip;
		});
	return filtrata;
}

vector<Locatar> Bloc::filtreaza_suprafata(int supr_min, int supr_max) {
	const vector<Locatar>& all_locatari = get_all_locatari();
	vector<Locatar> filtrata;
	std::copy_if(all_locatari.begin(), all_locatari.end(), back_inserter(filtrata), [=](const Locatar& l) {
		return l.get_suprafata() >= supr_min && l.get_suprafata() <= supr_max;
		});
	return filtrata;
}

void Bloc::adauga_locatar_admin_service(int nr_ap) {
	const auto& l = repo.cauta(nr_ap);
	admin_bloc.adauga_locatar_admin(l);
}

int Bloc::adauga_random_admin_service(int nr) {
	admin_bloc.adauga_random_admin(this->get_all_locatari(), nr);
	return int(admin_bloc.get_all_locatari_admin().size());
}

void Bloc::goleste_admin_service() {
	admin_bloc.goleste_admin();
}

const vector<Locatar>& Bloc::get_all_locatari_admin_service() {
	return admin_bloc.get_all_locatari_admin();
}

const vector<Locatar>& Bloc::lista_admin() const {
	return admin_bloc.lista();
}

void Bloc::exporta_admin_CVS(string nume_fis) const {
	//const vector<Locatar>& locatari = admin_bloc.get_all_locatari_admin();
	export_cvs(nume_fis, lista_admin());
}

void Bloc::exporta_admin_HTML(string nume_fis) const {
	export_html(nume_fis, lista_admin());
}

const Locatar& Bloc::cauta_locatar(int nr_ap) {
	return repo.cauta(nr_ap);
}