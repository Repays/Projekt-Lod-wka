#pragma once
#include "Blad.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "Jedzenie.h"
#include <vector>
#include "Magazyn.h"
using namespace std;

class Uzytkownik
{
private:
	string imie;
	string nazwisko;
	string login;
	unsigned int wiek;
	float waga;
	unsigned int wzrost;
	Magazyn *magazyn;
public:
	Uzytkownik(const string _imie, const string _nazwisko, const string _login, const unsigned int _wiek, const float _waga, const unsigned int _wzrost);
	Uzytkownik(){};
	void UstawImie(const string _imie);
	void UstawNazwisko(const string _nazwisko);
	void UstawLogin(const string _login);
	void UstawWiek(const unsigned int _wiek);
	void UstawWaga(const float _waga);
	void UstawWzrost(const unsigned int _wzrost);

	string ZwrocImie() const {return imie;}
	string ZwrocNazwisko() const {return nazwisko;}
	string ZwrocLogin() const {return login;}
	unsigned int ZwrocWiek() const {return wiek;}
	float ZwrocWaga() const {return waga;}
	unsigned int ZwrocWzrost() const {return wzrost;}
	Magazyn ZwrocMagazyn() const {return *magazyn;}

	void WysietlUzytkownika() const;
};