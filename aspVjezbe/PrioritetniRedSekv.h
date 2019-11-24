#pragma once
#include "PrioritetniRed.h"
#include <exception>

template <class T>
class PrioritetniRedSekv :public PrioritetniRed<T> {
	int maxSize = 100;
	T* niz = new T[maxSize];
	int brojac = 0;
public:
	void prosiri_niz()
	{
		T* tempNiz = new T[maxSize * 2];
		maxSize *= 2;
		for (size_t i = 0; i < brojac; i++)
		{
			tempNiz[i] = niz[i];
		}
		delete[]niz;
		niz = tempNiz;
	}

	bool jel_pun()
	{
		return brojac == maxSize;
	}

	void dodaj(T x)
	{
		if (jel_pun())
		{
			prosiri_niz();
		}
		niz[brojac] = x;
		brojac++;
	}
	T ukloni()
	{
		if (jel_prazna())
		{
			throw exception("Prioritetni red je prazan ");
		}
		int indexNajvecegBroja = 0;
		T trenutniNajveci = niz[0];
		for (size_t i = 1; i < brojac; i++)
		{
			if (trenutniNajveci > niz[i])
			{
				indexNajvecegBroja = i;
				trenutniNajveci = niz[i];
			}
		}
		brojac--;
		niz[indexNajvecegBroja] = niz[brojac];
		return trenutniNajveci;
	}
	void print() {
		for (size_t i = 0; i < brojac; i++)
		{
			cout << niz[i] << " ";
		}
		cout << endl;
	}

	bool jel_prazna()
	{ 
		return brojac == 0;
	}
	T& operator[](int index)
	{
		if (index<get_brojac())
		{
			return niz[index];
		}
		else {
			throw exception("Nepravilan indeks");
		}
	}
	T& get(int index)
	{
		return operator[](index);
	}
	int get_brojac()
	{
		return brojac;
	}

	void sveUkloni() {
		delete[]niz;
		brojac = 0;
	}

	
};