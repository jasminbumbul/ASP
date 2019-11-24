#pragma once

template <class T>
struct Cvor
{
	T info;
	Cvor<T>* next;
	Cvor(int info, Cvor<T>* next = nullptr)
	{
		this->info = info; 
		this->next = next;
	}
};