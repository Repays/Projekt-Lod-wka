#include "BazaUzytkownikow.h"
#include "Jedzenie.h"
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include "Mieso.h"
#include "Nabial.h"
#include "Napoje.h"
#include "Owoce.h"
#include "Prowiant.h"
#include "Warzywa.h"
#include "Stale.h"
#include "Informacje.h"
#include "Plan.h"
 
using namespace std;

class Menu
{
public:
	Menu(){};
	void Start(BazaUzytkownikow *baza);
	void Zalogowany(Uzytkownik *uzytkownik);
	void DodajJedzenie(Uzytkownik *uzytkownik);
	void Kalendarz(Uzytkownik *uzytkownik);
};