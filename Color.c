/*
 * Color.c
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

void coloresLista(eColor vec[],int tamC)
{
	if(vec!=NULL && tamC>0)
	{
		printf("****Colores de motos****\n\n");
		printf(    "id             color\n");
		printf("--------------------------\n");
		for(int i = 0;i<tamC;i++)
		{
			printf("%-10d     %-20s\n",vec[i].id,vec[i].nombreColor);
		}

	}
}

int descripcionColor(eColor vec[], int tamC, int id, char color[])
{
    int todoOk =0;

    if(vec != NULL && color != NULL && tamC > 0)
    {
      for(int i = 0; i < tamC; i++)
      {
          if(vec[i].id == id)
          {
              strcpy(color, vec[i].nombreColor);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}


