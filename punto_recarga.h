#ifndef PUNTO_RECARGA_H_INCLUDED
#define PUNTO_RECARGA_H_INCLUDED

#include "types.h"
#include "calendario.h"

// Definición del TAD Punto de Recarga
typedef struct PuntoRecarga {
    int id;                          // Identificador del punto de recarga
    char tipo_corriente[3];          // Tipo de corriente: "DC" o "AC"
    int potencia_kW;                 // Potencia en kW
    int rodaja_minima_minutos;       // Tiempo mínimo de recarga en minutos
    int nivel_carga;                 // Nivel de carga: 1 (Lento), 2 (Semi-Rápido), 3 (Rápido)
    CalendarioMes reservas_mensuales[MAX_MESES]; // Reservas mensuales
};

// Funciones para gestionar puntos de recarga
PuntoRecarga crear_punto_recarga(int id, const char* tipo_corriente, int potencia_kW, int rodaja_minima_minutos, int nivel_carga);
void editar_punto_recarga(PuntoRecarga* punto, const char* tipo_corriente, int potencia_kW, int rodaja_minima_minutos, int nivel_carga);
int reservar_punto_recarga(PuntoRecarga* punto, int dia, int mes, int anio);
void listar_reservas_punto(PuntoRecarga punto);
void mostrar_calendario_punto(PuntoRecarga punto, int mes, int anio);

#endif // PUNTO_RECARGA_H_INCLUDED
