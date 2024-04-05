#pragma once
#include <algorithm>
#include <vector>
using std::vector;

class Observer {
public:
	virtual void update() = 0;
};

class Observable {
private:
	vector<Observer*> interesati;
public:
	void notify() {
		for (auto obs : interesati) {
			obs->update();
		}
	}
	void adauga_observer(Observer* o) {
		interesati.push_back(o);
	}
	void sterge_observer(Observer* o) {
		interesati.erase(std::remove(interesati.begin(), interesati.end(), o), interesati.end());
	}
};