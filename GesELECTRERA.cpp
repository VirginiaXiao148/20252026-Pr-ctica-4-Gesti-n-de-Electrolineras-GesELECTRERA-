/**************************************
* NOMBRE: #Virginia#
* PRIMER APELLIDO: #Toledo#
* SEGUNDO APELLIDO: #Gavagnin#
* DNI: #49103395#
* EMAIL: #vtoledo27@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include "GesELECTRERA.h"
#include "electrolinera.h"
#include "punto_recarga.h"
#include "reservas.h"
#include "calendario.h"

#define MAX_ELECTROLINERAS 10

Electrolinera electrolineras[MAX_ELECTROLINERAS];
int num_electrolineras = 0;

void mostrar_menu() {
    printf("Gestión de Electrolineras\n");
    printf("1. Editar Electrolinera\n");
    printf("2. Editar Punto de Recarga\n");
    printf("3. Reservar Punto de Recarga\n");
    printf("4. Listar Reservas de una Electrolinera\n");
    printf("5. Listar Calendario de Reservas de un Punto de Recarga\n");
    printf("6. Salir\n");
}

void manejar_opcion(int opcion) {
    switch (opcion) {
        case 1:
            editar_electrolinera(electrolineras, &num_electrolineras);
            break;
        case 2:
            editar_punto_recarga(electrolineras, num_electrolineras);
            break;
        case 3:
            reservar_punto(electrolineras, num_electrolineras);
            break;
        case 4:
            listar_reservas_electrolinera(electrolineras, num_electrolineras);
            break;
        case 5:
            listar_calendario_punto_recarga(electrolineras, num_electrolineras);
            break;
        case 6:
            printf("Saliendo del programa...\n");
            exit(0);
        default:
            printf("Opción no válida. Intente de nuevo.\n");
    }
}

int main() {
    int opcion;

    while (1) {
        mostrar_menu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        manejar_opcion(opcion);
    }

    return 0;
}
