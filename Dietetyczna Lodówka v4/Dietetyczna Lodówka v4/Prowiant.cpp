#include "Prowiant.h"

Prowiant:: Prowiant(const string nazwa, const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
{
	UstawId(suchy_prowiant);
	Inicjalizacja(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, jednostka);
}

void Prowiant::Wyswietl()
{
	printf("%s %d %.2f %.2f %.2f ", ZwrocNazwa().c_str(), ZwrocKalorie(), ZwrocBialko(), ZwrocWeglowodany(), ZwrocTluszcze());
	if(jednostka == kg)
		printf("%dkg\n",ZwrocIlosc());
	else
		printf("%dml\n",ZwrocIlosc());
}