#include <iostream>
#include "ListaSekv.h"
#include "ListaPov.h"
#include "StekPov.h"
#include "StekSekv.h"
#include "RedPov.h"
#include "RedSekv.h"
#include "PrioritetniRed.h"
#include "PrioritetniRedSekv.h"
#include "PrioritetniRedPov.h"
#include "Tacka.h"
using namespace std;

template <class T>
void funkcijaStek(T obj) {
	int odabir = 0;	
	int broj = 0;
	do
	{
		cout << "1. Dodaj " << endl <<
			"2. Ukloni" << endl <<
			"3. Print" << endl <<
			"4. Sve ukloni " << endl;
		cout << "ODABERITE OPCIJU: " << endl;
		cin >> odabir;
		switch (odabir)
		{
		case 1:
			cout << "Unesite broj koji zelite dodati : " << endl;
			cin >> broj;
			obj.dodaj(broj);
			broj = 0;
			break;
		case 2:
			try
			{
				cout << "Uklonjeni broj --> " << obj.ukloni() << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 3:
			obj.print();
			/*for (int i = 0; i < obj.get_brojac(); ++i)
			{
				cout << obj.get(i) << " ";
			}
			cout << endl;*/
			break;
		case 4:
			obj.sveUkloni();
			break;

		default:
			break;
		}
	} while (odabir != 7);
}

template <class T>
void funkcijaRed(Red<T>* obj) {
	int odabir = 0;
	int broj = 0;
	do
	{
		cout << "1. Dodaj " << endl <<
			"2. Ukloni" << endl <<
			"3. Print" << endl <<
			"4. Sve ukloni " << endl;
		cout << "ODABERITE OPCIJU: " << endl;
		cin >> odabir;
		switch (odabir)
		{
		case 1:
			cout << "Unesite broj koji zelite dodati : " << endl;
			cin >> broj;
			try
			{
				obj->dodaj(broj);

			}
			catch (const std::exception & ex)
			{
				cout << ex.what();
			}
			broj = 0;
			break;
		case 2:
			try
			{
				cout << "Uklonjeni broj --> " << obj->ukloni() << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 3:
			try
			{
			obj->print();

			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			/*for (int i = 0; i < obj.get_brojac(); ++i)
			{
				cout << obj.get(i) << " ";
			}
			cout << endl;*/
			break;
		case 4:
			obj->ukloniSve();
			break;

		default:
			break;
		}
	} while (odabir != 7);
}

template <class T>
void funkcijaPrioritetniRed(PrioritetniRed<T>* obj) {
	int odabir = 0;
	int broj = 0;
	do
	{
		cout << "1. Dodaj " << endl <<
			"2. Ukloni" << endl <<
			"3. Print" << endl <<
			"4. Sve ukloni " << endl;
		cout << "ODABERITE OPCIJU: " << endl;
		cin >> odabir;
		switch (odabir)
		{
		case 1:
			cout << "Unesite broj koji zelite dodati: " << endl;
			cin >> broj;
			try
			{
				obj->dodaj(broj);

			}
			catch (const std::exception & ex)
			{
				cout << ex.what();
			}
			broj = 0;
			break;
		case 2:
			try
			{
				cout << "Uklonjeni broj --> " << obj->ukloni() << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 3:
			try
			{
				obj->print();

			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}
			/*for (int i = 0; i < obj.get_brojac(); ++i)
			{
				cout << obj.get(i) << " ";
			}
			cout << endl;*/
			break;
		case 4:
			//obj->ukloniSve();
			while (!obj->jel_prazna())
			{
				cout << "Uklonjeni element --->" << obj->ukloni() << endl;
			}
			break;

		default:
			break;
		}
	} while (odabir != 7);
}

void main() {

	int odabir = 0;
	int broj = 0;
	//ListaSekv obj;
	ListaPov<int> obj;
	//StekPov<int>obj;
	/*StekSekv<int>obj;
	funkcijaStek(obj);*/

	/*Red<int>* red1 = new RedPov<int>;
	Red<int>* red2 = new RedSekv<int>;
	funkcijaRed(red2);*/
	/*red1->dodaj(10);
	red1->dodaj(20);
	red1->print();*/

	/*PrioritetniRed<int>* red = new PrioritetniRedSekv<int>;
	funkcijaPrioritetniRed(red);*/
	
	/*PrioritetniRed<int>* red = new PrioritetniRedPov<int>;
	funkcijaPrioritetniRed(red);*/

	PrioritetniRed<Tacka>* prs = new PrioritetniRedSekv<Tacka>;
	Tacka tacka1(5, 5);
	Tacka tacka2(8, 3);
	Tacka tacka3(2, 9);
	Tacka tacka4(9, 1);
	
	prs->dodaj(tacka1);
	prs->dodaj(tacka2);
	prs->dodaj(tacka3);
	prs->dodaj(tacka4);

	int index;
	try
	{
		
		cout << "tacka1 : " << tacka1.udaljenostOdCentra() << endl;
		cout << "tacka2 : " << tacka2.udaljenostOdCentra() << endl;
		cout << "tacka3 : " << tacka3.udaljenostOdCentra() << endl;
		cout << "tacka4 : " << tacka4.udaljenostOdCentra() << endl;
		cout << prs->ukloni() << endl;
		cout << prs->ukloni() << endl;
		cout << prs->ukloni() << endl;
		cout << prs->ukloni() << endl;
		cout << prs->ukloni() << endl;
	}
	catch (const std::exception & ex)
	{
		cout << ex.what() << endl;
	}




	


	//do
	//{
	//	cout << "1. Dodaj na pocetak"<<endl<<
	//		"2. Dodaj na kraj" << endl <<
	//		"3. Ukloni sa pocetka"<<endl<<	
	//		"4. Ukloni sa kraja"<<endl<<
	//		"5. Print"<<endl<<	
	//		"6. Sve ukloni "<< endl;
	//	cout << "ODABERITE OPCIJU: " << endl;
	//	cin >> odabir;
	//	switch (odabir)
	//	{
	//	case 1:
	//		cout << "Unesite broj koji zelite dodati na pocetak: " << endl;
	//		cin >> broj;
	//		obj.dodajNaPocetak(broj);
	//		broj = 0;
	//		break;
	//	case 2:
	//		cout << "Unesite broj koji zelite dodati na kraj: " << endl;
	//		cin >> broj;
	//		obj.dodajNaKraj(broj);
	//		broj = 0;
	//		break;
	//	case 3:
	//		try
	//		{
	//			cout << "Uklonjeni broj --> " << obj.ukloniSaPocetka() << endl;
	//		}
	//		catch (const std::exception & ex)
	//		{
	//			cout << ex.what() << endl;
	//		}
	//		break;

	//	case 4:
	//		cout << "Uklonjeni broj --> " << obj.ukloniSaKraja() << endl;
	//		break;
	//	case 5:
	//		obj.print();
	//		/*for (int i = 0; i < obj.get_brojac(); ++i)
	//		{
	//			cout << obj.get(i) << " ";
	//		}
	//		cout << endl;*/
	//		break;
	//	case 6:
	//		obj.sveUkloni();
	//		break;

	//	default:
	//		break;
	//	}
	//} while (odabir!=7);

	cout << ":::KRAJ PROGRAMA:::" << endl;
	system("pause");
}