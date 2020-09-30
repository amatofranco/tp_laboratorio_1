#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

static int printEmployee(Employee *employee);

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

	do {

		flagSwap = 0;

		for (int i = 0; i < len - 1; i++) {

			if (order == 1) {

				if (strncmp(list[i].lastName, list[i + 1].lastName, MAX_NAME)
						> 0
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

				if (strncmp(list[i].lastName, list[i + 1].lastName, MAX_NAME)
						< 0
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

int updateEmployeeName(Employee *list, int len, int index, char name[]) {

	int ret = -1;

	char buffer[51];

	if (list != NULL && len > 0 && index >= 0 && name != NULL) {

		strncpy(list[index].name, name, sizeof(buffer));

		ret = 0;
	}

	return ret;

}

int updateEmployeeLastName(Employee *list, int len, int index, char lastName[]) {

	int ret = -1;

	char buffer[51];

	if (list != NULL && len > 0 && index >= 0 && lastName != NULL) {

		strncpy(list[index].lastName, lastName, sizeof(buffer));

		ret = 0;
	}

	return ret;

}

int updateEmployeeSalary(Employee *list, int len, int index, float salary) {

	int ret = -1;

	if (list != NULL && len > 0 && index >= 0 && salary > 0) {

		list[index].salary = salary;

		ret = 0;
	}

	return ret;

}

int updateEmployeeSector(Employee *list, int len, int index, int sector) {

	int ret = -1;

	if (list != NULL && len > 0 && index >= 0 && sector > 0) {

		list[index].sector = sector;

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

			if (list[i].isEmpty == 0 && list[i].salary > averageSalary){

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

