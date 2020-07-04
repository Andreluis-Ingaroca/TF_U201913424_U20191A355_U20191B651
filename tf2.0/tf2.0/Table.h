#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include <stdlib.h>
#include<string.h>
#include<iomanip>
#include "Column.h"
#include "Row.h"
#include "AVLBST.h"

using namespace std;

class Table
{
public:
	vector<string> *strings; //arreglo de los titulos.
	vector<Row*>*rows;//vector de filas
	int cant;
	int controw;


	int key;
	function<string(Row*)> k1 = [&](Row* row) {
		return row->getVec()->at(key)->getValor();
	};

	AVLBST<Row*, string, nullptr>* tree = new AVLBST<Row*, string, nullptr>(k1);

public:
	Table(int cant=0): cant(cant), key(0){
		strings = new vector<string>();
		rows = new vector<Row*>();
		
		controw=0;
		
	}
	~Table(){}

	void indexar(string columna) {

		for (int i = 0; i < strings->size(); i++) {

			if (columna == strings->at(i)) {
				key = i;
				break;
			}
		}

		auto k1 = [&](Row* row) {

			return row->getVec()->at(key)->getValor();

		};

		for (int i = 0; i < controw; i++) {
			tree->add(rows->at(i));
		}

	}

	void generate() {
		for (int i = 0; i < cant; i++) {
			Add();
		}
	}

	void Add() {

		string t; //titulo de columna

		cout << "Ingrese titulo de la columna: "; cin >> t;

		strings->push_back(t);
		
	}

	void AddRows() {
		rows->push_back(new Row(cant));

		for (int j = 0; j < strings->size(); j++) {
			rows->at(controw)->Agregar(strings->at(j));
		}
		cout << endl;
		controw++;//contador de filas
	}

	void Show() {
		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left<<setw(10)<<strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				cout << left << setw(10) << rows->at(i)->getVec()->at(j)->getValor();
				cout << setw(10);
				
			}
			cout << endl;
		}
	}

	void ordenar(string columna) {

		function<void(Row*)> print = [&](Row* a) {

			for (int i = 0; i < strings->size(); i++)
			{

				cout << left<<setw(10)<<a->getVec()->at(i)->getValor();
				cout << setw(10);

			}
			cout << endl;		};

		tree->inOrder(print);

	}

	void newtable(Table* t, int i) {

		t->strings = this->strings;

		t->rows->push_back(rows->at(i));

		t->controw++;
	}

	void mayorque(string dato,string columna, Table* t) {

		function<bool(Row*)> k1 = [&](Row* r) {

			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {

					if (dato[0] == '0' && dato[0] == '1' && dato[0] == '2' && dato[0] == '3' && dato[0] == '4' && dato[0] == '5' && dato[0] == '6' && dato[0] == '7' && dato[0] == '8' && dato[0] == '9') {

						return atoi(r->getVec()->at(i)->getValor().c_str()) > atoi(dato.c_str());
					}
					else
					{
						return r->getVec()->at(i)->getValor() > dato;
					}


				}
			}
		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				if (columna == strings->at(j)) {

					if (k1(rows->at(i))) { //if (rows->at(i)->getVec()->at(j)->getValor() > dato) {

						for (int k = 0; k < strings->size(); k++) {

							
							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);
							
						}
					}
				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}

	}

	void menorque(string dato, string columna, Table* t) {

		function<bool(Row*)> k1 = [&](Row* r) {

			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {

					if (dato[0] == '0' && dato[0] == '1' && dato[0] == '2' && dato[0] == '3' && dato[0] == '4' && dato[0] == '5' && dato[0] == '6' && dato[0] == '7' && dato[0] == '8' && dato[0] == '9') {

						return atoi(r->getVec()->at(i)->getValor().c_str()) < atoi(dato.c_str());
					}
					else
					{
						return r->getVec()->at(i)->getValor() < dato;
					}


				}
			}
		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				if (columna == strings->at(j)) {

					if (k1(rows->at(i))) { //if (rows->at(i)->getVec()->at(j)->getValor() > dato) {

						for (int k = 0; k < strings->size(); k++) {//;k<strings->size();

							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);

						}
					}
					
				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}

	}

	void igualque(string dato, string columna, Table* t) {

		function<bool(Row*)> k1 = [&](Row* r) {

			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {

					if (dato[0] == '0' && dato[0] == '1' && dato[0] == '2' && dato[0] == '3' && dato[0] == '4' && dato[0] == '5' && dato[0] == '6' && dato[0] == '7' && dato[0] == '8' && dato[0] == '9') {

						return atoi(r->getVec()->at(i)->getValor().c_str()) == atoi(dato.c_str());
					}
					else
					{
						return r->getVec()->at(i)->getValor() == dato;
					}
				}
			}
		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				if (columna == strings->at(j)) {

					 //if (rows->at(i)->getVec()->at(j)->getValor() > dato) {
					if (k1(rows->at(i))) {

						for (int k = 0; k < strings->size(); k++) {//;k<strings->size();

							
							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);

						}
					}
					
				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}

	}

	void iniciacon(string dato, string columna, Table* t) {

		function<bool(Row*)> k1 = [&](Row* r) {

			int x = 0;

			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {
					
					if (dato.length() == 1) {

						if (r->getVec()->at(i)->getValor()[0] == dato[0]) {

							return true;

						}
					}
					
					for (int s = 0; s < dato.length(); s++) {
						if (r->getVec()->at(i)->getValor()[s] == dato[s]) {
							x++;
							if (x == dato.length())
								return true;
						}
						else
						{
							return false;
						}

					}

				}
			}
		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				if (columna == strings->at(j)) {

					//if (rows->at(i)->getVec()->at(j)->getValor() > dato) {
					if (k1(rows->at(i))) {

						for (int k = 0; k < strings->size(); k++) {//;k<strings->size();

							
							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);

						}
					}

				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}
	}

	void finalizacon(string dato, string columna, Table* t) {
		function<bool(Row*)> k1 = [&](Row* r) {
			int x = 0;
			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {
					
					if (dato.length() == 1) {

						if (r->getVec()->at(i)->getValor()[r->getVec()->at(i)->getValor().length() - 1] == dato[0]) {
							return true;
						}
					}

					for (int s = 1; s < dato.length()+1; s++) {

						if (r->getVec()->at(i)->getValor()[r->getVec()->at(i)->getValor().length()-s] == dato[dato.length()-s]) {
							x++;
							if (x == dato.length())
								return true;
						}
						else
						{
							return false;
						}
					}
				}
			}
			return false;
		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				if (columna == strings->at(j)) {

					if (k1(rows->at(i))) {

						for (int k = 0; k < strings->size(); k++) {
							
							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);

						}
					}

				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}
	}

	void contenidoen(string dato, string columna, Table* t) {

		function<bool(Row*)> k1 = [&](Row* r) {

			int x=0;

			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {

					for (int j = 0; j < r->getVec()->at(i)->getValor().length();j++) {

						for (int k = 0; k < dato.length(); k++) {

							if (dato.length() == 1) {

								if (r->getVec()->at(i)->getValor()[j] == dato[k]) {

									return true;

								}
							}
							else
							{
								if (r->getVec()->at(i)->getValor()[j] == dato[k] && r->getVec()->at(i)->getValor()[j+1] == dato[k+1] && k+1 < dato.length() && j+1 < r->getVec()->at(i)->getValor().length()) {
									x++;

								}

								if (x+1 == dato.length()) {
									return true;
								}

							}
						}
					}
				}


			}
			return false;
		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;

		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{
				if (columna == strings->at(j)) {

					//if (rows->at(i)->getVec()->at(j)->getValor() > dato) {
					if (k1(rows->at(i))) {

						for (int k = 0; k < strings->size(); k++) {//;k<strings->size();

							
							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);

						}
					}

				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}

	}

	void nocontenidoen(string dato, string columna,Table* t) {

		function<bool(Row*)> k1 = [&](Row* r) {

			int x = 0;

			for (int i = 0; i < strings->size(); i++) {

				if (columna == strings->at(i)) {

					for (int j = 0; j < r->getVec()->at(i)->getValor().length(); j++) {

						for (int k = 0; k < dato.length(); k++) {

							if (dato.length() == 1) {

								if (r->getVec()->at(i)->getValor()[j] == dato[k]) {

									return false;

								}
							}

							else
							{
								if (r->getVec()->at(i)->getValor()[j] == dato[k] && r->getVec()->at(i)->getValor()[j + 1] == dato[k + 1]) {
									x++;

								}

								if (x + 1 == dato.length()) {
									return false;
								}




							}
						}
					}
				}

			}

			return true;

		};

		for (int i = 0; i < strings->size(); i++)//mostrartitulos
		{
			cout << left << setw(10) << strings->at(i) << setw(10);

		}
		cout << endl;
		
		for (int i = 0; i < controw; i++)//mostrar filas
		{
			for (int j = 0; j < strings->size(); j++)
			{  
				if (columna == strings->at(j)) {

					//if (rows->at(i)->getVec()->at(j)->getValor() > dato) {
					if (k1(rows->at(i))) {

						for (int k = 0; k < strings->size(); k++) {//;k<strings->size();
							
							cout << left << setw(10) << rows->at(i)->getVec()->at(k)->getValor();
							cout << setw(10);

						}
					}

				}
			}
			if (k1(rows->at(i))) {
				newtable(t, i);
				cout << endl;
			}
		}

	}

	void setControw(int c) { this->controw = c; }

	bool selection(Table *tablex) {

		vector<string> *campos=new vector<string>();

		string campo;

		while (true)
		{
			cout << "Ingrese los campos a seleccionar: "; cin >> campo;
			if (campo == ".")
				break;
			campos->push_back(campo);
			
		}

		Table *t = new Table(campos->size());
		t->strings = campos;
		for (int i = 0; i < strings->size(); i++) {
			for (int k = 0; k < campos->size(); k++) {
				if (campos->at(k) == strings->at(i)) {
					for (int j = 0; j < rows->size(); j++) {

						t->rows->push_back(new Row(campos->size()));
						t->setControw(this->controw);
						t->rows->at(j)->getVec()->push_back(this->rows->at(j)->getVec()->at(i));
						
					}
			    }
			}
		}
		*tablex = *t;
		return true;
	}

	

};

