#include "Magazyn.h"

void Magazyn::Serializuj()
{
	fstream plik;
	plik.open("pliki//MagazynJedzenia.csv",std::ios::out);
	if(plik!=0)
	{
		for(int i=0; i<bazaJedzenia.size(); i++)
		{
			plik << bazaJedzenia[i]->ZwrocId() << ";" << bazaJedzenia[i]->ZwrocKalorie() << ";" << bazaJedzenia[i]->ZwrocBialko() << ";" << bazaJedzenia[i]->ZwrocWeglowodany() 
				<< ";" << bazaJedzenia[i]->ZwrocTluszcze() << ";" << bazaJedzenia[i]->ZwrocIlosc() << ";" << bazaJedzenia[i]->ZwrocJednostka() << ";" << bazaJedzenia[i]->ZwrocNazwa() << endl;
		}
		plik.close();
		printf("Baza jedzenia zostala zapisana!\n");
	}
	else
		printf("Blad z zapisem");
}

void Magazyn::Deserializuj()
{
	string dana1, dana2, dana3, dana4, dana5, dana6, dana7, dana8;
	char separator = ';';
	char koniec = '\n';
	fstream plik;
	plik.open("pliki//MagazynJedzenia.csv");
	if(plik!=0)
	{
		while(!plik.eof())
		{
			getline(plik,dana1,separator); // id
			getline(plik,dana2,separator); // kalorie [int]
			getline(plik,dana3,separator); // bialko
			getline(plik,dana4,separator); // weglowodany
			getline(plik,dana5,separator); // tluszcze
			getline(plik,dana6,separator);    // ilosc
			getline(plik,dana7,separator); // jednostka
			getline(plik,dana8,koniec); // nazwa
			Jedzenie *obiekt;

			if(dana1!="")
			{
			switch(atoi(dana1.c_str()))
			{
			case 0:
				{
						obiekt = new Mieso(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg);
						bazaJedzenia.push_back(obiekt);
				}break;

			case 1:
				{
					if(atoi(dana7.c_str())==0)
					{
						obiekt = new Nabial(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg);
					}
					else
					{
						obiekt = new Nabial(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),ml);
					}
					bazaJedzenia.push_back(obiekt);
				}break;

			case 2:
				{
						obiekt = new Napoje(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg);
						bazaJedzenia.push_back(obiekt);
				}break;

			case 3:
				{
						obiekt = new Owoce(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg);
						bazaJedzenia.push_back(obiekt);
					
				}break;

			case 4:
				{
						obiekt = new Prowiant(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg);
						bazaJedzenia.push_back(obiekt);
				}break;

			case 5:
				{
						obiekt = new Warzywa(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg);
						bazaJedzenia.push_back(obiekt);
				}break;
			}
			}
		}
	}
	else
		throw Blad("Nie odnaleziono pliku Bazy Uzytkownikow!");
	plik.close();
}


void Magazyn::Dodaj(Jedzenie *obiekt)
{
	bazaJedzenia.push_back(obiekt);
}

void Magazyn::Wyswietl()
{
	cout << "\t\tChuja" << endl;
	for(int i=0; i<bazaJedzenia.size(); i++)
		bazaJedzenia[i]->Wyswietl();
}