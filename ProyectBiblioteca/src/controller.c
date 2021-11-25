#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libros.h"
#include "Editorial.h"
#include "functions.h"
#include "parser.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadBooksFromText(char* path , LinkedList* pArrayListBook)
{
	FILE* pFile;

	int retorno = -1;
	pFile = fopen(path, "r");

	if(pFile != NULL){
		retorno = parser_BookFromText(pFile, pArrayListBook);
	}
	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadEditorialsFromText(char* path , LinkedList* pArrayListEditorial)
{
	FILE* pFile;

	int retorno = -1;
	pFile = fopen(path, "r");

	if(pFile != NULL){
		retorno = parser_EditorialFromText(pFile, pArrayListEditorial);
	}
	fclose(pFile);

    return retorno;
}


int controller_loadBooksFromFile(LinkedList* pArrayListBook ,LinkedList* pArrayListEditoriales,int option, int* pFlagFileLoaded, char* nameFile)
{
	int validation = -1;
	char originalFile[] = "Data";
	int control;

		switch(option){
			case 1:
				ll_clear(pArrayListBook);
				control = strcmp(nameFile, originalFile);
				if(control == 0){
					*pFlagFileLoaded = 0;
					validation = controller_loadBooksFromText("src/data.csv", pArrayListBook);
					if(validation != -1){
						controller_ListBooks(pArrayListBook, pArrayListEditoriales);
					}
				}else{
					puts("El nombre del archivo esta mal ingresado");
				}


			break;
			case 2:
				puts("Cancelando carga de datos...");
				puts("Volviendo a cargar el Menu principal...");
			break;
			default:
				puts("La opcion ingresada no es correcta");
			break;
		}
		return validation;
}

int controller_loadEditorialsFromFile(LinkedList* listaEditoriales ,int option, int* pFlagFileLoaded, char* nameFile)
{
	int validation = -1;
	char originalFile[] = "Editoriales";
	int control;

		switch(option){
			case 1:
				ll_clear(listaEditoriales);
				control = strcmp(nameFile, originalFile);
				if(control == 0){
					*pFlagFileLoaded = 0;
					validation = controller_loadEditorialsFromText("src/editoriales.csv", listaEditoriales);
				}else{
					puts("El nombre del archivo esta mal ingresado");
				}


			break;
			case 2:
				puts("Cancelando carga de datos...");
				puts("Volviendo a cargar el Menu principal...");
			break;
			default:
				puts("La opcion ingresada no es correcta");
			break;
		}
		return validation;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_addBook(LinkedList* pArrayListBook)
{
	eLibro* oneBook;
	int retorno = -1;

	int validacionTitulo;
	int validacionAutor;
	int validacionPrecio;
	int validacionEditorial;

	int idLibro;
	char titulo[128];
	char autor[128];
	float precio;
	int editorial;

	oneBook = book_new();
	idLibro = controller_calculateId(pArrayListBook);

	if(pArrayListBook != NULL){

		getString(titulo, "Ingrese el titulo del libro", 128, &validacionTitulo);
		getString(autor, "Ingrese el nombre del autor", 128, &validacionAutor);
		precio = IngresarFlotante("Ingrese el precio del libro", &validacionPrecio);
		editorial = IngresarEntero("Ingrese la editorial del libro", &validacionEditorial);

		if(oneBook != NULL){
			if(validacionTitulo != -1 && validacionAutor != -1 && validacionPrecio != -1 && validacionEditorial != -1 && (editorial > 0 && editorial < 7)){
				idLibro++;
				book_setTitulo(oneBook, titulo);
				book_setAutor(oneBook, autor);
				book_setPrecio(oneBook, precio);
				book_setId(oneBook, idLibro);
				book_setIdEditorial(oneBook, editorial);
				ll_add(pArrayListBook, oneBook);
				controller_saveLastBookAsText("ultimoIdLibros.csv", idLibro);
				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_ListBooks(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial)
{
	eLibro* pBook;

    int retorno = -1;

    int control = -1;

    int idLibroObtenido;
    float precioObtenido;
    char autorObtenido[128];
    char tituloObtenido[128];

    int idEditorialObtenido;
    char editorialDefinida[128];

    if(pArrayListBook != NULL){
        puts("ID \t\t TITULO \t\t AUTOR \t\t PRECIO \t\t EDITORIAL");
        retorno = 0;

        for(int i = 0; i< ll_len(pArrayListBook); i++){
        	pBook = ll_get(pArrayListBook, i);

        	if(pBook != NULL){

            	book_getId(pBook, &idLibroObtenido);
            	book_getTitulo(pBook, tituloObtenido);
            	book_getAutor(pBook, autorObtenido);
            	book_getPrecio(pBook, &precioObtenido);
            	book_getIdEditorial(pBook, &idEditorialObtenido);

            	control = editorial_getEditorialNameById(pArrayListEditorial, idEditorialObtenido, editorialDefinida);

            	printf("%5d %20s %20s %20.2f %20s \n\n", idLibroObtenido, tituloObtenido, autorObtenido, precioObtenido, editorialDefinida );
        	}

        }
    }

    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_sortBooks(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial)
{
    int retorno = -1;

    if(pArrayListBook != NULL){
    	retorno = book_sortList(pArrayListBook, pArrayListEditorial);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_saveBookAsText(char* path , LinkedList* pArrayListBook)
{
    FILE* pFile;
    eLibro* book;
    int retorno = -1;
    int i;
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int idEditorial;

    if(pArrayListBook != NULL && path != NULL && ll_isEmpty(pArrayListBook) == 0){
    	retorno = 0;
        pFile = fopen(path,"w");
        fprintf(pFile,"idLibro,titulo,autor,precio,idEditorial\n");
        for(i=0; i< ll_len(pArrayListBook);i++){
        	book = (eLibro*) ll_get(pArrayListBook, i);

        	book_getId(book, &id);
        	book_getTitulo(book, titulo);
        	book_getAutor(book, autor);
        	book_getPrecio(book, &precio);
        	book_getIdEditorial(book, &idEditorial);

        	fprintf(pFile,"%d,%s,%s,%f,%d\n",id,titulo,autor,precio,idEditorial);
        }
    	fclose(pFile);
    	if(ll_len(pArrayListBook) == i ){
    	  retorno = 0;
    	}
    }
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadLastBookIdFromText(char* path)
{
	FILE* pFile;
	int retorno = -1;
	pFile = fopen(path, "r");

	if(pFile != NULL){
		retorno = parser_OneBookFromText(pFile);
		printf("EL ID CARGADO POR ULTIMO ES, %d\n", retorno);
	}
	fclose(pFile);

    return retorno;
}

int controller_saveLastBookAsText(char* path, int id){
	FILE* pFile;
	int retorno = -1;

	   if(path != NULL){
	    	retorno = 0;
	        pFile = fopen(path,"w");

				fprintf(pFile,"idLastBook\n");
				fprintf(pFile,"%d\n",id);

	    	fclose(pFile);

	    }
	return retorno;
}

//devuelve el id generado, o -1
int controller_calculateId(LinkedList* pArrayListBook){
	eLibro* book;
	int idLibro;
	int idMax = -1;
	int flagFirstBook = 1;
	int foundedId;

	if(pArrayListBook != NULL){
		if(ll_len(pArrayListBook) > 0){
			for(int i = 0; i < ll_len(pArrayListBook);i++){
				book = (eLibro*) ll_get(pArrayListBook, i);
				if(book != NULL){
					book_getId(book, &idLibro);

					if(flagFirstBook == 1 || idLibro > idMax){
						idMax = idLibro;
						flagFirstBook = 0;
					}
				}
			}
		}
	}

	foundedId = controller_loadLastBookIdFromText("ultimoIdLibros.csv");

	if(idMax < foundedId){
		idMax = foundedId;
	}
	return idMax;
}

int controller_listBooksFromEditorialMinotauro(LinkedList* bookList, LinkedList* pArrayEditorial){

	LinkedList* subList;

	int retorno = -1;

	subList = ll_newLinkedList();

	subList = ll_filter(bookList, book_checkAddElementToArray);
	if(subList != NULL){
		retorno = controller_ListBooks(subList,pArrayEditorial);
	}
	return retorno;
}

int controller_applyDisccountBooks(LinkedList* bookList){
	LinkedList* subList;

	int retorno = -1;

	subList = ll_newLinkedList();

	subList = ll_map(bookList, book_checkIfDisccount);
	if(subList != NULL){
		retorno = 0;
	}

	return retorno;
}

int controller_countBooksWithId(LinkedList* pArrayBookList, int id){
	eLibro* pLibro;
	int idObtenido;
	int retorno = -1;
	int control;
	int contadorCoincidencias = 0;

	for(int i =0; i<ll_len(pArrayBookList); i++){
		pLibro = ll_get(pArrayBookList, i);
		control = book_getId(pLibro, &idObtenido);
		if(control != -1){
			contadorCoincidencias++;
		}
	}

	if(contadorCoincidencias > 0){
		retorno =0;
	}

	return retorno;
}
