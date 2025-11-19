#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservas.h"
#include "punto_recarga.h"
#include "electrolinera.h"

#define MAX_RESERVAS 100

typedef struct {
    int id_reserva;
    int id_punto_recarga;
    char nombre_usuario[50];
    char fecha[11]; // formato: YYYY-MM-DD
    char hora[6];   // formato: HH:MM
} Reserva;

static Reserva reservas[MAX_RESERVAS];
static int num_reservas = 0;

int reservar_punto(int id_punto_recarga, const char* nombre_usuario, const char* fecha, const char* hora) {
    if (num_reservas >= MAX_RESERVAS) {
        printf("No se pueden realizar más reservas.\n");
        return -1;
    }

    reservas[num_reservas].id_reserva = num_reservas + 1;
    reservas[num_reservas].id_punto_recarga = id_punto_recarga;
    strncpy(reservas[num_reservas].nombre_usuario, nombre_usuario, sizeof(reservas[num_reservas].nombre_usuario) - 1);
    strncpy(reservas[num_reservas].fecha, fecha, sizeof(reservas[num_reservas].fecha) - 1);
    strncpy(reservas[num_reservas].hora, hora, sizeof(reservas[num_reservas].hora) - 1);
    num_reservas++;

    printf("Reserva realizada con éxito. ID de reserva: %d\n", reservas[num_reservas - 1].id_reserva);
    return reservas[num_reservas - 1].id_reserva;
}

void listar_reservas(int id_punto_recarga) {
    printf("Reservas para el punto de recarga ID %d:\n", id_punto_recarga);
    for (int i = 0; i < num_reservas; i++) {
        if (reservas[i].id_punto_recarga == id_punto_recarga) {
            printf("ID Reserva: %d, Usuario: %s, Fecha: %s, Hora: %s\n",
                   reservas[i].id_reserva,
                   reservas[i].nombre_usuario,
                   reservas[i].fecha,
                   reservas[i].hora);
        }
    }
}

void listar_reservas_electrolinera(int id_electrolinera) {
    printf("Reservas para la electrolinera ID %d:\n", id_electrolinera);
    for (int i = 0; i < num_reservas; i++) {
        if (reservas[i].id_punto_recarga == id_electrolinera) {
            printf("ID Reserva: %d, Usuario: %s, Fecha: %s, Hora: %s\n",
                   reservas[i].id_reserva,
                   reservas[i].nombre_usuario,
                   reservas[i].fecha,
                   reservas[i].hora);
        }
    }
}

void mostrar_calendario_reservas(int id_punto_recarga) {
    printf("Calendario de reservas para el punto de recarga ID %d:\n", id_punto_recarga);
    for (int i = 0; i < num_reservas; i++) {
        if (reservas[i].id_punto_recarga == id_punto_recarga) {
            printf("Fecha: %s, Hora: %s, Usuario: %s\n",
                   reservas[i].fecha,
                   reservas[i].hora,
                   reservas[i].nombre_usuario);
        }
    }
}
