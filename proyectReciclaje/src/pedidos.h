/*
 * pedidos.h
 *
 *  Created on: 11 Oct 2021
 *      Author: Lauta
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define EMPTY 0
#define FILLED 1
#define MODIFIED -1
#define TAM 200
#define TAM2 400
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
	int idCliente;
	int idPedido;
	float kgCargamento;
	int estadoPedido;

}ePedido;


/// @fn ePedido IngresarUnPedido(ePedido[], int, int, float, int, int, int, int*)
/// @brief Recibe todos los datos  necesarios para la carga de la estructura.
/// dentro de cada ingreso se evalua una validacion de datos de ingreso
/// y ante cualquier error, no registra al usuario
/// @pre
/// @post
/// @param lista --> lista de pedidos
/// @param idPedido --> identificador incrementado del pedido
/// @param idCliente --> identificador incrementado del cliente
/// @param kgCargamento --> cantidad de kilos del pedido
/// @param estadoPedido --> el estado con el que inicializamos el pedido (1 significa cargado pendiente)
/// @param validacionId --> guarda el estado de la validacion del ingreso del id del pedido
/// @param validacionKg --> guarda el estado de la validacion del ingreso de la cantidad de kg plasticos
/// @param pValidacion --> este es el puntero que guarda el estado de la validacion en el main
/// @return
ePedido IngresarUnPedido(ePedido lista[],int idPedido,int idCliente,float kgCargamento, int validacionId, int validacionKg, int* pValidacion);
/// @fn void InicializarListaPedidos(ePedido[], int)
/// @brief
/// solo setea el estado de pedido en 0, para que se sepa que nunca se cargo ningun pedido
/// @pre
/// @post
/// @param listaPedidos
/// @param tam
void InicializarListaPedidos(ePedido listaPedidos[], int tam);
/// @fn int MostrarListadoPedidos(ePedido[], int)
/// @brief
/// Muestra todos los pedidos de la lista de estructuras listaPedidos
/// @pre
/// @post
/// @param lista --> lista de estructuras de tipo ePedido
/// @param tam --> tamaño de la lista
/// @return
int MostrarListadoPedidos(ePedido lista[], int tam);
/// @fn void MostrarPedido(ePedido)
/// @brief
/// Muestra un pedido que se le pasa por parametro invocando a la lista[i]
/// @pre
/// @post
/// @param unPedido
void MostrarPedido(ePedido unPedido);
/// @fn void BuscarEstadoPedido(int, int, int, int*)
/// @brief en los pedidos, 1 significa en proceso, -1 completado
/// pasando estos datos en estadoAbuscar como parametro en su llamada,
/// devolvera 0 si se encontraron coincidencias o -1 si no se encontraron
/// @pre
/// @post
/// @param indicePedidos
/// @param indiceClientes
/// @param estadoABuscar --> valor a reemplazar para encontrar el estado que queremos evaluar
/// @param pValidacion
void BuscarEstadoPedido(ePedido listaPedidos[],int indicePedidos, int indiceClientes, int estadoABuscar, int* pValidacion);
/// @fn int BuscarPedidoPorId(ePedido*, int, int)
/// @brief
/// Busca un pedido segun el id
/// @pre
/// @post
/// @param list
/// @param len
/// @param id
/// @return index si esta bien , -1 para control de errores
int BuscarPedidoPorId(ePedido* list, int len,int id);
/// @fn int BuscarPedidoPorIdCliente(ePedido*, int, int)
/// @brief
/// busca un pedido asignado a un cliente
/// @pre
/// @post
/// @param list
/// @param len
/// @param id --> id del cliente a buscar
/// @return index si esta bien, -1 control de errores
int BuscarPedidoPorIdCliente(ePedido* list, int len,int id);
/// @fn int BuscarPrimerEspacioLibrePedidos(ePedido*, int, int*)
/// @brief
/// Busca espacios en la lista de pedidos que no se encuentren pendientes para ocuparlos con otro pedido
/// @pre
/// @post
/// @param list
/// @param tam
/// @param validation
/// @return devuelve index si esta bien, -1 para control de errores
int BuscarPrimerEspacioLibrePedidos(ePedido* list, int tam, int* validation);
/// @fn void CalcularCantidadPedidos(ePedido[], int, int, int*, int*, int*)
/// @brief
/// Cuenta la cantidad de pedidos por cliente, devuelve el resultado
/// de los contadores por parametros al main
/// @pre
/// @post
/// @param lista
/// @param tam
/// @param idCliente --> id del cliente que estamos evaluando
/// @param cantidadCompletados --> puntero a int
/// @param cantidadPendientes --> puntero a int
/// @param cantidadTotal --> puntero a int
void CalcularCantidadPedidos(ePedido lista[], int tam, int idCliente, int* cantidadCompletados, int* cantidadPendientes, int* cantidadTotal);


#endif /* PEDIDOS_H_ */

