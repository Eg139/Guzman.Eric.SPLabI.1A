#include "bicicleta.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int employeeSortByTipo(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    char nombreA[20];
    char nombreB[20];

    if(empleadoA!=NULL && empleadoB != NULL)
    {
        bici_getTipo((eBicicleta*)empleadoA,nombreA);
        bici_getTipo((eBicicleta*)empleadoB,nombreB);

        retorno = strcmp(nombreA,nombreB);
    }

    return retorno;
}


int employeeSortByInfectados(void* empleadoA, void* empleadoB)
{
    int retorno;
    int infectadosA;
    int infectadosB;
    eBicicleta* auxEmployee1;
    eBicicleta* auxEmployee2;


    if(empleadoA!=NULL && empleadoB != NULL)
    {
        auxEmployee1=(eBicicleta*)empleadoA;
        auxEmployee2=(eBicicleta*)empleadoB;

        bici_getTiempo(auxEmployee1, &infectadosA);
        bici_getTiempo(auxEmployee2, &infectadosB);

        if(infectadosA > infectadosB)
        {
            retorno=1;
        }
        else if(infectadosA < infectadosB){
            retorno=-1;
        }else{
            retorno = 0;
        }
    }


    return retorno;
}

int bici_setId(eBicicleta* employee,int id)
{
        int todoOk =0;

   if(employee != NULL && id > 0)
    {
        employee ->id_bike = id;
        todoOk = 1;
    }

    return todoOk;
}
int bici_getId(eBicicleta* employeeList,int* id)
{
        int todoOk =0;

    if(employeeList != NULL)
    {
        *id = employeeList->id_bike;
        todoOk = 1;
    }

    return todoOk;
}

int bici_setNombre(eBicicleta* employee,char* nombre)
{
        int todoOk =0;

    if(employee != NULL && nombre != NULL)
    {
        strcpy(employee ->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int bici_getNombre(eBicicleta* employeeList,char* nombre)
{
    int todoOk =0;

    if(employeeList != NULL && nombre != NULL)
    {
        strcpy(nombre, employeeList->nombre);
        todoOk = 1;
    }

    return todoOk;
}


int bici_setTipo(eBicicleta* employee,char* tipo)
{
        int todoOk =0;

    if(employee != NULL && tipo != NULL)
    {
        strcpy(employee ->tipo, tipo);
        todoOk = 1;
    }

    return todoOk;
}

int bici_getTipo(eBicicleta* employeeList,char* tipo)
{
    int todoOk =0;

    if(employeeList != NULL && tipo != NULL)
    {
        strcpy(tipo, employeeList->tipo);
        todoOk = 1;
    }

    return todoOk;
}




int bici_setTiempo(eBicicleta* employee,int tiempo)
{
    int todoOk =0;

    if(employee != NULL && tiempo > 0)
    {
        employee ->tiempo = tiempo;
        todoOk = 1;
    }

    return todoOk;
}
int bici_getTiempo(eBicicleta* employeeList,int* tiempo)
{
        int todoOk =0;

    if(employeeList != NULL && tiempo != NULL)
    {
        *tiempo = employeeList->tiempo;
        todoOk = 1;
    }

    return todoOk;
}


eBicicleta* newBicicleta()
{
    eBicicleta* nuevoEmpleado = NULL;
    nuevoEmpleado = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id_bike = 0;
        strcpy(nuevoEmpleado->nombre, "");
        strcpy(nuevoEmpleado->tipo, "");
        nuevoEmpleado->tiempo = 0;
    }

    return nuevoEmpleado;
}

eBicicleta* newBicicletaParam(char* id, char* nombre, char* tipo, char* tiempo)
{
    eBicicleta* nuevoEmpleado = newBicicleta();

    if(nuevoEmpleado != NULL)
    {
        if(!(bici_setId(nuevoEmpleado,atoi(id))
                && bici_setNombre(nuevoEmpleado,nombre)
                && bici_setTipo(nuevoEmpleado,tipo)
                && bici_setTiempo(nuevoEmpleado,atoi(tiempo))))
        {
            /*free(nuevoEmpleado);
            nuevoEmpleado = NULL;*/
        }

    }


    return nuevoEmpleado;
}

int mostrarEmpleado(eBicicleta* pEmp)
{
    int error = 0;

    int id;
    char nombre[50];
    char tipo[50];
    int tiempo;

    if(pEmp!=NULL)
    {
        if(bici_getId(pEmp, &id)==1
           && bici_getTipo(pEmp, tipo)==1
           && bici_getTiempo(pEmp, &tiempo)==1
           && bici_getNombre(pEmp, nombre)==1 )
        {
            printf("|%10d|%20s|%20s|%10d|\n", id, nombre, tipo, tiempo);
            error=1;
        }
    }
    printf("\n");


    return error;
}

int bici_buscarId(LinkedList* pArrayListBicis, int id)
{
    eBicicleta* employee;
    int auxId;
    int i;
    int index=-1;
    int size;

    if(pArrayListBicis != NULL)
    {
        size=ll_len(pArrayListBicis);

        for(i=0; i<size; i++)
        {
            employee=(eBicicleta*)ll_get(pArrayListBicis, i);
            bici_getId(employee, &auxId);

            if(id == auxId){
                index=i;
                break;
            }
        }
    }
    return index;

}



int filtrar_bmx(void* emp)
{
    int rta = 0;
    eBicicleta* aux=NULL;

    if(emp != NULL)
    {
        aux = (eBicicleta*)emp;

        if(strcmp(aux->tipo,"BMX")==0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrar_playera(void* emp)
{
    int rta = 0;
    eBicicleta* aux=NULL;

    if(emp != NULL)
    {
        aux = (eBicicleta*)emp;

        if(strcmp(aux->tipo,"PLAYERA")==0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrar_mtb(void* emp)
{
    int rta = 0;
    eBicicleta* aux=NULL;

    if(emp != NULL)
    {
        aux = (eBicicleta*)emp;

        if(strcmp(aux->tipo,"MTB")==0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrar_paseo(void* emp)
{
    int rta = 0;
    eBicicleta* aux=NULL;

    if(emp != NULL)
    {
        aux = (eBicicleta*)emp;

        if(strcmp(aux->tipo,"PASEO")==0)
        {
            rta = 1;
        }
    }
    return rta;
}

void* mapearRandom(void* pElement)
{
    eBicicleta* paciente=NULL;
    int tiempo = getRandomTiempos();

    if(pElement!= NULL)
    {
        paciente = (eBicicleta*)pElement;
        bici_setTiempo(paciente,tiempo);
    }
    paciente = (void*) paciente;

    return paciente;
}


