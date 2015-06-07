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
				<< ";" << bazaJedzenia[i]->ZwrocTluszcze() << ";" << bazaJedzenia[i]->ZwrocIlosc() << ";" << bazaJedzenia[i]->ZwrocJednostka() << ";" << bazaJedzenia[i]->ZwrocNazwa() << ";" << bazaJedzenia[i]->ZwrocDanie() << endl;
		}
		plik.close();
		printf("Baza jedzenia zostala zapisana!\n");
	}
	else
		printf("Blad z zapisem");
}

void Magazyn::Deserializuj()
{
	string dana1, dana2, dana3, dana4, dana5, dana6, dana7, dana8, dana9;
	posilek danie;
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
			getline(plik,dana6,separator); // ilosc
			getline(plik,dana7,separator); // jednostka
			getline(plik,dana8,separator); // nazwa
			getline(plik,dana9,koniec); // danie
			Jedzenie *obiekt;

			if(atoi(dana9.c_str())==0)
				danie=sniadanie;
			if(atoi(dana9.c_str())==1)
				danie=obiad;
			if(atoi(dana9.c_str())==2)
				danie=kolacja;
			if(atoi(dana9.c_str())==3)
				danie=sniad_kol;

			if(dana1!="")
			{
			switch(atoi(dana1.c_str()))
			{
			case 0:
				{
						obiekt = new Mieso(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg,danie);
						bazaJedzenia.push_back(obiekt);
				}break;

			case 1:
				{
					if(atoi(dana7.c_str())==0)
					{
						obiekt = new Nabial(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg,danie);
					}
					else
					{
						obiekt = new Nabial(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),ml,danie);
					}
					bazaJedzenia.push_back(obiekt);
				}break;

			case 2:
				{
						obiekt = new Napoje(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg,danie);
						bazaJedzenia.push_back(obiekt);
				}break;

			case 3:
				{
						obiekt = new Owoce(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg,danie);
						bazaJedzenia.push_back(obiekt);
					
				}break;

			case 4:
				{
						obiekt = new Prowiant(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg,danie);
						bazaJedzenia.push_back(obiekt);
				}break;

			case 5:
				{
						obiekt = new Warzywa(dana8.c_str(),atoi(dana2.c_str()),atof(dana3.c_str()),atof(dana4.c_str()),atof(dana5.c_str()),atoi(dana6.c_str()),kg,danie);
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

void Magazyn::Filtruj()
{
	printf("\tMieso\n");
	for(int i=0; i<bazaJedzenia.size(); i++)
	{
		if(mieso==bazaJedzenia[i]->ZwrocId())
			bazaJedzenia[i]->Wyswietl();
	}

	printf("\n\tNabial\n");
	for(int i=0; i<bazaJedzenia.size(); i++)
	{
		if(nabial==bazaJedzenia[i]->ZwrocId())
			bazaJedzenia[i]->Wyswietl();
	}

	printf("\n\tNapoje\n");
	for(int i=0; i<bazaJedzenia.size(); i++)
	{
		if(napoje==bazaJedzenia[i]->ZwrocId())
			bazaJedzenia[i]->Wyswietl();
	}

	printf("\n\tOwoce\n");
	for(int i=0; i<bazaJedzenia.size(); i++)
	{
		if(owoce==bazaJedzenia[i]->ZwrocId())
			bazaJedzenia[i]->Wyswietl();
	}

	printf("\n\tProwiant\n");
	for(int i=0; i<bazaJedzenia.size(); i++)
	{
		if(suchy_prowiant==bazaJedzenia[i]->ZwrocId())
			bazaJedzenia[i]->Wyswietl();
	}


	printf("\n\tWarzywa\n");
	for(int i=0; i<bazaJedzenia.size(); i++)
	{
		if(warzywa==bazaJedzenia[i]->ZwrocId())
			bazaJedzenia[i]->Wyswietl();
	}
}