#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

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

	char idAux[4096];
	char nombreAux[4096];
	char horasAux[4096];
	char sueldoAux[4096];

	Employee *pEmployee;

	if (path != NULL && pArrayListEmployee != NULL) {

		fp = fopen(path, "r");

		if (fp != NULL) {

			do {

				if (fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux,
						horasAux, sueldoAux) == 4) // cant. de variables

						{

					pEmployee = employee_newParametros(idAux, nombreAux,
							horasAux, sueldoAux);

					ll_add(pArrayListEmployee,pEmployee);

				}

			} while (feof(fp) == 0);

			fclose(fp);

			ret = 0;

		}

	}

	return ret;

	return 1;
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
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	return 1;
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

