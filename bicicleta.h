#include "LinkedList.h"

#ifndef bici_H_INCLUDED
#define bici_H_INCLUDED
typedef struct
{
    int id_bike;
    char nombre[128];
    char tipo[20];
    int tiempo;
}eBicicleta;

/** \brief crea una nueva bici inicializado en vacio
 *
 * \return eBicicleta*
 *
 */
eBicicleta* newBicicleta();
/** \brief crea una nueva bici con valores
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \return eBicicleta*
 *
 */
eBicicleta* newBicicletaParam(char* id, char* nombre, char* tipo, char* tiempo);
/** \brief id setter
 *
 * \param employee eBicicleta*
 * \param id int
 * \return int
 *
 */
int bici_setId(eBicicleta* employee,int id);
/** \brief id getter
 *
 * \param employeeList eBicicleta*
 * \param id int*
 * \return int
 *
 */
int bici_getId(eBicicleta* employeeList,int* id);

/** \brief tipo getter
 *
 * \param employee eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int bici_setTipo(eBicicleta* employee, char* tipo);
/** \brief tipo setter
 *
 * \param employeeList eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int bici_getTipo(eBicicleta* employeeList, char* tipo);

/** \brief horas setter
 *
 * \param employee eBicicleta*
 * \param horasTrabajadas int
 * \return int
 *
 */
int bici_getTiempo(eBicicleta* employeeList,int* tiempo);
/** \brief horas getter
 *
 * \param employeeList eBicicleta*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int bici_setTiempo(eBicicleta* employee,int tiempo);

/** \brief nombre setter
 *
 * \param employee eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int bici_setNombre(eBicicleta* employee,char* nombre);
/** \brief nombre getter
 *
 * \param employeeList eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int bici_getNombre(eBicicleta* employeeList,char* nombre);

/** \brief compara los nombres para luego ordenarlos
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortByTipo(void* empleadoA, void* empleadoB);

/** \brief compara los sueldos para luego ordenarlos
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortByInfectados(void* empleadoA, void* empleadoB);


/** \brief muestra a un empleado
 *
 * \param pEmp eBicicleta*
 * \return int
 *
 */
int mostrarEmpleado(eBicicleta* pEmp);
/** \brief busca el id de un empleado
 *
 * \param pArrayListBicis LinkedList*
 * \param id int
 * \return int
 *
 */
int bici_buscarId(LinkedList* pArrayListBicis, int id);


void* mapearRandom(void* pElement);

int filtrar_paseo(void* emp);
int filtrar_mtb(void* emp);
int filtrar_playera(void* emp);
int filtrar_bmx(void* emp);

#endif // bici_H_INCLUDED
