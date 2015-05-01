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

void Uzytkownik::WysietlUzytkownika()
{
	cout << "Login: " << ZwrocLogin() << endl << "Imie i nazwisko: " << ZwrocImie() << " " << ZwrocNazwisko() << endl << "Wiek: " << ZwrocWiek() << endl << "Wzrost: " << ZwrocWzrost() 
		<< endl << "Waga: " << ZwrocWaga() << endl << endl;
	//printf("Login: %s \nImie i nazwisko: %s %s \nWiek: %d \nWzrost: %d \nWaga: %.1f \n",ZwrocLogin(),ZwrocImie(),ZwrocNazwisko(),ZwrocWiek(),ZwrocWzrost(),ZwrocWaga());
}