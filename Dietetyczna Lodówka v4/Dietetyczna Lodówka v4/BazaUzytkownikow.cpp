#include "BazaUzytkownikow.h"

void BazaUzytkownikow::Serializuj()
{
	fstream plik;
	plik.open("pliki//BazaUzytkownikow.csv",std::ios::out);
	if(plik!=0)
	{
		for(int i=0; i<bazaUzytkownikow.size(); i++)
		{
			plik << bazaUzytkownikow[i].ZwrocLogin().c_str() << ";" << bazaUzytkownikow[i].ZwrocImie().c_str() << ";" << bazaUzytkownikow[i].ZwrocNazwisko().c_str() << ";" << bazaUzytkownikow[i].ZwrocWiek() 
				<< ";" << bazaUzytkownikow[i].ZwrocWaga() << ";" << bazaUzytkownikow[i].ZwrocWzrost() << endl;
		}
		plik.close();
		cout << "Baza uzytkownikow zostala zapisana!" << endl;
	}
	else
		printf("Blad z zapisem");
}

void BazaUzytkownikow::Deserializuj()	
{
	string dana1, dana2, dana3, dana4, dana5, dana6;
	char separator = ';';
	char koniec = '\n';
	fstream plik;
	plik.open("pliki//BazaUzytkownikow.csv");
	if(plik!=0)
	{
		while(!plik.eof())
		{
			getline(plik,dana1,separator); // login
			getline(plik,dana2,separator); // imie
			getline(plik,dana3,separator); // nazwisko
			getline(plik,dana4,separator); // wiek
			getline(plik,dana5,separator); // waga
			getline(plik,dana6,koniec);    // wzrost

			if(dana1!="")
			{
				Uzytkownik obiekt(dana2,dana3,dana1,atoi(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()));
				bazaUzytkownikow.push_back(obiekt);
			}
		}
	}
	else
		throw Blad("Nie odnaleziono pliku Bazy Uzytkownikow!");
	plik.close();
}

void BazaUzytkownikow::Dodaj()
{
	vector <Uzytkownik> :: iterator iterator;
	bool poprawny=false;
	float waga;
	int wiek, wzrost;
	string login, imie, nazwisko;
	cout << "\t\tDodawanie nowego uzytkownika" << endl;

	do
	{
		cout<< "Podaj login: ";
		cin>>login;
		if(bazaUzytkownikow.size()!=0)
		{
			for(iterator=bazaUzytkownikow.begin(); iterator!=bazaUzytkownikow.end(); iterator++)
			{
				if(login!=iterator->ZwrocLogin())
					poprawny=true;
				else
				{
					poprawny=false;
					break;
				}
			}
		}
		else
			poprawny=true;
	}while(poprawny==false);

	do
	{
		cout<< "Podaj imie: ";
		cin>>imie;
	}while(imie==" ");

	do
	{
		cout<< "Podaj nazwisko: ";
		cin>>nazwisko;
	}while(nazwisko==" ");

	do
	{
		cout<< "Podaj wiek: ";
		cin>>wiek;
	}while(wiek<=0);

	do
	{
		cout<< "Podaj wzrost: ";
		cin>>wzrost;
	}while(wzrost<=0);

	do
	{
		cout<< "Podaj wage: ";
		cin>>waga;
	}while(waga<=0);

	Uzytkownik obiekt(imie,nazwisko,login,wiek,waga,wzrost);
	bazaUzytkownikow.push_back(obiekt);
	cout<< "\n\nPomyslnie dodano nowego uzytkownika!" << endl;
}

void BazaUzytkownikow::Wyswietl()
{
	cout << "\t\tBaza Uzytkownikow" << endl;
	for(int i=0; i<bazaUzytkownikow.size(); i++)
		bazaUzytkownikow[i].WysietlUzytkownika();
}

void BazaUzytkownikow::Usun(string szukany)
{
	bool znaleziono=false;
	vector <Uzytkownik> :: iterator iterator;
	int j=0;
	for(iterator=bazaUzytkownikow.begin(); iterator!=bazaUzytkownikow.end(); iterator++)
	{
		if(j==(bazaUzytkownikow.size()-1))
		{
			if(szukany == iterator->ZwrocLogin())
			{
				bazaUzytkownikow.pop_back();
				znaleziono=true;
			} else
				j++;
		} else
		{
			if(szukany == iterator->ZwrocLogin())
			{
				bazaUzytkownikow[j]=bazaUzytkownikow[bazaUzytkownikow.size()-1];
				bazaUzytkownikow.pop_back();
				znaleziono=true;
			} else
				j++;
			}
	}
	if(znaleziono==false)
		printf("Nie znaleziono uzytkownika o loginie %s !\n\n",szukany.c_str());
	else
		printf("Usunieto uzytkownika o loginie %s!\n\n",szukany.c_str());

	/*

	bool znaleziona=false;
	vector <Pracownik> ::iterator t;
	int j=0;
	for(t=listaPracownikow.begin();t!=listaPracownikow.end();t++)
	{
		if (i == t->getId())
		{
			listaPracownikow[j]=listaPracownikow[listaPracownikow.size()-1];
			listaPracownikow.pop_back();
			znaleziona=true;
		} else
			j++;
	}
	if(znaleziona==false)
		cout << "Podano bledne ID pracownika!";


	*/
}

void BazaUzytkownikow::Znajdz(string szukany)
{
	bool znaleziona=false;
	vector <Uzytkownik> ::iterator iterator;
	int j=0;
	for(iterator=bazaUzytkownikow.begin(); iterator!=bazaUzytkownikow.end(); iterator++)
	{
		if (szukany == iterator->ZwrocLogin())
		{
			iterator->WysietlUzytkownika();
			znaleziona=true;
		} 
	}
	if(znaleziona==false)
		printf("Nie znaleziono uzytkownika o loginie %s !\n\n",szukany.c_str());
}