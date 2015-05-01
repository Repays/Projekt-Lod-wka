#include "Blad.h"

Blad::Blad(const string _wiadomosc): wiadomosc(_wiadomosc)
{}

string Blad::ZwrocWiadomosc() const
{
	return wiadomosc;
}