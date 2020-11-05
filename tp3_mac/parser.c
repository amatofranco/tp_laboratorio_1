#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int ret = -1;
	char idAux[4096];
	char nombreAux[4096];
	char horasAux[4096];
	char sueldoAux[4096];

	Employee *pEmployee = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL){


	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux, nombreAux, horasAux, sueldoAux); // lectura fantasma

				do {

					if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux,
							horasAux, sueldoAux) == 4) // cant. de variables

							{

						pEmployee = employee_newParametrosTxt(idAux, nombreAux,
								horasAux, sueldoAux);

						if (pEmployee!=NULL){

						ll_add(pArrayListEmployee,pEmployee);

						}

					}

				} while (feof(pFile) == 0);


				ret = 0;

	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int ret = -1;
	int idAux;
	char nombreAux[4096];
	int horasAux;
	int sueldoAux;

	Employee *pEmployee = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL){


				do {

						fread(pEmployee,sizeof(Employee),1,pFile);


						if (pEmployee!=NULL && employee_getNombre(pEmployee,nombreAux)==0
								&& employee_getId(pEmployee,&idAux)==0
								&& employee_getHorasTrabajadas(pEmployee,&horasAux)==0
								&& employee_getSueldo(pEmployee,&sueldoAux)==0){

							employee_newParametros(idAux,nombreAux,horasAux,sueldoAux);


						ll_add(pArrayListEmployee,pEmployee);

						}


				} while (feof(pFile) == 0);


				ret = 0;

	}
    return ret;
}
