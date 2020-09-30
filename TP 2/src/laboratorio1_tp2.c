#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"

#define QTY_EMPLOYEES 1000
#define QTY_SECTORS 50
#define MIN_SALARY 20000
#define MAX_SALARY 200000
#define MIN_ID 1


int main(void) {

	Employee arrayEmployees[QTY_EMPLOYEES];

	float minSalary = MIN_SALARY;
	float maxSalary = MAX_SALARY;
	int option;
	int ret;
	char name[MAX_NAME];
	char lastName[MAX_LASTNAME];
	int sector;
	int id = MIN_ID;
	int findId;
	int index;
	float salary;
	char mError[] = "Se produjo un error. Se redigirá al menú \n";
	char mSuccess[] = "Operación exitosa \n";
	char mEmpty[] = "No se registra la carga de ningún empleado \n";

	initEmployees(arrayEmployees, QTY_EMPLOYEES);

	do {

		ret = utn_getNumero(&option, "Seleccione una opción \n 1- Alta Empleado \n 2- Modificar Empleado \n 3- Baja Empleado \n 4- Informar Listado \n 5 Salir \n",
		            "Opción no válida  \n", 1, 5, 2);

		if (ret == 0) {

			switch (option) {

			case 1:

				if (utn_getNombre(name, "Ingrese nombre \n", "Nombre inválido \n", 2)!=0){

					printf("%s", mError);
					break;
				}


				if (utn_getNombre(lastName, "Ingrese apellido \n", "Apellido inválido \n", 2) != 0) {

					printf("%s", mError);
					break;
				}

				if (utn_getFloat(&salary, "Ingrese sueldo \n", "Número inválido \n",
					minSalary, maxSalary, 2) != 0) {

					printf("%s", mError);
					break;
				}

				if (utn_getNumero(&sector, "Ingrese número correspondiente al sector \n",
					"Número inválido \n", 1, QTY_SECTORS, 2) != 0) {

					printf("%s", mError);
					break;
				}

				if (addEmployee(arrayEmployees, QTY_EMPLOYEES, id, name,
					lastName, salary, sector) != 0) {

					printf("%s", mError);
					break;
				}
				else{

					printf("%s", mSuccess);
					id++;
				}
				break;

			case 2:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					printf("%s", mEmpty);
				}

				else {

					utn_getNumero(&findId, "Ingrese el Id del empleado a buscar \n",
					"Número inválido \n", 1, QTY_EMPLOYEES, 2);

					index = findEmployeeById(arrayEmployees, QTY_EMPLOYEES,findId);

					if (index == -1) {

						printf("No existe empleado con el ID seleccionado \n");
						break;
					}

					if (utn_getNumero(&option,"Ingrese el número correspondiente a la opción: \n 1-Modificar NOMBRE \n 2-Modificar APELLIDO \n 3-Modificar SUELDO \n 4 Modificar SECTOR \n",
					    "Opción inválida \n", 1, 4, 2)!=0){

						printf("%s", mError);
						break;
					}

					switch (option) {

					case 1:

						if (utn_getNombre(name, "Ingrese el nuevo nombre \n","Nombre Inválido \n", 2)==0
							&& updateEmployeeName(arrayEmployees,QTY_EMPLOYEES,index,name) ==0){
						printf("%s", mSuccess);
						}

						else {

							printf("%s",mError);
						}
						break;

					case 2:

						if (utn_getNombre(lastName, "Ingrese el nuevo apellido \n", "Apellido Inválido \n", 2)==0
							&& updateEmployeeLastName(arrayEmployees,QTY_EMPLOYEES,index,lastName)==0)
						{
						printf("%s", mSuccess);
						}
						else {
							printf("%s",mError);
						}
						break;

					case 3:

						if (utn_getFloat(&salary, "Ingrese el nuevo sueldo",
						    "Número fuera de rango", minSalary, maxSalary,2)==0) {

						updateEmployeeSalary(arrayEmployees,QTY_EMPLOYEES,index,salary);
						printf("%s", mSuccess);
						}

						else {
							printf("%s",mError);
						}

						break;

					case 4:

						if (utn_getNumero(&sector,"Ingrese el nuevo número correspondiente a sector \n ",
						"Número inválido \n", 1, QTY_SECTORS, 2)==0){

						updateEmployeeSector(arrayEmployees,QTY_EMPLOYEES,index,sector);
						printf("%s", mSuccess);
						}
						else{

						printf("%s",mError);
					    }
	                    break;

					}
				}
				break;

			case 3:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					printf("%s", mEmpty);

				} else {
					utn_getNumero(&findId, "Ingrese el Id del empleado a buscar \n",
					"Número inválido \n", 1, QTY_EMPLOYEES, 2);

					index = findEmployeeById(arrayEmployees, QTY_EMPLOYEES,findId);

					if (index == -1) {

						printf("No existe empleado con el ID seleccionado \n");
						break;
					}

					else {

					utn_getNumero(&option, "Seleccione: 1 para borrar - 2 para cancelar operación \n","Opción inválida \n",1,2,2);

						if (option == 1) {
							removeEmployee(arrayEmployees, QTY_EMPLOYEES,findId);
							printf("%s", mSuccess);
						} else {
							printf("Se canceló la operación \n");
						}
					}
				}

				break;

			case 4:

				if (isEmpty(arrayEmployees, QTY_EMPLOYEES)) {
					printf("%s", mEmpty);
				} else {

					if (utn_getNumero(&option,"Seleccione: 1 para ORDENAMIENTO ASCENDENTE - "
						"0 para ORDENAMIENTO DESCENDENTE \n", "Opción inválida \n",0,1,2)==0){

					sortEmployees(arrayEmployees,QTY_EMPLOYEES,option);
					printEmployees(arrayEmployees, QTY_EMPLOYEES);
					averageSalary(arrayEmployees,QTY_EMPLOYEES);
					}
					else{
						printf("%s",mError);
					}
				}
				break;
			case 5:
				printf("Saliendo del programa");
			}

		} else {
			printf("%s", mError);
		}

	} while (option != 5);

	return EXIT_SUCCESS;

}

