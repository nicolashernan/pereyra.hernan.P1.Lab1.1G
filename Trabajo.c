/*
 * Trabajo.c
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include "Moto.h"
#include "Tipo.h"
#include "Color.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"


int inicializarTrabajos(eTrabajo tra[],int tamTRA)
{
	int todoOk = 0;

	if(tra != NULL && tamTRA > 0)
	{
		for(int i = 0; i<tamTRA;i++)
		{
			tra[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarTrabajoLibre(eTrabajo tra[],int tamTRA,int* pIndice)
{
	int todoOk=0;

	if(tra!=NULL && pIndice != NULL && tamTRA>0)
	{
		for(int i = 0;i<tamTRA;i++)
		{
			*pIndice = -1;

			if(tra[i].isEmpty == 1)
			{
				*pIndice = i;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

void Trabajoslista(eTrabajo tra[],int tamTRA,eServicio ser[],int tamS)
{

	char trabajo[20];

	if(tra!=NULL && tamTRA>0)
	{
		printf("                        ****Lista Trabajos****                      \n\n");
		printf(    "id             id moto           id servicio                  fecha\n");
		printf("-----------------------------------------------------------------------\n");
		for(int i = 0;i<tamTRA;i++)
		{
			if(tra[i].isEmpty == 0 )
			{
				descripcionServicio(ser,tamS,tra[i].idServicio,trabajo);

				printf("%d            %5d               %s                  %d/%d/%d\n",tra[i].id,tra[i].idMoto,trabajo,tra[i].fecha.dia,tra[i].fecha.mes,tra[i].fecha.anio);
			}
		}

	}
}


int menuTrabajo()
{
	int opcion;
	int cant;
	system("cls");
	printf("        ****MENU TRABAJOS****    \n\n");
	printf("1)Iniciar alta de trabajo.\n");
	printf("2)Listar trabajos.\n");
	printf("3)Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	cant=scanf("%d", &opcion);
	while(cant != 1 || (opcion < 1 && opcion >3))
	{
		printf("Error,Ingrese opcion valida: ");
		fflush(stdin);
		cant=scanf("%d", &opcion);
	}

	return opcion;
}


int altaTrabajo(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,eServicio ser[],int tamS,eTrabajo tra[],int tamTRA,eCliente cli[],int tamCLI,int* pNextId)
{
	int todoOk = 0;
	int indiceLibre;
	int indiceMoto;
	int id;
	int cant;
	eFecha fecha;


	if(mot!=NULL && tip!=NULL && col!=NULL && ser!= NULL && (tamM && tamT && tamC && tamS > 0))
	{

		switch(menuTrabajo())
		{
		case 1:

			system("cls");
			printf("       ****ALTA TRABAJO****     \n\n");

			buscarTrabajoLibre(tra,tamTRA,&indiceLibre);

			if(indiceLibre == -1)
			{
				printf("No hay lugar en el sistema\n");
				system("pause");
			}
			else
			{
				tra[indiceLibre].id = *pNextId;
				system("cls");
				listarMotos(mot,tamM,tip,tamT,col,tamC,cli,tamCLI);

				printf("Ingrese el id de motocicleta: \n");
				fflush(stdin);
				scanf("%d",&id);

				buscarMoto(mot,tamM,id,&indiceMoto);

				if(indiceMoto == -1)
				{
					printf("No existe una moto con id: %d en el sistema\n", id);
					system("pause");
				}
				else
				{
					tra[indiceLibre].idMoto = id;
					serviciosLista(ser,tamS);
					printf("ingrese el id del servicio a realizar: \n");
					fflush(stdin);
					cant=scanf("%d",&tra[indiceLibre].idServicio);
					if(cant == 0 || (tra[indiceLibre].idServicio < 20000 || tra[indiceLibre].idServicio > 20003))
					{
						printf("Error,ingrese un id se servicio valido: \n");
						system("pause");
						serviciosLista(ser,tamS);
						printf("ingrese el id del servicio a realizar: \n");
						fflush(stdin);
						cant=scanf("%d",&tra[indiceLibre].idServicio);
					}

					printf("Ingrese fecha dd/mm/aaaa: ");
					fflush(stdin);
					cant=scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
					while(cant == 0 || (fecha.dia<1 || fecha.dia>31) || (fecha.mes<1 ||fecha.mes>12) || (fecha.anio< 1900 || fecha.anio>2022))
					{
						printf("Fecha ingresada incorrecta\n");
						printf("Ingrese fecha dd/mm/aaaa: ");
						fflush(stdin);
						cant=scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
					}

					tra[indiceLibre].fecha = fecha;
					tra[indiceLibre].isEmpty = 0;
					printf("Trabajo cargado con exito!!\n");
					system("pause");
				}

			}
		break;
		case 2:
			Trabajoslista(tra,tamTRA,ser,tamS);
			system("pause");
		break;
		case 3:
			printf("Alta de trabajo cancelada!!");
			system("pause");
		break;
		}
		todoOk=1;



	}

	return todoOk;
}





