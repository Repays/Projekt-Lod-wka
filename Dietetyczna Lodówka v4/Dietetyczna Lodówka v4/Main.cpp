#include "BazaUzytkownikow.h"
#include "Blad.h"
#include "Magazyn.h"
using namespace std;

int main()
{
	try
	{
	BazaUzytkownikow users;
	users.Deserializuj();

	//users.Dodaj();
	//users.Dodaj();
	
	//users.Znajdz("ALEK");
	//users.Znajdz("JANUSZ");
	//users.Znajdz("NI MA GO");

	//users.Usun("JANUSZ");

	users.Wyswietl();
	

	vector<Jedzenie*> tab;
	//Jedzenie *a = new Mieso(1000,10,10,10,500,ml);
	//Jedzenie *b = new Nabial(1000,10,10,10,500,ml);
	//Jedzenie *c = new Napoje(1000,10,10,10,500,ml);
	//Jedzenie *d = new Owoce(1000,10,10,10,500,ml);
	//Jedzenie *e = new Prowiant(1000,10,10,10,500,ml);
	//Jedzenie *g = new Warzywa(1000,10,10,10,500,ml);

	Magazyn magazynek;

	/*tab.push_back(a);
	tab.push_back(b);
	tab.push_back(c);
	tab.push_back(d);
	tab.push_back(e);
	tab.push_back(g);*/

	//magazynek.Dodaj(a);
	//magazynek.Dodaj(b);
	//magazynek.Dodaj(c);
	//magazynek.Dodaj(d);
	//magazynek.Dodaj(e);
	//magazynek.Dodaj(g);

	magazynek.Deserializuj();

	magazynek.Wyswietl();


	}catch(Blad blad)
	{
		cout<<blad.ZwrocWiadomosc();
	}


	_getch();
	return 0;
}