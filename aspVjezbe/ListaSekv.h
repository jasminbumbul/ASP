#pragma once
#include <iostream>
#include "Lista.h"
using namespace std;

template <class T>
class ListaSekv:public Lista<T> {
	int max_size = 5;
	T* niz = new T[max_size];
	int brojac = 0;
public:
	int getBrojac() {
		return brojac;
	}
	T get(int index)
	{
		return niz[index];
	}
	void dodajNaPocetak(T x) {
		if (!jelPun())
		{
			for (size_t i = brojac; i > 0; i--)
			{
				niz[i] = niz[i - 1];
			}
			niz[0] = x;
			brojac++;
		}
	}
	void dodajNaKraj(T x) {
		if (!jelPun())
		{
			niz[brojac] = x;
			brojac++;
		}
	}
	T ukloniSaPocetka() {
		if (!jelPrazan())
		{
			T tempReturnUklonjen = niz[0];
			for (size_t i = 0; i < brojac; i++)
			{
				niz[i] = niz[i + 1];
			}
			brojac--;
			return tempReturnUklonjen;
		}
	}
	T ukloniSaKraja() {
		if (!jelPrazan())
		{
			T tempReturnUklonjen = niz[brojac - 1];
			brojac--;
			return tempReturnUklonjen;
		}
	}
	void sveUkloni() {
		if (!jelPrazan())
		{
			brojac = 0;
			return;
		}
	}
	void print() {
		if (!jelPrazan())
		{
			//cout << ":::ISPIS NIZA:::" << endl;
			for (size_t i = 0; i < brojac; i++)
			{
				cout << niz[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	bool jelPun() {
		if (brojac == max_size)
		{
			prosiriNiz();
		}
		return false;
	}
	bool jelPrazan() {
		if (brojac == 0)
		{
			cout << "Niz je prazan" << endl;
			return true;
		}
		return false;
	}
	void prosiriNiz() {
		max_size *= 2;
		T* tempNiz = new T[max_size];
		for (size_t i = 0; i < brojac; i++)
		{
			tempNiz[i] = niz[i];
		}
		delete[]niz;
		niz = tempNiz;
		cout << "Niz je prosiren" << endl;
	}
	T operator[](int index)
	{
		if (index >= 0 && index < brojac)
		{
			return niz[index];
		}
		else
			return 0;
	}
};

