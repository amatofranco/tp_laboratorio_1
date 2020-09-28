#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

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

			if (list[i].id == id && list[i].isEmpty == 0) {

				ret = i;
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
	return 0;
}

int printEmployees(Employee *list, int length) {

	for (int i = 0; i < length && list[i].isEmpty != 1; i++) {

		printEmployeeByIndex(list, length, i);

	}

	return 0;
}

int printEmployeeByIndex(Employee *list, int len, int i) {

	int ret = -1;

	if (list != NULL && len > 0 && list[i].isEmpty != 1) {

		printf("Empleado id %d: %s %s, salario: %.2f, sector: %d \n",
				list[i].id, list[i].name, list[i].lastName, list[i].salary,
				list[i].sector);

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

