#pragma once
#include <stdio.h>
#include "Stale.h"
#include "Blad.h"
#include <vector>

class Informacje
{
private:

	int ilosc;
	string nazwa;
	float kaloria;

public:
	Informacje(int ilosc, string nazwa, float kaloria):ilosc(ilosc), nazwa(nazwa), kaloria(kaloria){}
	Informacje(){}

	Informacje & Informacje::operator = (Informacje &info)
	{
		ilosc = info.ZwrocIlosc();
		nazwa = info.ZwrocNazwe();
		kaloria = info.ZwrocKaloria();
		return *this;
	}

	int ZwrocIlosc() {return ilosc;}
	float ZwrocKaloria() {return kaloria;}
	string ZwrocNazwe() {return nazwa;}

};