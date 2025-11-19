#include <stdio.h>
#include <string.h>
#include "punto_recarga.h"
#include "types.h"

void editar_punto_recarga(PuntoRecarga *p, int id, tipoCorriente tipo, int potencia, int rodaja_minima) {
    p->id_punto = id;
    strncpy(p->tipo_corriente, tipo, sizeof(p->tipo_corriente) - 1);
    p->potencia_kW = potencia;
    p->rodaja_minima_minutos = rodaja_minima;

    if (strcmp(tipo_corriente, "DC") == 0) {
        // Nivel 3 (Rápido): DC y 50-300kW [cite: 61]
        if (potencia_kW >= 50 && potencia_kW <= 300) {
            p.nivel_carga = 3;
        } else {
            // Manejar error o asignar un valor por defecto si no está en el rango
            // Por ahora, solo asignamos un valor incorrecto para que falle si no cumple
            p.nivel_carga = 0;
        }
    } else if (strcmp(tipo_corriente, "AC") == 0) {
        if (potencia_kW >= 2 && potencia_kW <= 4) {
            p.nivel_carga = 1; // Nivel 1 (Lento): AC y 2-4 kW [cite: 61]
        } else if (potencia_kW >= 11 && potencia_kW <= 22) {
            p.nivel_carga = 2; // Nivel 2 (Semi-Rápido): AC y 11-22 kW [cite: 61]
        } else {
            p.nivel_carga = 0;
        }
    } else {
        p.nivel_carga = 0; // Tipo de corriente no válido
    }


    if (potencia <= 22) {
        p->nivel_carga = 1; // Lento
    } else if (potencia <= 75) {
        p->nivel_carga = 2; // Semi-Rápido
    } else {
        p->nivel_carga = 3; // Rápido
    }
}

int reservar_punto(PuntoRecarga *p, int mes, int anio) {
    // Implement reservation logic here
    // This is a placeholder for actual reservation logic
    printf("Reservando punto de recarga ID %d para el mes %d y año %d.\n", p->id_punto, mes, anio);
    return 1; // Return success
}

void listar_reservas(PuntoRecarga p) {
    // Implement logic to list reservations for the charging point
    printf("Listando reservas para el punto de recarga ID %d.\n", p.id_punto);
}

void mostrar_calendario_reservas(PuntoRecarga p) {
    // Implement logic to show the reservation calendar for the charging point
    printf("Mostrando calendario de reservas para el punto de recarga ID %d.\n", p.id_punto);
}
