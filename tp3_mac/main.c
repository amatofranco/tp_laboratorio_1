#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_inputs.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	LinkedList *listaEmpleados = ll_newLinkedList();

	int option = 0;

	int flagFile = 0;

	int flagBin = 0;

	do {

		printf(
				"/****************************************************/\n "
						"Menu:\n"
						"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
						"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
						"3. Alta de empleado\n"
						"4. Modificar datos de empleado\n"
						"5. Baja de empleado\n"
						"6. Listar empleados\n"
						"7. Ordenar empleados"
						"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
						"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
						"10. Salir\n"
						"/*****************************************************/\n"
						"");

		utn_getNumero(&option, "Ingrese opcion\n", "Opcion Inválida\n", 1, 10,
				2);

		switch (option) {
		case 1:

			if (flagFile == 1) {

				printf("El archivo ya se cargó anteriormente\n");
			}

			else if (controller_loadFromText("data.csv", listaEmpleados) == 0) {

				printf("Operación exitosa");

				flagFile = 1;
			}

			break;

		case 2: //si ya se cargo por texto no se puede cargar de archivo y viceversa.

			if (flagFile == 1) {
				printf("El archivo ya se cargó anteriormente\n");


			}


			else if (controller_loadFromBinary("data.bin", listaEmpleados) == 0) {

				printf("Operación exitosa");

				flagFile = 1;
			}

			else {

				printf("No se pudo cargar el archivo\n");

			}

			break;

		case 3:

			if (flagFile == 0) {

				printf(
						"Aún no se ha cargado el archivo con la lista de empleados\n");

			}

			else if (controller_addEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa\n");
			}

			break;

		case 4:

			if (ll_len(listaEmpleados) == 0) {

				printf(
						"No existen empleados cargados para realizar la operación\n");

			}

			else if (controller_editEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa");
			}

			break;

		case 5:

			if (ll_len(listaEmpleados) == 0) {

				printf(
						"No existen empleados cargados para realizar la operación\n");

			}

			else if (controller_removeEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa\n");
			}

			break;

		case 6:

			if (ll_len(listaEmpleados) == 0) {

				printf(
						"No existen empleados cargados para realizar la operación\n");

			}

			else if (controller_ListEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa\n");
			}
			break;

		case 7:

			if (controller_sortEmployee(listaEmpleados)==0){

				printf("Operación exitosa\n");
			}


			break;
		case 8:

			if (ll_len(listaEmpleados) == 0) {
				printf("No existen empleados cargados para realizar la operación\n");
			}

			else if (controller_saveAsText("data2.csv", listaEmpleados) == 0) {

				printf("Se guardaron %d empleados\n", ll_len(listaEmpleados));

				printf("Operación exitosa");
			}
			break;

		case 9:

			if (ll_len(listaEmpleados) == 0) {
				printf( "No existen empleados cargados para realizar la operación\n");
			}

			else if (controller_saveAsBinary("data.bin", listaEmpleados) == 0) {

				printf("Se guardaron %d empleados\n", ll_len(listaEmpleados));

				printf("Operación exitosa");

				flagBin= 1;
			}
			break;

		case 10:

			ll_deleteLinkedList(listaEmpleados);

			printf("Saliendo del programa");
			break;

		}
	} while (option != 10);

	return 0;
}

