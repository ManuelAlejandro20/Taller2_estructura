// Taller2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Menu.h"
#include <locale>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//Menu *menu = new Menu;
	//
	//menu->lecturaArchivos();
	//menu->menuPrincipal();
	
	vector<int> xd;
	cout << xd.size();
	/*int x = 8;
	xd.push_back(1);
	xd.push_back(7);
	xd.push_back(0);
	xd.push_back(2);
	xd.push_back(5);
	sort(xd.begin(), xd.end());
	for (int i = 0; i < xd.size(); i++) {
		cout << xd[i] << endl;
	}

	cout << "----------" << endl;

	for (int j = 0; j < xd.size(); j++) {
		if (x < xd[j]) {
			xd.insert(xd.begin() + j, x);
			break;
		}
	}
	
	for (int i = 0; i < xd.size(); i++) {
		cout << xd[i] << endl;
	}
*/
	double x = 4.5;
	cout << ceil((double) 9/2);
	return 0;
}

