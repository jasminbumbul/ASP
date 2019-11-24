#pragma once
#include <exception>

template <class T>
class RedSekv :public Red<T> {
	int maxSize = 100;
	T* niz = new T[maxSize];
	int brojac = 0;
	int pocetak = 0, kraj = 0;
public:

	bool jel_pun()
	{
		return brojac == maxSize;
	}

	void dodaj(T x)
	{
		if (jel_pun())
		{
			throw exception("Niz je pun");
		}
		niz[kraj] = x;
		kraj++;
		if (kraj==maxSize)
		{
			kraj == 0; 
		}
		brojac++;
	}
	T ukloni()
	{
		if (jel_prazna())
		{
			throw exception("Red je prazan");
		}
		T x = niz[pocetak];
		pocetak++;
		if (pocetak==maxSize)
		{
			pocetak = 0;
		}
		brojac--;
		return x;
	}
	void print() {
		for (size_t i = 0; i < brojac; i++)
		{
			cout << niz[i] << "  ";
		}
		cout << endl;
	}

	bool jel_prazna()
	{
		return brojac == 0;
	}
	/*T& operator[](int index)
	{
		
	}
	T& get(int index)
	{
		return operator[](index);
	}*/
	int get_brojac()
	{
		return brojac;
	}

	void ukloniSve() {
		if (jel_prazna())
		{
			cout << "Prazan red" << endl;
			return;
		}

		T temp;
		while (!jel_prazna())
		{
			cout << "Uklonjen element -->" << ukloni() << endl;
		}
	}
};