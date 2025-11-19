#include <stdio.h>
#include <string.h>
#include "electrolinera.h"
#include "types.h"

#define MAX_ELECTROLINERAS 10
#define MAX_PUNTOS_CARGA 20

static Electrolinera electrolineras[MAX_ELECTROLINERAS];
static int num_electrolineras = 0;

Electrolinera inicializar_electrolinera(int id) {
    Electrolinera e;
    e.id = id;
    e.num_puntos_configurados = 0;
    return e;
}

void editar_electrolinera(Electrolinera *e, const char *nombre, float latitud, float longitud) {
    strncpy(e->nombre, nombre, sizeof(e->nombre) - 1);
    e->latitud = latitud;
    e->longitud = longitud;
}

int configurar_punto(Electrolinera *e, int id_punto, tipoCorriente tipo_corriente, int potencia_kW, int rodaja_minima_minutos) {
    if (e->num_puntos_configurados >= MAX_PUNTOS_CARGA) {
        return -1; // No se pueden agregar más puntos de carga
    }
    PuntoRecarga p;
    p.id_punto = id_punto;
    strncpy(p.tipo_corriente, tipo_corriente, sizeof(p.tipo_corriente) - 1);
    p.potencia_kW = potencia_kW;
    p.rodaja_minima_minutos = rodaja_minima_minutos;
    p.nivel_carga = (potencia_kW <= 22) ? 1 : (potencia_kW <= 75) ? 2 : 3; // Asignar nivel de carga
    e->puntos[e->num_puntos_configurados++] = p;
    return 0; // Configuración exitosa
}

void listar_electrolineras() {
    for (int i = 0; i < num_electrolineras; i++) {
        printf("Electrolinera ID: %d, Nombre: %s, Ubicación: (%.6f, %.6f)\n",
               electrolineras[i].id, electrolineras[i].nombre,
               electrolineras[i].latitud, electrolineras[i].longitud);
    }
}

void agregar_electrolinera(Electrolinera e) {
    if (num_electrolineras < MAX_ELECTROLINERAS) {
        electrolineras[num_electrolineras++] = e;
    } else {
        printf("No se pueden agregar más electrolineras.\n");
    }
}
