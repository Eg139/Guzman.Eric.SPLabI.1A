#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bicicleta.h"

void menu();

int main()
{
    int option = 0;

    LinkedList* listaDeBicicletas = ll_newLinkedList();
    LinkedList* listaOrdenada=NULL;
    do
    {
        menu();
        printf("Ingrese una opcion: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            controller_loadFromText("bicicletas.csv",listaDeBicicletas);
            break;
        case 2:
            controller_ListBicis(listaDeBicicletas);
            break;
        case 3:
            ll_map(listaDeBicicletas,mapearRandom);
            controller_ListBicis(listaDeBicicletas);
            break;
        case 4:
            controller_MenuFilter(listaDeBicicletas);
            break;
        case 5:
            listaOrdenada = ll_clone(listaDeBicicletas);
            controller_sortBicis(listaOrdenada);
            controller_ListBicis(listaOrdenada);
            break;
        case 6:
            controller_saveAsText("listaFiltrada.csv",listaOrdenada);

            break;
        case 7:
            printf("Saliendo del programa....\n");
            break;
        default:
            printf("Opcion incorrecta, Ingrese una opcion valida\n");

        }
        system("pause");
        system("cls");
    }
    while(option != 7);
    free(listaDeBicicletas);
    return 0;
}

void menu()
{

    printf("  ****  Menu  ****\n\n");
    printf("1. Cargar los datos de los Pacientes desde el archivo data.csv (modo texto).\n");
    printf("2. Listar Bicis\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar Posiciones\n");
    printf("6. Guardar posiciones\n");
    printf("7. Salir \n\n");
}


