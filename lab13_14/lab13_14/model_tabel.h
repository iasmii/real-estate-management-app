#pragma once
#include <QAbstractTableModel>
#include "locatar.h"
#include <Qt>
#include <vector>
#include <qdebug.h>
using std::vector;

class ModelTabel :public QAbstractTableModel {
private:
	vector<Locatar> locatari;
public:
	ModelTabel(const vector<Locatar>& locatari): locatari{locatari}{}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return int(locatari.size());
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 1;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		qDebug() << "row: " << index.row() << "column: " << index.column() << "role: " << role;
		if (role == Qt::DisplayRole) {
			Locatar l = locatari[index.row()];
			if (index.column() == 0) {
				return QString::fromStdString(l.get_nume());
			}
		}
		if (role == Qt::UserRole) {
			Locatar l = locatari[index.row()];
			if (index.column() == 0) {
				return QString::number(l.get_nr_ap());
			}
		}
		return QVariant{};
	}
	void setLocatari(const vector<Locatar>& locatari) {
		this->locatari = locatari;
		auto topLeft = createIndex(0, 0);
		auto bottomR = createIndex(rowCount(), columnCount());
		//emit dataChanged(topLeft, bottomR);
		beginResetModel();
		endResetModel();
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role) const {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				switch (section) {
				case 0:
					return tr("Nume:");
				default:
					return QString("");
				}
			}
		}
		return QVariant();
	}
};