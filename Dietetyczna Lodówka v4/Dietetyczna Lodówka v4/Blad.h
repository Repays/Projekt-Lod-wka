#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Blad
{
private:
	string wiadomosc;

public:
	Blad(const string _wiadomosc);
	string ZwrocWiadomosc() const;
};