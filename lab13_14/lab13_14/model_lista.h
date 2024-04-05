#pragma once
#include <QAbstractListModel>
#include "locatar.h"
#include <qdebug.h>
#include <vector>
using std::vector;

class ModelLista :public QAbstractListModel {
private:
	vector<Locatar> locatari;
public:
	ModelLista(const vector<Locatar>& locatari):locatari{locatari}{}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return int(locatari.size());
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			qDebug() << "get row: " << index.row();
			auto nume = locatari[index.row()].get_nume();
			return QString::fromStdString(nume);
		}
		if (role == Qt::UserRole) {
			auto nr_ap = locatari[index.row()].get_nr_ap();
			return QString::number(nr_ap);
		}
		return QVariant{};
	}
};