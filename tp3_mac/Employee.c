#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"

static int isValidNumber(char *string, int length);

static int isValidName(char *string, int length);

static int isValidNumber(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i == 0 && (string[i] == '+' || string[i] == '-')) {

				continue;
			}

			if (string[i] < '0' || string[i] > '9') {

				ret = 0;

				break;

			}
		}
	}
	return ret;

}

static int isValidName(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i == 0 && string[i] >= 'A' && string[i] <= 'Z') {

				continue;
			}

			if (i != 0 && (string[i] == '-' || string[i] == ' ')) {

				continue;
			}

			if (string[i] < 'a' || string[i] > 'z') {

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

Employee* employee_new(void) {

	Employee *auxP = NULL;

	auxP = (Employee*) malloc(sizeof(Employee));

	return auxP;

}

Employee* employee_newParametrosTxt(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {

	Employee *this = NULL;

	this = employee_new();

	if (this != NULL && idStr != NULL && nombreStr != NULL
			&& horasTrabajadasStr != NULL && sueldoStr != NULL) {

		if (employee_setIdTxt(this, idStr) == -1
				|| employee_setNombre(this, nombreStr) == -1
				|| employee_setHorasTrabajadasTxt(this, horasTrabajadasStr)
						== -1 || employee_setSueldoTxt(this, sueldoStr) == -1) {

			printf("Se borró id %s %s\n", idStr, nombreStr);

			employee_delete(this);

			this = NULL;

		}

	}

	return this;
}

Employee* employee_newParametros(int id, char *nombre, int horasTrabajadas,
		int sueldo) {

	Employee *this = NULL;

	this = employee_new();

	if (this != NULL && nombre != NULL && horasTrabajadas >= 0 && sueldo) {

		if (employee_setId(this, id) == -1
				|| employee_setNombre(this, nombre) == -1
				|| employee_setHorasTrabajadas(this, horasTrabajadas) == -1
				|| employee_setSueldo(this, sueldo) == -1) {

			employee_delete(this);

			this = NULL;

		}

	}

	return this;
}

int employee_delete(Employee *this) {

	int ret = -1;

	if (this != NULL) {

		free(this);

		ret = 0;

	}

	return ret;

}

int employee_setId(Employee *this, int id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		this->id = id;

		ret = 0;

	}

	return ret;

}

int employee_setIdTxt(Employee *this, char *id) {

	int ret = -1;

	if (this != NULL && id != NULL) {

		if (isValidNumber(id, MAX_ID)) {

			this->id = atoi(id);

			ret = 0;

		}

	}

	return ret;

}

int employee_getId(Employee *this, int *id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		*id = this->id;

		ret = 0;

	}

	return ret;
}

int employee_setNombre(Employee *this, char *nombre) {

	int ret = -1;

	if (this != NULL && nombre != NULL) {

		if (isValidName(nombre, MAX_NOMBRE)) {

			strncpy(this->nombre, nombre, MAX_NOMBRE);

			ret = 0;

		}

	}

	return ret;
}

int employee_getNombre(Employee *this, char *nombre) {

	int ret = -1;

	if (this != NULL && nombre != NULL) {

		strncpy(nombre, this->nombre, MAX_NOMBRE);

		ret = 0;

	}

	return ret;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {

	int ret = -1;

	if (this != NULL && horasTrabajadas >= 0) {

		this->horasTrabajadas = horasTrabajadas;

		ret = 0;

	}

	return ret;
}

int employee_setHorasTrabajadasTxt(Employee *this, char *horasTrabajadas) {

	int ret = -1;

	int horasAux;

	if (this != NULL && horasTrabajadas != NULL) {

		if (isValidNumber(horasTrabajadas, MAX_HORAS)) {

			horasAux = atoi(horasTrabajadas);

			this->horasTrabajadas = horasAux;

			ret = 0;
		}

	}

	return ret;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {

	int ret = -1;

	if (this != NULL && horasTrabajadas != NULL) {

		*horasTrabajadas = this->horasTrabajadas;

		ret = 0;

	}

	return ret;
}

int employee_setSueldo(Employee *this, int sueldo) {

	int ret = -1;

	if (this != NULL && sueldo >= 0) {

		this->sueldo = sueldo;
		ret = 0;

	}

	return ret;
}

int employee_setSueldoTxt(Employee *this, char *sueldo) {

	int ret = -1;

	int sueldoAux;

	if (this != NULL && sueldo != NULL) {

		if (isValidNumber(sueldo, MAX_SUELDO)) {

			sueldoAux = atoi(sueldo);

			this->sueldo = sueldoAux;

			ret = 0;
		}

	}

	return ret;
}

int employee_getSueldo(Employee *this, int *sueldo) {

	int ret = -1;

	if (this != NULL && sueldo != NULL) {

		*sueldo = this->sueldo;

		ret = 0;

	}

	return ret;
}

int employee_print(Employee *this) {

	int ret = -1;

	int id;

	char nombre[128];

	int horasTrabajadas;

	int sueldo;

	if (this != NULL &&

	employee_getId(this, &id) == 0 &&

	employee_getNombre(this, nombre) == 0 &&

	employee_getHorasTrabajadas(this, &horasTrabajadas) == 0 &&

	employee_getSueldo(this, &sueldo) == 0)

	{

		printf("ID: %d, Nombre: %s,Horas Trabajadas: %d,Sueldo: %d\n", id,
				nombre, horasTrabajadas, sueldo);

	}

	return ret;

}

int employee_compareBySalary(void *e1, void *e2) {

	int ret = 0;

	/*
	int sueldo1;
	int sueldo2;
	char nombre1[MAX_NOMBRE];
	char nombre2[MAX_NOMBRE];
*/

	Employee* pEmployee1;
	Employee* pEmployee2;

	pEmployee1 = (Employee*) e1;
	pEmployee2 = (Employee*) e2;


	if (pEmployee1 != NULL && pEmployee2 != NULL) {

		printf("hola");


			if (pEmployee1->sueldo >  pEmployee2->sueldo) {

				printf("Ok\n");

				ret = 1;
			}

			else {

				ret = -1;
			}


	}

	return ret;

}
