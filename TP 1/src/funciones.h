#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/**
 * Toma un número entero mediante scan y lo informa por print
 * @return Numero obtenido
 */
int getNum(void);


/**
 * Suma de dos números enteros
 * @param num1 Primer numero a sumar
 * @param num2 Segundo numero a sumar
 * @return Suma obtenida
 */

int sumar(int num1, int num2);

/**
 * Resta de dos números enteros
 * @param num1 Primer numero
 * @param num2 Segundo numero
 * @return Resta obtenida
 */

int restar(int num1, int num2);
/**
 * Multiplicación de dos numeros entero
 * @param num1 Primer número
 * @param num2 Segundo número
 * @return Producto obtenido
 */

int multiplicar(int num1, int num2);

/**
 * División de dos numeros enteros
 * @param num1 Primer número
 * @param num2 Segundo número
 * @return Resultado de la división (número flotante)
 */

float dividir(int num1, int num2);



/**
 * Realiza el factorial de un número entero
 * @param num1 Número para realizar la operación
 * @return Factorial obtenido
 */

int factorial(int num);

#endif /* FUNCIONES_H_ */

