#include "Libros.h"
#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eLibro* book_new(){
	eLibro* nuevoLibro;

	nuevoLibro = (eLibro*)malloc(sizeof(eLibro));

	if(nuevoLibro != NULL){
		nuevoLibro -> id = 0;
		nuevoLibro->idEditorial = 0;
		strcpy(nuevoLibro -> autor, "");
		strcpy(nuevoLibro -> titulo, "");
	}

	return nuevoLibro;
}

void book_delete(eLibro* this){
	if(this != NULL){
		free(this);
	}
}

int book_setId(eLibro* this,int id){
	int retorno = -1;

	if(this != NULL){
		if(id >= 0){
			this -> id = id;
			retorno = 0;
		}
	}

	return retorno;
}


int book_getId(eLibro* this, int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}


int book_setIdEditorial(eLibro* this,int idEditorial){
	int retorno = -1;

	if(this != NULL){
		if(idEditorial >= 0){
			this -> idEditorial = idEditorial;
			retorno = 0;
		}
	}

	return retorno;
}

int book_getIdEditorial(eLibro* this, int* idEditorial){
	int retorno = -1;

	if(this != NULL && idEditorial != NULL){
		*idEditorial = this -> idEditorial;
		retorno = 0;
	}
	return retorno;
}



int book_setAutor(eLibro* this,char* autor){
	int retorno = -1;

	if(this != NULL && autor != NULL){
		strcpy(this -> autor, autor);
		retorno = 0;
	}
	return retorno;
}

int book_getAutor(eLibro* this,char* autor){
	int retorno = -1;

	if(this != NULL && autor != NULL){
		strcpy(autor, this -> autor);
		retorno = 0;
	}

	return retorno;
}

int book_setTitulo(eLibro* this,char* titulo){
	int retorno = -1;

	if(this != NULL && titulo != NULL){
		strcpy(this -> titulo, titulo);
		retorno = 0;
	}
	return retorno;
}

int book_getTitulo(eLibro* this,char* titulo){
	int retorno = -1;

	if(this != NULL && titulo != NULL){
		strcpy(titulo, this -> titulo);
		retorno = 0;
	}

	return retorno;
}
int book_setPrecio(eLibro* this,float precio){
	int retorno = -1;

	if(this != NULL){
		if(precio >= 0){
			this -> precio = precio;
			retorno = 0;
		}
	}

	return retorno;
}

int book_getPrecio(eLibro* this,float* precio){
	int retorno = -1;

	if(this != NULL){
		if(precio >= 0){
			*precio = this -> precio;
			retorno = 0;
		}
	}

	return retorno;
}

eLibro* book_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr){
	eLibro* nuevoLibro;
	nuevoLibro = book_new();

	int idAux;
	float precioAux;
	int idEditorialAux;

	idAux = atoi(idStr);
	precioAux = atof(precioStr);
	idEditorialAux = atoi(idEditorialStr);

	if(nuevoLibro != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL){
		book_setId(nuevoLibro, idAux);
		book_setTitulo(nuevoLibro, tituloStr);
		book_setAutor(nuevoLibro, autorStr);
		book_setPrecio(nuevoLibro, precioAux);
		book_setIdEditorial(nuevoLibro, idEditorialAux);
	}

	return nuevoLibro;
}

int book_sortList(LinkedList* pArrayBook){
	int retorno = -1;

	if(pArrayBook != NULL){
		retorno = ll_sort(pArrayBook, book_sortByAutor, 1);
		if(retorno != -1){
			retorno = controller_ListBooks(pArrayBook);
			puts("------------------------------------");
			puts("Lista Ordenada con exito por AUTOR");
		}
	}
	return retorno;
}



int book_sortByAutor(void* firstBook, void* secondBook){
	int retorno = 0;

	char firstAutor[50];
	char secondAutor[50];
	int control1;
	int control2;

	control1 = book_getAutor(firstBook, firstAutor);
	control2 = book_getAutor(secondBook, secondAutor);

	if(strcmp(firstAutor,secondAutor) > 0 && (control1 != -1 && control2 != -1)){
		//El primer nombre es mayor al segundo (va primero)
		retorno = 1;
	}
	if(strcmp(firstAutor,secondAutor) < 0){
		retorno = -1;
	}

	return retorno;
}


int book_checkAddElementToArray(void* auxElement){
	eLibro* pLibro;
	int retorno = -1;
	pLibro = auxElement;
	if(pLibro -> idEditorial == 4){
		retorno = 0;
	}

	return retorno;
}
