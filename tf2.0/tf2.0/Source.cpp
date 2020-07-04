#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sstream>
#include<conio.h>
#include<functional>
#include<fstream>
#include "Table.h"

using namespace std;

void menu() {

	cout << "<---------------------------------------->"<<endl;
	cout << "****************BIENVENIDO***************>"<<endl;
	cout << " 1. Creación de tabla" << endl;
	cout << " 2. Inserción de datos" << endl;//s
	cout << " 3. Indexar datos por columna" << endl;//a
	cout << " 4. Selección de datos por columna" << endl;//a
	cout << " 5. Filtrar datos por columna" << endl;//t
	cout << " 6. Ordenar datos por columna(Primero indexar)" << endl;//s
	cout << " 7. Exportación de datos a archivo plano" << endl;//t
	cout << " 8. Mostrar tabla" << endl;
	cout << " 9. Seleccionar tabla" << endl;
	cout << "10. Salir" << endl;
	cout << endl;
}

Table* f1(vector<Table*>*tables,int &contables) {

	cout << "Creación de tabla" << endl;
	cout << "Ingrese numero de columnas: ";

	int n; cin >> n;

	tables->push_back(new Table(n));

	Table *t = tables->at(contables);

	contables = tables->size()-1;
	
	t->generate();

	return t;
}

void f2(Table *t) {

	string tecla;

	while (true)
	{
		if (_kbhit) {
			if (tecla != "s") {
				cout << "Ingrese fila" << endl;
				t->AddRows();
				cout << "Salir(s) o continuar(cualquier tecla): "; cin >> tecla;
			}
			else
			{
				break;
			}
		}

	}

	t->Show();
	_getch();
}

void f3(Table* t) {

	string columna;

	cout << "Nombre de la columna a indexar: "; cin >> columna;

	t->indexar(columna);

	t->Show();
	_getch();
}

void f4(Table* &t, vector<Table*>*tables, int &contador) {
	tables->push_back(new Table(t->strings->size()));
	t->selection(tables->at(tables->size()-1));
	t = tables->at(tables->size()-1);
	t->Show();
	_getch();
}

void f5(Table* &t, vector<Table*>*tables, int &contador) {
	int op=0;
	string columna;
	string dato;
	while (true)
	{
		cout << "<---------------------------------------->" << endl;
		cout << "                FILTRADO***************>" << endl;
		cout << "1.Mayor" << endl;
		cout << "2.Menor" << endl;
		cout << "3.Igual" << endl;
		cout << "4.Inicia con" << endl; //si inicia con la letra "a"", lo imprime .   //strings
		cout << "5.Finaliza con" << endl;//string
		cout << "6.Está contenido en" << endl;//si se encuentra el nombre tal "", lo imprime. //strings
		cout << "7.No está contenido en" << endl;
		cout << "8.Regresar a Menú" << endl;
		cout << "Ingrese opción: "; cin >> op;
		
		switch (op)
		{
		
		case 1:
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;
			
			t->mayorque(dato, columna,tables->at(tables->size()-1));
			t = tables->at(tables->size()-1);
			
			break;
		case 2:
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;

			t->menorque(dato, columna, tables->at(tables->size() - 1));
			t = tables->at(tables->size()-1);
			
			break;
		case 3:
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;
			t->igualque(dato, columna, tables->at(tables->size() - 1));
			t = tables->at(tables->size()-1);

			break;
		case 4: 
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;
			t->iniciacon(dato, columna, tables->at(tables->size() - 1));
			t = tables->at(tables->size()-1);

			break;
		case 5: 
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;
			t->finalizacon(dato, columna, tables->at(tables->size() - 1));
			t = tables->at(tables->size()-1);

			break;
			
		case 6: 
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;
			t->contenidoen(dato, columna, tables->at(tables->size() - 1));
			t = tables->at(tables->size()-1);

			break;
		
		case 7: 
			tables->push_back(new Table(t->strings->size()));
			contador = tables->size() - 1;
			cout << "Elegir dato: "; cin >> dato;
			cout << "Elegir columna : "; cin >> columna;
			t->nocontenidoen(dato, columna, tables->at(tables->size() - 1));
			t = tables->at(tables->size()-1);

			break;

		case 8:
			return;
		}
		contador++;
	}
	
}

void f6(Table *t) {

	string columna;

	cout << "Ordenar según la columna: "; cin >> columna;

	t->ordenar(columna);

	_getch();
}

void f7(Table *t) {



	int x=0;

	cout << "1.csv"<<endl<<"2.txt"<<endl;

	cout << "Ingrese opcion: ";  cin >> x;
	cout << endl;

	string extension;

	switch (x)
	{
	case 1: 
		extension = ".csv";
		break;
	case 2: 
		extension = ".txt";
		break;
	default:
		break;
	}

	string nombre;

	cout << "Ingrese el nombre del archivo: "; cin >> nombre;

	ofstream f(nombre+extension);

	if (!f.is_open()) {
		cout << "ERROR: El archivo no pudo ser abierto." << endl;	
	}

	for (int i = 0; i < t->controw; i++)//mostrar filas
	{
		for (int j = 0; j < t->strings->size(); j++)
		{
			
			f << t->rows->at(i)->getVec()->at(j)->getValor();
			f << ",";

		}
		f << endl;
	}

	f.close();
}

int main() {

	setlocale(LC_ALL,"");

	int opcion = 0;

	Table *t ;

	vector<Table*>* tables = new vector<Table*>();

	int contables = 0;

	while (true)
	{
		menu();
		cout << "Ingrese opción: "; cin >> opcion;
		switch (opcion)
		{
			case 1: 
				t = f1(tables,contables);
				break;
			case 2: 
				f2(t);
				break;
			case 3: 
				f3(t);
				break;
			case 4:
				f4(t,tables,contables);
				break;
			case 5: 
				f5(t,tables,contables);
				break;
			case 6: 
				f6(t);
				break;
			case 7: 
				f7(t);
				break;

			case 8:
				for (int i = 0; i < tables->size();i++) {
					cout << "TABLA NÚMERO: "<<i+1 << endl;
					tables->at(i)->Show();
					cout << endl;
				}
				
				_getch();
				break;

			case 9:
				int pos;
				cout << "Ingrese posición: "; cin >> pos;

				contables = pos - 1;

				t = tables->at(contables);

				t->Show();
				_getch();
				break;
			case 10:

				exit(0);
		}
		system("cls");
	}


	_getch();
	return 0;
}