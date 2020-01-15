#pragma once
#include <iostream>
using namespace std;

struct Ivica {
	int startVrh;
	int endVrh;
	int tezina;
	Ivica()
	{

	}
	Ivica(int startVrh,int endVrh,int tezina)
	{
		this->startVrh = startVrh;
		this->endVrh = endVrh;
		this->tezina = tezina;
	}
	friend ostream& operator<<(ostream& cout, const Ivica& ivica)
	{
		cout << "Start vrh --> " << ivica.startVrh << endl;
		cout << "End vrh --> " << ivica.endVrh << endl;
		cout << "Tezina --> " << ivica.tezina << endl;
		return cout;
	}

	friend bool operator>(const Ivica& left, const Ivica& right)
	{
		return left.tezina > right.tezina;
	}


};