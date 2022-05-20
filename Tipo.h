/*
 * Tipo.h
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
	int id;
	char descripcion[20];
}eTipo;



#endif /* TIPO_H_INCLUDED */

void tiposLista(eTipo vec[],int tamT);
int descripcionTipo(eTipo vec[], int tamT, int id, char tipo[]);
