#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include "ListaNodo.h"

using namespace std;

class BuscaminasImpl
{
public:
	BuscaminasImpl();
	void agregarCampo(string campo, string dif); // agrega el archivo leido a la lista de string de archivos disponibles solo si este existe
	string buscarCampo(string dif); // retorna el nombre de un archivo escogido al azar  ej "campo001.txt"
	void leerCampo(string nomArchivo, string dif); // lee toda la informacion del campo escogido por el metodo anterior y crea los nodos correspondientes
	void crearMatrizJug(string dif); // crea la matriz de las H
	void hacerJugada(); //lee la jugada que hace el usuario, esta incompleto compa
	~BuscaminasImpl();


private:
	vector <string> difFacil; // lista que contiene todos los nombres de los archivos faciles
	vector <string> difMedia; // lo mismo pero en medio
 	vector <string> difDificil; // lo mismo pero en dificil
	ListaNodo *lista; // matriz poco poblada que contendra la informacion que se lee desde los archivos (numeros y X) , le puse lista porque idk im retard
	ListaNodo *listajug; // martriz poco poblada que se imprime por pantalla, la de las H

	 
};

