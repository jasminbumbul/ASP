#pragma once

template <class T>
class Lista
{
public:
	virtual void dodajNaPocetak(T x) = 0;
	virtual void dodajNaKraj(T x) = 0;
	virtual T ukloniSaPocetka() = 0;
	virtual T ukloniSaKraja() = 0;
	virtual void sveUkloni() = 0;
	virtual void print() = 0;
	//virtual T get(int index) = 0;
	virtual bool jelPun() = 0;
	//virtual bool jelPrazna() = 0;
	//virtual int getBrojac() = 0;
};