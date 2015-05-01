#pragma once
#include <stdio.h>
#include "Stale.h"

class Jedzenie
{
protected:
	ID id;
	int kalorie;
	float bialko;
	float weglowodany;
	float tluszcze;
	int ilosc;
	jednoski jednostka;

public:
	virtual void Inicjalizacja(const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
	{
		this->kalorie = kalorie;
		this->bialko = bialko;
		this->weglowodany = weglowodany;
		this->tluszcze = tluszcze;
		this->ilosc = ilosc;
		this->jednostka = jednostka;
	}

	int ZwrocKalorie() const {return kalorie;}
	float ZwrocBialko() const {return bialko;}
	float ZwrocWeglowodany() const {return weglowodany;}
	float ZwrocTluszcze() const {return tluszcze;}
	int ZwrocIlosc() const {return ilosc;}
	jednoski ZwrocJednostka() const {return jednostka;}
	ID ZwrocId() const {return id;}

	void UstawKalorie(const int kalorie)
	{
		this->kalorie = kalorie;
	}

	void UstawBialko(const float bialko)
	{
		this->bialko = bialko;
	}

	void UstawWeglowodany(const float weglowodany)
	{
		this->weglowodany = weglowodany;
	}

	void UstawTluszcze(const float tluszcze)
	{
		this->tluszcze = tluszcze;
	}

	void UstawJednostka(const jednoski jednostka)
	{
		this->jednostka = jednostka;
	}

	void UstawIlosc(const int ilosc)
	{
		this->ilosc = ilosc;
	}

	void UstawId(const ID id)
	{
		this->id = id;
	}

	virtual void Wyswietl() =0;



	virtual ~Jedzenie(){}
};