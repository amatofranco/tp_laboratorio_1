#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_input.h"
#include "ArrayEmployees.h"

#define QTY_EMPLEADOS 1000


int main(void) {

	Employee arrayEmpleados[QTY_EMPLEADOS];
	int opcion;
	int respuesta;
	char nombre[51];
	char apellido[51];
	char sector[51];
	int id;
	float sueldo;


	initEmployees (arrayEmpleados,QTY_EMPLEADOS);

	do {

		respuesta = utn_getNumero(&opcion, "Seleccione una opción \n 1- Alta Empleado \n 2- Modificar Empleado \n 3- Baja Empleado \n 4- Informar Listado \n 5 Salir \n","Opción no válida  \n", 1, 4, 3);

		if (respuesta == 0) {


			switch (respuesta) {

			case 1:

				utn_getNombre();


			   // addEmployee(arrayEmpleados, QTY_EMPLEADOS, id, nombre, apellido, sueldo, sector);



				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				printf("Saliendo del programa");
			}

		} else {
			printf("Se quedó sin reintentos \n");
		}
	} while (respuesta != 5);

	return EXIT_SUCCESS;

}



int altaEmpleado(void){


/*
	nombre = utn_getNombre;
	apellido = utn_getApellido;
	salario = utn_getFloat;
	sector = utn_getString;
*/
	return 0;
}

