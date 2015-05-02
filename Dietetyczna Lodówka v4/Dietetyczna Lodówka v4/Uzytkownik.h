#pragma once
#include "Blad.h"
#include <stdio.h>
#include <string>
#include <iostream>
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

public:
	Uzytkownik(const string _imie, const string _nazwisko, const string _login, const unsigned int _wiek, const float _waga, const unsigned int _wzrost);

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

	void WysietlUzytkownika() const;
};