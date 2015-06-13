#include "Uzytkownik.h"


Uzytkownik::Uzytkownik(const string _imie, const string _nazwisko, const string _login, const unsigned int _wiek, const float _waga, const unsigned int _wzrost)
{
	UstawImie(_imie);
	UstawNazwisko(_nazwisko);
	UstawLogin(_login);
	UstawWiek(_wiek);
	UstawWaga(_waga);
	UstawWzrost(_wzrost);
}

void Uzytkownik::UstawImie(const string _imie)
{
	if(_imie=="")
		throw Blad("Pole imie jest puste!");
	else
		imie=_imie;
}

void Uzytkownik::UstawNazwisko(const string _nazwisko)
{
	if(_nazwisko=="")
		throw Blad("Pole nazwisko jest puste!");
	else
		nazwisko=_nazwisko;
}

void Uzytkownik::UstawLogin(const string _login)
{
	if(_login=="")
		throw Blad("Pole login jest puste!");
	else
		login=_login;
}

void Uzytkownik::UstawWiek(const unsigned int _wiek)
{
	if(_wiek<=0)
		throw Blad("Wiek jest nieprawidlowy!");
	else
		wiek=_wiek;
}

void Uzytkownik::UstawWaga(const float _waga)
{
	if(_waga<=0)
		throw Blad("Waga jest nieprawidlowa!");
	else
		waga=_waga;
}

void Uzytkownik::UstawWzrost(const unsigned int _wzrost)
{
	if(_wzrost<=0)
		throw Blad("Wzrost jest nieprawidlowy!");
	else
		wzrost=_wzrost;
}

void Uzytkownik::WysietlUzytkownika() const
{
	cout << "Login: " << ZwrocLogin() << endl << "Imie i nazwisko: " << ZwrocImie() << " " << ZwrocNazwisko() << endl << "Wiek: " << ZwrocWiek() << endl << "Wzrost: " << ZwrocWzrost() 
		<< endl << "Waga: " << ZwrocWaga() << endl << endl;
	//printf("Login: %s \nImie i nazwisko: %s %s \nWiek: %d \nWzrost: %d \nWaga: %.1f \n",ZwrocLogin(),ZwrocImie(),ZwrocNazwisko(),ZwrocWiek(),ZwrocWzrost(),ZwrocWaga());
}


void Uzytkownik::Serializuj()
{
	string temp = "pliki//";
	temp += login;
	temp += ".csv";
	fstream plik;
	plik.open(temp,std::ios::out);
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

void Uzytkownik::Deserializuj()
{

	string temp = "pliki//";
	temp += login;
	temp += ".csv";

	string dana1, dana2, dana3, dana4, dana5, dana6, dana7, dana8;
	char separator = ';';
	char koniec = '\n';
	fstream plik;
	plik.open(temp);
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


void Uzytkownik::Dodaj(Jedzenie *obiekt)
{
	bazaJedzenia.push_back(obiekt);
}

void Uzytkownik::Filtruj()
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

float Uzytkownik::IleKalorii()	
{
	float BMR;
	float TEA_EPOC;
	BMR = (9.99 * waga) + (6.25 * wzrost) - (4.92 * wiek) +5;
	TEA_EPOC = (3*45*8) + (3 * 0.05 * BMR) +(3*20*5)+(3*5);
	TEA_EPOC = TEA_EPOC/7;
	return (BMR + TEA_EPOC + 300) + ((BMR + TEA_EPOC + 300)*0.08);
}