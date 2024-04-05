#pragma once
#include "locatar.h"
#include "repository.h"

class ActiuneUndo {
public:
	virtual void do_undo() = 0;
	virtual ~ActiuneUndo() = default;
};

class UndoAdaugare : public ActiuneUndo {
	Locatar locatar_adaugat;
	RepoAbstract& repo;
public:
	UndoAdaugare(RepoAbstract& repo, const Locatar& locatar) :repo{ repo }, locatar_adaugat{ locatar } {}
	void do_undo() override {
		repo.sterge(locatar_adaugat);
	}
};

class UndoStergere : public ActiuneUndo {
	Locatar locatar_sters;
	RepoAbstract& repo;
public:
	UndoStergere(RepoAbstract& repo, const Locatar& locatar) :repo{ repo }, locatar_sters{ locatar } {}
	void do_undo() override {
		repo.adauga(locatar_sters);
	}
};

class UndoModificare :public ActiuneUndo {
	Locatar locatar_modificat;
	RepoAbstract& repo;
public:
	UndoModificare(RepoAbstract& repo, const Locatar& locatar) :repo{ repo }, locatar_modificat{ locatar }{}
	void do_undo() override {
		repo.modifica(locatar_modificat);
	}
};
