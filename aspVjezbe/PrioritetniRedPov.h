#pragma once
#include "Cvor.h"
#include <exception>
#include "PrioritetniRed.h"

template <class T>
class PrioritetniRedPov :public PrioritetniRed<T>
{
	Cvor<T>* prvi = nullptr;
public:
	void dodaj(T x)
	{
		Cvor<T>* t = prvi;
		Cvor<T>* b = nullptr;

		while (t!=nullptr && t->info>x)
		{
			b = t;
			t = t->next;
		}
		Cvor<T>* n = new Cvor<T>(x);
		n->next = t;

		if (b==nullptr)
		{
			prvi = n;
		}
		else {
			b->next = n;
		}
		
	}

	T ukloni()
	{
		if (jel_prazna())
		{
			throw exception("Red je prazan");
		}
		else {
			Cvor<T>* t = prvi;
			T tempInfo = t->info;
			prvi = prvi->next;
			delete t;
			return tempInfo;
		}
	}

	bool jel_pun()
	{
		return true;
	}


	bool jel_prazna() {
		return prvi == nullptr;
	}

	void print() {
		if (!jel_prazna())
		{
			Cvor<T>* t = prvi;
			while (t != nullptr)
			{
				cout << t->info << " ";
				t = t->next;
			}
			cout << endl;
		}
		else {
			throw exception("Red je prazan");
		}

	}

	void sveUkloni() {
		while (!jel_prazna())
		{
			ukloni();
		}
	}
};