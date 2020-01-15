#include "Cvor.h"
#include <exception>
#include "Red.h"

template <class T>
class RedPov :public Red<T>
{
	Cvor<T>* pocetak = nullptr;
	Cvor<T>* kraj = nullptr;
public:
	void dodaj(T x)
	{
		Cvor<T>* temp = new Cvor<T>(x);
		if (jel_prazna())
		{
			pocetak = temp;
			kraj = temp;
		}
		else {
			kraj->next = temp;
			kraj = temp;
		}

	}

	T ukloni()
	{
		if (!jel_prazna())
		{
			Cvor<T>* temp = pocetak;
			pocetak = pocetak->next;
			T tempInfo = temp->info;
			delete temp;

			if (pocetak==nullptr)
			{
				kraj = nullptr;
			}

			return tempInfo;
		}
		else {
			throw exception("Niz je prazan");
		}
	}

	bool jel_pun() {
		return true;
	}

	bool jel_prazna() {
		return pocetak == nullptr ;
	}

	int get_brojac() {
		int brojac = 0;
		Cvor<T>* temp = pocetak;
		while (temp!=nullptr)
		{
			brojac++;
			temp = temp->next;
		}
		return brojac;
	}
	void print() {
		if (jel_prazna())
		{
			throw exception("Niz je prazan");
		}
		Cvor<T>* temp = pocetak;
		while (temp!=nullptr)
		{
			cout << temp->info << "  ";
			temp = temp->next;
		}
		cout << endl;
		
	}

	void ukloniSve() {
		/*if (!jel_prazna())
		{
			for (size_t i = 0; i < brojElemenata; i++)
			{
				ukloni();
			}
		}*/
		if (jel_prazna())
		{
			cout << "RED JE PRAZAN" << endl;
		}
		while (!jel_prazna())
		{
			cout << "Uklonjeni element ---->" << ukloni() << endl;
		}
		/*else
			throw exception("Niz je prazan");*/

	}
};