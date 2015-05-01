#include "Mieso.h"

Mieso::	Mieso(const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
{
	UstawId(mieso);
	Inicjalizacja(kalorie, bialko, weglowodany, tluszcze, ilosc, jednostka);
}

void Mieso::Wyswietl()
{
	printf("%d %.2f %.2f %.2f ", kalorie, bialko, weglowodany, tluszcze);
	if(jednostka == kg)
		printf("%dkg\n",ilosc);
	else
		printf("%dml\n",ilosc);
}

