#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <stack>
#include "BuscaminasImpl.h"

using namespace std;


class Menu
{
public:
	Menu();
	void menuPrincipal();
	void submenuDificultad();
	void Estadisticas();
	bool Validacion(string str);
	void lecturaArchivos();
	~Menu();

private:
	BuscaminasImpl sistema;

};

