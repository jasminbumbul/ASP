#pragma once

template <class T>
class StekSekv :public Stek<T> {
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
		if (brojac==0)
		{
			niz[0] = x;
		}
		else {

			for (size_t i = brojac; i > 0; i--)
			{
				niz[i] = niz[i-1];
			}
			niz[0] = x;
		}
		brojac++;	
	}
	T ukloni()
	{
		if (!jel_prazna())
		{
			T tempUklonjeni = niz[0];
			for (size_t i = 0; i < brojac; i++)
			{
				niz[i-1] = niz[i];
			}
			brojac--;
			return tempUklonjeni;
		}
		else {
			throw exception("Niz je prazan");
		}
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