/* Example02.cpp: PROGRAMA QUE ALMACENA LOS DATOS INGRESADOS POR LE USUARIO A UN ARCHIVO datos.txt
EL CUAL ACTUA COMO UNA BASE DE DATOS. PERMITIENDO VISUALIZAR DESPUES O CUANTAS VECES SEA NECESARIO
LOS DATOS.
PROGRAMADOR : WALTER FRANCISCO CHEREC CASTRO	CARNET: 1990-16-10786	SECCION:B
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;
/********************VARIABLES AUXILIARES******************************/
int N = 3;
#define MAX 30
char lectura[256];
/********************FIN VARIABLES AUXILIARES**************************/




/********************REGISTROS******************************/
struct datos
{
	int carnet;
	string nombre;
	float parcial_1, parcial_2, zona, proyecto_f, examen_f, nota_f = 0;
};
/********************FIN REGISTROS******************************/




/********************CLASES******************************/
class Alumnos
{
public:
	void ingresar(datos[], int);
	void mostrar();
};
/********************FIN CLASES**************************/




/********************PROCEDIMIENTOS******************************/
void Alumnos::ingresar(datos I[], int N) {
	cout << "\t\t\tUNIVERSIDAD MARIANO GALVEZ DE GUATEMALA" << endl;
	cout << "\t\t\tFACULTAD DE INGENIERIA EN SISTEMAS\n\n" << endl;
	for (int i = 0; i < N; i++)
	{
		ofstream salida;
		salida.open("datos.txt", ios::app);
		cout << "\t\t\t         INGRESE SU CARNET :"; cin >> I[i].carnet;
		cout << "\t\t\t         INGRESE SU NOMBRE :"; cin >> I[i].nombre;



		cout << "\t\t\t INGRESE SU PRIMER PARCIAL :"; cin >> I[i].parcial_1;
		/********************VALIDACIONES RANGO DE NOTAS******************************/
		while (I[i].parcial_1<0 || I[i].parcial_1>10)
		{
			cout << "\t\t\tERROR: Nota no es Valido. INGRESE SU PRIMER PARCIAL :"; cin >> I[i].parcial_1;
		}
		/********************FIN VALIDACIONES RANGO DE NOTAS******************************/



		cout << "\t\t\tINGRESE SU SEGUNDO PARCIAL :"; cin >> I[i].parcial_2;
		/********************VALIDACIONES RANGO DE NOTAS******************************/
		while (I[i].parcial_2<0 || I[i].parcial_2>20)
		{
			cout << "\t\t\tERROR: Nota no es Valido. INGRESE SU SEGUNDO PARCIAL :"; cin >> I[i].parcial_2;
		}
		/********************FIN VALIDACIONES RANGO DE NOTAS******************************/



		cout << "\t\t\t           INGRESE SU ZONA :"; cin >> I[i].zona;
		/********************VALIDACIONES RANGO DE NOTAS******************************/
		while (I[i].zona<0 || I[i].zona>20)
		{
			cout << "\t\t\tERROR: Nota no es Valido. INGRESE SU ZONA :"; cin >> I[i].zona;
		}
		/********************FIN VALIDACIONES RANGO DE NOTAS******************************/



		cout << "\t\t\t INGRESE SU PROYECTO FINAL :"; cin >> I[i].proyecto_f;
		/********************VALIDACIONES RANGO DE NOTAS******************************/
		while (I[i].proyecto_f<0 || I[i].proyecto_f>25)
		{
			cout << "\t\t\tERROR: Nota no es Valido. INGRESE SU PROYECTO FINAL :"; cin >> I[i].proyecto_f;
		}
		/********************FIN VALIDACIONES RANGO DE NOTAS******************************/



		cout << "\t\t\t   INGRESE SU EXAMEN FINAL :"; cin >> I[i].examen_f;
		/********************VALIDACIONES RANGO DE NOTAS******************************/
		while (I[i].examen_f<0 || I[i].examen_f>25)
		{
			cout << "\t\t\tERROR: Nota no es Valido. INGRESE SU EXAMEN FINAL :"; cin >> I[i].examen_f;
		}
		/********************FIN VALIDACIONES RANGO DE NOTAS******************************/



		/*CALCULO DE LA NOTA FINAL-------->*/ I[i].nota_f += I[i].parcial_1 + I[i].parcial_2 + I[i].zona + I[i].proyecto_f + I[i].examen_f;
		salida << I[i].carnet << "\t\t" << I[i].nombre << "\t\t" << I[i].parcial_1 << "\t\t" << I[i].parcial_2 << "\t\t" << I[i].zona << "\t\t" << I[i].proyecto_f << "\t\t" << I[i].examen_f << "\t\t" << I[i].nota_f << endl;
		system("cls");
		cout << endl;
		salida.close();
	}
}




void Alumnos::mostrar() {
	cout << setw(6) << "CARNET" << setw(15) << "NOMBRE" << setw(17) << "PARCIAL_1" << setw(17) << "PARCIAL_2" << setw(13) << "ZONA" << setw(19) << "PROYECTO_F" << setw(15) << "EXAMEN_F" << setw(15) << "NOTA_F" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------";
	for (int m = 0; m < 1; m++)
	{
		/****************LECTURA DESDE EL ARCHIVO datos.txt********************/
		ifstream entrada;
		entrada.open("datos.txt", ios::in);
		while (!entrada.eof())
		{
			cout << lectura << endl;
			entrada.getline(lectura, 256);
		}
		entrada.close();
		/*******FIN DE LA LECTURA DESDE EL ARCHIVO datos.txt*****************/
	}
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
}
/********************FIN PROCEDIMIENTOS******************************/




int main()
{
	int opcion;
	Alumnos registros;
	datos data_alumnos[MAX];


	/********************MENU PRINCIPAL******************************/
	do
	{
		cout << "\t\t\tUNIVERSIDAD MARIANO GALVEZ DE GUATEMALA" << endl;
		cout << "\t\t\tFACULTAD DE INGENIERIA EN SISTEMAS\n\n" << endl;
		cout << "\t\t\t1----------INGRESAR ALUMNOS" << endl;
		cout << "\t\t\t2----------VER ALUMNOS" << endl;
		cout << "\t\t\t3----------BUSCAR ALUMNOS" << endl;//INGRESA CARNET MOSTRAR DATOS TABULAR
		cout << "\t\t\t4----------MODIFICCAR" << endl; //SOLICITAR CARNET SI APARECE MUESTRA Y MODIFICAR MENSAJE ALUMNO NO EXISTE(CARNET NO SE MODIFICA)
		cout << "\t\t\t5----------ELIMINAR ALUMNOS" << endl; //SOLICITAR CARNET, MOSTRAR ALUMNOS Y ELIMINAR
		cout << "\t\t\t6----------SALIR\n\n";

		cout << "\t\t\tSELECCIONE UNA OPCION :"; cin >> opcion;
		while (opcion<1 || opcion>3)
		{
			cout << "\t\t\tERROR: Opcion no es valida. SELECCIONA UNA OPCION :"; cin >> opcion;
		}
		system("cls");

		switch (opcion)
		{
		case 1:  registros.ingresar(data_alumnos, N);
			break;
		case 2: registros.mostrar();
			break;
		case 3:
			break;
		}
	} while (opcion != 3);
	/********************FIN MENU******************************/
	return 0;
}

