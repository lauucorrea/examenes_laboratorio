/*
 * funciones.c
 *
 *  Created on: 13 Oct 2021
 *      Author: Lauta
 */

#include "funciones.h"


void MostrarMenu(){
	puts("-------------------------------------------");
	puts("1. Alta de cliente\n");
	puts("2. Modificar datos de cliente\n");
	puts("3. Baja de cliente\n");
	puts("4. Crear pedido de recoleccion\n");
	puts("5. Procesar residuos\n");
	puts("6. Imprimir clientes c/cantidad de pedidos en estado pendiente\n");
	puts("7. Imprimir pedidos pendientes\n");
	puts("8. Imprimir pedidos procesados\n");
	puts("9. Ingresar localidad y cantidad de pedidos pendientes\n");
	puts("10.Promedio de la cantidad de kilos de prolipropileno reciclado\n");
	puts("11. Salir");
}


void NormalizarString(char string[]){
	int flag = 0;
	for(int i = 0 ; i<strlen(string);i++){
		if(flag == 0){
			string[i] = toupper(string[i]);
			flag = 1;
		}else
		{
			string[i] = tolower(string[i]);
		}

	}
}
int ValidarNumero(char number[]){
    int i=0;
    int j;
    int ret=0;

    j=strlen(number);
    while(i<j && ret==0){
        if(isdigit(number[i])!=0){
            i++;
        }
        else{
            ret=-1;
        }
    }
    return ret;
}
//isalpha retorna 0 cuando se trata de un numero
//si no retorna 0 sigue recorriendo
//si retorna 0 , la validacion queda en -1 (dato erroneo)
int ValidarString(char string[]){
    int i=0;
    int retorno=0;
    int j;
    j=strlen(string);
    while(i<j && retorno==0){
        if(isalpha(string[i])!=0){
            i++;
        }
        else{
            retorno=-1;
        }
    }
    return retorno;
}

void getString(char cadena[], char mensaje[], int tam, int* validacion)
{
	char auxiliarString[50];
	int intentos;
	int estado;
	intentos = 4;
	if (cadena != NULL && mensaje != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);
		estado = ValidarString(auxiliarString);
		while (estado !=0  && intentos > 0)
		{
			intentos--;
			if(strlen(auxiliarString) > tam){
				printf("Reingrese %s no es una opcion: ", auxiliarString);
				printf("Te quedan %d intentos", intentos);
				fflush(stdin);
				scanf("%[^\n]", auxiliarString);
				estado = ValidarString(auxiliarString);
			}
		}
		if(intentos <=0){
			puts("-------------------------------------------");
			puts("Se te acabaron los intentos.");
			*validacion = -1;
		}else{
			NormalizarString(auxiliarString);
			strcpy(cadena, auxiliarString);
			*validacion = 0;
		}

	}
}

int IngresarEntero(char mensaje[], int num, int* validacion)
{
	char opcion[50];
	    int estado;
	    int intentos;
	    int opcionValida=0;
	    intentos = 4;
	    do{
	    printf("%s", mensaje);
	    fflush(stdin);
	    scanf("%[^\n]", opcion);
	    estado = ValidarNumero(opcion);/****/
	    while(estado!=0 && intentos >0){
	    	intentos--;
	        printf("ERROR. '%s' no es una opcion. Debe ser menor a %d\n", opcion, num);
	        printf("Te quedan %d intentos\n", intentos);
	        fflush(stdin);
	        scanf("%[^\n]", opcion);
	        estado=ValidarNumero(opcion);
	    }
	    if(intentos <=0){
	    	puts("-------------------------------------------");
	    	puts("Se te acabaron los intentos.");
	    	*validacion = -1;
	    }else{
	    	opcionValida= atoi(opcion);
	    	*validacion = 0;
	    }

	    }while(intentos >= 1 && (opcionValida <0 || opcionValida > num));
	    return opcionValida;


}
float IngresarFlotante(char mensaje[], int num, int* validacion){
	char opcion[50];
	int estado;
	int intentos;
	int opcionValida;
	intentos = 4;
	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", opcion);
		estado = ValidarNumero(opcion);
	while(estado!=0 && intentos >= 1){
		intentos--;
		printf("ERROR. '%s' no es una opcion. Debe ser menor a %d\n", opcion, num);
		printf("Te quedan %d intentos\n", intentos);
		fflush(stdin);
		scanf("%[^\n]", opcion);
		estado=ValidarNumero(opcion);
	}
	if(intentos <=0){
		puts("-------------------------------------------");
		puts("Se te acabaron los intentos.");
		 *validacion = -1;
	}else{
		opcionValida= atof(opcion);
		*validacion = 0;
	}

	}while(intentos >= 1 && (opcionValida <0 || opcionValida > num));
	return opcionValida;
}
