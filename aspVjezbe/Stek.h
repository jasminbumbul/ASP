#pragma once

template <class T>
class Stek
{
public:
	virtual void dodaj(T x) = 0;
	virtual T ukloni() = 0;
	virtual bool jel_prazna() = 0;
	virtual T& operator[](int index) = 0;
	virtual T& get(int index) = 0;
	virtual int get_brojac() = 0;
};