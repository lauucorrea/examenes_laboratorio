/*
 * clientes.h
 *
 *  Created on: 8 Oct 2021
 *      Author: Lauta
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_
#define EMPTY 0
#define FILLED 1
#define MODIFIED -1
#define TAM 200
#define TAM2 400
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	int idCliente;
	char empresa[50];
	int cuit;
	char direccion[50];
	int localidad;
	int isEmpty;

} eCliente;


/// @fn eCliente IngresarUnCliente(eCliente[], int, int*)
/// @brief recibe la lista de clientes como parametro, y guarda la informacion correspondiente
///
/// @pre
/// @post
/// @param lista
/// @param idCliente
/// @param validacion --> devuelve 0 o -1 dependiendo del estado de la validacion del ingreso
/// @return
///
eCliente IngresarUnCliente(eCliente lista[],int idCliente,int* validacion);
/// @fn void InicializarListaClientes(eCliente[], int)
/// @brief
/// inicializa la lista de clientes para que aparezcan sus isEmpty en 0
/// recordemos que esto nos permite el control para el ABM
/// @pre
/// @post
/// @param listaClientes
/// @param tam
void InicializarListaClientes(eCliente listaClientes[], int tam);

/// @fn void MostrarListadoClientes(eCliente[], int)
/// @brief
/// muestra la lista de clientes
/// @pre
/// @post
/// @param lista
/// @param tam
/// @return 0 flag lista llena || -1 lista vacia
int MostrarListadoClientes(eCliente lista[], int tam);

/// @fn void MostrarCliente(eCliente, int)
/// @brief
///muestra un solo cliente y la cantidad de pedidos.
/// si se le pasa de parametro cantidadPedidos = 0 , esta funcion evitara
/// mostrar el campo "pedidos" en la impresion del cliente
/// @pre
/// @post
/// @param unCliente
/// @param cantidadPedidos
void MostrarCliente(eCliente unCliente, int cantidadPedidos);

/// @fn void BorrarCliente(eCliente[], int, int*)
/// @brief
/// prototipo a terminar de la funcion BorrarCliente
/// @pre
/// @post
/// @param lista
/// @param tam
/// @param pValidacion --> devuelve el estado de las validaciones internas
void BorrarCliente(eCliente lista[], int tam, int *pValidacion);

/// @fn void CargarCambios(char[], char[], eCliente[], int)
/// @brief
/// guarda los cambios de la opcion 2 del switch.
/// nos permite guardar los cambios de direccion en localidad recorriendo un for
/// @pre
/// @post
/// @param direccion
/// @param localidad
/// @param listaClientes
/// @param posicion --> index del cliente actual
void CargarCambios(char direccion[], eCliente listaClientes[],int posicion);


/// @fn int CompararIdCliente(int, int)
/// @brief
///
/// @pre
/// @post
/// @param idCliente
/// @param IdPedido
/// @return  0 si es el mismo id, y -1 si no es el mismo
int CompararIdCliente(int idCliente, int IdPedido);

/// @fn int BuscarPrimerEspacioLibreClientes(eCliente*, int, int*)
/// @brief
/// Busca el primer espacio libre disponible en el array de clientes
/// @pre
/// @post
/// @param list
/// @param tam
/// @param validation
/// @return index si lo encuentra, -1 para error
int BuscarPrimerEspacioLibreClientes(eCliente* list, int tam, int* validation);
/// @fn int BuscarClientePorId(eCliente*, int, int)
/// @brief
/// Busca un cliente segun el id ingresado por el usuario
/// @pre
/// @post
/// @param list
/// @param len
/// @param id
/// @return index si encuentra, -1 para errores
int BuscarClientePorId(eCliente* list, int len,int id);
/// @fn int BuscarClientePorLocalidad(eCliente[], int, int)
/// @brief
/// Busca un cliente segun la localidad (int) ingresada por el usuario
/// @pre
/// @post
/// @param lista
/// @param localidad
/// @param len
/// @return index si encuentra, -1 para control de errores
int BuscarClientePorLocalidad(eCliente lista[], int localidad, int len);


#endif /* CLIENTES_H_ */
