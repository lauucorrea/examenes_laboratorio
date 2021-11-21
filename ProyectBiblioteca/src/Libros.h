#include "LinkedList.h"
#ifndef libros_H_INCLUDED
#define libros_H_INCLUDED

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int idEditorial;
}eLibro;
//Reserva y asigna un espacio en memoria para el nuevo empleado generado
eLibro* book_new();

//Carga los datos en el espacio asignado por book_new
eLibro* book_newParametros(char* idStr,char* titulo,char* autor, char* precio, char* idEditorial);

//Libera la memoria reservada para el empleado
void book_delete(eLibro* this);

//Guarda el id del empleado en su atributo Id
int book_setId(eLibro* this,int id);
int book_setIdEditorial(eLibro* this,int idEditorial);

//Obtiene el id del empleado desde su atributo ID
int book_getId(eLibro* this,int* id);
int book_getIdEditorial(eLibro* this, int* idEditorial);

//Guarda el nombre del empleado en su atributo Nombre
int book_setAutor(eLibro* this,char* autor);

//Obtiene el nombre del empleado desde su atributo Nombre
int book_getAutor(eLibro* this,char* autor);

int book_setTitulo(eLibro* this,char* titulo);

int book_getTitulo(eLibro* this,char* titulo);

int book_setPrecio(eLibro* this,float precio);

int book_getPrecio(eLibro* this,float* precio);



//Ordena la lista de empleados segun el critero del cliente
int book_sortList(LinkedList* pArrayBook);

//Ordena la lista de empleados por NOMBRE
int book_sortByAutor(void* firstBook, void* secondBook);

int book_checkAddElementToArray(void* auxElement);
#endif // libros_H_INCLUDED

