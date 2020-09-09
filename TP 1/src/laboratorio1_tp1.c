/*
 1 Enunciado
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

 AL INGRESAR EL USUARIO EL 1:
 1. Ingresar 1er operando (A=x)

 AL INGRESAR EL USUARIO EL 2:
 2. Ingresar 2do operando (B=y)

 AL INGRESAR EL USUARIO 3:
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)

 AL INGRESAR EL USUARIO EL 4:
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion = 0;
	int num1;
	int num2;
	int flagNum1 = 0;
	int flagNum2 = 0;
	int flagOperacion = 0;
	int suma;
	int resta;
	int producto;
	float division;
	int factorial1;
	int factorial2;

	do {

		printf("Ingrese el número correspondiente a la opción: \n 1 Ingresar 1er Operando ");

		if (flagNum1 == 1) {
			printf("(A= %d)", num1);
		}

		printf("\n 2 Ingresar 2do Operando ");

		if (flagNum2 == 1) {
			printf("(B= %d)", num2);
		}

		printf("\n 3 Calcular Operaciones \n 4 Mostrar Resultado \n 5 Salir \n");

		fpurge(stdin);
		scanf("%d", &opcion);

		switch (opcion) {

		case 1:

			printf("Ingrese el 1er Operando: ");
			num1 = getNum();
			flagNum1 = 1;
			break;

		case 2:
			printf("Ingrese el 2do Operando: ");
			num2 = getNum();
			flagNum2 = 1;
			break;

		case 3:
			if (flagNum1 == 0 || flagNum2 == 0) {
				printf( "Falta ingresar alguno de los 2 operandos. Ingréselos nuevamente \n");
			}

			else {

				suma = sumar(num1, num2);
				resta = restar(num1, num2);
				producto = multiplicar(num1, num2);
				division = dividir(num1, num2);
				factorial1 = factorial(num1);
				factorial2 = factorial(num2);
				flagOperacion = 1;
				printf("Se calcularon las operaciones \n");
			}
			break;

		case 4:

			if (flagOperacion == 1) {

				printf("El resultado de %d + %d es: %d \n", num1, num2, suma);
				printf("El resultado de %d - %d es: %d \n", num1, num2, resta);
				printf("El resultado de %d * %d es: %d \n", num1, num2,producto);

				if (num2 != 0) {
					printf("El resultado de %d / %d es: %f \n", num1, num2, division);
				}

				else {
					printf("El resultado de %d / %d es: No se puede dividir por cero \n",num1, num2);

				}

				if (num1 >= 0) {
					printf("El factorial de %d es: %d \n", num1, factorial1);
				}

				else {

					printf("El factorial de %d es: No se puede realizar factorial de negativos \n", num1);

				}

				if (num2 >= 0) {
					printf("El factorial de %d es: %d \n", num2, factorial2);
				}

				else {
					printf("El factorial de %d es: No se puede realizar factorial de negativos \n", num2);
				}

			}

			else {
				printf("Aún no se realizaron operaciones \n");
			}

			break;

		case 5:
			printf("Saliendo del programa");
			break;

		default:
			printf("Opcion no válida. \n");

		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
