#include "stdafx.h"
#include "NodoDoble.h"


NodoDoble::NodoDoble(int id)
{
	this->valor = "";
	if (id == 0) {
		this->fila = -1; // nunca se pregunta este valor asi que ps da lo mismo con que valor este
		this->col = 0;
		this->left = nullptr;
		this->up = nullptr;
	}
	else {
		this->fila = 0;
		this->col = -1;// lo mismo este, la vd no deberia existir pero lo puse mas que nada para corroborar que los nodos estaban bien enlazados
		this->left = nullptr;
		this->up = nullptr;
	}
}

NodoDoble::NodoDoble(string valor, int col, int fila)
{
	this->valor = valor;
	this->col = col;
	this->fila = fila;
	this->left = nullptr;
	this->up = nullptr;
}


NodoDoble::~NodoDoble()
{
}
