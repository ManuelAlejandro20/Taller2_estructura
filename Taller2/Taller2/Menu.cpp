#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	this->sistema = BuscaminasImpl();
}

void Menu::menuPrincipal()
{
	bool salir = false;
	string opcstr;
	while (!salir)
	{
		cout << "@@@@@@@@@@@@@@@@@@" << endl;
		cout << "@@@ Buscaminas @@@" << endl;
		cout << "@@@@@@@@@@@@@@@@@@\n" << endl;
		cout << "1. Iniciar Partida" << endl;
		cout << "2. Estadisticas" << endl;
		cout << "\nPor favor escoge una opcion (-1 para salir): ";
		getline(cin, opcstr);
		if (!Validacion(opcstr))continue;
		int opcion = stoi(opcstr);
		system("CLS");
		switch (opcion) {
		case 1:
			submenuDificultad();
			break;

		case 2:
			Estadisticas();
			continue;

		case -1:
			cout << "\nHas salido exitosamente del juego\n" << endl;
			salir = true;
			continue;


		default:
			cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			cout << "XXX Escoge una opcion valida porfavor XXX" << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
			system("PAUSE");
			system("CLS");
			continue;
		}


	}
}

void Menu::submenuDificultad()
{
	bool salir2 = false;
	string opcstr;
	while (!salir2)
	{
		cout << "Escogiste empezar una nueva partida\n" << endl;
		cout << "1. Facil" << endl;
		cout << "2. Media" << endl;
		cout << "3. Dificil" << endl;
		cout << "\nPor favor escoge una dificultad (-1 para volver al menu principal): ";
		getline(cin, opcstr);
		if (!Validacion(opcstr))continue;
		int opcion = stoi(opcstr);
		system("CLS");
		switch (opcion) {
		case 1:
			sistema.leerCampo(sistema.buscarCampo("facil"), "facil");
			sistema.crearMatrizJug("facil");
			continue;

		case 2:
			sistema.leerCampo(sistema.buscarCampo("medio"), "medio");
			sistema.crearMatrizJug("medio");
			continue;

		case 3:
			sistema.leerCampo(sistema.buscarCampo("dificil"), "dificil");
			sistema.crearMatrizJug("dificil");
			continue;

		case -1:
			system("CLS");
			salir2 = true;
			continue;


		default:
			cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			cout << "XXX Escoge una opcion valida porfavor XXX" << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
			system("PAUSE");
			system("CLS");
			continue;
		}


	}
}

void Menu::Estadisticas()
{
	cout << "\nSe desplegaran las victorias repartidas en dificultades y la cantidad de partidas totales" << endl;
	system("PAUSE");
	system("CLS");
}

bool Menu::Validacion(string str)
{
	try
	{
		stoi(str);

	}
	catch (const std::exception&)
	{
		cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << "XXX Escoge un numero porfavor XXX" << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
		system("PAUSE");
		system("CLS");
		return false;
	}
	return true;
}

void Menu::lecturaArchivos()
{
	ifstream campos("Campos.txt");
	if (campos.fail()) {
		cout << "Hubo un error al leer el archivo Campos.txt" << endl;
		system("PAUSE");
	}
	string linea;
	while (getline(campos, linea)) {
		stringstream sublinea(linea);
		while (!sublinea.eof()) {
			string nomArchivo;
			string dificultad;
			getline(sublinea, nomArchivo, ',');
			getline(sublinea, dificultad, ',');
			this->sistema.agregarCampo(nomArchivo, dificultad);

		}
	}

}


Menu::~Menu()
{
}
