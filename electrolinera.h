#ifndef ELECTROLINERA_H_INCLUDED
#define ELECTROLINERA_H_INCLUDED

#include "types.h"

// Maximum number of charging stations and points
#define MAX_ELECTROLINERAS 10
#define MAX_PUNTOS_CARGA 20

// Function to initialize an electric charging station
Electrolinera inicializar_electrolinera(int id);

// Function to edit the details of an electric charging station
void editar_electrolinera(Electrolinera *e, const char *nombre, int n1, int n2, int n3, const char *tipo_estacion, float latitud, float longitud);

// Function to configure a charging point in a charging station
int configurar_punto(Electrolinera *e, int id_punto, tipoCorriente tipo_corriente, int potencia_kW, int rodaja_minima_minutos);

// Function to reserve a charging point
int reservar_punto(Electrolinera *e, int id_punto, const char *nombre_usuario, const char *fecha_reserva);

// Function to list reservations of a charging station
void listar_reservas_electrolinera(Electrolinera e);

// Function to list the reservation calendar of a charging point
void mostrar_calendario_punto(PuntoRecarga p);

#endif // ELECTROLINERA_H_INCLUDED
