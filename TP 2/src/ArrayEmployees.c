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
						> 0) {

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

	if (employee != NULL && employee->isEmpty==0) {

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

