

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn_input.h"


int initEmployees(Employee* list, int len) {

	int ret = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty=1;
		}
		ret=0;
	}

	return ret;

}




int addEmployee(Employee *list, int len, int id, char name[], char lastName[],float salary, int sector) {

return -1;
}





int findEmployeeById(Employee *list, int len, int id) {
return NULL;
}

int removeEmployee(Employee *list, int len, int id) {
return -1;
}

int sortEmployees(Employee *list, int len, int order) {
return 0;
}

int printEmployees(Employee *list, int length) {
return 0;
}

