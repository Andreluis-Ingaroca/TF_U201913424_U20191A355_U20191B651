#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

class Column
{

	string valor; //valor de la columna

	string name; //titulo de la columna

public:

	Column(string n, string valor) : valor(valor), name(n) {}

	~Column() {}

	string getValor() {
		return valor;
	}

	string getName() {
		return name;
	}

	void setValor(string n) {
		valor = n;
	}

	void setName(string n) {
		name = n;
	}


};

