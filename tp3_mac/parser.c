#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/**
 * Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * @param pFile Directorio del archivo
 * @param pArrayListEmployee Linkedlist de empleados
 * @return 0 Éxito -1 Error
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {

	int ret = -1;
	char idAux[4096];
	char nombreAux[4096];
	char horasAux[4096];
	char sueldoAux[4096];
	int cont = 0;

	Employee *pEmployee = NULL;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux,
				sueldoAux); // lectura fantasma

		do {

			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux,
					horasAux, sueldoAux) == 4) // cant. de variables

					{

				pEmployee = employee_newParametrosTxt(idAux, nombreAux,
						horasAux, sueldoAux);

				if (pEmployee != NULL) {

					if (ll_add(pArrayListEmployee, pEmployee) == 0) {

						cont++;
					}

				}

			}

		} while (feof(pFile) == 0);

		if (cont > 0) {

			ret = 0;

			printf("Se agregaron %d empleados\n", cont);
		}

	}
	return ret;
}

/**
 * Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * @param pFile Directorio del archivo
 * @param pArrayListEmployee Linkedlist de empleados
 * @return 0 Éxito -1 Error
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {

	int ret = -1;
	int idAux;
	char nombreAux[4096];
	int horasAux;
	int sueldoAux;

	int cont = 0;

	int read;

	Employee *pEmployee = NULL;

	Employee employeeAux;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		do {

			read = fread(&employeeAux, sizeof(Employee), 1, pFile);

			if (read==1){

				if (employee_getNombre(&employeeAux, nombreAux) == 0
						&& employee_getId(&employeeAux, &idAux) == 0
						&& employee_getHorasTrabajadas(&employeeAux, &horasAux)
								== 0
						&& employee_getSueldo(&employeeAux, &sueldoAux) == 0) {

					pEmployee = employee_newParametros(idAux, nombreAux,
							horasAux, sueldoAux);

					if (pEmployee != NULL) {

						if (ll_add(pArrayListEmployee, pEmployee) == 0) {

							cont++;
						}
					}
				}
			}

		} while (feof(pFile) == 0);

		if (cont > 0) {

			printf("Se agregaron %d empleados\n", cont);

			ret = 0;
		}

	}
	return ret;
}
