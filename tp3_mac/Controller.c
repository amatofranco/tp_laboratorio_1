#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {

	int ret = -1;

	FILE *fp;

	if (path != NULL && pArrayListEmployee != NULL) {

		fp = fopen(path, "r");

		if (fp != NULL) {

			if (parser_EmployeeFromText(fp, pArrayListEmployee) == 0) {

				ret = 0;

			}

		}

		fclose(fp);

	}

	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {

	int ret = -1;

	char nombreAux[MAX_NOMBRE];
	int horasAux;
	int sueldoAux;

	Employee *pEmployee = NULL;
	Employee *pEmployeeId = NULL;

	int idAux;

	int maxId = -1;

	int len;

	if (utn_getNombre(nombreAux, "Ingrese nombre de Empleado\n",
			"Ingreso incorrecto\n", 2) == 0
			&& utn_getNumero(&horasAux,
					"Ingrese Cantidad de horas trabajadas \n",
					"Ingreso incorrecto\n", 0, MAX_HORAS, 2) == 0
			&& utn_getNumero(&sueldoAux, "Ingrese sueldo del Empleado\n",
					"Ingreso incorrecto", 0, MAX_SUELDO, 2) == 0) {

		len = ll_len(pArrayListEmployee);

		for (int i = 0; i < len; i++) {

			pEmployeeId = ll_get(pArrayListEmployee, i);
			employee_getId(pEmployeeId, &idAux);

			if (idAux > maxId) {

				maxId = idAux;
			}

		}

		pEmployee = employee_newParametros(maxId + 1, nombreAux, horasAux,
				sueldoAux);

		if (pEmployee != NULL) {

			if (ll_add(pArrayListEmployee, pEmployee) == 0) {
				ret = 0;
			}
		}
	}

	return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {

	int ret = -1;

	char nombreAux[MAX_NOMBRE];
	int horasAux;
	int sueldoAux;

	Employee *pEmployee = NULL;

	int idSearch;

	int idAux;

	int flagId = 0;

	int len;

	int option;

	if (utn_getNumero(&idSearch,
			"Ingrese el Número de ID del Empleado a modificar\n",
			"Ingreso inválido\n", 0, MAX_ID, 2) == 0)

	{

		len = ll_len(pArrayListEmployee);

		for (int i = 0; i < len; i++) {

			pEmployee = ll_get(pArrayListEmployee, i);

			if (pEmployee != NULL && employee_getId(pEmployee, &idAux) == 0
					&& idAux == idSearch) {

				printf("Se encontró:\n");

				employee_print(pEmployee);
				flagId = 1;
				break;

			}

		}

		if (flagId == 1) {

			do {

				if (utn_getNumero(&option,
						"Seleccione el número correspondiente a la opción: \n 1-Modificar NOMBRE\n 2-Modificar HORAS TRABAJADAS \n 3 - Modificar SUELDO \n 4- Volver al Menú Anterior\n",
						"Opción inválida\n", 1, 4, 2) == 0) {

					switch (option) {

					case 1:

						if (utn_getNombre(nombreAux,
								"Ingrese el nuevo NOMBRE\n",
								"Ingreso inválido\n", 2) == 0) {

							if (employee_setNombre(pEmployee, nombreAux) == 0) {

								printf("Se modificó:\n");

								employee_print(pEmployee);

								printf("Operación Exitosa\n");

								ret = 0;
							}

						}
						break;

					case 2:

						if (utn_getNumero(&horasAux,
								"Ingrese cantidad de HORAS TRABAJADAS \n",
								"Ingreso inválido\n", 0, MAX_HORAS, 2) == 0) {

							if (employee_setHorasTrabajadas(pEmployee, horasAux)
									== 0) {

								printf("Se modificó:\n");

								employee_print(pEmployee);

								printf("Operación Exitosa\n");
								ret = 0;
							}

						}
						break;

					case 3:

						if (utn_getNumero(&sueldoAux, "Ingrese nuevo SUELDO n",
								"Ingreso inválido\n", 0, MAX_SUELDO, 2) == 0) {

							if (employee_setSueldo(pEmployee, sueldoAux) == 0) {

								printf("Se modificó:\n");

								employee_print(pEmployee);

								printf("Operación Exitosa\n");

								ret = 0;
							}

						}
						break;

					}

				}
			}

			while (option != 4);
		}

		else {

			printf("No se encontró el ID seleccionado\n");
		}

	}

	return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {

	int ret = -1;

	int idSearch;

	int idAux;

	int len;

	int index;

	int flagId = 0;

	int option;

	Employee *pEmployee = NULL;

	if (pArrayListEmployee != NULL) {

		if (utn_getNumero(&idSearch,
				"Ingrese el Número de ID del Empleado a ELIMINAR\n",
				"Ingreso inválido\n", 0, MAX_ID, 2) == 0) {

			len = ll_len(pArrayListEmployee);

			for (int i = 0; i < len; i++) {

				pEmployee = ll_get(pArrayListEmployee, i);

				if (pEmployee != NULL && employee_getId(pEmployee, &idAux) == 0
						&& idAux == idSearch) {

					index = i;

					printf("Se encontró:\n");

					employee_print(pEmployee);
					flagId = 1;
					break;

				}

			}

			if (flagId == 1) {

				if (utn_getNumero(&option,
						"Ingrese: 1 Para BORRAR - 2 Para Cancelar\n",
						"Opcion inválida", 1, 2, 2) == 0 && option == 1) {

					pEmployee = ll_get(pArrayListEmployee, index);


					if (pEmployee!=NULL && employee_delete(pEmployee)==0 && ll_remove(pArrayListEmployee, index) == 0) {

						printf("OK");

					ret = 0;
				}

			}

			else {

				printf("Se canceló la operación\n");

			}

		}

		else {

			printf("No se encontró el ID seleccionado\n");
		}

	}

}

return ret;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {

int ret = -1;

int len;

Employee *aux;

if (pArrayListEmployee != NULL) {

	len = ll_len(pArrayListEmployee);

	for (int i = 0; i < len; i++) {

		aux = (Employee*) ll_get(pArrayListEmployee, i);

		employee_print(aux);

	}

	ret = 0;

}

return ret;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
return 1;
}

