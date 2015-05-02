#pragma once
#include <stdio.h>
#include "Stale.h"
#include "Blad.h"

class Jedzenie
{
protected:
	ID id;
	string nazwa;
	int kalorie;
	float bialko;
	float weglowodany;
	float tluszcze;
	int ilosc;
	jednoski jednostka;

public:
	virtual void Inicjalizacja(const string nazwa, const int kalorie,const float bialko,const float weglowodany,const float tluszcze,const int ilosc,const jednoski jednostka)
	{
		UstawNazwa(nazwa);
		UstawKalorie(kalorie);
		UstawBialko(bialko);
		UstawWeglowodany(weglowodany);
		UstawTluszcze(tluszcze);
		UstawJednostka(jednostka);
		UstawIlosc(ilosc);
	}

	string ZwrocNazwa() const {return nazwa;}
	int ZwrocKalorie() const {return kalorie;}
	float ZwrocBialko() const {return bialko;}
	float ZwrocWeglowodany() const {return weglowodany;}
	float ZwrocTluszcze() const {return tluszcze;}
	int ZwrocIlosc() const {return ilosc;}
	jednoski ZwrocJednostka() const {return jednostka;}
	ID ZwrocId() const {return id;}

	void UstawNazwa(const string nazwa)
	{
		if(nazwa=="")
			throw Blad("Nazwa jedzenia jest pusta!");
		else
			this->nazwa=nazwa;
	}

	void UstawKalorie(const int kalorie)
	{
		if(kalorie<0)
			throw Blad("Bledna wartosc kalorii!");
		else
			this->kalorie = kalorie;
	}

	void UstawBialko(const float bialko)
	{
		if(bialko<0)
			throw Blad("Bledna wartosc bialka!");
		else
			this->bialko = bialko;
	}

	void UstawWeglowodany(const float weglowodany)
	{
		if(weglowodany<0)
			throw Blad("Bledna wartosc weglowodanow!");
		else
			this->weglowodany = weglowodany;
	}

	void UstawTluszcze(const float tluszcze)
	{
		if(tluszcze<0)
			throw Blad("Bledna wartosc tluszczy!");
		else
			this->tluszcze = tluszcze;
	}

	void UstawJednostka(const jednoski jednostka)
	{
		if(jednostka == 0 || jednostka == 1)
			this->jednostka = jednostka;
		else
			throw Blad("Bledna wartosc jednostki!");
	}

	void UstawIlosc(const int ilosc)
	{
		if(ilosc<=0)
			throw Blad("Bledna wartosc ilosci!");
		else
			this->ilosc = ilosc;
	}

	void UstawId(const ID id)
	{
		if(id>=0 && id<=5)
			this->id = id;
		else
			throw Blad("Bledna wartosc id");
	}

	virtual void Wyswietl() =0;

	virtual ~Jedzenie(){}
};