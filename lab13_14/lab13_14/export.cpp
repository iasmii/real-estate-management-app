#include "export.h"
#include "locatar.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void export_cvs(const string& nume_fis, const vector<Locatar>& locatari) {
	ofstream out(nume_fis, std::ios::trunc);
	if (!out.is_open()) {
		throw ExceptieLocatar("Nu se deschide fisierul " + nume_fis);
	}
	for (const auto& l : locatari) {
		out << l.get_nr_ap() << ", " << l.get_nume() << ", " << l.get_suprafata() << ", " << l.get_tip() << endl;
	}
	out.close();
}

void export_html(const string& nume_fis, const vector<Locatar>& locatari) {
	ofstream out(nume_fis, std::ios::trunc);
	if (!out.is_open()) {
		throw ExceptieLocatar("Nu se deschide fisierul " + nume_fis);
	}
	out << "<html><body>" << endl;
	out << "<table border=\"1\" style=\"width 100 % \">";
	for (const auto& l : locatari) {
		out << "<tr>" << endl;
		out << l.get_nr_ap() << "</td>" << endl;
		out << l.get_nume() << "</td>" << endl;
		out << l.get_suprafata() << "</td>" << endl;
		out << l.get_tip() << "</td>" << endl;
		out << "</tr>" << endl;
	}
	out << "</table>" << endl;
	out << "</body></html>" << endl;
	out.close();
}