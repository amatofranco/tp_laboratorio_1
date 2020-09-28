/*
 * utn_inputs.h
 *
 *  Created on: Sep 27, 2020
 *      Author: francoamato
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int myGets (char* cadena, int longitud);

int esNumerica(char* cadena, int limite);

int getInt(int* pResultado);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int esFlotante(char* cadena, int limite);

int getFloat(float* pResultado);

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


int esNegativo(char *cadena, int limite);

int getNegativo(int *pResultado);

int utn_getNegativo(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);


int esNombre(char *cadena, int limite);

int getNombre(char *pResultado);

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,int reintentos);










#endif /* UTN_INPUTS_H_ */
