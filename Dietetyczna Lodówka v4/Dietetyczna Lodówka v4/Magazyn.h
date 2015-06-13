#pragma once
#include "Jedzenie.h"
#include "Mieso.h"
#include "Nabial.h"
#include "Napoje.h"
#include "Owoce.h"
#include "Prowiant.h"
#include "Warzywa.h"
#include "Blad.h"
#include <vector>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Magazyn
{
private:
	vector<Jedzenie*> bazaJedzenia;

public:
	Magazyn(string login){Deserializuj(login);};
	void Serializuj(string login);
	void Deserializuj(string login);
	void Wyswietl();
	void Dodaj(Jedzenie *obiekt, string login);
	void Znajdz(string szukany);
	void Usun(string szukany);
	void Filtruj(string login);
	vector<Jedzenie*> getBaza(){return bazaJedzenia;}
};
