#pragma once
#include "Uzytkownik.h"
#include <vector>
#include <fstream>
#include <conio.h>

class BazaUzytkownikow
{
private:
	vector <Uzytkownik> bazaUzytkownikow;

public:
	void Serializuj();
	void Deserializuj();
	void Wyswietl();
	void Dodaj();
	void Znajdz(string szukany);
	void Usun(string szukany);
};