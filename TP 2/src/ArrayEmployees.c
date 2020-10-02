#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"

/**
 * Imprime nombre,apellido,salario, sector e id de un empleado
 * @param employee empleado a imprimir
 * @return 0 Éxito -1 Error
 */
static int printEmployee(Employee *employee);

int initEmployees(Employee *list, int len) {

	int ret = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

int getEmployee(Employee *list, int length, int *pId) {

	char name[MAX_NAME];
	char lastName[MAX_LASTNAME];
	int sector;
	float salary;
	float minSalary = MIN_SALARY;
	float maxSalary = MAX_SALARY;
	int id = *pId;

	int ret = -1;

	if (list != NULL && length > 0) {

		if (utn_getNombre(name, "Ingrese nombre \n", "Nombre inválido \n", 2)
				== 0

				&& utn_getNombre(lastName, "Ingrese apellido \n",
						"Apellido inválido \n", 2) == 0
				&& utn_getFloat(&salary, "Ingrese sueldo \n",
						"Número inválido \n", minSalary, maxSalary, 2) == 0
				&& utn_getNumero(&sector,
						"Ingrese número correspondiente al sector \n",
						"Número inválido \n", 1, QTY_SECTORS, 2) == 0
				&& addEmployee(list, length, id, name, lastName, salary, sector)
						== 0) {

			(*pId)++;

			ret = 0;

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

int fullArray(Employee *list, int len){

	int ret = 1;

	if (list != NULL && len > 0) {

			for (int i = 0; i < len; i++) {

				if (list[i].isEmpty == 1) {

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

	if (list != NULL && len > 0 && id >= MIN_ID) {

		for (int i = 0; i < len; i++) {

			if (list[i].isEmpty == 0 && list[i].id == id) {

				ret = i;

				printEmployee(&list[i]);
				break;

			}

		}
	}

	return ret;
}

int updateEmployee(Employee *list, int len) {

	char name[MAX_NAME];
	char lastName[MAX_LASTNAME];
	int sector;
	float salary;
	float minSalary = MIN_SALARY;
	float maxSalary = MAX_SALARY;

	int ret = -1;

	int findId;

	int option;

	int index = -1;

	char idError[] = "No existe un empleado con el Id seleccionado \n";

	if (utn_getNumero(&findId, "Ingrese el Id del empleado a buscar \n",
			"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		index = findEmployeeById(list, QTY_EMPLOYEES, findId);

		if (index != -1
				&& utn_getNumero(&option,
						"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar NOMBRE \n 2-Modificar APELLIDO \n 3-Modificar SUELDO \n 4 "
								"Modificar SECTOR \n", "Opción inválida \n", 1,
						4, 2) == 0) {

			switch (option) {

			case 1:

				if (utn_getNombre(name, "Ingrese el nuevo nombre \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(list[index].name, name, sizeof(name));

					ret = 0;
				}

				break;

			case 2:

				if (utn_getNombre(lastName, "Ingrese el nuevo apellido \n",
						"Apellido Inválido \n", 2) == 0) {

					strncpy(list[index].lastName, lastName, sizeof(lastName));
					ret = 0;

				}

				break;

			case 3:

				if (utn_getFloat(&salary, "Ingrese el nuevo sueldo \n",
						"Número fuera de rango", minSalary, maxSalary, 2)
						== 0) {

					list[index].salary = salary;

					ret = 0;
				}

				break;

			case 4:

				if (utn_getNumero(&sector,
						"Ingrese el nuevo número correspondiente "
								"a sector \n ", "Número inválido \n", 1,
						QTY_SECTORS, 2) == 0) {

					list[index].sector = sector;

					ret = 0;

					break;

				}
			}
		}

		else if (index == -1) {
			(printf("%s", idError));
		}

	}

	return ret;
}

int deleteEmployee(Employee *list, int len) {

	int option = 2; // Cancelar

	int ret = -1;

	int findId;

	int index = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "El id seleccionado no corresponde a ningún empleado \n";

	if (utn_getNumero(&findId, "Ingrese el Id del empleado a buscar \n",
			"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		index = findEmployeeById(list, QTY_EMPLOYEES, findId);

		if (index != -1
				&& utn_getNumero(&option, "Seleccione: 1 para borrar - "
						"2 para cancelar operación \n", "Opción inválida \n", 1,
						2, 2) == 0 && option == 1
				&& removeEmployee(list, len, findId) == 0) {

			ret = 0;

		}

		else if (index == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
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
				"Opción inválida \n", 0, 1, 2) == 0) {

			sortEmployees(list, len, option);
			printEmployees(list, len);
			averageSalary(list, len);

			ret = 0;

		}

	}

	return ret;

}

