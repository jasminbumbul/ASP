#pragma once
#include "ListaPov.h"
#include <iostream>
using namespace std;

//template <class T>
class hesiranjeUlancavanje {
	int trenutno = 0;
	int maxSize = 10;
	ListaPov<int>* niz = new ListaPov<int>[maxSize];

	int hesFunkcija(int x)
	{
		return x % maxSize;
	}
public:
	bool jelPrazna() {
		return trenutno == 0;
	}
	bool jelPun() {
		return trenutno == maxSize;
	}
	void dodaj(int x)
	{
		if (jelPun()) {
			throw exception("Niz je pun");
		}
		int p = hesFunkcija(x);
		while ()
		{

		}
		niz[p].dodajNaPocetak(x);
		trenutno++;
	}
	bool Ukloni(int x)
	{

	}
	void print() {

	}
};
