#pragma once
#include "Jedzenie.h"


class Prowiant : public Jedzenie
{
public:
	Prowiant(const string nazwa, const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka, const posilek danie);

	void Wyswietl();
};