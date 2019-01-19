#pragma once
#include <vector>
#include "stdafx.h"
#include "NodoDoble.h"

class ListaNodo
{
public:
	ListaNodo(string dif);
	void agregarNodo(string contenido, int fila, int columna); // se agregan nodos, se necesita su contenido, su fila y su columna, estos datos ademas de ser sus parametros se aprovechan para encontrar los nodos de cabecera a los que se tienen que enlazar
	void imprimir(); // metodo qliao que no se imprime bien because nose >:,v
	~ListaNodo();

private:
	vector <NodoDoble*> _cabeceraFilas; // nodos de cabecera
	vector <NodoDoble*> _cabeceraCol;

};

