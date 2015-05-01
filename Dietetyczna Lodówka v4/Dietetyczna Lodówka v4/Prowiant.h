#pragma once
#include "Jedzenie.h"


class Prowiant : public Jedzenie
{
public:
	Prowiant(const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka);

	void Wyswietl();
};