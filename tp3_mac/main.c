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

	int flagTxtFile = 0;

	do {

		utn_getNumero(&option, "Ingrese opcion", "Opcion Inválida", 1, 10, 2);

		switch (option) {
		case 1:

			if (flagTxtFile == 1) {

				printf("El archivo ya se cargó anteriormente\n");
			}

			else if (controller_loadFromText("data.csv", listaEmpleados) == 0) {

				printf("Se cargaron %d empleados\n", ll_len(listaEmpleados));

				flagTxtFile = 1;
			}

			break;

		case 2: //si ya se cargo por texto no se puede cargar de archivo y viceversa.

			break;

		case 3:

			if (flagTxtFile == 0) {

				printf(
						"Aún no se ha cargado el archivo con la lista de empleados\n");

			}

			else if (controller_addEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa\n");
			}

			break;

		case 4:

			if (flagTxtFile == 0) {

				printf(
						"Aún no se ha cargado el archivo con la lista de empleados\n");

			}

			else if (controller_editEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa");
			}

			break;

		case 5:

			if (flagTxtFile == 0) {

				printf("Aún no se ha cargado el archivo con la lista de empleados\n");

			}

			else if (controller_removeEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa");
			}

			break;

		case 6:

			if (controller_ListEmployee(listaEmpleados) == 0) {

				printf("Operación exitosa\n");
			}
			break;

		case 10:

			/*AL SALIR: FREE Y FCLOSE
			 *
			 */

			break;

		}
	} while (option != 10);

	return 0;
}

