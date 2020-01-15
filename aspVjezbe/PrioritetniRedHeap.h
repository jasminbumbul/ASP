#pragma once

template <class T>
class PrioritetniRedHeap:public PrioritetniRed<T>
{
	int max_size = 10;
	int n = 0;
	T* A = new T[max_size + 1];

	void rotiraj(int i,int j) {
		swap(A[i], A[j]);
	}
public:
	void rekonstrukcijaPremaGore(int iVrh)
	{
		if (iVrh==1)
		{
			return;
		}
		int roditelji = iVrh / 2;

		if (A[iVrh]>A[roditelji])
		{
			rotiraj(iVrh, roditelji);
			rekonstrukcijaPremaGore(roditelji);
		}
	}

	virtual void dodaj(T x) 
	{
		if (jel_pun())
		{
			throw exception("Niz je pun");
		}
		n++;
		A[n] = x;
		rekonstrukcijaPremaGore(n);
	}

	void rekonstrukcijaPremaDole(int iVrh)
	{
		if (2*iVrh>n)
		{
			return;
		}

		int lijevoDijete = iVrh * 2;
		int desnoDijete = iVrh * 2 + 1;

		int max = iVrh;
		if (A[lijevoDijete]>A[iVrh])
		{
			max = lijevoDijete;
		}
		if (2 * iVrh + 1 >= n && A[desnoDijete]>A[max])
		{
			max = desnoDijete;
		}
		if (max!=iVrh)
		{
			rotiraj(max, iVrh);
			rekonstrukcijaPremaDole(max);
		}


	}
	virtual T ukloni() 
	{
		if (jel_prazna())
		{
			throw exception("Niz je prazan");
		}
		T temp = A[1];
		A[1] = A[n];
		n--;
		rekonstrukcijaPremaDole(1);
		return temp;
	}
	virtual bool jel_prazna() 
	{
		return n == 0;
	}
	virtual bool jel_pun() 
	{
		return n == max_size;
	}
	virtual void print() 
	{
		if (jel_prazna())
		{
			throw exception("Niz je prazan");
		}
		for (size_t i = 1; i < n; i++)
		{
			cout << A[i] << "  ";
		}
		cout << endl;
	}
	
};