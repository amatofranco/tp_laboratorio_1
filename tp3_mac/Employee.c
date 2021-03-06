#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


static int isValidNumber(char *string, int length);

static int isValidName(char *string, int length);



/**
 * Valida que la cadena recibida sea un número
 * @param string Cadena a analizar
 * @param length largo de la cadena
 * @return 0 Éxito -1 Error
 */
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


/**
 * Valida que la cadena ingresada sea un nombre
 * @param string Cadena a analizar
 * @param length Largo de la cadena
 * @return 0 Éxito -1 Error
 */
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

/**
 * Guarda espacio en memoria correspondiente a un empleado
 * y lo asigna a un puntero
 * @return Puntero al empleado
 */


Employee* employee_new(void) {

	Employee *auxP = NULL;

	auxP = (Employee*) malloc(sizeof(Employee));

	return auxP;

}

/**
 *
 * Escribe los parámetros de un empleado, recibidos por texto
 * @param idStr Id de empleado
 * @param nombreStr Nombre de empleado
 * @param horasTrabajadasStr Horas trabajadas del empleado
 * @param sueldoStr Sueldo del empleado
 * @return
 */


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

/**
 *
 * Escribe los parámetros de un empleado
 * @param id Id de empleado
 * @param nombre Nombre de empleado
 * @param horasTrabajadas Horas trabajadas del empleado
 * @param sueldo Sueldo del empleado
 * @return
 */

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

/**
 * Libera el espacio en memoria correspondiente al empleado
 * @param this Puntero a espacio en memoria a liberar
 * @return 0 Éxito -1 Error
 */

int employee_delete(Employee *this) {

	int ret = -1;

	if (this != NULL) {

		free(this);

		ret = 0;

	}

	return ret;

}

/**
 * Asigna ID a un empleado
 * @param this Puntero a empleado
 * @param id Id a asignar
 * @return 0 Éxito -1 Error
 */

int employee_setId(Employee *this, int id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		this->id = id;

		ret = 0;

	}

	return ret;

}


/**
 * Asigna ID a un empleado, recibido por texto
 * @param this Puntero a empleado
 * @param id Id a asignar
 * @return 0 Éxito -1 Error
 */


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


/**
 * Obtiene id de un empleado
 * @param this Puntero a empleado
 * @param id Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */


int employee_getId(Employee *this, int *id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		*id = this->id;

		ret = 0;

	}

	return ret;
}


/**
 * Asigna nombre a un empleado
 * @param this Puntero a empleado
 * @param id Nombre a asignar
 * @return 0 Éxito -1 Error
 */


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

/**
 * Obtiene nombre de un empleado
 * @param this Puntero a empleado
 * @param nombre Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */


int employee_getNombre(Employee *this, char *nombre) {

	int ret = -1;

	if (this != NULL && nombre != NULL) {

		strncpy(nombre, this->nombre, MAX_NOMBRE);

		ret = 0;

	}

	return ret;
}

/**
 * Asigna horas trabajadas a un empleado
 * @param this Puntero a empleado
 * @param horasTrabajadas horas trabajadas a asignar
 * @return 0 Éxito -1 Error
 */



int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {

	int ret = -1;

	if (this != NULL && horasTrabajadas >= 0) {

		this->horasTrabajadas = horasTrabajadas;

		ret = 0;

	}

	return ret;
}


/**
 * Asigna horas trabajadas a un empleado, recibidas desde texto
 * @param this Puntero a empleado
 * @param horasTrabajadas horas trabajadas a asignar
 * @return 0 Éxito -1 Error
 */




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


/**
 * Obtiene horas trabajadas de un empleado
 * @param this Puntero a empleado
 * @param horasTrabajadas Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */


int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {

	int ret = -1;

	if (this != NULL && horasTrabajadas != NULL) {

		*horasTrabajadas = this->horasTrabajadas;

		ret = 0;

	}

	return ret;
}


/**
 * Asigna sueldo a un empleado
 * @param this Puntero a empleado
 * @param sueldo sueldo a asignar
 * @return 0 Éxito -1 Error
 */


int employee_setSueldo(Employee *this, int sueldo) {

	int ret = -1;

	if (this != NULL && sueldo >= 0) {

		this->sueldo = sueldo;
		ret = 0;

	}

	return ret;
}

/**
 * Asigna sueldo a un empleado, recibido desde texto
 * @param this Puntero a empleado
 * @param sueldo sueldo a asignar
 * @return 0 Éxito -1 Error
 */



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


/**
 * Obtiene sueldo de un empleado
 * @param this Puntero a empleado
 * @param sueldo sueldo a asignar
 * @return 0 Éxito -1 Error
 */


int employee_getSueldo(Employee *this, int *sueldo) {

	int ret = -1;

	if (this != NULL && sueldo != NULL) {

		*sueldo = this->sueldo;

		ret = 0;

	}

	return ret;
}

/**
 * Imprime datos de un empleado
 * @param this Puntero a empleado
 * @return 0 Éxito -1 Error
 */



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

		printf("%10d | %20s  | %20d | %20d |\n", id,
				nombre, horasTrabajadas, sueldo);

	}

	return ret;

}

/**
 * Compara mayor sueldo entre dos empleados
 * @param elementA Puntero (void) a castear (EmployeeA)
 * @param elementB Puntero (void) a castear (EmployeeB)
 * @return 0 Error 1 Sueldo de Empleado A mayor -1 Sueldo de Empleado B mayor
 */


int employee_compareBySalary(void *elementA, void *elementB) {

	int ret = 0;
	Employee *employeeA;
	Employee *employeeB;
	employeeA = (Employee*) elementA;
	employeeB = (Employee*) elementB;

	int salaryA;
	int salaryB;

	if (employee_getSueldo(employeeA, &salaryA) == 0 && employee_getSueldo(employeeB, &salaryB) == 0) {

		if (salaryA > salaryB) {

			ret = 1;

		}

		if(salaryA < salaryB){

			ret = -1;
		}

	}

	return ret;
}

int employee_compareByName(void *elementA, void *elementB) {

	int ret = 0;
	Employee *empleadoA;
	Employee *empleadoB;
	empleadoA = (Employee*) elementA;
	empleadoB = (Employee*) elementB;

	char nombreA[MAX_NOMBRE];
	char nombreB [MAX_NOMBRE];

	if (employee_getNombre(empleadoA,nombreA)==0 && employee_getNombre(empleadoB,nombreB)==0){

		if (strncmp(nombreA,nombreB,MAX_NOMBRE)>0){

			ret = 1;
		}

		if (strncmp(nombreA,nombreB,MAX_NOMBRE)<0){

			ret = -1;
		}

	}
	return ret;
}
