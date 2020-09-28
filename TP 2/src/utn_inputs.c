#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Lee de stdin hasta encontrar '\n' o
 * hasta que haya copiado el maximo de longitud de cadena -1
 * @param cadena Puntero al espacio en memoria donde se copiará la cadena obtenida
 * @param longitud Longitud máxima definida para la cadena
 * @return 0 Éxito -1 Error
 */
int myGets(char *cadena, int longitud) {

	int ret = -1;

	char buffer[4096];
	if (cadena != NULL && longitud > 0) {

		fpurge(stdin);
		if (fgets(buffer, sizeof(buffer), stdin) != NULL) {

			if (buffer[strlen(buffer) - 1] == '\n') {

				buffer[strlen(buffer) - 1] = '\0';

			}

			if (strlen(buffer) <= longitud) {

				strncpy(cadena, buffer, longitud);
				ret = 0;
			}

		}

	}

	return ret;

}

/**
 * Verifica si la cadena ingresada es solo numérica (positivo o negativo)
 * @param cadena puntero a dirección de memoria de la cadena
 * @param limite de la cadena
 * @return 1 VERDADERO 0 FALSO
 */

int esNumerica(char *cadena, int limite) {

	int ret = 1;

	if (cadena != NULL && limite > 0) {

		for (int i = 0; i < limite && cadena[i] != '\0'; i++) {

			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {

				continue;
			}

			if (cadena[i] < '0' || cadena[i] > '9') {

				ret = 0;

				break;

			}
		}
	}
	return ret;

}

/**
 * Obtiene un número entero (positivo o negativo)
 * @param pResultado Puntero a espacio en memoria donde será guardado el entero
 * @return 0 Éxito -1 Error
 */
int getInt(int *pResultado) {

	int ret = -1;
	char buffer[50];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNumerica(buffer, sizeof(buffer))) {

			*pResultado = atoi(buffer);
			ret = 0;
		}
	}

	return ret;
}

/**
 * Pide y obtiene un número entero positvo o negativo
 * @param pResultado puntero a direccion de memoria donde se guardará el número
 * @param mensaje Mensaje para pedir el número
 * @param mensajeError Mensaje para indicar número inválido
 * @param minimo Número minimo permitido
 * @param maximo Número máximo permitido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int ret = -1;

	int bufferInt;

	do {

		printf("%s", mensaje);

		if (getInt(&bufferInt) == 0 && bufferInt >= minimo
				&& bufferInt <= maximo) {

			*pResultado = bufferInt;
			ret = 0;
			break;
		}

		else {
			printf("%s", mensajeError);
			reintentos--;

		}

	} while (reintentos >= 0);

	return ret;

}

/**
 * Verifica si la cadena ingresada es un numero flotante (positivo o negativo)
 * @param cadena puntero a dirección de memoria de la cadena
 * @param limite de la cadena
 * @return 1 VERDADERO 0 FALSO
 */

int esFlotante(char *cadena, int limite) {

	int ret = 1;

	int flagFloat = 0;

	if (cadena != NULL && limite > 0) {

		for (int i = 0; i < limite && cadena[i] != '\0'; i++) {

			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {

				continue;
			}

			if (cadena[i] == '.' && flagFloat == 0) {

				flagFloat = 1;

				continue;
			}

			if (cadena[i] < '0' || cadena[i] > '9') {

				ret = 0;

				break;

			}
		}
	}

	return ret;

}

/**
 * Obtiene un número flotante (positivo o negativo)
 * @param pResultado Puntero a espacio en memoria donde será guardado el float
 * @return 0 Éxito -1 Error
 */
int getFloat(float *pResultado) {

	int ret = -1;
	char buffer[50];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0
				&& esFlotante(buffer, sizeof(buffer))) {

			*pResultado = atof(buffer);
			ret = 0;
		}
	}

	return ret;
}

/**
 * Pide y obtiene un número flotante positvo o negativo
 * @param pResultado puntero a direccion de memoria donde se guardará el flotante
 * @param mensaje Mensaje para pedir el número
 * @param mensajeError Mensaje para indicar número inválido
 * @param minimo Número minimo permitido
 * @param maximo Número máximo permitido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	int ret = -1;

	float bufferFloat;

	do {

		printf("%s", mensaje);

		if (getFloat(&bufferFloat) == 0 && bufferFloat >= minimo
				&& bufferFloat <= maximo) {

			*pResultado = bufferFloat;
			ret = 0;
			break;
		}

		else {
			printf("%s", mensajeError);
			reintentos--;

		}

	} while (reintentos >= 0);
	return ret;

}

/**
 * Verifica si la cadena pertenece a un número negativo entero
 * @param cadena puntero a dirección de memoria de la cadena
 * @param limite de la cadena
 * @return 1 VERDADERO 0 FALSO
 */

int esNegativo(char *cadena, int limite) {

	int ret = 1;

	if (cadena != NULL && limite > 0) {

		for (int i = 0; i < limite && cadena[i] != '\0'; i++) {

			if (i==0 && cadena[i] == '-') {

				continue;
			}

			if (cadena[i] < '0' || cadena[i] > '9') {

				ret = 0;

				break;

			}
		}
	}

	return ret;

}

/**
 * Obtiene un número negativo entero
 * @param pResultado Puntero a espacio en memoria donde será guardado el numero
 * @return 0 Éxito -1 Error
 */
int getNegativo(int *pResultado) {

	int ret = -1;
	char buffer[50];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNegativo(buffer, sizeof(buffer))) {

			*pResultado = atoi(buffer);
			ret = 0;
		}
	}

	return ret;
}

/**
 * Pide y obtiene un número negativo entero
 * @param pResultado puntero a direccion de memoria donde se guardará el numero
 * @param mensaje Mensaje para pedir el número
 * @param mensajeError Mensaje para indicar número inválido
 * @param minimo Número minimo permitido
 * @param maximo Número máximo permitido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */

int utn_getNegativo(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int ret = -1;

	int bufferInt;

	do {

		printf("%s", mensaje);

		if (getNegativo(&bufferInt) == 0 && bufferInt >= minimo
				&& bufferInt <= maximo) {

			*pResultado = bufferInt;
			ret = 0;
			break;
		}

		else {
			printf("%s", mensajeError);
			reintentos--;

		}

	} while (reintentos >= 0);
	return ret;

}

/**
 * Verifica si la cadena pertenece a un número entero de 7 u 8 digitos
 * @param cadena puntero a dirección de memoria de la cadena
 * @param limite de la cadena
 * @return 1 VERDADERO 0 FALSO
 */



int esNombre(char *cadena, int limite) {

	int ret = 1;
	int flagEspacio = 0;

	if (cadena != NULL && limite > 0) {

		for (int i = 0; i < limite && cadena[i] != '\0'; i++) {

			if (i == 0 && cadena[i] >= 'A' && cadena[i] < 'Z') {

				continue;
			}

			if (cadena[i] == ' ' && flagEspacio == 0) {

				flagEspacio = 1;

				continue;
			}

			if (flagEspacio == 1 && cadena[i] >= 'A' && cadena[i] < 'Z') {

				flagEspacio = 2;
				continue;
			}

			if (cadena[i] < 'a' || cadena[i] > 'z') {

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

/**
 * Obtiene una cadena alfabética, pudiendo ser dos palabras y una primer Mayúscula en cada una
 * @param pResultado Puntero a espacio en memoria donde será guardada la cadena
 * @return 0 Éxito -1 Error
 */
int getNombre(char *pResultado) {

	int ret = -1;
	char buffer[51];

	if (pResultado != NULL) {

		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer))) {

			strncpy(pResultado, buffer, sizeof(buffer));
			ret = 0;
		}
	}

	return ret;
}

/**
 * Pide y obtiene un nombre o apellido, pudiendo ser dos palabras y una primer Mayúscula en cada una
 * @param pResultado puntero a direccion de memoria donde se guardará el nombre
 * @param mensaje Mensaje para pedir el nombre
 * @param mensajeError Mensaje para indicar nombre inválido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos) {

	int ret = -1;

	char bufferString[51];

	do {

		printf("%s", mensaje);

		if (getNombre(bufferString) == 0) {

			strncpy(pResultado, bufferString, sizeof(bufferString));
			ret = 0;
			break;
		}

		else {
			printf("%s", mensajeError);
			reintentos--;

		}

	} while (reintentos >= 0);
	return ret;

}



