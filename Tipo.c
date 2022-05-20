/*
 * Tipo.c
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tipo.h"

void tiposLista(eTipo vec[],int tamT)
{
	if(vec!=NULL && tamT>0)
	{
		printf("****Tipos de motos****\n\n");
		printf(    "id             tipo\n");
		printf("--------------------------\n");
		for(int i = 0;i<tamT;i++)
		{
			printf("%-10d     %-20s\n",vec[i].id,vec[i].descripcion);
		}

	}
}

int descripcionTipo(eTipo vec[], int tamT, int id, char tipo[])
{
    int todoOk =0;

    if(vec != NULL && tipo != NULL && tamT > 0)
    {
      for(int i = 0; i < tamT; i++)
      {
          if(vec[i].id == id)
          {
              strcpy(tipo, vec[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}



