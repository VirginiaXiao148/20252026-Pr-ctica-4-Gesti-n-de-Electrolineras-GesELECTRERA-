#ifndef RESERVAS_H_INCLUDED
#define RESERVAS_H_INCLUDED

#include "punto_recarga.h"

// Estructura para una reserva
typedef struct {
    int id_reserva;           // Identificador de la reserva
    int id_punto_recarga;    // Identificador del punto de recarga reservado
    char fecha[11];          // Fecha de la reserva (formato: YYYY-MM-DD)
    char hora[6];            // Hora de la reserva (formato: HH:MM)
    char email[50];          // Email del usuario que realiza la reserva
} Reserva;

// Funciones para gestionar reservas
void crear_reserva(PuntoRecarga *punto, const char *fecha, const char *hora, const char *email);
void modificar_reserva(Reserva *reserva, const char *nueva_fecha, const char *nueva_hora);
void listar_reservas(const PuntoRecarga *punto);
void cancelar_reserva(Reserva *reserva);

#endif // RESERVAS_H_INCLUDED
