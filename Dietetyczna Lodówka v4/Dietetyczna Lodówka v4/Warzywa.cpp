#include "Warzywa.h"

Warzywa:: Warzywa(const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
{
	UstawId(warzywa);
	Inicjalizacja(kalorie, bialko, weglowodany, tluszcze, ilosc, jednostka);
}

void Warzywa::Wyswietl()
{
	printf("%d %.2f %.2f %.2f ", kalorie, bialko, weglowodany, tluszcze);
	if(jednostka == kg)
		printf("%dkg\n",ilosc);
	else
		printf("%dml\n",ilosc);
}