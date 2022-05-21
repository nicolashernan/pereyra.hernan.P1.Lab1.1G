/*
 * Trabajo.h
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Fecha.h"


typedef struct
{
	int id;
	int idMoto;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


#endif /* TRABAJO_H_INCLUDED */


int inicializarTrabajos(eTrabajo tra[],int tamTRA);
int buscarTrabajoLibre(eTrabajo tra[],int tamTRA,int* pIndice);
int altaTrabajo(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,eServicio ser[],int tamS,eTrabajo tra[],int tamTRA,eCliente cli[],int tamCLI,int* pNextId);
void TrabajosLista(eTrabajo tra[],int tamTRA,eServicio ser[],int tamS);
int menuTrabajo();
