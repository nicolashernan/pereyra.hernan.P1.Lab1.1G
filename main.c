/*
 * main.c
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Moto.h"
#include "Tipo.h"
#include "Color.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Cliente.h"


#define TAMM 10
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMTRA 10
#define TAMCLI 5

int main()
{
	setbuf(stdout,NULL);

	char salir = 'n';
	int nextId = 3000;
	int nexIdTrabajo = 100;
	int contMotos = 0;
	int cant1;
	int cant2;
	eMoto motos[TAMM];
	eTrabajo trabajos[TAMTRA];

	eTipo tipos[TAMT]=
	{
		{1000, "Enduro"},
		{1001, "Chopera"},
		{1002, "Scooter"},
		{1003, "Vintage"}
	};

	eColor colores[TAMC]=
	{
		{10000,"Gris"},
		{10001,"Negro"},
		{10002,"Azul"},
		{10003,"Blaco"},
		{10004,"Rojo"}
	};

	eServicio servicios[TAMS]=
	{
		{20000,"Limpieza",450},
		{20001,"Ajuste",300},
		{20002,"Balanceo",150},
		{20003,"Cadena",390}
	};

	eCliente clientes[TAMCLI] =
	{
		{500,"Juan",'m'},
		{501,"Nicolas",'m'},
		{502,"Yamila",'f'},
		{503,"Veronica",'f'},
		{504,"Leonardo",'m'}
	};


	inicializarMotos(motos,TAMM);
	inicializarTrabajos(trabajos,TAMTRA);
	//harcodearMotos(motos,TAMM,10, &nextId);

	do
	{
		switch(menuMotos())
		{
			case 1:

				cant1 = altaMoto(motos,TAMM,tipos,TAMT,colores,TAMC,clientes,TAMCLI,&nextId);
				if(cant1 == 1)
				{
					contMotos++;
				}
			break;
			case 2:
				if(contMotos>0)
				{
					modificarMoto(motos,TAMM,tipos,TAMT,colores,TAMC,clientes,TAMCLI);
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 3:
				if(contMotos > 0)
				{
					cant2 = bajaMoto(motos,TAMM,tipos,TAMT,colores,TAMC,clientes,TAMCLI);
					if(cant2 == 1)
					{
						contMotos--;
					}
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 4:
				if(contMotos>0)
				{
					system("cls");
					ordenarMotosTipoId(motos,TAMM);
					listarMotos(motos,TAMM,tipos,TAMT,colores,TAMC,clientes,TAMCLI);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 5:
				system("cls");
				tiposLista(tipos,TAMT);
				system("pause");
			break;
			case 6:
				system("cls");
				coloresLista(colores,TAMC);
				system("pause");
			break;
			case 7:
				system("cls");
				serviciosLista(servicios,TAMS);
				system("pause");
			break;
			case 8:
				if(contMotos>0)
				{
					altaTrabajo(motos,TAMM,tipos,TAMT,colores,TAMC,servicios,TAMS,trabajos,TAMTRA,clientes,TAMCLI,&nexIdTrabajo);
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el systema.\n");
					system("pause");
				}
			break;
			case 9:
				if(contMotos > 0)
				{
					system("cls");
					mostrarMotosPorColorSeleccionado(motos,TAMM,tipos,TAMT,colores,TAMC);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
				    system("pause");
				}
			break;
			case 10:
				if(contMotos>0)
				{
					system("cls");
					promedioDePuntajesDeTipoSeleccionado(motos,TAMM);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 11:
				if(contMotos>0)
				{
					system("cls");
					motosDeMayorCilindrada(motos,TAMM,tipos,TAMT,colores,TAMC);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 12:
				if(contMotos>0)
				{
					system("cls");
					mostrarMotosSeparadasPorTipo(motos,TAMM,tipos,TAMT,colores,TAMC);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 13:
				if(contMotos>0)
				{
					cantidadDeMotosporTipoYcolorSeleccionado(motos,TAMM,colores,TAMC,tipos,TAMT);
					system("pause");
				}
				else
				{
						system("cls");
						printf("No hay motos cargadas en el sistema.\n");
						system("pause");
				}
			break;
			case 14:
				if(contMotos>0)
				{
					coloresMasElejidos(motos,TAMM);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No hay motos cargadas en el sistema.\n");
					system("pause");
				}
			break;
			case 15:
				salir = 's';
			break;
			default:
				system("cls");
				printf("opcion incorrecta.\n");
				system("pause");
			break;
		}
	}while(salir != 's');

	return 0;
}




