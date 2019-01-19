#pragma once
#include <string>
#include <iostream>
#include "stdafx.h"


using namespace std;

class NodoDoble
{
public:
	NodoDoble(int id); //constructor para nodos de cabecera
	NodoDoble(string valor, int col, int fila); // constrcutor para nodos normales
	~NodoDoble();
private:
	NodoDoble *up;
	NodoDoble *left;
	string valor;
	int col;
	int fila;

	friend class ListaNodo; // para que no tengamos que hacer gets y sets :v
};

