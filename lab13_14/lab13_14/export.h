#pragma once
#include <string.h>
#include <vector>
#include "locatar.h"
using std::vector;
using std::string;

/*
* scrie in fisier lista de locatari separati cu virgula, format CVS
* param nume_fis: numele fisierului in care se afiseaza (string)
* param all_locatari: lista de locatari care trebuie afisata (vector<Locatar>)
* throws: ExceptieLocatar daca fisiserul nu poate fi creat
*/
void export_cvs(const string& nume_fis, const vector<Locatar>& all_locatari);

/*
* scrie in fisier lista de locatari in format HTML
* param nume_fis: numele fisierului in care se afiseaza (string)
* param all_locatari: lista de locatari care trebuie afisata (vector<Locatar>)
* throws: ExceptieLocatar daca fisiserul nu poate fi creat
*/
void export_html(const string& nume_fis, const vector<Locatar>& all_locatari);
