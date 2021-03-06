/*
 * Moto.h
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "Tipo.h"
#include "Color.h"
#include "Cliente.h"

typedef struct
{
	int id;
	int idCliente;
	char marca[20];
	int idTipo;
	int idColor;
	int cilindrada;
	int puntaje;
	int isEmpty;
}eMoto;


#endif /* MOTO_H_INCLUDED */

int inicializarMotos(eMoto vec[],int tamM);
int harcodearMotos(eMoto vec[], int tamM, int cant, int* pNextId);
int menuMotos();
int buscarLibre(eMoto vec[],int tamM,int* pIndice);
int altaMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,eCliente cli[],int tamCLI,int* pNextId);
void listarMotos(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,eCliente cli[],int tamCLI);
int buscarMoto(eMoto mot[],int tamT,int id,int* pIndice);
int menuModificacion();
void mostrarMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,int id);
int bajaMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,eCliente cli[],int tamCLI);
int ordenarMotosTipoId(eMoto mot[],int tamM);
int modificarMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,eCliente cli[],int tamCLI);


void mostrarMotosPorColorSeleccionado(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC);
void promedioDePuntajesDeTipoSeleccionado(eMoto mot[],int tamM);
void motosDeMayorCilindrada(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC);
void mostrarMotosSeparadasPorTipo(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC);
int cantidadDeMotosporTipoYcolorSeleccionado(eMoto mot[],int tamM,eColor col[],int tamC,eTipo tip[],int tamT);
int coloresMasElejidos(eMoto mot[],int tamM);




