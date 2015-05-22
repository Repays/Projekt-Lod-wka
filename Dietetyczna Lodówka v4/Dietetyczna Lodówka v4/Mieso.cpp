#include "Mieso.h"

Mieso::	Mieso(const string nazwa, const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka, const posilek danie)
{
	UstawId(mieso);
	Inicjalizacja(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, jednostka, danie);
}

void Mieso::Wyswietl()
{
	printf("%s %d %.2f %.2f %.2f ", ZwrocNazwa().c_str(), ZwrocKalorie(), ZwrocBialko(), ZwrocWeglowodany(), ZwrocTluszcze());
	if(jednostka == kg)
		printf("%dkg\n",ZwrocIlosc());
	else
		printf("%dml\n",ZwrocIlosc());
}

