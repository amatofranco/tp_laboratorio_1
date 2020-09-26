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
 * @param pResultado
 * @return 0 operacion exitosa -1 error
 */
static int esNumerica(char *cadena, int lenght);


/**
 * Toma solo numeros enteros
 * @param cadena La cadena ingresada
 * @return 0 FALSO 1 VERDADERO
 */


static int getInt(int *pResultado, int lenght);


static int esNombre(char *pResultado, int lenght);


static int getNombre(char *pResultado, int lenght);

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



static int esNumerica(char *cadena, int lenght) {

	int ret = 1;

	if (cadena != NULL && lenght > 0) {

		for (int i = 0; cadena[i] != '\0'; i++) {

			if (cadena[i] > '9' || cadena[i] < '0') {

				ret = 0;
				break;
			}
		}
	}

	return ret;

}

static int esNombre(char *cadena, int lenght) {

	int ret = 1;

	if (cadena != NULL && lenght > 0) {

		for (int i = 0; cadena[i] != '\0'; i++) {

			if (cadena[i] < '97' || cadena[i] > '122' ) {

				ret = 0;
				break;
			}
		}
	}

	return ret;

}

static int getNombre(char *pResultado, int lenght) {

	char buffer[4096];
	int ret = -1;

	if (pResultado != NULL) {

		if (getString(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < lenght) {

			strncpy(pResultado, buffer, lenght);
			ret = 0;
		}

	}
	return ret;
}



static int getInt(int *pResultado, int lenght) {

	int ret = -1;
	char buffer[4096];

	if (pResultado != NULL && lenght>0) {

		if (getInt(buffer, sizeof(buffer)) == 0 && esEsnumerica(buffer, sizeof(buffer) {

		*pResultado = atoi(buffer);
		ret = 0;
	}
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

		if (getInt(&buffer,sizeof(buffer)) == 0 && buffer >= minimo && buffer <= maximo) {

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

int utn_getNombre(int *pResultado, char *mensaje, char *mensajeError, int maximo, int reintentos) {
	int retorno = -1;
	int buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0) {

		while (reintentos > 0) {

			printf("%s", mensaje);

			// scanf("%d", &buffer);

			if (getNombre(&buffer, sizeof(buffer)) == 0 && buffer <= maximo) {

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


