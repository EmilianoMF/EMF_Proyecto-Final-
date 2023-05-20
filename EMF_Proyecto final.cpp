#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>// funcione new y delete
#include <vector>

using namespace std;

//definición de la funcion
void Alta();
void listas();
void archivos();
void eliminar();
void modificar();

int alta, *codigo, contador;
string *nombre, *genero, *descripcion, *status;
float *precio, *iva, *total;
int main()
{
	int opc;
	int num = 3;
	printf("%c%c%c%c%c%c%c%c%c%c\n",1,1,1,1,1,1,1,1,1,1);
	printf("1.-Alta\n2.-Lista\n3.-Limpiar pantalla\n4.-Modificar\n5.-Eliminar\n6.-Salir\n");
	scanf_s("%d", &opc);

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}

void Alta()
{
	printf("Digite el numero de registros que desea dar de alta \n");
	scanf_s("%d", &alta);
	codigo = new int[alta]; //arreglos
	precio = new float[alta];
	nombre = new string[alta];
	status = new string[alta];
	genero = new string[alta];
	descripcion = new string[alta];

	for (int i = 0; i < alta; i++)
	{

		printf("%c%c%c%c%c%c%c%c%c%c\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, 3);
		printf("Ingrese el c%cdigo \n", 162);
		scanf_s("%d", &codigo[i]); 
		while (getchar() != '\n'); //se vacia el buffer o el espacio 
		printf("Ingrese nombre del art%cculo \n",161);
		getline(cin, nombre[i]); //permite los espacios en el nombre
		printf("Ingrese el precio \n");
		scanf_s("%f", &precio[i]);
		precio[i] = precio[i] * 1.16;
		while (getchar() != '\n');
		printf("Ingresa el g%cnero \n",130);
		getline(cin, genero[i]);
		printf("Ingresa una descripci%cn al art%cculo \n",162,161);
		getline(cin, descripcion[i]);
		//* subtotal, * iva, * total

	}
}

void listas()
{
	for (int i = 0; i < alta; i++)
	{
		//if (matricula[i] == 0)
		if (status[i] == "ELIMINADO")
		{
			printf("REGISTRO ELIMINADO %d \n", i + 1);
		} 
		else
		{
			printf("%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176);
			printf("Registro %d \n", i + 1);
			printf("C%cdigo:\t%d \n",162, codigo[i]);
			printf("Nombre:\t%s \n", nombre[i].c_str());
			printf("Precio:\t%f \n", precio[i]);
			printf("G%cnero:\t%s \n",130, genero[i].c_str());
			printf("Descripci%cn: %s \n",162, descripcion[i].c_str());
		}
	}
}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2,texto3,texto4;
	float texto1;

	nombrearchivo = "Altas videojuegos.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}

	archivo << "CÓDIGO" << "\t\t";
	archivo << "NOMBRE" << "\t \t";
	archivo << "PRECIO" << "\t \t";
	archivo << "GÉNERO" << "\t \t";
	archivo << "DESCRIPCIÓN" << "\t \t";

	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			texto2 = "\nREGISTRO ELIMINADO ";
			texto = i+1;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			archivo <<"\n";
			texto = codigo[i];
			archivo << texto << "\t" << "\t";
			texto2 = nombre[i];
			archivo << texto2 << "\t" << "\t";
			texto1 = precio[i];
			archivo << texto1 << "\t" << "\t";
			texto3 = genero[i];
			archivo << texto3 << "\t" << "\t";
			texto4 = descripcion[i];
			archivo << texto4 << "\t" << "\t";
		
		}
	}


	archivo.close();
}

void eliminar()
{
	int j;
	printf("Ingrese el  registro a eliminar \n");
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Registro %d eliminado \n", j + 1);
		status[i] = "ELIMINADO";
		/*
		matricula[i] = 0;
		nombre[i] = " ";
		calf[i] = 0;
		calflab[i] = 0;
		*/
	}
}

void modificar()
{
	int j, opcion, op2;
	do
	{
		printf("ingrese el numero registro a modificar \n");
		scanf_s("%d", &j);
		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++)
		{
			if ((status[i] == "ELIMINADO"))
			{
				printf("REGISTRO %d ELIMINADO \n", i + 1);
				printf("Ingrese un registro valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("ingrese que desea modificar 1.-C%cdigo, 2.-Nombre, 3.-Precio, 4.-G%cnero, 5.-Descripci%cn \n",162,130,162);
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el c%cdigo \n",162);
			scanf_s("%d", &codigo[i]);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese nombre \n");
			getline(cin, nombre[i]);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el precio \n");
			scanf_s("%f", &precio[i]);
			precio[i] = precio[i] * 1.16;
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingresa el g%cnero \n",130);
			getline(cin, genero[i]);
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingresa una descripci%cn \n",162);
			getline(cin, descripcion[i]);
		}
		break;
		
	}
	
}