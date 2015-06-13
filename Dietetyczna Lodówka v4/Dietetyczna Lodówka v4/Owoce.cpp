#include "Owoce.h"

Owoce:: Owoce(const string nazwa, const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
{
	UstawId(owoce);
	Inicjalizacja(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, jednostka);
}

void Owoce::Wyswietl()
{
	printf("%s %d %.2f %.2f %.2f ", ZwrocNazwa().c_str(), ZwrocKalorie(), ZwrocBialko(), ZwrocWeglowodany(), ZwrocTluszcze());
	if(jednostka == kg)
		printf("%dkg\n",ZwrocIlosc());
	else
		printf("%dml\n",ZwrocIlosc());
}