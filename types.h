#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <stdio.h>

#define MAX_ELECTROLINERAS 10
#define MAX_PUNTOS_CARGA 20
#define MAX_SERVICIOS 5
#define MAX_NOMBRE 50
#define MAX_TIPO_CORRIENTE 3
#define MAX_RESERVAS 100
#define MAX_DIAS_MES 31 // Máximo de días en un mes
#define MINUTOS_DIA 1440 // 24 horas * 60 minutos

typedef char tipoCorriente[MAX_TIPO_CORRIENTE]; // "DC" o "AC"
typedef char nombreChar[MAX_NOMBRE];
typedef char tipoEstacion[MAX_NOMBRE];

// TAD para almacenar la ocupación en minutos por cada día del mes
typedef struct CalendarioMes {
    int mes;
    int anio;
    // Ocupación total para cada día del mes, en minutos
    int ocupacion_minutos[MAX_DIAS_MES];
};

// Definición del TAD Electrolinera
typedef struct Electrolinera {
    int id;                        // Identificador de la electrolinera
    nombreChar nombre;            // Nombre de la electrolinera
    int max_puntos_n1;            // Máximo puntos de carga nivel 1
    int max_puntos_n2;            // Máximo puntos de carga nivel 2
    int max_puntos_n3;            // Máximo puntos de carga nivel 3
    tipoEstacion tipo_estacion[MAX_SERVICIOS]; // Tipos de estación
    float latitud;                // Latitud
    float longitud;               // Longitud
    PuntoRecarga puntos[MAX_PUNTOS_CARGA]; // Colección de Puntos de Recarga
    int num_puntos_configurados;  // Número de puntos configurados
};

#endif // TYPES_H_INCLUDED
