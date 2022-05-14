#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>
#include<locale.h>
using namespace std;

void agendar();
void mostrar();
void editar();
void eliminacion();
void salida();

int agend, * dientes, * total, * hora, * precio, * subtotal;
string* nombre;
string* descripcion;
string* nomtra;
int main() {

	setlocale(LC_CTYPE, "Spanish");
	int op;
	cout << "Bienvenido, ¿Qué desea hacer? \n";
	cout << "1.-Agendar cita \n";
	cout << "2.-Modificar cita \n";
	cout << "3.-Eliminar cita \n";
	cout << "4.Mostrar citas vigentes \n";
	cout << "5.Limpiar pantalla \n";
	cout << "6.-Salir \n";
	cin >> op;

	switch (op) {

	case 1:
		agendar();
		return main();
		break;

	case 2:
		editar();
		return main();
		break;

	case 3:
		eliminacion();
		return main();
		break;

	case 4:
		mostrar();
		return main();
		break;

	case 5:
		system("cls");
		return main();
		break;

	case 6:
		salida();
		break;
	
	default:
		printf("Opción invalida \n");
		printf("Vuelva a escoger otra opcion \n");
		return main();
		break;
	}
}

void agendar() {
	setlocale(LC_CTYPE, "Spanish");

	printf("Ingrese la cantidad de pacientes \n");
	cin >> agend;
	dientes = new int[agend];
	nomtra = new string[agend];
	total = new int[agend];
	hora = new int[agend];
	nombre = new string[agend];
	descripcion = new string[agend];
	precio = new int[agend];
	subtotal = new int[agend];

	for (int i = 0; i < agend; i++) {
		
		printf("Ingresa la hora de la cita (Formato 24 horas) \n");
		cin >> hora[i];
		if (hora[i] > 24||hora[i]<1) {
			while (hora[i] > 24 || hora[i] < 1) {
				printf("Ingresa la hora del tratamiento correta (24 hrs) \n");
				cin >> hora[i];
			}
		}
		while (getchar() != '\n');
		printf("Ingrese el nombre del paciente \n");
		getline(cin, nombre[i]);
		printf("Ingresa el nombre del tratamiento \n");
		getline(cin, nomtra[i]);
		printf("Ingresa la descripcion del tratamiento \n");
		getline(cin, descripcion[i]);
		printf("Ingrese la cantidad del tratamiento \n");
		cin >> dientes[i];
		printf("Ingrese el precio unitario \n");
		cin>>precio[i];
		subtotal[i] = dientes[i] * precio[i];
		total[i] = subtotal[i] * 1.16;
		

	}

}
void mostrar() {
	setlocale(LC_CTYPE, "Spanish");
	cout << "Las citas vigentes son: \n";
	for (int i = 0; i < agend; i++) {
		if (hora[i]==0) {
		
		}
		else {
			cout << "La cita del registro " << i + 1 << " del paciente " << nombre[i] <<"."<< endl;
			cout << "Tiene un tratamiento de " << nomtra[i];
			cout << " que consiste en " << descripcion[i] << "."<<endl;
			cout << "La cita se atendara a las " << hora[i]<< " horas. \n";
			cout << "La cantidad del tratamiento es de " << dientes[i]<<"." << endl;
			cout << "El precio unitario es de $" << precio[i] <<"."<< endl;
			cout << "Tendra un costo total de $" << total[i] << "."<<endl;
		}
	}
}

void editar(){
	setlocale(LC_CTYPE, "Spanish");
	int j, opc, op2;
	do {
		cout << "Introduzca el número de cita que quiera editar \n";
		cin >> j;
		j = j - 1;
		cout << "Introduzca el numero que desee editar \n";
		cout << "1.-Nombre del paciente \n";
		cout << "2.-Nombre del tratamiento \n";
		cout << "3.-Descripcion \n";
		cout << "4.-Hora \n";
		cout << "5.-Costo \n";
		cin >> opc;

		switch (opc) {

		case 1:
			for (int i = 0; i == j; i++) {
				while (getchar() != '\n');
				cout << "Ingrese el nombre paciente. \n";
				getline(cin, nombre[i]);

			}
			break;

		case 2:
			for (int i = 0; i == j; i++) {
				while (getchar() != '\n');
				cout << "Ingrese el nombre del tratamiento. \n";
				getline(cin, nomtra[i]);


			}
			break;

		case 3:
			for (int i = 0; i == j; i++) {
				while (getchar() != '\n');
				cout << "Ingrese la descripcion. \n";
				getline(cin, descripcion[i]);

			}
			break;

		case 4:
			for (int i = 0; i == j; i++) {
				cout << "Ingrese la hora del tratamiento. \n";
				cin >> hora[i];

				if (hora[i] > 24)
				{
					while (hora[i] > 24)
					{
						printf("Ingresa la hora del tratamiento correta (24 hrs). \n");
						cin >> hora[i];
					}
				}


			}
			break;

		case 5:
			for (int i = 0; i == j; i++) {
				while (getchar() != '\n');
				printf("Ingrese la cantidad del tratamiento. \n");
				cin >> dientes[i];
				printf("Ingrese el precio unitario. \n");
				cin >> precio[i];
				subtotal[i] = dientes[i] * precio[i];
				total[i] = subtotal[i] * 1.16;
			}
			break;
		}
		cout << "¿Desea ingresar otro dato?, si es asi ingrese 1 y en otro caso ingrese cualquier numero. \n";
		cin >> op2;
	} while (op2 == 1);
}
void eliminacion() {

	int j;
	cout << "Ingrese el numero de cita que desee eliminar \n";
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++) {
		cout << "Elimanado registro " << j + 1 << endl;
		nombre[i] = " ";
		nomtra[i] = " ";
		descripcion[i] = " ";
		hora[i] = 0;
		precio[i] = 0;
		dientes[i] = 0;
		subtotal[i] = 0;
		total[i] = 0;
	}
}

void salida()
{
	setlocale(LC_CTYPE, "Spanish");
	ofstream archivo;
	string archivo2, txt;
	int t;

	while (getchar() != '\n');
	cout << "Ingresa el nombre del archivo " << endl;
	getline(cin, archivo2);

	archivo.open(archivo2.c_str(), ios::out);

	if (archivo.fail()) {
		cout << "Eror no se pudo crear";
		exit(1);

	}
	archivo << "No. de cita" << "\t";
	archivo << "Paciente" << "\t";
	archivo << "Tratamiento" << "\t";
	archivo << "Descripcion" << "\t";
	archivo << "Hora" << "\t";
	archivo << "costo" << "\n";

	for (int i = 0; i < agend; i++) {
		if (hora[i] == 0) {

		}
		else {
			t = i + 1;
			archivo << t << "\t" << "\t";
			txt = nombre[i];
			archivo << txt << "\t" << "\t"<<"\t";
			txt = nomtra[i];
			archivo << txt << "\t" << "\t";
			txt = descripcion[i];
			archivo << txt << "\t" << "\t"<<"\t";
			t = hora[i];
			archivo << t << "\t" << "\t";
			t = total[i];
			archivo << t << "\t" << "\n";
		}
	}
	archivo.close();
}