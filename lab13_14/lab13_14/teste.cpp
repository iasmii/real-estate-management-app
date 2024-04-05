#pragma once
#include "teste.h"
#include <assert.h>
#include <unordered_map>
#include <fstream>

#include <functional>
using std::function;
using std::unordered_map;

void test_adauga_repo() {
	RepoLocatar test_repo;
	Locatar l1{ 1, "Viorel", 100, "penthouse" };
	test_repo.adauga(l1);
	assert(test_repo.get_all_locatari().size() == 1);
	Locatar l2{ 3, "Marcel", 50, "standard" };
	Locatar l3{ 1, "Aurica", 10, "garsoniera" };
	test_repo.adauga(l2);
	try {
		test_repo.adauga(l3);
		assert(false);
	}
	catch (ExceptieRepo) {
		assert(true);
	}
	assert(test_repo.get_all_locatari().size() == 2);
}

void test_exista_repo() {
	RepoLocatar test_repo;
	Locatar l1{ 1, "Viorel", 100, "penthouse" };
	Locatar l2{ 3, "Marcel", 50, "standard" };
	test_repo.adauga(l1);
	assert(test_repo.get_all_locatari().size() == 1);
	assert(test_repo.exista(l1) == true);
	assert(test_repo.exista(l2) == false);
}

void test_sterge_repo() {
	RepoLocatar test_repo;
	Locatar l1{ 1, "Viorel", 100, "penthouse" };
	Locatar l2{ 3, "Marcel", 50, "standard" };
	Locatar l3{ 7, "Aurica", 10, "garsoniera" };
	test_repo.adauga(l1);
	test_repo.adauga(l2);
	test_repo.adauga(l3);
	assert(test_repo.get_all_locatari().size() == 3);
	test_repo.sterge(l2);
	assert(test_repo.exista(l2) == false);
	assert(test_repo.get_all_locatari().size() == 2);
	try {
		test_repo.sterge(l2);
		assert(false);
	}
	catch (ExceptieRepo) {
		assert(true);
	}
	assert(test_repo.get_all_locatari().size() == 2);
}

void test_modifica_repo() {
	RepoLocatar test_repo;
	Locatar l1{ 1, "Viorel", 100, "penthouse" };
	Locatar l2{ 3, "Marcel", 50, "standard" };
	Locatar l3{ 7, "Aurica", 10, "garsoniera" };
	test_repo.adauga(l1);
	test_repo.adauga(l2);
	test_repo.adauga(l3);
	assert(test_repo.get_all_locatari().size() == 3);
	Locatar l4{ 3, "Minnie", 50, "standard" };
	test_repo.modifica(l4);
	assert(test_repo.get_all_locatari().size() == 3);
	assert(test_repo.get_all_locatari()[1].get_nr_ap() == 3);
	assert(test_repo.get_all_locatari()[1].get_nume() == "Minnie");
	assert(test_repo.get_all_locatari()[1].get_suprafata() == 50);
	assert(test_repo.get_all_locatari()[1].get_tip() == "standard");
	Locatar l5{ 12, "Aurel", 150, "penthouse" };
	try {
		test_repo.modifica(l5);
		assert(false);
	}
	catch (ExceptieRepo) {
		assert(true);
	}
}

void test_cauta_repo() {
	RepoLocatar test_repo;
	Locatar l1{ 1, "Viorel", 100, "penthouse" };
	Locatar l2{ 2, "Marcel", 50, "standard" };
	Locatar l3{ 3, "Aurica", 10, "garsoniera" };
	test_repo.adauga(l1);
	test_repo.adauga(l2);

	assert(test_repo.exista(l1));
	assert(!test_repo.exista(l3));

	auto l_gasit = test_repo.cauta(2);
	assert(l_gasit.get_nr_ap() == 2);
	assert(l_gasit.get_nume() == "Marcel");
	assert(l_gasit.get_suprafata() == 50);
	assert(l_gasit.get_tip() == "standard");

	try {
		test_repo.cauta(5);
		assert(false);
	}
	catch (ExceptieRepo& ve) {
		assert(ve.get_mesaj_eroare_repo() == "Nu exista niciun locatar cu nr apartamentului egal cu cel dat");
	}
}

void test_file_repo() {
	std::ofstream out("test_locatari.txt", std::ios::trunc);
	out.close(); //fisier gol
	RepoLocatarFile repo_f1{ "test_locatari.txt" };
	repo_f1.adauga(Locatar{ 1, "Gica", 60, "standard" });
	assert(repo_f1.get_all_locatari().size() == 1);
	RepoLocatarFile repo_f2{ "test_locatari.txt" };
	auto l = repo_f2.cauta(1);
	try {
		std::ofstream outt("t/est_l/ocata/ri.txt", std::ios::trunc);
		outt.close();
		RepoLocatarFile repo_fe{ "t/est_l/ocata/ri.txt" };
		repo_fe.adauga(Locatar{ 7, "Gica", 60, "standard" });
		assert(false);
	}
	catch (ExceptieLocatar&) {
		assert(true);
	}
	try {
		repo_f2.cauta(3);
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}
	repo_f2.sterge(Locatar{ 1, "Gica", 60, "standard" });
	assert(repo_f2.get_all_locatari().size() == 0);
	try {
		repo_f2.sterge(Locatar{ 3, "Gina", 40, "standard" });
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}

	RepoLocatarFile repo_f3{ "test_locatari.txt" };
	assert(repo_f3.get_all_locatari().size() == 0);

	try {
		RepoLocatarFile repo_f4{ "test/locatari.txt" };
		assert(false);
	}
	catch (ExceptieLocatar&) {
		assert(true);
	}
}

void teste_repo() {
	test_exista_repo();
	test_adauga_repo();
	test_cauta_repo();
	test_sterge_repo();
	test_modifica_repo();
	test_file_repo();
}

void test_adauga() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "Pop Ion", 55, "standard");
	test_srv.adauga_locatar(2, "Pop Ana", 25, "studio");
	test_srv.adauga_locatar(3, "Puya", 155, "penthouse");

	assert(test_srv.get_all_locatari().size() == 3);
	Locatar l1 = test_srv.cauta_locatar(1);
	assert(l1.get_nume() == "Pop Ion");
	try {
		test_srv.cauta_locatar(5);
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}
	try {
		test_srv.adauga_locatar(1, "Anca", 40, "standard");
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}

	try {
		test_srv.adauga_locatar(4, "Anca", 40, "standard");
		assert(true);
	}
	catch (ExceptieValidare&) {
		assert(false);
	}

	try {
		test_srv.adauga_locatar(0, "Anca", 40, "standard");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}

	try {
		test_srv.adauga_locatar(6, "a", 40, "standard");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}

	try {
		test_srv.adauga_locatar(7, "Anca", 9, "standard");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}

	try {
		test_srv.adauga_locatar(9, "Aurel", 40, "Standard");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}
}

void test_sterge() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "Pop Ion", 55, "standard");
	test_srv.adauga_locatar(2, "Pop Ana", 25, "studio");
	test_srv.adauga_locatar(3, "Puya", 155, "penthouse");

	assert(test_srv.get_all_locatari().size() == 3);

	test_srv.sterge_locatar(1);
	assert(test_srv.get_all_locatari().size() == 2);
	assert(test_srv.get_all_locatari()[0].get_nr_ap() == 2);
	assert(test_srv.get_all_locatari()[1].get_nr_ap() == 3);

	try {
		test_srv.sterge_locatar(1);
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}
	assert(test_srv.get_all_locatari().size() == 2);
	try {
		test_srv.sterge_locatar(-2);
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}
	assert(test_srv.get_all_locatari().size() == 2);
}

void test_modifica() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "Pop Ion", 55, "standard");
	test_srv.adauga_locatar(2, "Pop Ana", 25, "studio");
	test_srv.adauga_locatar(3, "Puya", 155, "penthouse");

	assert(test_srv.get_all_locatari().size() == 3);

	test_srv.modifica_locatar(2, "Marcel Gigel");
	assert(test_srv.get_all_locatari()[1].get_nr_ap() == 2);
	assert(test_srv.get_all_locatari()[1].get_nume() == "Marcel Gigel");
	assert(test_srv.get_all_locatari()[1].get_suprafata() == 25);
	assert(test_srv.get_all_locatari()[1].get_tip() == "studio");

	try {
		test_srv.modifica_locatar(5, "Dorian Popa");
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}
	try {
		test_srv.modifica_locatar(-2, "Dorian Popa");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}
	try {
		test_srv.modifica_locatar(2, "A");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}
	try {
		test_srv.modifica_locatar(-2, "A");
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}
}

void test_sorteaza() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "Carla", 20, "garsoniera");
	test_srv.adauga_locatar(2, "Bogdan", 100, "penthouse");
	test_srv.adauga_locatar(3, "Elvis", 70, "standard");
	test_srv.adauga_locatar(4, "Ana", 30, "standard");
	test_srv.adauga_locatar(5, "Doru", 90, "penthouse");

	vector<Locatar> sortat_nume = test_srv.sorteaza_nume();
	assert(sortat_nume[0].get_nr_ap() == 4);
	assert(sortat_nume[1].get_nr_ap() == 2);
	assert(sortat_nume[2].get_nr_ap() == 1);
	assert(sortat_nume[3].get_nr_ap() == 5);
	assert(sortat_nume[4].get_nr_ap() == 3);

	vector<Locatar> sortat_suprafata = test_srv.sorteaza_suprafata();
	assert(sortat_suprafata[0].get_nr_ap() == 1);
	assert(sortat_suprafata[1].get_nr_ap() == 4);
	assert(sortat_suprafata[2].get_nr_ap() == 3);
	assert(sortat_suprafata[3].get_nr_ap() == 5);
	assert(sortat_suprafata[4].get_nr_ap() == 2);

	vector<Locatar> sortat_tip = test_srv.sorteaza_tip_suprafata();
	assert(sortat_tip[0].get_nr_ap() == 1);
	assert(sortat_tip[1].get_nr_ap() == 5);
	assert(sortat_tip[2].get_nr_ap() == 2);
	assert(sortat_tip[3].get_nr_ap() == 4);
	assert(sortat_tip[4].get_nr_ap() == 3);
}

void test_filtreaza() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "Carla", 20, "garsoniera");
	test_srv.adauga_locatar(2, "Bogdan", 100, "penthouse");
	test_srv.adauga_locatar(3, "Elvis", 70, "penthouse");
	test_srv.adauga_locatar(4, "Ana", 30, "studio");
	test_srv.adauga_locatar(5, "Doru", 90, "penthouse");

	vector<Locatar> penthouse = test_srv.filtreaza_tip("penthouse");
	assert(penthouse.size() == 3);
	vector<Locatar> garsoniera = test_srv.filtreaza_tip("garsoniera");
	assert(garsoniera.size() == 1);

	vector<Locatar> supr50_90 = test_srv.filtreaza_suprafata(50, 90);
	assert(supr50_90.size() == 2);
	vector<Locatar> supr15_95 = test_srv.filtreaza_suprafata(15, 95);
	assert(supr15_95.size() == 4);
}

void test_administrator() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "ACIU MIRCEA", 90, "penthouse");
	test_srv.adauga_locatar(2, "TITIHAZAN VIOREL", 50, "standard");
	test_srv.adauga_locatar(3, "RACASAN NICOLETA", 17, "garsoniera");
	test_srv.adauga_locatar(4, "HELEREA ELENA", 23, "studio");
	test_srv.adauga_locatar(5, "BROJBOIU MARIA", 110, "penthouse");

	test_srv.adauga_random_admin_service(3);
	assert(test_srv.get_all_locatari_admin_service().size() == 3);
	//std::cout << test_srv.get_all_locatari_admin_service().size();
	test_srv.goleste_admin_service();
	assert(test_srv.get_all_locatari_admin_service().size() == 0);
	test_srv.adauga_random_admin_service(13);
	assert(test_srv.get_all_locatari_admin_service().size() == 5);

	test_srv.goleste_admin_service();
	test_srv.adauga_locatar_admin_service(4);
	assert(test_srv.get_all_locatari_admin_service().size() == 1);

	try {
		test_srv.adauga_locatar_admin_service(24);
		assert(false);
	}
	catch (ExceptieRepo&) {
		assert(true);
	}
}

void test_admin_tipruri() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };

	test_srv.adauga_locatar(1, "ACIU MIRCEA", 90, "penthouse");
	test_srv.adauga_locatar(2, "TITIHAZAN VIOREL", 50, "standard");
	test_srv.adauga_locatar(3, "RACASAN NICOLETA", 17, "garsoniera");
	test_srv.adauga_locatar(4, "HELEREA ELENA", 37, "standard");
	test_srv.adauga_locatar(5, "BROJBOIU MARIA", 110, "penthouse");
	test_srv.adauga_locatar(6, "Pop Ion", 55, "standard");
	test_srv.adauga_locatar(7, "Pop Ana", 90, "penthouse");
	test_srv.adauga_locatar(8, "Dorel Dorian", 15, "garsoniera");
	test_srv.adauga_locatar(9, "Florin Florian", 20, "studio");
	test_srv.adauga_locatar(10, "Stefana Stefanescu", 45, "standard");

	unordered_map<string, vector<Locatar>>dict = test_srv.admin_tipruri();

	assert(dict["garsoniera"].size() == 2);
	assert(dict["penthouse"].size() == 3);
	assert(dict["standard"].size() == 4);
	assert(dict["studio"].size() == 1);
}

void test_undo() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };
	test_srv.adauga_locatar(1, "ACIU MIRCEA", 90, "penthouse");
	test_srv.adauga_locatar(2, "TITIHAZAN VIOREL", 50, "standard");
	test_srv.adauga_locatar(3, "RACASAN NICOLETA", 17, "garsoniera");
	assert(test_srv.get_all_locatari().size() == 3);
	test_srv.undo();
	assert(test_srv.get_all_locatari().size() == 2);
	test_srv.undo();
	test_srv.undo();
	assert(test_srv.get_all_locatari().size() == 0);
	try {
		test_srv.undo();
		assert(false);
	}
	catch (ExceptieLocatar&) {
		assert(true);
	}
	test_srv.adauga_locatar(10, "Stefana Stefanescu", 45, "standard");
	assert(test_srv.get_all_locatari()[0].get_nume() == "Stefana Stefanescu");
	test_srv.modifica_locatar(10, "Andrei Andreescu");
	assert(test_srv.get_all_locatari()[0].get_nume() == "Andrei Andreescu");
	test_srv.undo();
	assert(test_srv.get_all_locatari()[0].get_nume() == "Stefana Stefanescu");
	assert(test_srv.get_all_locatari().size() == 1);
	test_srv.sterge_locatar(10);
	assert(test_srv.get_all_locatari().size() == 0);
	test_srv.undo();
	assert(test_srv.get_all_locatari().size() == 1);
	assert(test_srv.get_all_locatari()[0].get_nr_ap() == 10);
}

void test_export() {
	RepoLocatar test_repo;
	ValidatorLocatar test_val;
	Bloc test_srv{ test_repo, test_val };
	test_srv.adauga_locatar(1, "ACIU MIRCEA", 90, "penthouse");
	test_srv.adauga_locatar(2, "TITIHAZAN VIOREL", 50, "standard");
	test_srv.adauga_locatar(3, "RACASAN NICOLETA", 17, "garsoniera");
	test_srv.adauga_random_admin_service(3);
	//assert(test_srv.lista_admin().size() == 3);
	//cout << test_srv.lista_admin().size() << " ";
	test_srv.exporta_admin_CVS("testexport.cvs");
	std::ifstream in("testexport.cvs");
	assert(in.is_open());
	int nr_linii = 0;
	while (!in.eof()) {
		string linie;
		in >> linie;
		//cout << linie << "\n";
		nr_linii++;
	}
	in.close();
	//cout << nr_linii << "\n";
	//assert(nr_linii == 4);
	test_srv.exporta_admin_HTML("testexport.html");
	in.open("testexport.html");
	assert(in.is_open());
	try {
		test_srv.exporta_admin_CVS("tes/texport.cvs");
		assert(false);
	}
	catch (ExceptieLocatar&) {
		assert(true);
	}
	try {
		test_srv.exporta_admin_HTML("tes/texp/ort.html");
		assert(false);
	}
	catch (ExceptieLocatar&) {
		assert(true);
	}
}

void teste_service() {
	test_adauga();
	test_sterge();
	test_modifica();
	test_sorteaza();
	test_filtreaza();
	test_administrator();
	test_admin_tipruri();
	test_undo();
	test_export();
}

void test_validare() {
	ValidatorLocatar test_val;

	Locatar l1{ 1, "Gica Popescu", 65, "standard" };

	Locatar l2{ 0, "Gica Popescu", 65, "standard" };
	try {
		test_val.valideaza(l2);
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}

	Locatar l3{ 1, "G", 65, "standard" };
	try {
		test_val.valideaza(l3);
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}

	Locatar l4{ 1, "Gica Popescu", 5, "standard" };
	try {
		test_val.valideaza(l4);
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}

	Locatar l5{ 1, "Gica Popescu", 65, "decomandat" };
	try {
		test_val.valideaza(l5);
		assert(false);
	}
	catch (ExceptieValidare&) {
		assert(true);
	}
}

void test_get_set() {
	Locatar l1{ 1, "Pop Ion", 55, "standard" };
	assert(l1.get_nr_ap() == 1);
	assert(l1.get_nume() == "Pop Ion");
	assert(l1.get_suprafata() == 55);
	assert(l1.get_tip() == "standard");

	l1.set_nume("Pop Ana");
	l1.set_suprafata(30);
	l1.set_tip("studio");

	assert(l1.get_nume() == "Pop Ana");
	assert(l1.get_suprafata() == 30);
	assert(l1.get_tip() == "studio");
}

void test_cmp() {
	Locatar l1{ 1, "Pop Ion", 55, "standard" };
	Locatar l2{ 1, "Pop Ana", 30, "studio" };
	Locatar l3{ 1, "Mariah Carrey", 75, "standard" };
	assert(cmp_nume(l1, l2) == false);
	assert(cmp_suprafata(l2, l1) == true);
	assert(cmp_tip(l1, l2) == true);
	assert(cmp_tip(l3, l1) == false);
}

void teste_domeniu() {
	test_get_set();
	test_cmp();
}

void test_all() {
	teste_domeniu();
	//cout << "Teste domeniu trecute.\n";
	teste_repo();
	//cout << "Teste repo trecute.\n";
	teste_service();
	//cout << "Teste service trecute.\n";
	test_validare();
	//cout << "Teste validator trecute.\n";
}