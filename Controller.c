#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"



int controller_loadFromText(char* path , LinkedList* pArrayListBicis)
{
    int todoOk = -1;
    FILE* f;
    if(path != NULL && pArrayListBicis!=NULL)//verificar que los punteros no sean null
    {

        f = fopen(path, "r");
        parser_BicisFromText(f,pArrayListBicis);

        todoOk = 1;
        fclose(f);
        /*            if(!parser_PacientFromText(file, pArrayList))
            {
                retorno = 0;
            }
            fclose(file);
        */
    }else{
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }


    return todoOk;
}

int controller_ListBicis(LinkedList* pArrayListBicis)
{
    int i;
    int retorno=0;
    int size;
    eBicicleta* aux;

    if(pArrayListBicis != NULL)
    {
        size = ll_len(pArrayListBicis);
        if(size!=0)
        {
            printf("___________________________________________________________________\n"
                   "|    ID    |       NOMBRE       |Recuperados|Infectados| Muertos  |\n"
                   "|__________|____________________|___________|__________|__________|\n");
            for(i=0; i<size; i++)
            {
                aux =(eBicicleta*)ll_get(pArrayListBicis, i);
                mostrarEmpleado(aux);
            }
            printf("|__________|____________________|___________|__________|__________|\n");
            retorno=1;
        }else{
            retorno=-1;
        }
    }
    return retorno;
}


int controller_sortBicis(LinkedList* pArrayListBicis)
{
    int retorno = 1;

    if(pArrayListBicis != NULL)
    {
        retorno = 0;
        system("cls");
            ll_sort(pArrayListBicis,employeeSortByInfectados,1);
            ll_sort(pArrayListBicis,employeeSortByTipo,0);
    }
    return retorno;
}

int controller_MenuFilter(LinkedList* pArrayListBicis)
{
    int retorno = 1;
    int option=0;
    LinkedList* auxiliar;
    auxiliar = ll_clone(pArrayListBicis);

    if(pArrayListBicis != NULL && auxiliar != NULL)
    {
        retorno = 0;

        system("cls");

        printf("  ****  Menu de filtrado ****\n\n 1. Filtrar BMX.\n2. Filtrar Playera.\n3. Filtrar BTC\n4. Filtrar Paseo\n5. Salir \n\n");
        printf("Ingrese una opcion\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            auxiliar=ll_filter(auxiliar,filtrar_bmx);
            printf("Ordenados correctamente\n");
            break;
        case 2:
            auxiliar=ll_filter(auxiliar,filtrar_playera);
            printf("Ordenados correctamente\n");
            break;
        case 3:
            auxiliar=ll_filter(auxiliar,filtrar_mtb);
            printf("Ordenados correctamente\n");
            break;
        case 4:
            auxiliar=ll_filter(auxiliar,filtrar_paseo);
            printf("Ordenados correctamente\n");
            break;
        case 5:
            printf("Saliendo del menu de ordenamiento\n");
            break;
        default:
            printf("Opcion incorrecta, Ingrese una opcion valida\n");

        }
        controller_ListBicis(auxiliar);
        system("pause");
        system("cls");
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListBicis)
{
    FILE* textFile;
    int retorno=0;

    if(pArrayListBicis != NULL && path != NULL && ll_isEmpty(pArrayListBicis)==0)
    {
        textFile=fopen(path, "w");
        if(textFile!= NULL)
        {
            retorno = parser_BicisToText(textFile, pArrayListBicis);
            printf("Archivo guardado con exito\n");
        }
    }else{
        printf("No se pudo guardar el archivo\n");
    }
    return retorno;
}
