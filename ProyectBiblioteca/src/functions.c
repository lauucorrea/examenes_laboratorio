#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int DeployMainMenu(){
	int opcion;
	int validacion;
	int retorno;
	puts("------------------------------------");
    puts("MENU:");
    puts("1. Leer archivo con los datos de los libros (.csv)");
    puts("2. Leer archivo con los datos de las editoriales (.csv)");
    puts("3. Ordenar lista de Libros");
    puts("4. Imprimir libros en pantalla");
    puts("5. Listar libros de la editorial MINOTAURO.");
    puts("6. Salir.\n");

    opcion = IngresarEntero("Elija una opcion:", &validacion);

	if(validacion == 0 && opcion!= 6){
		retorno = opcion;
	}else{
		retorno = -1;;
	}

	return retorno;
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

int IngresarEntero(char mensaje[], int* validacion)
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
				puts("El dato ingresado no es un numero");
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

	    }while(intentos >= 1 && opcionValida <0);
	    return opcionValida;


}
float IngresarFlotante(char mensaje[], int* validacion){
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
		puts("El dato ingresado no es un numero");
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

	}while(intentos >= 1 && opcionValida <0);
	return opcionValida;
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

int FindMaxNumber(int num1, int num2){
	int retorno = -1;
	 if(num1 > num2){
		 retorno = 1;
	 }
	 if(num1 < num2){
		 retorno = 2;
	 }
	 if(num1 == num2){
		 retorno = 0;
	 }
	 return retorno;
}

