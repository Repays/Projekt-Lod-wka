#pragma once
#include "Stale.h"
#include "Jedzenie.h"
#include <vector>
#include "Informacje.h"

class Plan
{
private:
	dni dzien;
	float kalorie;
	vector<Informacje*> info;
	//Informacje info1[100];

public:
	Plan(int _dzien, float kalorie):kalorie(kalorie)
	{

		if(_dzien == 0)
			dzien = poniedzialek;
		if(_dzien == 1)
			dzien = wtorek;
		if(_dzien == 2)
			dzien = sroda;
		if(_dzien == 3)
			dzien = czwartek;
		if(_dzien == 4)
			dzien = piatek;
		if(_dzien == 5)
			dzien = sobota;
		if(_dzien == 6)
			dzien = niedziela;
	}

	void DodajInfo(Informacje *informacje) {info.push_back(informacje);}
	vector<Informacje*> getInfo() const {return info;}

	int ZwrocWielkosc() {return info.size();}
	float ZwrocKalorie() const {return kalorie;}
};