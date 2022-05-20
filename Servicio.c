/*
 * Servicio.c
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include "Servicio.h"

void serviciosLista(eServicio ser[],int tamS)
{
	if(ser!=NULL && tamS>0)
	{
		printf("           ****Servicios de motos****\n\n");
		printf(    "id                  servicio                     precio\n");
		printf("------------------------------------------------------------\n");
		for(int i = 0;i<tamS;i++)
		{
			printf("%-10d          %-20s        $%.2f\n",ser[i].id,ser[i].descripcion,ser[i].precio);
		}

	}
}

int descripcionServicio(eServicio ser[],int tamS, int id, char trabajo[])
{
    int todoOk =0;

    if(ser != NULL && trabajo != NULL && tamS > 0)
    {
      for(int i = 0; i < tamS; i++)
      {
          if(ser[i].id == id)
          {
              strcpy(trabajo, ser[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

