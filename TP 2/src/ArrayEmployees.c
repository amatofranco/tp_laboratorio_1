#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"

char name[MAX_NAME];
char lastName[MAX_LASTNAME];
int sector;
float salary;

float minSalary = MIN_SALARY;
float maxSalary = MAX_SALARY;
int id = MIN_ID;

/**
 * Imprime nombre,apellido,salario, sector e id de un empleado
 * @param employee empleado a imprimir
 * @return 0 Éxito -1 Error
 */
static int printEmployee(Employee *employee);

/**
 * Actualiza el nombre de un empleado en el array de empleados
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @param index posición del array a la cual modificar
 * @param name nuevo nombre
 * @return 0 Éxito -1 Error;
 */
static int updateEmployeeName(Employee *list, int len, int index, char name[]);

/**
 * Actualiza el apellido de un empleado en el array de empleados
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @param index posición del array a la cual modificar
 * @param name nuevo apellido
 * @return 0 Éxito -1 Error;
 */

static int updateEmployeeLastName(Employee *list, int len, int index,
		char lastName[]);

/**
 * Actualiza el salario de un empleado en el array de empleados
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @param index posición del array a la cual modificar
 * @param name nuevo salario
 * @return 0 Éxito -1 Error;
 */

static int updateEmployeeSalary(Employee *list, int len, int index,
		float salary);

/**
 * Actualiza el salario de un empleado en el array de empleados
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @param index posición del array a la cual modificar
 * @param name nuevo salario
 * @return 0 Éxito -1 Error;
 */

static int updateEmployeeSector(Employee *list, int len, int index, int sector);

int initEmployees(Employee *list, int len) {

	int ret = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
			list[i].id = 0;
		}
		ret = 0;
	}

	return ret;

}

int getEmployee(Employee *list, int length) {

	int ret = 0;

	if (list != NULL && length > 0) {

		if (utn_getNombre(name, "Ingrese nombre \n", "Nombre inválido \n", 2)
				!= 0) {

			ret = -1;
		}

		else if (utn_getNombre(lastName, "Ingrese apellido \n",
				"Apellido inválido \n", 2) != 0) {

			ret = -1;
		}

		else if (utn_getFloat(&salary, "Ingrese sueldo \n",
				"Número inválido \n", minSalary, maxSalary, 2) != 0) {

			ret = -1;
		}

		else if (utn_getNumero(&sector,
				"Ingrese número correspondiente al sector \n",
				"Número inválido \n", 1, QTY_SECTORS, 2) != 0) {

			ret = -1;
		}

		else if (addEmployee(list, length, id, name, lastName, salary, sector)
				!= 0) {

			ret = -1;

		} else {

			id++;
		}
	}
	return ret;
}

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {

	int ret = -1;

	if (list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL
			&& salary > 0 && sector > 0) {

		for (int i = 0; i < len; i++) {

			if (list[i].isEmpty == 1) {

				list[i].id = id;
				strncpy(list[i].name, name, sizeof(list[i].name));
				strncpy(list[i].lastName, lastName, sizeof(list[i].lastName));
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;

				ret = 0;
				break;

			}
		}

	}

	return ret;
}

int isEmpty(Employee *list, int len) {

	int ret = 1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {

			if (list[i].isEmpty == 0) {

				ret = 0;
			}
		}
	}

	return ret;
}

static int printEmployee(Employee *employee) {

	int ret = -1;

	if (employee != NULL && employee->isEmpty == 0) {

		printf("Empleado id %d: %s %s, salario: %.2f, sector: %d \n",
				employee->id, employee->lastName, employee->name,
				employee->salary, employee->sector);

		ret = 0;

	}
	return ret;
}

int findEmployeeById(Employee *list, int len, int id) {

	int ret = -1;

	if (list != NULL && len > 0 && id > 0) {

		for (int i = 0; i < len; i++) {

			if (list[i].id == id) {

				ret = i;

				printEmployee(&list[i]);
				break;

			}

		}
	}

	return ret;
}

static int updateEmployeeName(Employee *list, int len, int index, char name[]) {

	int ret = -1;

	char buffer[51];


	if (list != NULL && len > 0 && index >= 0 && name != NULL) {


		strncpy(list[index].name, name, sizeof(buffer));

		ret = 0;
	}

	return ret;

}

static int updateEmployeeLastName(Employee *list, int len, int index,
		char lastName[]) {

	int ret = -1;

	char buffer[51];

	if (list != NULL && len > 0 && index >= 0 && lastName != NULL) {

		strncpy(list[index].lastName, lastName, sizeof(buffer));

		ret = 0;
	}

	return ret;

}

static int updateEmployeeSalary(Employee *list, int len, int index,
		float salary) {

	int ret = -1;

	if (list != NULL && len > 0 && index >= 0 && salary > 0) {

		list[index].salary = salary;

		ret = 0;
	}

	return ret;

}

static int updateEmployeeSector(Employee *list, int len, int index, int sector) {

	int ret = -1;

	if (list != NULL && len > 0 && index >= 0 && sector > 0) {

		list[index].sector = sector;

		ret = 0;
	}

	return ret;

}

int updateEmployee(Employee *list, int len) {

	int ret = 0;

	int findId;

	int option;

	int index;

	char idError[] = "No existe un empleado con el Id seleccionado \n";

	if (utn_getNumero(&findId, "Ingrese el Id del empleado a buscar \n",
			"Número inválido \n", 1, QTY_EMPLOYEES, 2) != 0) {

		ret = -1;
	} else {

		index = findEmployeeById(list, QTY_EMPLOYEES, findId);

		if (index == -1) {

			printf("%s", idError);

			ret = -1;

		}

		else if (utn_getNumero(&option,
				"Ingrese el número correspondiente a la opción: "
						"\n 1-Modificar NOMBRE \n 2-Modificar APELLIDO \n 3-Modificar SUELDO \n 4 "
						"Modificar SECTOR \n", "Opción inválida \n", 1, 4, 2)
				!= 0) {

			ret = -1;
		}

		else {

			switch (option) {

			case 1:

				if (utn_getNombre(name, "Ingrese el nuevo nombre \n","Nombre Inválido \n", 2) != 0
					|| (updateEmployeeName(list, len, index, name) != 0)) {

					ret = -1;
				}


				break;

			case 2:

				if (utn_getNombre(lastName, "Ingrese el nuevo apellido \n",
						"Apellido Inválido \n", 2) != 0
						|| updateEmployeeLastName(list, len, index, lastName)
								!= 0) {

					ret = -1;
				}
				break;

			case 3:

				if (utn_getFloat(&salary, "Ingrese el nuevo sueldo \n",
						"Número fuera de rango", minSalary, maxSalary, 2) != 0
						|| updateEmployeeSalary(list, len, index, salary)
								!= 0) {
					ret = -1;
				}

				break;

			case 4:

				if (utn_getNumero(&sector,
						"Ingrese el nuevo número correspondiente a sector \n ",
						"Número inválido \n", 1, QTY_SECTORS, 2) != 0
						|| updateEmployeeSector(list, len, index, sector)
								!= 0) {

					ret = -1;

					break;

				}
			}
		}

	}
	return ret;
}



int deleteEmployee(Employee *list, int len) {

	int option;

	int ret = 0;

	int findId;

	int index;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "El id seleccionado no corresponde a ningún empleado \n";

	if (utn_getNumero(&findId, "Ingrese el Id del empleado a buscar \n",
			"Número inválido \n", 1, QTY_EMPLOYEES, 2) != 0) {

		ret = -1;
	}

	else {

		index = findEmployeeById(list, QTY_EMPLOYEES, findId);

		if (index == -1) {

			printf("%s", idError);

			ret = -1;

		}

		else if (utn_getNumero(&option,
				"Seleccione: 1 para borrar - 2 para cancelar operación \n",
				"Opción inválida \n", 1, 2, 2) != 0) {

			ret = -1;

		}

		else if (option == 1) {
			removeEmployee(list, len, findId);
		}

		else {
			printf("%s", cancel);
			ret = 1;
		}
	}

	return ret;

}

int removeEmployee(Employee *list, int len, int id) {
	int ret = -1;
	if (list != NULL && len > 0 && id > 0) {

		for (int i = 0; i < len; i++) {

			if (id == list[i].id) {
				list[i].isEmpty = 1;
			}
		}
		ret = 0;
	}

	return ret;

}

int sortEmployees(Employee *list, int len, int order) {
	int ret = -1;
	Employee buffer;

	int flagSwap;

	if (list != NULL && len > 0) {

		do {

			flagSwap = 0;

			for (int i = 0; i < len - 1; i++) {

				if (order == 1) {

					if (strncmp(list[i].lastName, list[i + 1].lastName,
					MAX_NAME) > 0
							|| (strncmp(list[i].lastName, list[i + 1].lastName,
							MAX_NAME) == 0
									&& list[i].sector > list[i + 1].sector)) {

						flagSwap = 1;
						buffer = list[i];
						list[i] = list[i + 1];
						list[i + 1] = buffer;
					}

				}

				else if (order == 0) {

					if (strncmp(list[i].lastName, list[i + 1].lastName,
					MAX_NAME) < 0
							|| (strncmp(list[i].lastName, list[i + 1].lastName,
							MAX_NAME) == 0
									&& list[i].sector < list[i + 1].sector)) {

						flagSwap = 1;
						buffer = list[i];
						list[i] = list[i + 1];
						list[i + 1] = buffer;
					}

				}
			}

			len--;

		} while (flagSwap == 1);

		ret = 0;

	}
	return ret;
}

int printEmployees(Employee *list, int length) {

	int ret = -1;

	if (list != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0) {

				printEmployee(&list[i]);
			}

		}

		ret = 0;
	}
	return ret;
}

int averageSalary(Employee *list, int length) {

	int ret = -1;

	int count = 0;

	float totalSalary = 0;

	float averageSalary = 0;

	int aboveAverage = 0;

	if (list != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0) {

				totalSalary += list[i].salary;
				count++;
			}

		}

		averageSalary = totalSalary / count;

		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0 && list[i].salary > averageSalary) {

				aboveAverage++;
			}

		}

		printf(" Total salarios: %.2f\n Salario promedio: %.2f\n "
				"Cantidad de salarios por encima del promedio: %d \n",
				totalSalary, averageSalary, aboveAverage);

		ret = 0;
	}
	return ret;

}

int printEmployeeList(Employee *list, int len) {

	int ret = -1;

	int option;

	if (list != NULL && len > 0) {

		if (utn_getNumero(&option,
				"Seleccione: 1 para ORDENAMIENTO ASCENDENTE - "
						"0 para ORDENAMIENTO DESCENDENTE \n",
				"Opción inválida \n", 0, 1, 2) != 0) {

			ret = -1;
		} else {
			sortEmployees(list, len, option);
			printEmployees(list, len);
			averageSalary(list, len);

			ret = 0;

		}

	}

	return ret;

}

