#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "Controller.h"



int parser_BicisFromText(FILE* pFile , LinkedList* pArrayListBicis)
{

    eBicicleta* auxBici;
    int retorno=-1;
    char idStr[30];
    char nombreStr[30];
    char tipoStr[30];
    char tiempoStr[30];
    int i=-1;
    char cabecera[50];


    if(pFile!=NULL && pArrayListBicis!=NULL)
    {
        while(!feof(pFile)){
            i++;
            if(i==0){
                fscanf(pFile, "%[^\n]\n",cabecera);
                printf("cabecera: %s\n", cabecera);
                continue;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr,nombreStr,tipoStr,tiempoStr);
            auxBici=newBicicletaParam(idStr,nombreStr,tipoStr,tiempoStr);
            ll_add(pArrayListBicis,auxBici);

        }
        printf("Archivo cargado con Exito\n\n");
        retorno = 0;

    }
    return retorno;
}

int parser_BicisToText(FILE* pFile , LinkedList* pArrayListBicis)
{
    eBicicleta* auxBici;
    int i;
    int size;
    int id;
    char nombre[20];
    int tiempo;
    char tipo[20];
    int retorno=0;

    if(pFile != NULL && pArrayListBicis != NULL)
    {
        fprintf(pFile, "id,nombre,tipo,tiempo\n");

        size=ll_len(pArrayListBicis);
        for(i=0; i<size; i++)
        {
            auxBici=(eBicicleta*)ll_get(pArrayListBicis, i);

            if(bici_getId(auxBici, &id)==1 && bici_getTiempo(auxBici, &tiempo)==1 &&
               bici_getNombre(auxBici, nombre) ==1 && bici_getTipo(auxBici, tipo)==1)
            {
                retorno=1;
                fprintf(pFile, "%d,%s,%s,%d\n", id, nombre, tipo, tiempo);
            }
        }
        fclose(pFile);

    }
    return retorno;
}
