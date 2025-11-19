#ifndef CALENDARIO_H_INCLUDED
#define CALENDARIO_H_INCLUDED

#include "types.h"

// Function to initialize the reservation calendar for a charging point
void inicializar_calendario(CalendarioMes *calendario);

// Function to reserve a charging point on a specific date
int reservar_punto_en_calendario(CalendarioMes *calendario, int dia, int mes, int anio, int id_punto);

// Function to list all reservations for a specific month and year
void listar_reservas_por_mes(CalendarioMes calendario, int mes, int anio);

// Function to display the reservation calendar for a specific charging point
void mostrar_calendario_punto(PuntoRecarga p);

#endif // CALENDARIO_H_INCLUDED
