/*
 * Servicio.h
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}eServicio;

#endif /* SERVICIO_H_INCLUDED */

void serviciosLista(eServicio ser[],int tamS);
int descripcionServicio(eServicio ser[],int tamS, int id, char trabajo[]);
