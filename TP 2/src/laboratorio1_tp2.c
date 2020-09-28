#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"


#define QTY_EMPLEADOS 1000
#define QTY_SECTORES 50
#define MIN_SUELDO 20000;
#define MAX_SUELDO 200000;

int main(void) {

	Employee arrayEmpleados[QTY_EMPLEADOS];

	float minSueldo = MIN_SUELDO
	;
	float maxSueldo = MAX_SUELDO
	;
	int maxSectores = QTY_SECTORES;
	int opcion;
	int respuesta;
	char nombre[51];
	char apellido[51];
	int sector;
	int id = 1;
	int findId;
	int index;
	float sueldo;
	char mensajeError[] = "Se produjo un error. Se redigirá al menú \n";
	char mensajeExito[] = "Operación exitosa \n";
	char mensajeEmpty[] = "No se registra la carga de ningún empleado \n";

	initEmployees(arrayEmpleados, QTY_EMPLEADOS);

	do {

		respuesta =
				utn_getNumero(&opcion,
						"Seleccione una opción \n 1- Alta Empleado \n 2- Modificar Empleado \n 3- Baja Empleado \n 4- Informar Listado \n 5 Salir \n",
						"Opción no válida  \n", 1, 5, 2);

		if (respuesta == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(nombre, "Ingrese nombre \n",
						"Nombre inválido \n", 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (utn_getNombre(apellido, "Ingrese apellido \n",
						"Apellido inválido \n", 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (utn_getFloat(&sueldo, "Ingrese sueldo \n",
						"Número inválido \n", minSueldo, maxSueldo, 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (utn_getNumero(&sector,
						"Ingrese número correspondiente al sector \n",
						"Número inválido \n", 1, maxSectores, 2) != 0) {

					printf("%s", mensajeError);
					break;
				}

				if (addEmployee(arrayEmpleados, QTY_EMPLEADOS, id, nombre,
						apellido, sueldo, sector) == 0) {
					printf("%s", mensajeExito);
					id++;
				}

				else {

					printf("%s", mensajeError);
				}
				break;
			case 2:

				if (isEmpty(arrayEmpleados, QTY_EMPLEADOS)) {
					printf("%s", mensajeEmpty);
				}

				else {

					utn_getNumero(&findId,
							"Ingrese el Id del empleado a buscar \n",
							"Número inválido \n", 1, QTY_EMPLEADOS, 2);

					index = findEmployeeById(arrayEmpleados, QTY_EMPLEADOS,
							findId);

					if (index == -1) {

						printf("No existe empleado con el ID seleccionado \n");
						break;
					}

					printEmployeeByIndex(arrayEmpleados, QTY_EMPLEADOS, index);

					utn_getNumero(&opcion,
							"Ingrese el número correspondiente a la opción: \n 1-Modificar NOMBRE \n 2-Modificar APELLIDO \n 3-Modificar SUELDO \n 4 Modificar SECTOR \n",
							"Opción inválida", 1, 4, 2);

					switch (opcion) {

					case 1:

						utn_getNombre(nombre, "Ingrese el nuevo nombre \n",
								"Nombre Inválido \n", 2);

						strncpy(arrayEmpleados[index].name, nombre,
								sizeof(nombre));

						break;
					case 2:

						utn_getNombre(apellido, "Ingrese el nuevo apellido \n",
								"Apellido Inválido \n", 2);

						strncpy(arrayEmpleados[index].lastName, apellido,
								sizeof(apellido));

						break;
					case 3:

						utn_getFloat(&sueldo, "Ingrese el nuevo sueldo",
								"Número fuera de rango", minSueldo, maxSueldo,
								2);

						arrayEmpleados[index].salary = sueldo;
						break;
					case 4:

						utn_getNumero(&sector,
								"Ingrese el nuevo número correspondiente a sector \n ",
								"Número inválido \n", 1, maxSectores, 2);

						arrayEmpleados[index].sector = sector;
						break;

					}

					printEmployeeByIndex(arrayEmpleados, QTY_EMPLEADOS, index);
				}
				break;
			case 3:
				if (isEmpty(arrayEmpleados, QTY_EMPLEADOS)) {
					printf("%s", mensajeEmpty);
				} else {



				}

				break;
			case 4:

				if (isEmpty(arrayEmpleados, QTY_EMPLEADOS)) {
					printf("%s", mensajeEmpty);
				} else {
					printEmployees(arrayEmpleados, QTY_EMPLEADOS);
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

int altaEmpleado(void) {

	/*
	 nombre = utn_getNombre;
	 apellido = utn_getApellido;
	 salario = utn_getFloat;
	 sector = utn_getString;
	 */
	return 0;
}

