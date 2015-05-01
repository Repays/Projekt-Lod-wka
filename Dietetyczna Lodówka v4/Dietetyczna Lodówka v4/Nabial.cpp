#include "Nabial.h"

Nabial:: Nabial(const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
{
	UstawId(nabial);
	Inicjalizacja(kalorie, bialko, weglowodany, tluszcze, ilosc, jednostka);
}

void Nabial::Wyswietl()
{
	printf("%d %.2f %.2f %.2f ", kalorie, bialko, weglowodany, tluszcze);
	if(jednostka == kg)
		printf("%dkg\n",ilosc);
	else
		printf("%dml\n",ilosc);
}

