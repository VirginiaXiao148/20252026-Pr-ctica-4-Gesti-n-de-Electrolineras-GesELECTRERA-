#include <stdio.h>
#include <stdlib.h>
#include "calendario.h"
#include "reservas.h"

// Function to initialize the reservation calendar for a charging point
CalendarioMes inicializar_calendario() {
    CalendarioMes calendario;
    for (int i = 0; i < MAX_MESES; i++) {
        for (int j = 0; j < MAX_DIAS; j++) {
            calendario.dias[j] = NULL; // Initialize all days to NULL
        }
    }
    return calendario;
}

// Function to add a reservation to the calendar
int agregar_reserva(CalendarioMes *calendario, Reserva reserva, int dia, int mes) {
    if (calendario->dias[dia] == NULL) {
        calendario->dias[dia] = (Reserva *)malloc(sizeof(Reserva) * MAX_RESERVAS);
        calendario->num_reservas[dia] = 0;
    }

    if (calendario->num_reservas[dia] < MAX_RESERVAS) {
        calendario->dias[dia][calendario->num_reservas[dia]] = reserva;
        calendario->num_reservas[dia]++;
        return 1; // Success
    }
    return 0; // Failure: no space for more reservations
}

// Function to list reservations for a specific day in the calendar
void listar_reservas_dia(CalendarioMes calendario, int dia) {
    if (calendario.dias[dia] != NULL) {
        printf("Reservas para el día %d:\n", dia);
        for (int i = 0; i < calendario.num_reservas[dia]; i++) {
            printf("Reserva ID: %d, Usuario: %s\n", calendario.dias[dia][i].id_reserva, calendario.dias[dia][i].usuario);
        }
    } else {
        printf("No hay reservas para el día %d.\n", dia);
    }
}

// Function to display the reservation calendar for a charging point
void mostrar_calendario(CalendarioMes calendario) {
    for (int i = 0; i < MAX_DIAS; i++) {
        listar_reservas_dia(calendario, i);
    }
}
