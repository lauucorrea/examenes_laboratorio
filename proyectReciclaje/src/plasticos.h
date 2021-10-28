/*
 * plasticos.h
 *
 *  Created on: 12 Oct 2021
 *      Author: Lauta
 */

#ifndef PLASTICOS_H_
#define PLASTICOS_H_
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
	int idPedido;
	float altaDensidad;
	float bajaDensidad;
	float polipropileno;
	float basura;
	int estadoPlasticos;
}ePlasticos;

/// @fn void InicializarListaPlasticos(ePlasticos[], int)
/// @brief
/// Inicia los contadores de la lista de division de plasticos en 0
/// asi como tambien deja disponible el estado del epdido de plastico en EMPTY
/// @pre
/// @post
/// @param listaPlasticos
/// @param tam
void InicializarListaPlasticos(ePlasticos listaPlasticos[], int tam);
/// @fn void AdministrarPlasticos(ePlasticos[], float, int, int*)
/// @brief
/// divide los plasticos segun la cantidad ingresada por el usuario
/// el restante no restado, se considera basura
/// @pre
/// @post
/// @param listaPlasticos
/// @param kgPedido
/// @param index
/// @param pValidacion --> por punteros devuelve el estado del proceso. control de errores 0 / -1
void AdministrarPlasticos(ePlasticos listaPlasticos[], float kgPedido,int index, int* pValidacion);
/// @fn void MostrarPlasticos(ePlasticos[], int)
/// @brief
/// Muestra la distribucion de plasticos segun la posicion de la lista
/// @pre
/// @post
/// @param lista --> lista plastico
/// @param index --> posicion de la lista
void MostrarPlasticos(ePlasticos lista[], int index);
/// @fn void CalcularPropilenoPromedio(ePlasticos[], int, int)
/// @brief
/// Calcula la cantidad de propileno reciclado promedio segun la cantidad de clientes ingresados
/// @pre
/// @post
/// @param listaPlasticos
/// @param totalClientes --> cantidad de clientes ingresados incrementado en el main al elegir la opcion 1
/// @param tam
void CalcularPropilenoPromedio(ePlasticos listaPlasticos[], int totalClientes, int tam);
/// @fn int BuscarPrimerEspacioLibrePlasticos(ePlasticos*, int, int*)
/// @brief
/// Busca espacios disponibles como EMPTY para ingresar nuevas distribuciones de plasticsos
/// @pre
/// @post
/// @param list
/// @param tam
/// @param validation
/// @return index si encuentra espacio, -1 control de errores
int BuscarPrimerEspacioLibrePlasticos(ePlasticos* list, int tam, int* validation);
#endif /* PLASTICOS_H_ */
