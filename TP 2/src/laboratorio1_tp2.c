#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"

/**
 * Imprime mensaje error
 */
void errorMessage();

/**
 * Imprime mensaje de operación exitosa
 */
void successMessage();

/**
 * Imprime mensaje de array vacío
 */
void isEmptyMessage();

int main(void) {

	Employee arrayEmployees[QTY_EMPLOYEES];

	int option;
	int ret;

	initEmployees(arrayEmployees, QTY_EMPLOYEES);

	do {

		ret =
				utn_getNumero(&option,
						"Seleccione una opción \n 1- Alta Empleado \n 2- Modificar Empleado \n 3- Baja Empleado \n 4- Informar Listado \n 5 Salir \n",
						"Opción no válida  \n", 1, 5, 2);

		if (ret == 0) {

			switch (option) {

			case 1:

				if (getEmployee(arrayEmployees, QTY_EMPLOYEES) == 0) {
					successMessage();
				}

				else {
					errorMessage();
				}

				break;

			case 2:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					isEmptyMessage();
				}

				else if (updateEmployee(arrayEmployees, QTY_EMPLOYEES) == 0) {

					successMessage();
				}

				else {

					errorMessage();
				}

				break;

			case 3:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {

					isEmptyMessage();

				} else if (deleteEmployee(arrayEmployees, QTY_EMPLOYEES) == 0) {

					successMessage();
				}

				else{

					errorMessage();
				}

				break;

			case 4:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {

					isEmptyMessage();

				} else if (printEmployeeList(arrayEmployees,QTY_EMPLOYEES)==0){

					successMessage();

				}

				else {
					errorMessage();
				}
				break;
			case 5:
				printf("Saliendo del programa");
			}

		} else {
			errorMessage();
		}

	} while (option != 5);

	return EXIT_SUCCESS;

}

void errorMessage() {

	char mError[] = "Se produjo un error. Se redigirá al menú \n";

	printf("%s", mError);

}

void successMessage() {

	char mSuccess[] = "Operación exitosa \n";

	printf("%s", mSuccess);

}

void isEmptyMessage() {

	char mEmpty[] = "No se registra la carga de ningún empleado \n";

	printf("%s", mEmpty);

}

