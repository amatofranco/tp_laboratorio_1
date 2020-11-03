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




int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();



do{

	   utn_getNumero(&option,"Ingrese opcion","Opcion Inválida",1,10,2);

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);

                printf("%d",ll_len(listaEmpleados));

                break;

            case 6:

            	if(controller_ListEmployee(listaEmpleados)==0){

            		printf("Operación exitosa");
            	}
            	break;


        }
}while(option!=10);








    return 0;
}

