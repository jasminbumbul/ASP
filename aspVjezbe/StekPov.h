#pragma once
#include "Cvor.h"
#include <exception>
#include "Stek.h"

template <class T>
class StekPov :public Stek<T>
{
	Cvor<T>* prvi = nullptr;
public:
	void dodaj(T x)
	{
		if (prvi == nullptr)
		{
			prvi = new Cvor<T>(x);
		}
		else
		{
			Cvor<T>* temp = new Cvor<T>(x);
			temp->next = prvi;
			prvi = temp;
		}
	}

	T ukloni()
	{
		if (!jel_prazna())
		{
			Cvor<T>* temp = prvi;
			prvi=prvi->next;
			T info = temp->info;
			delete temp;
			return info;
		}
		else {
			throw exception("Niz je prazan");
		}
	}

	bool jel_prazna() {
		return prvi == nullptr;
	}
	T& operator[](int i) {
		int brojac = 0;
		Cvor<T>* temp = prvi;
		while (temp!=nullptr)
		{
			if (brojac==i)
			{
				return temp->info;
			}
			brojac++;
			temp = temp->next;
		}
		throw exception("Nepravilan index");
	}
	T& get(int index) {
		return operator[](index);
	}
	int get_brojac() {
		int brojac = 0;
		Cvor<T>* temp = prvi;
		while (temp!=nullptr)
		{
			brojac++;
			temp = temp->next;
		}
		return brojac;
	}
	void print() {
		for (size_t i = 0; i < get_brojac(); i++)
		{
			cout << this->get(i) << " ";
		}
		cout << endl;
	}

	void sveUkloni() {
		int brojElemenata = get_brojac();
		if (!jel_prazna())
		{
			for (size_t i = 0; i < brojElemenata; i++)
			{
				ukloni();
			}
		}
		/*else
			throw exception("Niz je prazan");*/

	}
};