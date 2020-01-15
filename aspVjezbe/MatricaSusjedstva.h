#pragma once
#include <iostream>
#include "ListaSekv.h"
#include "Ivica.h"
#include <fstream>
using namespace std;

class MatricaSusjedstva
{
	int** matrica;
	const int velicina;
public:
	int getVelicina() {
		return velicina;
	}
	void ucitajMatricu(string filename)
	{
		ifstream fin(filename);

		for (int i = 0; i < velicina; i++)
		{
			for (int j = 0; j < velicina; j++)
			{
				int u;
				fin >> u;
				matrica[i][j] = u;
			}
		}

		fin.close();
	}

	MatricaSusjedstva(int vel):velicina(vel)
	{
		matrica = new int*[vel];
		for (size_t i = 0; i < vel; i++)
		{
			matrica[i] = new int[vel];
			for (size_t j = 0; j < vel; j++)
			{
				matrica[i][j] = 0;
			}
		}
	}

	void print() {
		for (size_t i = 0; i < velicina; i++)
		{
			for (size_t j = 0; j < velicina; j++)
			{
				cout << matrica[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool provjeraGlavnaDijagonala() {
		for (size_t i = 0; i < velicina; i++)
		{
			if (matrica[i][i]!=0)
			{
				return false;
			}
		}
		return true;
	}

	//vraca podatak sa koliko je vrhova povezan proslijedjeni vrh
	int izlazniStepen(int i) {
		int suma = 0;
		for (size_t j = 0;j < velicina; j++)
		{
			suma += matrica[i][j];
		}
		return suma;
	}

	//vraca podatak koliko je vrhova povezano sa proslijedjenim vrhom
	int ulazniStepen(int j)
	{
		int suma = 0;
		for (size_t i = 0; i < velicina; i++)
		{
			suma += matrica[i][j];
		}
		return suma;
	}

	ListaSekv<int>* susjediTo(int i)
	{
		ListaSekv<int>* listaSusjediTo = new ListaSekv<int>;
		for (size_t j = 0; j < velicina; j++)
		{
			if (matrica[i][j]!=0)
			{
				listaSusjediTo->dodajNaKraj(j);
			}
		}
		return listaSusjediTo;
	}
	
	ListaSekv<int>* susjediFrom(int j)
	{
		ListaSekv<int>* listaSusjediFrom = new ListaSekv<int>;
		for (size_t i = 0; i < velicina; i++)
		{
			if (matrica[i][j]!=0)
			{
				listaSusjediFrom->dodajNaKraj(i);
			}
		}
		return listaSusjediFrom;
	}

	ListaSekv<int>* izlazniStepenMax()
	{
		int* nizIzlaznihStepena = new int[velicina];
		for (size_t i = 0; i < velicina; i++)
		{
			nizIzlaznihStepena[i] = izlazniStepen(i);
		}
		
		int najveciStepen = 0;
		for (size_t i = 0; i < velicina; i++)
		{
			if (najveciStepen<nizIzlaznihStepena[i])
			{
				najveciStepen = nizIzlaznihStepena[i];
			}
		}

		ListaSekv<int>* listaNajvecihIzlaznihStepena = new ListaSekv<int>;
		for (size_t i = 0; i < velicina; i++)
		{
			if (nizIzlaznihStepena[i]==najveciStepen)
			{
				listaNajvecihIzlaznihStepena->dodajNaKraj(i);
			}
		}

		return listaNajvecihIzlaznihStepena;


	}

	int tezina(int from, int to)
	{
		return matrica[from][to];
	}

	//vraca susjeda koji ima najvezu tezinu
	int najbliziSusjed(int from) {
		ListaSekv<int>* listaSusjeda = susjediTo(from);

		int minSusjed = -1;
		int minTezina = INT_MAX;

		for (size_t i = 0; i < listaSusjeda->getBrojac(); i++)
		{
			int element = listaSusjeda->get(i);
			int tez = tezina(from, element);
			if (tez<minTezina)
			{
				minTezina = tez;
				minSusjed = element;
			}
		}
		return minSusjed;
	}

	void dodaj(Ivica* ivica)
	{
		matrica[ivica->startVrh][ivica->endVrh] = ivica->tezina;
	}
};