#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#define MAX_ID 5000
#define MAX_NOMBRE 51
#define MAX_HORAS 1000000
#define MAX_SUELDO 1000000


Employee* employee_new();
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo);
int employee_delete(Employee *this);

int employee_setId(Employee* this,int id);
int employee_setIdTxt(Employee *this, char *id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee *this, char *horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTxt(Employee *this, char *sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_print(Employee *this);


#endif // employee_H_INCLUDED
