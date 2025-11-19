#ifndef GESELECTRERA_H_INCLUDED
#define GESELECTRERA_H_INCLUDED

#include "electrolinera.h"
#include "punto_recarga.h"
#include "reservas.h"
#include "calendario.h"


void mostrar_menu();
void manejar_opcion(int opcion);
void editar_electrolinera(Electrolinera *e);
void editar_punto_recarga(Electrolinera *e);
void reservar_punto(Electrolinera *e);
void listar_reservas(Electrolinera e);
void mostrar_calendario_punto(PuntoRecarga p);

#endif // GESELECTRERA_H_INCLUDED
