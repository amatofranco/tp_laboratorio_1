#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"

#define QTY_EMPLOYEES 1000
#define QTY_SECTORS 50
#define MIN_SALARY 20000;
#define MAX_SALARY 200000;


int main(void) {

	Employee arrayEmployees[QTY_EMPLOYEES];

	float minSalary = MIN_SALARY
	;
	float maxSalary = MAX_SALARY
	;
	int opcion;
	int respuesta;
	char name[MAX_NAME];
	char lastName[MAX_LASTNAME];
	int sector;
	int id = 1;
	int findId;
	int index;
	float salary;
	char mensajeError[] = "Se produjo un error. Se redigirá al menú \n";
	char mensajeExito[] = "Operación exitosa \n";
	char mensajeEmpty[] = "No se registra la carga de ningún empleado \n";

	initEmployees(arrayEmployees, QTY_EMPLOYEES);

	do {

		respuesta =
				utn_getNumero(&opcion,
						"Seleccione una opción \n 1- Alta Empleado \n 2- Modificar Empleado \n 3- Baja Empleado \n 4- Informar Listado \n 5 Salir \n",
						"Opción no válida  \n", 1, 5, 2);

		if (respuesta == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(name, "Ingrese nombre \n",
						"Nombre inválido \n", 2)!=0){

					printf("%s", mensajeError);
					break;
				}


				if (utn_getNombre(lastName, "Ingrese apellido \n",
						"Apellido inválido \n", 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (utn_getFloat(&salary, "Ingrese sueldo \n", "Número inválido \n", minSalary, maxSalary, 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (utn_getNumero(&sector,
						"Ingrese número correspondiente al sector \n",
						"Número inválido \n", 1, QTY_SECTORS, 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (addEmployee(arrayEmployees, QTY_EMPLOYEES, id, name,
						lastName, salary, sector) == 0) {
					printf("%s", mensajeExito);
					id++;
				}

				else {

					printf("%s", mensajeError);
				}
				break;
			case 2:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					printf("%s", mensajeEmpty);
				}

				else {

					utn_getNumero(&findId,
							"Ingrese el Id del empleado a buscar \n",
							"Número inválido \n", 1, QTY_EMPLOYEES, 2);



					index = findEmployeeById(arrayEmployees, QTY_EMPLOYEES,
							findId);


					if (index == -1) {

						printf("No existe empleado con el ID seleccionado \n");
						break;
					}

					utn_getNumero(&opcion,
							"Ingrese el número correspondiente a la opción: \n 1-Modificar NOMBRE \n 2-Modificar APELLIDO \n 3-Modificar SUELDO \n 4 Modificar SECTOR \n",
							"Opción inválida", 1, 4, 2);

					switch (opcion) {

					case 1:

						utn_getNombre(name, "Ingrese el nuevo nombre \n",
								"Nombre Inválido \n", 2);

						strncpy(arrayEmployees[index].name, name,
								sizeof(name));
						printf("%s", mensajeExito);


						break;
					case 2:

						utn_getNombre(lastName, "Ingrese el nuevo apellido \n",
								"Apellido Inválido \n", 2);

						strncpy(arrayEmployees[index].lastName, lastName,
								sizeof(lastName));
						printf("%s", mensajeExito);


						break;
					case 3:

						utn_getFloat(&salary, "Ingrese el nuevo sueldo",
								"Número fuera de rango", minSalary, maxSalary,
								2);

						arrayEmployees[index].salary = salary;
						printf("%s", mensajeExito);

						break;
					case 4:

						utn_getNumero(&sector,
								"Ingrese el nuevo número correspondiente a sector \n ",
								"Número inválido \n", 1, QTY_SECTORS, 2);

						arrayEmployees[index].sector = sector;
						printf("%s", mensajeExito);

						break;

					}
				}
				break;

			case 3:
				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					printf("%s", mensajeEmpty);
				} else {
					utn_getNumero(&findId,
							"Ingrese el Id del empleado a buscar \n",
							"Número inválido \n", 1, QTY_EMPLOYEES, 2);

					index = findEmployeeById(arrayEmployees, QTY_EMPLOYEES,
							findId);

					if (index == -1) {

						printf("No existe empleado con el ID seleccionado \n");
						break;
					}

					else {

					utn_getNumero(&opcion, "Seleccione: 1 para borrar - 2 para cancelar operación \n","Opción inválida \n",1,2,2);

						if (opcion == 1) {
							removeEmployee(arrayEmployees, QTY_EMPLOYEES,
									findId);
							printf("%s", mensajeExito);
						} else {
							printf("Se canceló la operación \n");
						}

					}

				}

				break;
			case 4:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					printf("%s", mensajeEmpty);
				} else {

					sortEmployees(arrayEmployees,QTY_EMPLOYEES,1);
					printEmployees(arrayEmployees, QTY_EMPLOYEES);
				}
				break;
			case 5:
				printf("Saliendo del programa");
			}

		} else {
			printf("%s", mensajeError);
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;

}

