

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define QTY_EMPLOYEES 1000
#define QTY_SECTORS 50
#define MIN_SALARY 20000
#define MAX_SALARY 200000
#define MIN_ID 1
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




/**
* Para indicar que todas las posiciones del array están vacías,
* pone la bandera (isEmpty) en TRUE en todas las posiciones
* \param list puntero a array de empleados
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/

int initEmployees(Employee* list, int len);


/**
 * Valida los parámetros reales para agregar un empleado
 * y llama a la función add employee
 * @param list puntero a Array de empleados
 * @param len longitud del array
 * @return 0 Éxito -1 ERror
 */

int getEmployee(Employee* list, int len);

/**
* Agrega en la primer posición libre del array de empleados
* los parámetros reales recibidos
* @param list employee*
* @param len int
* @param id int
* @param name[] char
* @param lastName[] char
* @param salary float
* @param sector int
* @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

/**
 * Verifica si el array de empleados en su totalidad está vacio
 * @param list Puntero a array de empleados
 * @param len longitud del array
 * @return 1 VERDADERO 0 FALSO
 */
int isEmpty(Employee *list, int len);


/**
 * Verifica si existe una posición ocupada del array
 * que coincida con el valor del parametro id y devuelve la posicion
 * @param list Puntero a array de empleados
 * @param len longitud del array
 * @param id id a buscar
 * @return posición del array
 */
int findEmployeeById(Employee* list, int len,int id);

/**
 * Actualiza o nombre, o apellido, o salario o sector de un empleado
 * de la lista de empleados, verificando si existe su id
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int updateEmployee(Employee *list, int len);


/**
* Elimina un empleado del array de empleados tomando su id
* Pone (isEmpty) en 1
* @param list puntero a array de empleados
* @param len largo del array
* @param id id del empleado a eliminar
* @return 0 Éxito -1 Error
*
*/
int removeEmployee(Employee* list, int len, int id);

/**
 * Pide un empleado de la lista de empleados a eliminar por id,
 * verifica que existe y llama a la funcion removeEmployee
 * @param list puntero a array de empleados
 * @param len largo del array
 * @return
 */

int deleteEmployee(Employee *list, int len);



/**
* Ordena los elementos del array de empleados
* en base a apellido y sector de manera ascendente o descendente
* @param lista puntero a array de empleados
* @param len largo del array
* @param order 1 Ordenamiento ascendente 0 Ordenamiento descendente
* @return 0 Éxito -1 Error
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief Imprime el contenido de todas las posiciones
* del array de empleados ocupadas
* \param list puntero a array de empleados
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/
int printEmployees(Employee* list, int length);


/**
 * Calcula el promedio del salario de los empleados
 * y la cantidad de salarios por encima del promedio y lo imprime
 * @param list puntero a array de empleados
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */

int averageSalary(Employee *list, int length);

/**
 * Toma la opción para realizar el tipo de ordenamiento del array
 * e imprime la lista de empleados y el salario promedio,
 * llamando a las funciones sortEmployees, printEmployees y averageSalary
 * @param list
 * @param len
 * @return
 */

int printEmployeeList (Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */

