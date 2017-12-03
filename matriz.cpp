//MULTIPLICACION DE MATRICES
//ALUMNO: JESUS R. GONZALEZ L.
//Cedula: 23.543.415
#include <time.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{	
	int hilos,total;

	//Crear matrices
	cout<<"---------------------------------------------------------"<<endl;
	cout << "  Ingrese el tamaño de las matrices" << endl;
	cin  >> total;
	srand(time(NULL));
	int **ma = new int*[total];
	int **mb = new int*[total];
	int **mr = new int*[total];	
	for(int i = 0; i < total; i++)
	{
		ma[i] = new int[total];
		mb[i] = new int[total];
		mr[i] = new int[total];
	}

	//Llenado de la matriz con numeros aleatorios
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < total; j++) 
		{
			ma[i][j] = rand() % 10 + 1;
			mb[i][j] = rand() % 10 + 1;
			
		
		}
        }

	//Asignar Cantidad de Hilos a Utilizar
	cout << "  Ingrese La cantidad de Hilos" << endl;	
	cin  >> hilos;	
	omp_set_num_threads(hilos);

	//Multiplicacion
	clock_t begin = clock();

	#pragma omp parallel for
		for (int i = 0; i < total; i++) 
		{

			#pragma omp parallel for
			for (int j = 0; j < total; j++)
			{
				mr[i][j] = ma[i][j] * mb[j][i];
			}

		}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n TIEMPO: %6f Segundos \n",time_spent);
	cout<<"--------------------------------------------------------------"<<endl;

    return 1;
		
}
