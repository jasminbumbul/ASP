#pragma once
#include "Lista.h"
#include "Cvor.h"

template <class T>
class ListaPov : public Lista<T> {
	Cvor<T>* prvi = nullptr;
public:
	bool jelPun()
	{
		return false;
	}
	void dodajNaPocetak(T x)
	{
		if (prvi == nullptr)
		{
			prvi = new Cvor<T>(x);
		}
		else
		{
			Cvor<T>* n = new Cvor<T>(x);
			n->next = prvi;
			prvi = n;
		}
	}
	void dodajNaKraj(T x)
	{
		Cvor<T>* t = prvi;
		if (t == nullptr)
		{
			dodajNaPocetak(x);
		}
		else
		{
			while (t->next != nullptr)
			{
				t = t->next;
			}
			t->next = new Cvor<T>(x);
		}
		
	}
	T ukloniSaPocetka()
	{
		if (jelPrazna())
			throw std::exception("greska. lista je prazna");

		Cvor<T>* t = prvi;
		prvi = prvi->next;
		T x = t->info;
		delete t;
		return x;
	}
	T ukloniSaKraja()
	{
		Cvor<T>* t = prvi;
		Cvor<T>* b = nullptr;
		//ovdje dodati provjeru jel lista prazna
		if (jelPrazna())
		{
			if (jelPrazna())
				throw std::exception("greska. lista je prazna");
		}

		while (t->next != nullptr)
		{
			b = t;
			t = t->next;
		}
		T x = t->info;
		delete t;

		//ovdje dodati provjeru jel b == null??
		if (b == nullptr)
		{
			//lista ima samo jedan element, koji se ulanja
			prvi = nullptr;
		}
		else
		{
			b->next = nullptr;
		}

		return x;
	}
	bool jelPrazna() {
		return prvi == nullptr;
	}
	T& operator[](int i) {

		int b = 0;
		Cvor<T>* t = prvi;
		while (t != nullptr)
		{
			if (b == i)
			{
				return t->info;
			}
			b++;
			t = t->next;
		}
		throw std::exception("indeks pozicija je veca nego broj elemenata");
	}
	void sveUkloni() {

	}

	void print() {

	}



	T get(int index) {
		return operator[](index);
	}
	int getBrojac() {
		int b = 0;
		Cvor<int>* t = prvi;
		while (t != nullptr)
		{
			b++;
			t = t->next;
		}
		return b;
	}
};
