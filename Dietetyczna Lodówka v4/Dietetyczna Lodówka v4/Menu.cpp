#include "Menu.h"


void Menu::Start(BazaUzytkownikow baza)
{
	int wybor;
	string login;
	int numer;
	cout << "\tWitaj w programie Dietetyczna lodowka" << endl << endl;
	do
	{
		cout << "1. Logowanie" << endl;
		cout << "2. Usuwanie profilow" << endl;
		cout << "Inne. Wyjdz z programu" << endl;
		cout << "Twoj wybor: ";
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
				cout << "Podaj login do usuniecia: ";
				cin >> login;
				baza.Usun(login);
				baza.Serializuj();
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
	uzytkownik.Serializuj();
	do
	{
		cout << "1. Dodaj produkt" << endl;
		cout << "2. Zobacz zawartosc lodowki" << endl;
		cout << "3. Twoj kalendarz" << endl;
		cout << "4. Usun produkt" << endl;
		cout << "Inny. Wyloguj" << endl;
		cout << "Twoj wybor: ";
		cin >> wybor;

		switch(wybor)
		{
		case 1:
			system("CLS");
			DodajJedzenie(&uzytkownik);
			system("CLS");
			break;
		case 2:
			system("CLS");
			uzytkownik.Filtruj();
			cout << endl;
			break;

		case 3:
			system("CLS");
			break;
		case 4:
			system("CLS");
			uzytkownik.Filtruj();
			cout << endl << "Podaj nazwe do usuniecia: ";
			cin >> nazwa;
			cout << "Podaj ilosc do usuniecia: ";
			cin >> ilosc;
				
			for(int i=0; i<uzytkownik.getBaza().size(); i++)
			{
				if(uzytkownik.getBaza()[i]->ZwrocNazwa() == nazwa)
				{
					if(uzytkownik.getBaza()[i]->ZwrocIlosc() < ilosc)
					{
						cout<<"Nie masz tyle produktu!"<<endl;
						break;
					}
					else if(uzytkownik.getBaza()[i]->ZwrocIlosc() == ilosc)
					{
						uzytkownik.getBaza().erase(uzytkownik.getBaza().begin()+i);
						uzytkownik.Serializuj();
					}
					else if(uzytkownik.getBaza()[i]->ZwrocIlosc() > ilosc)
					{
						uzytkownik.getBaza()[i]->UstawIlosc(uzytkownik.getBaza()[i]->ZwrocIlosc()-ilosc);
						uzytkownik.Serializuj();
					}
				}
			}
			system("CLS");
		}
	}
	while(wybor == 1 || wybor == 2 || wybor == 3 ||  wybor == 4 );
}

void Menu::DodajJedzenie(Uzytkownik *uzytkownik)
{
	int wybor;
	string nazwa;
	int kalorie;
	float bialko;
	float weglowodany;
	float tluszcze;
	int ilosc;
	int jednostka;

	cout << "1. Mieso" << endl;
	cout << "2. Nabial" << endl;
	cout << "3. Napoje" << endl;
	cout << "4. Owoce" << endl;
	cout << "5. Suchy Prowiant" << endl;
	cout << "6. Warzywa" << endl;
	cout << "Twoj wybor: ";
	cin >> wybor;

	cout << endl << "Nazwa: ";
	cin>>nazwa;
	cout << "Kalorie: ";
	cin  >> kalorie;
	cout << "Bialko: ";
	cin  >> bialko;
	cout << "Weglowodany: ";
	cin  >> weglowodany;
	cout << "Tluszcze: ";
	cin  >> tluszcze;
	cout << "Ilosc: ";
	cin  >> ilosc;
	switch(wybor)
	{
	case 1:
		uzytkownik->Dodaj(new Mieso(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg));
		system("CLS");
		break;
	case 2:
		cout << "Jednostka (0.kg  /  1.ml): ";
		cin  >> jednostka;
		if(jednostka == 0)
			uzytkownik->Dodaj(new Nabial(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg));
		if(jednostka == 1)
			uzytkownik->Dodaj(new Nabial(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, ml));

		system("CLS");
		break;

	case 3:
		uzytkownik->Dodaj(new Napoje(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, ml));
		system("CLS");
		break;

	case 4:
		uzytkownik->Dodaj(new Owoce(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg));

		system("CLS");
		break;
	case 5:
		uzytkownik->Dodaj(new Prowiant(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg));
		system("CLS");
		break;

	case 6:
		uzytkownik->Dodaj(new Warzywa(nazwa, kalorie, bialko, weglowodany, tluszcze, ilosc, kg));
		system("CLS");
		break;
	}
	uzytkownik->Serializuj();

}
