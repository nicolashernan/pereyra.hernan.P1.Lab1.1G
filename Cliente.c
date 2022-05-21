/*
 * Cliente.c
 *
 *  Created on: 20 may. 2022
 *      Author: nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"


void ClienteLista(eCliente cli[],int tamCLI)
{
	if(cli!=NULL && tamCLI>0)
	{
		printf("****Lista de clientes****\n\n");
		printf(    "id             Nombre                    sexo\n");
		printf("-------------------------------------------------\n");
		for(int i = 0;i<tamCLI;i++)
		{
			printf("%-10d         %-20s     %c\n",cli[i].id,cli[i].nombre,cli[i].sexo);
		}

	}
}

int descripcionCliente(eCliente cli[],int tamCLI,int id,char cliente[])
{
    int todoOk =0;

    if(cli != NULL && cliente != NULL && tamCLI > 0)
    {
      for(int i = 0; i < tamCLI; i++)
      {
          if(cli[i].id == id)
          {
              strcpy(cliente, cli[i].nombre);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}


