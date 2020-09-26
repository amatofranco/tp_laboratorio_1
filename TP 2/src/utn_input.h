
#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_


/**
 * Pide un numero por scanf y valida segun maximo y minimo
 * @param pResultado puntero para numero validado
 * @param mensaje mensaje para ingresar numero
 * @param mensajeError mensaje de numero incorrecto
 * @param minimo numero minimo aceptado
 * @param maximo numero maximo aceptado
 * @param reintentos cantidad de reintentos posibles
 * @return 0 operacion exitosa -1 error
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


#endif /* UTN_INPUT_H_ */
