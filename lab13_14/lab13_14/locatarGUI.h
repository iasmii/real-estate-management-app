#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qtablewidget.h>
#include "service.h"
#include "locatar.h"
#include <vector>
#include <qlabel.h>
#include <qpainter.h>
#include "observer.h"
#include <cstdlib>
#include <iostream>

class GUIcos :public QWidget, public Observer {
private:
	Administrator& adm;
	Bloc& srv;
	QListWidget* cos;
	QPushButton* btn_adauga_loc;
	QPushButton* btn_adauga_random;
	QPushButton* btn_goleste;
	QPushButton* btn_export_CVS;
	QPushButton* btn_export_HTML;
	QLineEdit* cos_nr_ap;
	QLineEdit* cos_nume;
	QLineEdit* cos_suprafata;
	QLineEdit* cos_tip;
	QLineEdit* cos_nume_fis;
	void initGUIcos();
	void conecteaza();
	void reincarca(const std::vector<Locatar>& locatari);
public:
	GUIcos(Administrator& adm, Bloc& srv) :adm{ adm }, srv { srv } {
		initGUIcos();
		conecteaza();
		adm.adauga_observer(this);
		reincarca(adm.lista());
	}
	void update() override {
		reincarca(adm.lista());
	}
	~GUIcos() {
		adm.sterge_observer(this);
	}
};

class GUIcosReadOnly :public QWidget, public Observer {
private:
	Administrator& adm;
	Bloc& srv;
public:
	GUIcosReadOnly(Administrator& adm, Bloc& srv) :adm{ adm }, srv{ srv } {
		adm.adauga_observer(this);
	}
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		for (const auto& l : adm.lista()) {
			int x = rand() % 350;
			p.drawRect(x, x, 30, 30);
		}
	}
	void update() override {
		repaint();
	}
	~GUIcosReadOnly() {
		adm.sterge_observer(this);
	}
};

class GUIbloc :public QWidget {
private:
	Bloc& srv;
	Administrator& adm;
	QListWidget* lst;
	QPushButton* btn_sort_nume;
	QPushButton* btn_sort_suprafata;
	QPushButton* btn_sort_suprafata_tip;
	QPushButton* btn_filtr_suprafata;
	QPushButton* btn_filtr_tip;
	QPushButton* btn_adauga;
	QPushButton* btn_sterge;
	QPushButton* btn_modifica;
	QPushButton* btn_undo;
	QPushButton* btn_cos;
	QPushButton* btn_cosReadOnly;
	QLineEdit* txt_nr_ap;
	QLineEdit* txt_nume;
	QLineEdit* txt_suprafata;
	QLineEdit* txt_tip;
	QLineEdit* txt_sup_min;
	QLineEdit* txt_sup_max;
	QWidget* btn_dinamice;
	QVBoxLayout* ly_din;
	QTableWidget* tab;
	void initGUI();
	void connect_signal_slots();
	void reincarca_lista(const std::vector<Locatar>& locatari);
	void adauga_butoane_din();
	void reincarca_tabel(const std::vector<Locatar>& locatari);
public:
	GUIbloc(Administrator& adm, Bloc& srv) :adm{ adm }, srv { srv } {
		initGUI();
		connect_signal_slots();
		reincarca_lista(srv.get_all_locatari());
		adauga_butoane_din();
		reincarca_tabel(srv.get_all_locatari());
	}
};