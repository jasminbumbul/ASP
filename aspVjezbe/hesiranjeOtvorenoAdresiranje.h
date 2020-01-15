#pragma once
#include <iostream>
#include <exception>

using namespace std;

class hesiranjeOtvorenoAdresiranje {
	int trenutno = 0;
	int maxSize = 10;
	int* niz = new int[maxSize];
	int* zauzeto = new int[maxSize];
	
	int hesFunkcija(int x) {
		return x % maxSize;
	}
public:
	bool jel_prazna()
	{
		return trenutno == 0;
	}
	bool jel_pun()
	{
		return trenutno == maxSize;
	}
	void dodaj(int x)
	{
		if (jel_pun())
		{
			throw exception("Niz je pun!");
		}

		int p = hesFunkcija(x);
		while (zauzeto[p]==true)
		{
			p++;
			if (p==maxSize)
			{
				p = 0;
			}
		}
		niz[p] = x;
		zauzeto[p] = true;
		cout << "Uspjesno dodan element " << x << endl;
		trenutno++;
	}

	bool ukloni(int x)
	{
		int p = hesFunkcija(x);
		int brojac = 0;
		while (brojac<maxSize)
		{
			if (zauzeto[p]==true && (niz[p]==x))
			{
				zauzeto[p]= false;
				cout << "Uspjesno uklonjen element " << x << endl;
				return true;
			}
			brojac++;
			p++;
			
		}
		return false;

	}

	void print() {
		if (jel_prazna())
		{
			throw exception("Niz je prazan");
		}
		for (size_t i = 0; i < maxSize; i++)
		{
			if (zauzeto[i]==true)
			{
				cout << niz[i] << "  ";
			}
		}
		cout << endl;
	}
};