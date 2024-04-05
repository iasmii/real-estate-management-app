#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/qlineedit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qheaderview.h>
#include <string>
#include <iostream>
#include <algorithm>
#include "locatar.h"
#include "model_locatarGUI.h"
#include "model_lista.h"
#include "model_tabel.h"
#include <unordered_map>

/*
void MGUIcos::initGUIcos() {
	QHBoxLayout* ly_cos = new QHBoxLayout;
	setLayout(ly_cos);

	QWidget* wid_dr_cos = new QWidget;
	QVBoxLayout* vl_cos = new QVBoxLayout;
	wid_dr_cos->setLayout(vl_cos);

	cos = new QListView;
	vl_cos->addWidget(cos);

	ly_cos->addWidget(wid_dr_cos);

	QWidget* wid_detalii_cos = new QWidget;
	QFormLayout* form_detalii_cos = new QFormLayout;
	wid_detalii_cos->setLayout(form_detalii_cos);

	cos_nr_ap = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Nr apartament: "), cos_nr_ap);

	cos_nume = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Nume: "), cos_nume);

	cos_suprafata = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Suprafata: "), cos_suprafata);

	cos_tip = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Tip: "), cos_tip);

	cos_nume_fis = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Nume fisier export: "), cos_nume_fis);

	btn_adauga_loc = new QPushButton("Adauga locatar");
	form_detalii_cos->addWidget(btn_adauga_loc);

	btn_adauga_random = new QPushButton("Adauga random");
	form_detalii_cos->addWidget(btn_adauga_random);

	btn_goleste = new QPushButton("Goleste lista");
	form_detalii_cos->addWidget(btn_goleste);

	btn_export_CVS = new QPushButton("Exporta CVS");
	form_detalii_cos->addWidget(btn_export_CVS);

	btn_export_HTML = new QPushButton("Exporta HTML");
	form_detalii_cos->addWidget(btn_export_HTML);

	ly_cos->addWidget(wid_detalii_cos);
}

void MGUIcos::conecteaza() {
	QObject::connect(btn_adauga_loc, &QPushButton::clicked, [&]() {
		try {
			Locatar l = srv.cauta_locatar(cos_nr_ap->text().toInt());
			adm.adauga_locatar_admin(l);
			reincarca(adm.lista());
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		catch (ExceptieValidare& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_msg_eroare_validare()));
		}
		});
	QObject::connect(btn_adauga_random, &QPushButton::clicked, [&]() {
		adm.adauga_random_admin(srv.get_all_locatari(), cos_nr_ap->text().toInt());
		reincarca(adm.lista());
		});
	QObject::connect(btn_goleste, &QPushButton::clicked, [&]() {
		adm.goleste_admin();
		reincarca(adm.lista());
		});
	QObject::connect(btn_export_CVS, &QPushButton::clicked, [&]() {
		try {
			srv.exporta_admin_CVS(cos_nume_fis->text().toStdString());
			QMessageBox::information(this, "Information", QString::fromStdString("Export reusit"));
		}
		catch (ExceptieLocatar& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_locatar()));
		}
		});
	QObject::connect(btn_export_HTML, &QPushButton::clicked, [&]() {
		try {
			srv.exporta_admin_HTML(cos_nume_fis->text().toStdString());
			QMessageBox::information(this, "Information", QString::fromStdString("Export reusit"));
		}
		catch (ExceptieLocatar& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_locatar()));
		}
		});
	QObject::connect(cos->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (cos->selectionModel()->selectedIndexes().isEmpty()) {
			cos_nr_ap->setText("");
			cos_nume->setText("");
			cos_suprafata->setText("");
			cos_tip->setText("");
			return;
		}
		auto item_sel = cos->selectionModel()->selectedIndexes().at(0);
		QString nume = item_sel.data(Qt::DisplayRole).toString();
		cos_nume->setText(nume);
		QString nr_ap_q = item_sel.data(Qt::UserRole).toString();
		cos_nr_ap->setText(nr_ap_q);
		try {
			int nr_ap = nr_ap_q.toInt();
			Locatar l = srv.cauta_locatar(nr_ap);
			cos_suprafata->setText(QString::number(l.get_suprafata()));
			cos_tip->setText(QString::fromStdString(l.get_tip()));
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(nullptr, "Atentie", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		});
}

void MGUIcos::reincarca(const vector<Locatar>& locatari) {
	//model = new ModelLista(locatari);
	cos->setModel(model);
}
*/

void MGUIcos::initGUIcos() {
	QHBoxLayout* ly_cos = new QHBoxLayout;
	setLayout(ly_cos);

	QWidget* wid_dr_cos = new QWidget;
	QVBoxLayout* vl_cos = new QVBoxLayout;
	wid_dr_cos->setLayout(vl_cos);

	cos = new QListWidget;
	vl_cos->addWidget(cos);

	ly_cos->addWidget(wid_dr_cos);

	QWidget* wid_detalii_cos = new QWidget;
	QFormLayout* form_detalii_cos = new QFormLayout;
	wid_detalii_cos->setLayout(form_detalii_cos);

	cos_nr_ap = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Nr apartament: "), cos_nr_ap);

	cos_nume = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Nume: "), cos_nume);

	cos_suprafata = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Suprafata: "), cos_suprafata);

	cos_tip = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Tip: "), cos_tip);

	cos_nume_fis = new QLineEdit;
	form_detalii_cos->addRow(new QLabel("Nume fisier export: "), cos_nume_fis);

	btn_adauga_loc = new QPushButton("Adauga locatar");
	form_detalii_cos->addWidget(btn_adauga_loc);

	btn_adauga_random = new QPushButton("Adauga random");
	form_detalii_cos->addWidget(btn_adauga_random);

	btn_goleste = new QPushButton("Goleste lista");
	form_detalii_cos->addWidget(btn_goleste);

	btn_export_CVS = new QPushButton("Exporta CVS");
	form_detalii_cos->addWidget(btn_export_CVS);

	btn_export_HTML = new QPushButton("Exporta HTML");
	form_detalii_cos->addWidget(btn_export_HTML);

	ly_cos->addWidget(wid_detalii_cos);
}

void MGUIcos::conecteaza() {
	QObject::connect(btn_adauga_loc, &QPushButton::clicked, [&]() {
		try {
			//srv.adauga_locatar_admin_service(cos_nr_ap->text().toInt());
			//reincarca(srv.get_all_locatari_admin_service());
			Locatar l = srv.cauta_locatar(cos_nr_ap->text().toInt());
			adm.adauga_locatar_admin(l);
			reincarca(adm.lista());
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		catch (ExceptieValidare& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_msg_eroare_validare()));
		}
		});
	QObject::connect(btn_adauga_random, &QPushButton::clicked, [&]() {
		//srv.adauga_random_admin_service(cos_nr_ap->text().toInt());
		//reincarca(srv.get_all_locatari_admin_service());
		adm.adauga_random_admin(srv.get_all_locatari(), cos_nr_ap->text().toInt());
		reincarca(adm.lista());
		});
	QObject::connect(btn_goleste, &QPushButton::clicked, [&]() {
		//srv.goleste_admin_service();
		//reincarca(srv.get_all_locatari_admin_service());
		adm.goleste_admin();
		reincarca(adm.lista());
		});
	QObject::connect(btn_export_CVS, &QPushButton::clicked, [&]() {
		try {
			srv.exporta_admin_CVS(cos_nume_fis->text().toStdString());
			QMessageBox::information(this, "Information", QString::fromStdString("Export reusit"));
		}
		catch (ExceptieLocatar& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_locatar()));
		}
		});
	QObject::connect(btn_export_HTML, &QPushButton::clicked, [&]() {
		try {
			srv.exporta_admin_HTML(cos_nume_fis->text().toStdString());
			QMessageBox::information(this, "Information", QString::fromStdString("Export reusit"));
		}
		catch (ExceptieLocatar& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_locatar()));
		}
		});
	QObject::connect(cos, &QListWidget::itemSelectionChanged, [&]() {
		if (cos->selectedItems().isEmpty()) {
			cos_nr_ap->setText("");
			cos_nume->setText("");
			cos_suprafata->setText("");
			cos_tip->setText("");
			return;
		}
		QListWidgetItem* item_sel = cos->selectedItems().at(0);
		QString nume = item_sel->text();
		cos_nume->setText(nume);
		QString nr_ap_q = item_sel->data(Qt::UserRole).toString();
		cos_nr_ap->setText(nr_ap_q);
		try {
			int nr_ap = nr_ap_q.toInt();
			Locatar l = srv.cauta_locatar(nr_ap);
			cos_suprafata->setText(QString::number(l.get_suprafata()));
			cos_tip->setText(QString::fromStdString(l.get_tip()));
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(nullptr, "Atentie", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		});
}

void MGUIcos::reincarca(const vector<Locatar>& locatari) {
	cos->clear();
	for (const auto& l : locatari) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(l.get_nume()), cos);
		string nr_ap_s = std::to_string(l.get_nr_ap());
		item->setData(Qt::UserRole, QString::fromStdString(nr_ap_s));
	}
}

void MGUIbloc::initGUI() {
	QHBoxLayout* ly = new QHBoxLayout;
	setLayout(ly);

	QWidget* wid_dreapta = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	wid_dreapta->setLayout(vl);

	QWidget* wid_tab = new QWidget;
	QHBoxLayout* vl_tab = new QHBoxLayout;
	wid_tab->setLayout(vl_tab);

	tab = new QTableView(this);
	tab->verticalHeader()->setVisible(false);
	vl_tab->addWidget(tab);
	ly->addWidget(wid_tab);

	//lst = new QListView;
	//vl->addWidget(lst);

	QWidget* wid_butoane_dreapta = new QWidget;
	QHBoxLayout* ly_butoane_dreapta = new QHBoxLayout;
	wid_butoane_dreapta->setLayout(ly_butoane_dreapta);

	btn_sort_nume = new QPushButton("Sorteaza nume");
	ly_butoane_dreapta->addWidget(btn_sort_nume);

	btn_sort_suprafata = new QPushButton("Sorteaza suprafata");
	ly_butoane_dreapta->addWidget(btn_sort_suprafata);

	btn_sort_suprafata_tip = new QPushButton("Sorteaza suprafata+tip");
	ly_butoane_dreapta->addWidget(btn_sort_suprafata_tip);

	btn_filtr_suprafata = new QPushButton("Filtreaza suprafata");
	ly_butoane_dreapta->addWidget(btn_filtr_suprafata);

	btn_filtr_tip = new QPushButton("Filtreaza tip");
	ly_butoane_dreapta->addWidget(btn_filtr_tip);

	vl->addWidget(wid_butoane_dreapta);
	ly->addWidget(wid_dreapta);

	QWidget* wid_detalii = new QWidget;
	QFormLayout* form_detalii = new QFormLayout;
	wid_detalii->setLayout(form_detalii);

	txt_nr_ap = new QLineEdit;
	form_detalii->addRow(new QLabel("Nr apartament: "), txt_nr_ap);

	txt_nume = new QLineEdit;
	form_detalii->addRow(new QLabel("Nume: "), txt_nume);

	txt_suprafata = new QLineEdit;
	form_detalii->addRow(new QLabel("Suprafata: "), txt_suprafata);

	txt_tip = new QLineEdit;
	form_detalii->addRow(new QLabel("Tip: "), txt_tip);

	txt_sup_min = new QLineEdit;
	form_detalii->addRow(new QLabel("Suprafata minima pt filtru: "), txt_sup_min);

	txt_sup_max = new QLineEdit;
	form_detalii->addRow(new QLabel("Suprafata maxima pt filtru: "), txt_sup_max);

	btn_adauga = new QPushButton("Adauga locatar");
	form_detalii->addWidget(btn_adauga);

	btn_sterge = new QPushButton("Sterge locatar");
	form_detalii->addWidget(btn_sterge);

	btn_modifica = new QPushButton("Modifica locatar");
	form_detalii->addWidget(btn_modifica);

	btn_undo = new QPushButton("Undo");
	form_detalii->addWidget(btn_undo);

	btn_cos = new QPushButton("Lista administrator");
	form_detalii->addWidget(btn_cos);

	btn_cosReadOnly = new QPushButton("Lista administrator Poze");
	form_detalii->addWidget(btn_cosReadOnly);

	ly->addWidget(wid_detalii);
	btn_dinamice = new QWidget;
	ly_din = new QVBoxLayout;
	btn_dinamice->setLayout(ly_din);

	ly->addWidget(btn_dinamice);
}

void MGUIbloc::connect_signal_slots() {
	QObject::connect(btn_sort_nume, &QPushButton::clicked, [&]() {
		//reincarca_lista(srv.sorteaza_nume());
		reincarca_tabel(srv.sorteaza_nume());
		});
	QObject::connect(btn_sort_suprafata, &QPushButton::clicked, [&]() {
		//reincarca_lista(srv.sorteaza_suprafata());
		reincarca_tabel(srv.sorteaza_suprafata());
		});
	QObject::connect(btn_sort_suprafata_tip, &QPushButton::clicked, [&]() {
		//reincarca_lista(srv.sorteaza_tip_suprafata());
		reincarca_tabel(srv.sorteaza_tip_suprafata());
		});
	QObject::connect(btn_filtr_suprafata, &QPushButton::clicked, [&]() {
		int sup_min = txt_sup_min->text().toInt();
		int sup_max = txt_sup_max->text().toInt();
		//reincarca_lista(srv.filtreaza_suprafata(sup_min, sup_max));
		reincarca_tabel(srv.filtreaza_suprafata(sup_min, sup_max));
		});
	QObject::connect(btn_filtr_tip, &QPushButton::clicked, [&]() {
		string tip = txt_tip->text().toStdString();
		//reincarca_lista(srv.filtreaza_tip(tip));
		reincarca_tabel(srv.filtreaza_tip(tip));
		});
	/*
	QObject::connect(lst->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (lst->selectionModel()->selectedIndexes().isEmpty()) {
			txt_nr_ap->setText("");
			txt_nume->setText("");
			txt_suprafata->setText("");
			txt_tip->setText("");
			return;
		}
		auto item_sel = lst->selectionModel()->selectedIndexes().at(0);
		QString nume = item_sel.data(Qt::DisplayRole).toString();
		txt_nume->setText(nume);
		QString nr_ap_q = item_sel.data(Qt::UserRole).toString();
		txt_nr_ap->setText(nr_ap_q);
		try {
			int nr_ap = nr_ap_q.toInt();
			Locatar l = srv.cauta_locatar(nr_ap);
			txt_suprafata->setText(QString::number(l.get_suprafata()));
			txt_tip->setText(QString::fromStdString(l.get_tip()));
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(nullptr, "Atentie", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		});
	*/
	QObject::connect(tab->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (tab->selectionModel()->selectedIndexes().isEmpty()) {
			txt_nr_ap->setText("");
			txt_nume->setText("");
			txt_suprafata->setText("");
			txt_tip->setText("");
			return;
		}
		int item_selectat = tab->selectionModel()->selectedIndexes().at(0).row();
		auto index = tab->model()->index(item_selectat, 0);
		auto nume = tab->model()->data(index, Qt::DisplayRole).toString();
		txt_nume->setText(nume);
		auto nr_ap_q = tab->model()->data(index, Qt::UserRole).toString();
		txt_nr_ap->setText(nr_ap_q);
		try {
			int nr_ap = nr_ap_q.toInt();
			Locatar l = srv.cauta_locatar(nr_ap);
			txt_suprafata->setText(QString::number(l.get_suprafata()));
			txt_tip->setText(QString::fromStdString(l.get_tip()));
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		});

	QObject::connect(btn_adauga, &QPushButton::clicked, [&]() {
		try {
			srv.adauga_locatar(txt_nr_ap->text().toInt(), txt_nume->text().toStdString(), txt_suprafata->text().toInt(), txt_tip->text().toStdString());
			//reincarca_lista(srv.get_all_locatari());
			reincarca_tabel(srv.get_all_locatari());
			adauga_butoane_din();
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		catch (ExceptieValidare& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_msg_eroare_validare()));
		}
		});

	QObject::connect(btn_sterge, &QPushButton::clicked, [&]() {
		try {
			srv.sterge_locatar(txt_nr_ap->text().toInt());
			//reincarca_lista(srv.get_all_locatari());
			reincarca_tabel(srv.get_all_locatari());
			adauga_butoane_din();
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		catch (ExceptieValidare& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_msg_eroare_validare()));
		}
		});

	QObject::connect(btn_modifica, &QPushButton::clicked, [&]() {
		try {
			srv.modifica_locatar(txt_nr_ap->text().toInt(), txt_nume->text().toStdString());
			//reincarca_lista(srv.get_all_locatari());
			reincarca_tabel(srv.get_all_locatari());
		}
		catch (ExceptieRepo& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_repo()));
		}
		catch (ExceptieValidare& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_msg_eroare_validare()));
		}
		});

	QObject::connect(btn_undo, &QPushButton::clicked, [&]() {
		try {
			srv.undo();
			//reincarca_lista(srv.get_all_locatari());
			reincarca_tabel(srv.get_all_locatari());
			adauga_butoane_din();
		}
		catch (ExceptieLocatar& re) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_mesaj_eroare_locatar()));
		}
		});

	QObject::connect(btn_cos, &QPushButton::clicked, [&]() {
		auto cos = new MGUIcos{ adm, srv };
		cos->show();
		});
	QObject::connect(btn_cosReadOnly, &QPushButton::clicked, [&]() {
		auto cosRO = new MGUIcosReadOnly{ adm, srv };
		cosRO->show();
		});

}
/*
void MGUIbloc::reincarca_lista(const std::vector<Locatar>& locatari) {
	model_lista = new ModelLista(locatari);
	lst->setModel(model_lista);
}
*/
void MGUIbloc::reincarca_tabel(const std::vector<Locatar>& locatari) {
	model_tabel->setLocatari(locatari);
}

void MGUIbloc::adauga_butoane_din() {
	std::unordered_map<string, vector<Locatar>>solutie = srv.admin_tipruri();

	QLayoutItem* item;
	while ((item = ly_din->takeAt(0))) {
		delete item->widget();
		delete item;
	}
	delete ly_din;
	ly_din = new QVBoxLayout;
	btn_dinamice->setLayout(ly_din);

	for (const auto& el : solutie) {
		if (el.second.size() != 0) {
			auto btn = new QPushButton{ QString::fromStdString(el.first) };
			ly_din->addWidget(btn);
			int nr = int(el.second.size());
			QObject::connect(btn, &QPushButton::clicked, [nr, this, btn]() {
				txt_nr_ap->setText(QString::number(nr));
				QMessageBox::information(nullptr, "Information", QString::number(nr));
				});
		}
	}
}
