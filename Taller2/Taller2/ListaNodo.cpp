#include "stdafx.h"
#include "ListaNodo.h"


ListaNodo::ListaNodo(string dif)
{
	if (dif == "dificil") {
		for (int i = 0; i < 16; i++) {
			this->_cabeceraFilas.push_back(new NodoDoble(0)); // se agrega un nodo de cabecera 16 veces
			NodoDoble *nodoaux = this->_cabeceraFilas[i]; // por cada i hay un nodo auxiliar que apunta al nodo recien creado
			this->_cabeceraFilas[i]->left = nodoaux; // ya sabes, nodo.setsiguiente(nodoaux) lista circular;
			nodoaux = NULL; // no se si esto sea redudante pero en foros de c++ en ingles decian que era necesario because muh puntero 
			delete nodoaux;
		}
		for (int j = 0; j < 30;j++) {
			this->_cabeceraCol.push_back(new NodoDoble(1));
			NodoDoble *nodoaux = this->_cabeceraCol[j];  // son dos for porque el largo es diferente, no se me ocurrio otra forma de llenarlos
			this->_cabeceraCol[j]->up = nodoaux;
			nodoaux = NULL;
			delete nodoaux;
		}

	}
	else {
		int num = 0; // la cantidad de veces que se repita el ciclo depeende de su dificultado, como son matrices cuadradas es mas facil
		if (dif == "facil") {
			num = 9;
		}
		else {
			num = 16;
		}
		for (int i = 0; i < num; i++) { 
			this->_cabeceraFilas.push_back(new NodoDoble(0));
			this->_cabeceraCol.push_back(new NodoDoble(1));
			NodoDoble *nodoaux = this->_cabeceraFilas[i]; // lo mismo de arriba solo que ahora estan juntos
			NodoDoble *nodoaux2 = this->_cabeceraCol[i];
			this->_cabeceraFilas[i]->left = nodoaux;
			this->_cabeceraCol[i]->up = nodoaux2;
			nodoaux = nodoaux2 = NULL;
			delete nodoaux, nodoaux2;
		}
	}
}

void ListaNodo::agregarNodo(string contenido, int fila, int columna)
{
	NodoDoble *nodonuevo = new NodoDoble(contenido, columna + 1, fila + 1); // se crea nodo nuevo, se aumenta en uno porque en las MPP la posicion 0 las ocupan los nodos de cabecera so...
	if (this->_cabeceraFilas[fila]->left == this->_cabeceraFilas[fila] && this->_cabeceraCol[columna]->up == this->_cabeceraCol[columna]) {
		this->_cabeceraFilas[fila]->left = nodonuevo;
		nodonuevo->left = this->_cabeceraFilas[fila];  // primer caso, el nodo de cabecera en la columna y fila se apuntan a si mismos (columna y filas vacias)
		this->_cabeceraCol[columna]->up = nodonuevo; 
		nodonuevo->up = this->_cabeceraCol[columna];
	}
	else if (this->_cabeceraFilas[fila]->left != this->_cabeceraFilas[fila] && this->_cabeceraCol[columna]->up == this->_cabeceraCol[columna]) {
		this->_cabeceraCol[columna]->up = nodonuevo;
		nodonuevo->up = this->_cabeceraCol[columna]; // segundo caso, el nodo de cabecera de la fila ya apunta a otro nodo pero el de la columna apunta a si mismo (columna vacia, fila con elementos)
		NodoDoble *aux = this->_cabeceraFilas[fila];
		while (aux->left != this->_cabeceraFilas[fila]) {
			aux = aux->left; // avanza hasta que sea el final
		}
		nodonuevo->left = aux->left;
		aux->left = nodonuevo;
		aux = NULL;
		delete aux;
	
	}
	else if (this->_cabeceraFilas[fila]->left == this->_cabeceraFilas[fila] && this->_cabeceraCol[columna]->up != this->_cabeceraCol[columna]) {
		this->_cabeceraFilas[fila]->left = nodonuevo;
		nodonuevo->left = this->_cabeceraFilas[fila];//tercer caso el nodo cabecera de la fila apunta a si mismo, pero de la columna apunta a otro nodo (fila vacia, columna con elementos)
		NodoDoble *aux = this->_cabeceraCol[columna];
		while (aux->up != this->_cabeceraCol[columna]) {
			aux = aux->up;
		}
		nodonuevo->up = aux->up;
		aux->up = nodonuevo;
		aux = NULL;
		delete aux;
	}

	else {
		NodoDoble *aux = this->_cabeceraFilas[fila]; // cuarto caso, ambos nodos de cabecera apuntan a otros nodos, eso quiere decir que hay mas elementos en esa fila y columna
		NodoDoble *aux2 = this->_cabeceraCol[columna];
		while (aux->left != this->_cabeceraFilas[fila]) {
			aux = aux->left;
		}
		while (aux2->up != this->_cabeceraCol[columna]) {			
			aux2 = aux2->up;
		}
		nodonuevo->left = aux->left;
		aux->left = nodonuevo;
		nodonuevo->up = aux2->up;
		aux2->up = nodonuevo;
		aux = aux2 = NULL;
		delete aux, aux2;

	}
	nodonuevo = NULL;
	delete nodonuevo; 

	
}

void ListaNodo::imprimir()
{
	int lim = this->_cabeceraCol.size();
	for (int i = 0; i < lim; i++) {
		cout << "C" + to_string(i + 1) + " ";
	}
	cout << "" << endl;
	for (int i = 0; i < this->_cabeceraFilas.size(); i++) {
		NodoDoble *aux = this->_cabeceraFilas[i];
		do {
			aux = aux->left;
			cout << "|" + aux->valor + "|"; //AHhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
		} while (aux->left != this->_cabeceraFilas[i]);
		cout << " F" + to_string(i + 1);
		cout << "" << endl;
		aux = NULL;
		delete aux;
	}
}


ListaNodo::~ListaNodo()
{
}
