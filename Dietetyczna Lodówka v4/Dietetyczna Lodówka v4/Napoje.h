#pragma once
#include "Jedzenie.h"


class Napoje : public Jedzenie
{
public:
	Napoje(const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka);

	void Wyswietl();
};