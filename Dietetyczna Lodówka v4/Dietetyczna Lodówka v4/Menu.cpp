#include "Menu.h"


void Menu::Start(BazaUzytkownikow baza)
{
	int wybor;
	string login;
	int numer;
	cout << "Witaj w programie Dietetyczna lod�wka" << endl;
	do
	{
		cout << "1. Logowanie" << endl;
		cout << "2. Usuwanie profil�w" << endl;
		cout << "Inne. Wyjdz z programu" << endl;
		cin >> wybor;
		system("CLS");
		switch(wybor)
		{
			case 1:
				numer = baza.Logowanie();
				if(numer>=0)
					Zalogowany(baza.getUzytkownik(numer));

				system("CLS");
				break;
			case 2:
				cout << "Podaj login do usuniecia" << endl;
				cin >> login;
				baza.Usun(login);
				system("CLS");
				break;
		}
	}
	while(wybor==1 || wybor == 2);
}

void Menu::Zalogowany(Uzytkownik uzytkownik)
{
	int wybor;
	int ilosc;
	string nazwa;
	do
	{
		cout << "1. Dodaj produkt" << endl;
		cout << "2. Zobacz zawartosc lodowki" << endl;
		cout << "3. Twoj kalendarz" << endl;
		cout << "4. Usu� produkt" << endl;
		cout << "Inny. Wyloguj" << endl;
		cin >> wybor;

		switch(wybor)
		{
		case 1:
			system("CLS");
			DodajJedzenie(uzytkownik);
			system("CLS");
			break;
		case 2:
			system("CLS");
			uzytkownik.ZwrocMagazyn().Filtruj(uzytkownik.ZwrocLogin());
			break;

		case 3:


			system("CLS");
			break;
		case 4:
			uzytkownik.ZwrocMagazyn().Filtruj(uzytkownik.ZwrocLogin());
			cout << "Co chcesz usunac?" << endl;
			cin >> nazwa;
			cout << "Ile?" << endl;
			cin >> ilosc;

			

	
			for(int i=0; i<uzytkownik.ZwrocMagazyn().getBaza().size(); i++)
			{
				if(uzytkownik.ZwrocMagazyn().getBaza()[i]->ZwrocNazwa() == nazwa)
				{
					if(uzytkownik.ZwrocMagazyn().getBaza()[i]->ZwrocIlosc() < ilosc)
					{
						cout<<"Nie masz tyle produktu"<<endl;
					}
					else if(uzytkownik.ZwrocMagazyn().getBaza()[i]->ZwrocIlosc() == ilosc)
					{
						uzytkownik.ZwrocMagazyn().getBaza().erase(uzytkownik.ZwrocMagazyn().getBaza().begin()+i);
					}
					else if(uzytkownik.ZwrocMagazyn().getBaza()[i]->ZwrocIlosc() > ilosc)
					{
						uzytkownik.ZwrocMagazyn().getBaza()[i]->UstawIlosc(uzytkownik.ZwrocMagazyn().getBaza()[i]->ZwrocIlosc()-ilosc);
					}
				}
			}
			
			uzytkownik.ZwrocMagazyn().Serializuj(uzytkownik.ZwrocLogin());

			system("CLS");
			break;
		}
	}
	while(wybor == 1 || wybor == 2 || wybor == 3 );
}

void Menu::DodajJedzenie(Uzytkownik uzytkownik)
{
	int wybor;
	string nazwa;
	int kalorie;
	float bialko;
	float weglowodany;
	float tluszcze;
	int ilosc;
	int jednostka;

	uzytkownik.ZwrocMagazyn().Deserializuj(uzytkownik.ZwrocLogin());

	cout << "1. Mieso" << endl;
	cout << "2. Nabial" << endl;
	cout << "3. Napoje" << endl;
	cout << "4. Owoce" << endl;
	cout << "5. Suchy Prowiant" << endl;
	cout << "6. Warzywa" << endl;
	cin >> wybor;

	cout << "Nazwa" << endl;
	cin  >> nazwa;
	cout << "Kalorie" << endl;
	cin  >> kalorie;
	cout << "Bialko" << endl;
	cin  >> bialko;
	cout << "Weglowodany" << endl;
	cin  >> weglowodany;
	cout << "Tluszcze" << endl;
	cin  >> tluszcze;
	cout << "Ilosc" << endl;
	cin  >> ilosc;
	switch(wybor)
	{
	case 1:
		uzytkownik.ZwrocMagazyn().Dodaj(new Mieso(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg, obiad), uzytkownik.ZwrocLogin());
		system("CLS");
		break;
	case 2:
		cout << "Jednostka  =  0.kg  /  1.ml" << endl;
		cin  >> jednostka;
		if(jednostka == 0)
			uzytkownik.ZwrocMagazyn().Dodaj(new Nabial(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg, obiad), uzytkownik.ZwrocLogin());
		if(jednostka == 1)
			uzytkownik.ZwrocMagazyn().Dodaj(new Nabial(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, ml, obiad),uzytkownik.ZwrocLogin());

		system("CLS");
		break;

	case 3:
		uzytkownik.ZwrocMagazyn().Dodaj(new Napoje(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, ml, obiad),uzytkownik.ZwrocLogin());
		system("CLS");
		break;

	case 4:
		uzytkownik.ZwrocMagazyn().Dodaj(new Owoce(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg, obiad),uzytkownik.ZwrocLogin());

		system("CLS");
		break;
	case 5:
		uzytkownik.ZwrocMagazyn().Dodaj(new Prowiant(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg, obiad),uzytkownik.ZwrocLogin());
		system("CLS");
		break;

	case 6:
		uzytkownik.ZwrocMagazyn().Dodaj(new Warzywa(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg, obiad),uzytkownik.ZwrocLogin());
		system("CLS");
		break;
	}

}
