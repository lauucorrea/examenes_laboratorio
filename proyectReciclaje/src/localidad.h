/*
 * localidad.h
 *
 *  Created on: 14 Oct 2021
 *      Author: Lauta
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
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
	int idLocalidad;
	char nombreLocalidad[50];
	int cantidadPedidos;
}eLocalidad;


int ImprimirLocalidad(int localidad);
int BuscarLocalidadPorId(eLocalidad lista[], int len, int id);

#endif /* LOCALIDAD_H_ */
