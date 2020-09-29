

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define MAX_NAME 51
#define MAX_LASTNAME 51

struct {
int id;
char name[MAX_NAME];
char lastName[MAX_LASTNAME];
float salary;
int sector;
int isEmpty;
} typedef Employee;




/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
*(isEmpty) en TRUE en todas las posiciones del array
* Poisición del array
* \param list Employee* Puntero a array de empleados
* \param len int length del Array
* \return -1 Error - 0 Ok
*
*/

int initEmployees(Employee* list, int len);



/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);

int printEmployeeByIndex(Employee *list, int len, int i);

/**
 * Verifica si el array de empleados en su totalidad está vacio
 * @param list Puntero a array de empleados
 * @param len longitud del array
 * @return 1 VERDADERO 0 FALSO
 */
int isEmpty(Employee *list, int len);



#endif /* ARRAYEMPLOYEES_H_ */

