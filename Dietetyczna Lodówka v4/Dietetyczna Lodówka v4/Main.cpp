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
		users.Wyswietl();
		users.Logowanie();
		//users.Serializuj();




		
		/*
		users.Deserializuj();

		users.Dodaj();
		users.Dodaj();

		users.Znajdz("ALEK");

		users.Usun("JANUSZ");

		users.Wyswietl();
		*/

		Magazyn magazynek;

		/*Jedzenie *a = new Mieso("szynka",450,34,554,345,432,kg,sniad_kol);
		Jedzenie *b = new Nabial("mleko",100,100,40,130,50,ml,sniad_kol);
		Jedzenie *c = new Napoje("sok jablkowy",430,160,50,210,5500,ml,sniad_kol);
		Jedzenie *d = new Owoce("Grapefruit",70,70,50,30,70,kg,sniad_kol);
		Jedzenie *e = new Prowiant("Ryz",1000,10,10,10,500,kg,obiad);
		Jedzenie *g = new Warzywa("Ziemniak",100,100,100,100,50,kg,obiad);	

		magazynek.Dodaj(a);
		magazynek.Dodaj(b);
		magazynek.Dodaj(c);
		magazynek.Dodaj(d);
		magazynek.Dodaj(e);
		magazynek.Dodaj(g);*/

		//magazynek.Serializuj();
		magazynek.Deserializuj();
		//magazynek.Wyswietl();
		magazynek.Filtruj();


	}catch(Blad blad)
	{
		cout<<blad.ZwrocWiadomosc();
	}


	_getch();
	return 0;
}