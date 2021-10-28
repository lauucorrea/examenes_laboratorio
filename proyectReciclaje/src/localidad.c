#include "localidad.h"
#include "funciones.h"

int BuscarLocalidadPorId(eLocalidad lista[], int len, int id){
	int index = -1;
		for(int i = 0; i < len; i++){
			if(lista[i].idLocalidad == id){
				index = i;
				break;
			}
		}
	 return index;
}

int ImprimirLocalidad(int localidad){
	int validation = 0;
	char LDZ[] = {"Lomas de Zamora"};
	char BFL[] = {"Banfield"};
	char AVN[] = {"Avellaneda"};

	//elijo default para error porque en la funcion de ingresar entero, paso como parametro el limite maximo de ese numero
	//por lo tanto lo unico a valorar son los valores menores a 0

	switch(localidad){
		case 1:
			printf("Localidad: %s \n", LDZ);
		break;
		case 2:
			printf("Localidad: %s \n", BFL);
		break;
		case 3:
			printf("Localidad: %s \n", AVN);
		break;
		default:
			validation = -1;
		break;
	}
	return validation;
}
