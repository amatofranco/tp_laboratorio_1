#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Lee de stdin (fgets) hasta encontrar \n o el maximo de longitud de caracteres -1
 * @param string cadena a leer
 * @param lenght longitud maxima
 * @return 0 operación exitosa -1 error
 */
static int getString(char *string, int lenght);

/**
 * Verifica si la cadena esta formada solo por numeros enteros
 * @param puntero a cadena
 * @return 0 FALSO 1 VERDADERO
 */
static int esNumerica(char *cadena);

/**
 * Toma solo numeros enteros
 * @param puntero a numero
 * @return 0 operacion exitosa -1 error
 */

static int getInt(int *pResultado);

/**
 * Verifica si la cadena esta formada por caracteres y solo la primer letra mayuscula
 * @param puntero a cadena
 * @return 0 FALSO 1 VERDADERO
 */

static int esNombre(char *cadena);

static int esFlotante(char *cadena);

/**
 * Toma solo caracteres y primer letra mayuscula
 * @param puntero a cadena
 * @return 0 operacion exitosa -1 error
 */

static int getNombre(char *pResultado);



static int getFloat(float *pResultado);

/////////////////


static int getString(char *string, int lenght) {

	int ret = -1;

	if (string != NULL && lenght > 0) {

		fpurge(stdin);
		fgets(string, lenght, stdin);

		if (string[strlen(string) - 1] == '\n') {

			string[strlen(string) - 1] = '\0';

		}

		ret = 0;
	}

	return ret;

}

static int esNumerica(char *cadena) {

	int ret = 1;

	if (cadena != NULL) {

		for (int i = 0; cadena[i] != '\0'; i++) {

			if (cadena[i] > '9' || cadena[i] < '0') {

				ret = 0;
				break;
			}
		}
	}

	return ret;

}

static int esFlotante(char *cadena) {

	int ret = 1;

	if (cadena != NULL) {

		for (int i = 0; cadena[i] != '\0'; i++) {

			if (i!=0 && cadena[i] == '.'){

				continue;
			}

			if (cadena[i] > '9' || cadena[i] < '0') {

				ret = 0;
				break;
			}
		}
	}

	return ret;

}


static int esNombre(char *cadena) {

	int ret = 1;

	if (cadena != NULL) {

		for (int i = 0; cadena[i] != '\0'; i++) {

			if (i==0 && (cadena[i] >= 'A' || cadena[i] <= 'Z')) {

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

static int getNombre(char *pResultado) {

	int ret = -1;

	char buffer[51];


	if (pResultado != NULL) {

		if (getString(buffer, sizeof(buffer)) == 0 && esNombre(buffer)){

			strncpy(pResultado, buffer, sizeof(buffer));
			ret = 0;
		}

	}
	return ret;
}

static int getInt(int *pResultado) {

	int ret = -1;
	char buffer[4096];

	if (pResultado != NULL && getString(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {

					*pResultado = atoi(buffer);
					ret = 0;
				}


			return ret;

	}

static int getFloat(float *pResultado) {

	int ret = -1;
	char buffer[4096];

	if (pResultado != NULL && getString(buffer, sizeof(buffer)) == 0 && esFlotante(buffer)) {

					*pResultado = atof(buffer);
					ret = 0;
				}


			return ret;

	}

	int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
			int minimo, int maximo, int reintentos) {

		int retorno = -1;
		int buffer;

		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& minimo <= maximo && reintentos >= 0) {

			while (reintentos > 0) {

				printf("%s", mensaje);

				// scanf("%d", &buffer);

				if (getInt(&buffer) == 0 && buffer >= minimo
						&& buffer <= maximo) {

					*pResultado = buffer;
					retorno = 0;
					break;
				}

				else {
					printf("%s", mensajeError);
					reintentos--;
				}

			}

			if (reintentos == 0) {
				retorno = -1;
			}

		}

		return retorno;
	}

	int utn_getNombre(int *pResultado, char *mensaje, char *mensajeError,
			int maximo, int reintentos) {
		int retorno = -1;
		char buffer;

		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& reintentos >= 0) {

			while (reintentos > 0) {

				printf("%s", mensaje);

				// scanf("%d", &buffer);

				if (getNombre(&buffer) == 0 && buffer <= maximo) {

					*pResultado = buffer;
					retorno = 0;
					break;
				}

				else {
					printf("%s", mensajeError);
					reintentos--;
				}

			}

			if (reintentos == 0) {
				retorno = -1;
			}
		}

		return retorno;
	}

	int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
				int maximo, int reintentos) {
			int retorno = -1;
			float buffer;

			if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
					&& reintentos >= 0) {

				while (reintentos > 0) {

					printf("%s", mensaje);

					// scanf("%d", &buffer);

					if (getFloat(&buffer) == 0) {

						*pResultado = buffer;
						retorno = 0;
						break;
					}

					else {
						printf("%s", mensajeError);
						reintentos--;
					}

				}

				if (reintentos == 0) {
					retorno = -1;
				}
			}

			return retorno;
		}


