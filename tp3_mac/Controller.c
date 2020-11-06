#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
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
			fclose(fp);

		}

		else {

			printf("No pudo abrirse el archivo. \n");
		}

	}

	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

	int ret = -1;

	FILE *fp;

	if (path != NULL && pArrayListEmployee != NULL) {

		fp = fopen(path, "rb");

		if (fp != NULL) {

			if (parser_EmployeeFromBinary(fp, pArrayListEmployee) == 0) {

				ret = 0;

			}

			fclose(fp);

		}

		else {

			printf("No pudo abrirse el archivo\n");

		}

	}

	return ret;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
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

			pEmployeeId = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmployeeId, &idAux);

			if (idAux > maxId) {

				maxId = idAux;
			}

		}

		pEmployee = employee_newParametros(maxId + 1, nombreAux, horasAux,
				sueldoAux);

		if (pEmployee != NULL) {

			if (ll_add(pArrayListEmployee, pEmployee) == 0) {

				printf("Se agregó:\n");

				employee_print(pEmployee);

				ret = 0;
			}
		}
	}

	return ret;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
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

			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

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
						"Seleccione el número correspondiente a la opción: \n 1 - Modificar NOMBRE\n 2 - Modificar HORAS TRABAJADAS \n 3 - Modificar SUELDO \n 4 - Volver al Menú Anterior\n",
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

 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
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

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

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

					pEmployee = (Employee*) ll_get(pArrayListEmployee, index);

					if (pEmployee != NULL && employee_delete(pEmployee) == 0
							&& ll_remove(pArrayListEmployee, index) == 0) {

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
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
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

/** \brief Ordenar empleados segun criterio
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {

	int ret = -1;

	int option;

	if (pArrayListEmployee != NULL) {

		if (utn_getNumero(&option,
				"Ingrese el numero para elegir parámetro de ordenamiento: "
				"\n 1- Ordenar por SUELDO (De menor a mayor)\n 2- ORDENAR por SUELDO (De mayor a menor)\n",
				"Opción inválida", 1, 2, 2) == 0) {

			switch (option) {

			case 1:

				if (ll_sort(pArrayListEmployee, employee_compareBySalary, 1)==0){

                ret = 0;


				}

				break;

			case 2:

				if (ll_sort(pArrayListEmployee, employee_compareBySalary, 0)==0){

	             ret = 0;

				}

				break;

			}
		}

	}

	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {

	int ret = -1;

	FILE *fp;
	char nombreAux[MAX_NOMBRE];
	int horasAux;
	int sueldoAux;
	int idAux;

	int len;
	Employee *pEmployee = NULL;

	if (path != NULL && pArrayListEmployee != NULL) {

		fp = fopen(path, "w");

		if (fp != NULL) {

			len = ll_len(pArrayListEmployee);

			fprintf(fp, "Id,Nombre,Horas Trabajadas,Sueldo\n");

			for (int i = 0; i < len; i++) {

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				if (pEmployee != NULL) {

					if (employee_getNombre(pEmployee, nombreAux) == 0
							&& employee_getId(pEmployee, &idAux) == 0
							&& employee_getHorasTrabajadas(pEmployee, &horasAux)
									== 0
							&& employee_getSueldo(pEmployee, &sueldoAux) == 0) {

						fprintf(fp, "%d,%s,%d,%d\n", idAux, nombreAux, horasAux,
								sueldoAux);

					}
				}

			}

			ret = 0;

			fclose(fp);

		}

	}

	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {

	int ret = -1;

	FILE *fp;

	int len;

	Employee *pEmployee = NULL;

	if (path != NULL && pArrayListEmployee != NULL) {

		fp = fopen(path, "wb");

		if (fp != NULL) {

			len = ll_len(pArrayListEmployee);

			for (int i = 0; i < len; i++) {

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				if (pEmployee != NULL) {

					fwrite(pEmployee, sizeof(Employee), 1, fp);

				}
			}

			fclose(fp);

		}

		ret = 0;

	}

	return ret;

}

