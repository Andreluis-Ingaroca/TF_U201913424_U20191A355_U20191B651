#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include "Column.h"

using namespace std;

class Row
{

	vector<Column*> *vec;

	int n;

public:

	Row(int n): n(n) {
		vec=new vector<Column*>();
	}
	~Row(){}
	
	void Agregar(string t) {

		string valor;

		cout << "Ingrese " << t << ":"; cin >> valor;


		vec->push_back(new Column(t, valor));

	}
	vector<Column*>* getVec() { 
		
		return this->vec; 

	}


};
