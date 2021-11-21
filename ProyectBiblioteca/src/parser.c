#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "Editorial.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook)
{
	eLibro* pBook;

	char idBook[128];
	char tituloBook[128];
	char autorBook[128];
	char precioBook[128];
	char idEditorial[128];

	int retorno = -1;

	if(pFile != NULL && pArrayListBook != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idBook, tituloBook, autorBook, precioBook,idEditorial);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idBook, tituloBook, autorBook, precioBook,idEditorial);
			pBook = book_newParametros(idBook, tituloBook, autorBook, precioBook, idEditorial);

			if(pBook != NULL && !feof(pFile)){
				retorno = ll_add(pArrayListBook, pBook);
			}
		}
	}

    return retorno;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial){
	eEditorial* pEditorial;

	char idEditorial[128];
	char nombre[128];

	int retorno = -1;

	if(pFile != NULL && pArrayListEditorial != NULL){
		fscanf(pFile, "%[^,],%[^\n]\n", idEditorial, nombre);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^\n]\n", idEditorial, nombre);
			pEditorial = editorial_newParametros(idEditorial, nombre);

			if(pEditorial != NULL && !feof(pFile)){
				retorno = ll_add(pArrayListEditorial, pEditorial);
			}
		}
	}

    return retorno;
}


int parser_OneBookFromText(FILE* pFile)
{
	char idBook[128];
	int retorno = -1;

	if(pFile != NULL){
		fscanf(pFile, "%[^\n]\n", idBook);
		while(!feof(pFile)){
			fscanf(pFile, "%[^\n]\n", idBook);
			retorno = atoi(idBook);
		}
	}

    return retorno;
}

int parser_OneEditorialFromText(FILE* pFile)
{
	char idEditorial[128];
	int retorno = -1;

	if(pFile != NULL){
		fscanf(pFile, "%[^\n]\n", idEditorial);
		while(!feof(pFile)){
			fscanf(pFile, "%[^\n]\n", idEditorial);
			retorno = atoi(idEditorial);
		}
	}

    return retorno;
}

