#pragma once
#include <exception>
#include "PrioritetniRedSekv.h"

struct Tacka {
	float x;
	float y;

	Tacka()
	{}

	Tacka(float x,float y)
	{
		this->x = x;
		this->y = y;
	}

	float udaljenostOdCentra() {
		return sqrt(x * x + y * y);
	}

	friend ostream& operator<<(ostream& cout, const Tacka& t) {
		cout << "Koordinata x --->" << t.x << endl;
		cout << "Koordinata y --->" << t.y << endl;
		return cout;
	}
};

bool operator<(Tacka& a, Tacka& b) {
	return a.udaljenostOdCentra() < b.udaljenostOdCentra();
}

bool operator>(Tacka& a, Tacka& b) {
	return a.udaljenostOdCentra() > b.udaljenostOdCentra();
}