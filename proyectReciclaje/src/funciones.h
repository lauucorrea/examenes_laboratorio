/*
 * funciones.h
 *
 *  Created on: 13 Oct 2021
 *      Author: Lauta
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/// @fn void NormalizarString(char[])
/// @brief
/// La primer posicion del string, la convierte en mayusculas y las demas letras en minusculas
/// @pre
/// @post
/// @param string
void NormalizarString(char string[]);

/// @fn void getString(char[], char[], int, int*)
/// @brief
/// obtiene el mensaje que ingresa el usuario
/// llama a NormalizarString para generalizar los ingresos
/// devuelve un valor que oscila entre 0 y -1 para control de validaciones
/// @pre
/// @post
/// @param cadena
/// @param mensaje
/// @param tam
/// @param validacion
void getString(char cadena[], char mensaje[], int tam, int* validacion);

/// @fn float IngresarFlotante(char[], int, int*)
/// @brief
/// recibe un numero, evalua si es un numero y resta intentos hasta que el contador llega a 0
/// el usuario tiene hasta 4 intentos antes de que no tenga mas oportunidades de ingresar
/// datos erroneos
/// @pre
/// @post
/// @param mensaje
/// @param num
/// @param validacion --> puntero que guarda la validacion de la funcion
/// @return
float IngresarFlotante(char mensaje[], int num, int* validacion);

/// @fn int IngresarEntero(char[], int, int*)
/// @brief
/// recibe un numero, evalua si es un numero y resta intentos hasta que el contador llega a 0
/// el usuario tiene hasta 4 intentos antes de que no tenga mas oportunidades de ingresar
/// datos erroneos
/// @pre
/// @post
/// @param mensaje
/// @param num
/// @param validacion
/// @return
int IngresarEntero(char mensaje[], int num, int* validacion);
/// @fn int ValidarNumero(char[])
/// @brief
/// valida caracter a caracter si el dato ingresado es un int
/// @pre
/// @post
/// @param number
/// @return
int ValidarNumero(char number[]);
/// @fn int ValidarString(char[])
/// @brief
/// valida caracter a caracter si el dato ingresado es un char
/// @pre
/// @post
/// @param string
/// @return
int ValidarString(char string[]);
/// @fn void MostrarMenu()
/// @brief
/// Muestra el menu de seleccion
/// @pre
/// @post
void MostrarMenu();
#endif /* FUNCIONES_H_ */
