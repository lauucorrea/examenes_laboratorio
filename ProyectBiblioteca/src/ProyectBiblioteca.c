/*
 ============================================================================
 Name        : ProyectBiblioteca.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libros.h"
#include "controller.h"
#include "editorial.h"
#include "LinkedList.h"
#include "functions.h"
int main(void) {
	setbuf(stdout, NULL);
	int option;
	int optionConfirmOperation = 1;
	int flagBooksLoaded = -1;
	int flagEditorialsLoaded = -1;
	int flagFileSaved = -1;
	int pValidation;
	int validationControl;

	char nameFile[128];

	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();

	do{
		option = DeployMainMenu();
		if(option !=-1){
			switch(option){
			case 1:
            	if(flagBooksLoaded == 0 && flagFileSaved == -1){
            		puts("Hay datos sin guardar en el sistema.");
            		puts("Desea continuar sin guardar los datos?");
            		optionConfirmOperation = IngresarEntero("Ingrese la respuesta: 1. Si 2.No\n", &pValidation);

					if(pValidation != -1){
	            		getString(nameFile, "Ingrese el nombre del archivo a cargar\n", sizeof(nameFile), &pValidation);
	            		if(pValidation != -1){
	            			validationControl = controller_loadBooksFromFile(listaLibros, option, &flagBooksLoaded, nameFile);
	            		}
					}else{
						puts("El dato ingresado es incorrecto");
						validationControl = -1;
					}
            	}else if(flagBooksLoaded != 0){
            		getString(nameFile, "Ingrese el nombre del archivo a cargar", sizeof(nameFile), &pValidation);
            		if(pValidation != -1){
            			validationControl = controller_loadBooksFromFile(listaLibros, option, &flagBooksLoaded, nameFile);
            		}

            	}
			break;
			case 2:
            	if(flagEditorialsLoaded == 0 && flagFileSaved == -1){
            		puts("Hay datos sin guardar en el sistema.");
            		puts("Desea continuar sin guardar los datos?");
            		optionConfirmOperation = IngresarEntero("Ingrese la respuesta: 1. Si 2.No\n", &pValidation);

					if(pValidation != -1){
	            		getString(nameFile, "Ingrese el nombre del archivo a cargar\n", sizeof(nameFile), &pValidation);
	            		if(pValidation != -1){
	            			validationControl = controller_loadEditorialsFromFile(listaEditoriales, optionConfirmOperation, &flagEditorialsLoaded, nameFile);
	            		}
					}else{
						puts("El dato ingresado es incorrecto");
						validationControl = -1;
					}
            	}else if(flagEditorialsLoaded != 0){
            		getString(nameFile, "Ingrese el nombre del archivo a cargar", sizeof(nameFile), &pValidation);
            		if(pValidation != -1){
            			validationControl = controller_loadEditorialsFromFile(listaEditoriales, optionConfirmOperation, &flagEditorialsLoaded, nameFile);
            		}

            	}
			break;
			case 3:
            	if(flagBooksLoaded == 0){
                	validationControl = controller_sortBooks(listaLibros);
                    if(validationControl != -1){
                    	puts("La lista se ordeno correctamente");
                    }else{
                    	puts("ERROR ! No pudo ordenarse la lista");
                    }
            	}else{
            		puts("Error ! Lista Vacia");
            		puts("Deberias cargar al menos un archivo");
            	}

			break;
			case 4:
				if(flagBooksLoaded == 0){
					validationControl = controller_ListBooks(listaLibros);
					if(validationControl != -1){
						puts("------------------------------------");
						puts("Libros enlistados exitosamente");
					}else{
						puts("ERROR ! No pudo imprimirse la lista de libros");
					}
				}else{
            		puts("Error ! Lista Vacia");
            		puts("Deberias cargar al menos un archivo");
            	}
			break;
			case 5:
				validationControl = controller_listBooksFromEditorialMinotauro(listaLibros);
				if(validationControl != -1){
					puts("------------------------------------");
					puts("Libros enlistados exitosamente");
				}
			break;
			}
		}
	}while(option != 6 && option != -1);
}
