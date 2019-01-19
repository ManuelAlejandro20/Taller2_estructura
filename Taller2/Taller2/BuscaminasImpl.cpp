#include "stdafx.h"
#include "BuscaminasImpl.h"


BuscaminasImpl::BuscaminasImpl()
{
}

void BuscaminasImpl::agregarCampo(string campo, string dif)
{
	ifstream archivo;
	archivo.open(campo);
	if (!archivo.fail()) {
		if (dif == "facil") {
			this->difFacil.push_back(campo);
		}
		else if (dif == "medio") {
			this->difMedia.push_back(campo);
		}
		else {
			this->difDificil.push_back(campo);
		}
	}

}

string BuscaminasImpl::buscarCampo(string dif)
{
	int randNum;
	if (dif == "facil") {
		randNum = rand() % ((this->difFacil.size() - 1) - 0 + 1) + 0;
		return this->difFacil[randNum];
	}
	else if (dif == "medio") {
		randNum = rand() % ((this->difMedia.size() - 1) - 0 + 1) + 0;
		return this->difMedia[randNum];
	}
	randNum = rand() % ((this->difDificil.size() - 1) - 0 + 1) + 0;
	return this->difDificil[randNum];
}

void BuscaminasImpl::leerCampo(string nomArchivo, string dif)
{
	this->lista = new ListaNodo(dif);

	vector <string> vecaux;
	int contaux = 0;
	ifstream arc(nomArchivo);
	string linea;
	getline(arc, linea); // se salta la primera linea (9x9, 16x16, 16x30)
	while (getline(arc, linea)) {
		stringstream sublinea(linea);
		while (!sublinea.eof()) {
			string valorleido;
			getline(sublinea, valorleido, ',');
			vecaux.push_back(valorleido); // se llena un vector con los datos a poner en la fila de la matriz
		} 
		for (int i = 0; i < vecaux.size(); i++) { // el for es porque usaremos el i para representar cada columna en la matriz, excepto si el valor es 0  
			if (vecaux[i] != "0") {
				lista->agregarNodo(vecaux[i], contaux, i); // el contador representa la fila de la matriz por eso se aumenta en uno cuando se termina de leer toda la fila del archivo 
			}

		}
		vecaux.clear();
		contaux++;
		
	}
}

void BuscaminasImpl::crearMatrizJug(string dif)
{
	int lim = 0;
	int num = 0;
	int contaux = 0;
	this->listajug = new ListaNodo(dif);
	if (dif == "facil") {
		num = 9;
		lim = num;
	}
	else{
		lim = 16;
		if (dif == "dificil") {
			num = 30;
		}
		else {
			num = lim;
		}
	}
	while (contaux != lim) {
		for (int i = 0; i < num; i++) {
			this->listajug->agregarNodo("H", contaux, i);
		}
		contaux++;
	
	}

	this->listajug->imprimir();

}

void BuscaminasImpl::hacerJugada()
{
	string jugada;
	cout << "\nHaz una jugada porfavor\n";
	cin >> jugada;
}


BuscaminasImpl::~BuscaminasImpl()
{
}
