/*
 * Moto.c
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Moto.h"
#include "Tipo.h"
#include "Color.h"
#include "Funcionvalidar.h"

int harcodearMotos(eMoto mot[], int tamM, int cant, int* pNextId)
{
    int todoOk = 0;

    eMoto motos[10] =
    {
        {0,"Yamaha",1003,10004,500,10,0},
        {0,"Corven",1000,10000,50,3,0},
        {0,"Triax",1002,10003,750,7,0},
        {0,"Honda",1001,10003,125,6,0},
        {0,"Motomel",1002,10000,750,4,0},
        {0,"Yamaha",1003,10001,50,2,0},
        {0,"Zanella",1001,10002,500,6,0},
        {0,"Pirulo",1001,10001,125,7,0},
        {0,"Honda",1002,10002,750,10,0},
        {0,"Yamaha",1003,10004,750,9,0},
    };
    if(mot!=NULL && pNextId!=NULL && (tamM && cant >= 0))
    {
        for(int i = 0; i < cant; i++)
        {
            mot[i] = motos[i];
            mot[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuMotos()
{
	int opcion;
	int cant;
	system("cls");
	printf("     *** MENU DE  OPCIONES ***\n\n");
	printf("1. ALTA MOTO\n");
	printf("2. MODIFICAR MOTO\n");
	printf("3. BAJA MOTO\n");
    printf("4. LISTAR MOTOS\n");
	printf("5. LISTAR TIPOS\n");
	printf("6. LISTAR COLORES\n");
	printf("7. LISTAR SERVICIOS\n");
	printf("8. ALTA TRABAJO\n");
	printf("9. Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	cant=scanf("%d", &opcion);
	while(cant != 1 || (opcion < 1 && opcion >9))
	{
		printf("Error,Ingrese opcion: ");
		fflush(stdin);
		cant=scanf("%d", &opcion);
	}

	return opcion;
}

int inicializarMotos(eMoto vec[],int tamM)
{
	int todoOk = 0;

	if(vec != NULL && tamM > 0)
	{
		for(int i = 0; i<tamM;i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int altaMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,int* pNextId)
{
	int todoOk = 0;
	int indice;
	char auxChar[100];
	int cant;

	if(mot!=NULL && tip!=NULL && col!=NULL && (tamM && tamT && tamC > 0))
	{
		system("cls");
		printf("****Alta de Motocicleta****\n\n");
		buscarLibre(mot,tamM,&indice);

		if(indice == -1)
		{
			printf("No hay lugar en el sistema.\n");
			system("pause");
		}
		else
		{
			mot[indice].id = *pNextId;

			printf("Ingrese marca: \n");
			fflush(stdin);
			gets(auxChar);
			while(strlen(auxChar) >= 20 || validarPalabra(auxChar) == 0)
			{
				printf("Error,reingrese marca: \n");
				gets(auxChar);
			}
			strcpy(mot[indice].marca,auxChar);

			tiposLista(tip,tamT);
			printf("Ingrese el id segun el tipo de moto:\n");
			fflush(stdin);
			cant=scanf("%d",&mot[indice].idTipo);
			while(cant == 0 || (mot[indice].idTipo <1000 || mot[indice].idTipo>1004))
			{

				printf("Error,ingrese un id valido:\n");
				system("pause");
				tiposLista(tip,tamT);
				printf("Ingrese el id segun el tipo de moto:\n");
				fflush(stdin);
				cant=scanf("%d",&mot[indice].idTipo);
			}

			coloresLista(col,tamC);
			printf("Ingrese el id segun el color de moto:\n");
			fflush(stdin);
			cant=scanf("%d",&mot[indice].idColor);
			while(cant == 0 || (mot[indice].idColor <10000 || mot[indice].idColor>10005))
			{
				printf("Error,ingrese un id valido:\n");
				system("pause");
				coloresLista(col,tamC);
				printf("Ingrese el id segun el color de moto:\n");
				fflush(stdin);
				cant=scanf("%d",&mot[indice].idColor);
			}

			printf("Ingrese cilindradas(cc) :\n50\n125\n500\n600\n750\n");
			fflush(stdin);
			cant=scanf("%d",&mot[indice].cilindrada);
			while(cant == 0 || (mot[indice].cilindrada!=50 && mot[indice].cilindrada !=125 && mot[indice].cilindrada != 500
			&& mot[indice].cilindrada != 600 && mot[indice].cilindrada != 750))
			{
					printf("Error.ingrese una cilindradas(cc) valida\n");
					system("pause");
					printf("Ingrese cilindradas(cc) :\n50\n125\n500\n600\n750\n");
					fflush(stdin);
					cant=scanf("%d",&mot[indice].cilindrada);
			}

			printf("Ingrese un puntaje calificando entre 1 y 10:\n");
			fflush(stdin);
			cant=scanf("%d",&mot[indice].puntaje);
			while(cant == 0 || (mot[indice].puntaje <1 || mot[indice].puntaje>10))
			{
				printf("error,ingrese un puntaje calificando entre 1 y 10:\n");
				fflush(stdin);
				cant=scanf("%d",&mot[indice].puntaje);
			}

			mot[indice].isEmpty = 0;
			(*pNextId)++;

			printf("Alta relizada con exito\n");
			system("pause");

			todoOk = 1;
		}


	}
	return todoOk;

}

int buscarLibre(eMoto mot[],int tamM,int* pIndice)
{
	int todoOk=0;

	if(mot!=NULL && pIndice != NULL && tamM>0)
	{
		for(int i = 0;i<tamM;i++)
		{
			*pIndice = -1;

			if(mot[i].isEmpty == 1)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

void listarMotos(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC)
{
	char color[15];
	char tipo[15];

	if(mot!=NULL && tip!=NULL && col!=NULL && (tamM && tamT && tamC > 0))
	{
		printf("                                        ****Listado de Motocicletas****                                           \n\n");
		        printf("id             marca                  tipo                  color               cilindrada         puntaje\n\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");

		for(int i = 0; i<tamM; i++)
		{

			if(mot[i].isEmpty==0)
			{
			descripcionColor(col,tamC,mot[i].idColor,color);
			descripcionTipo(tip,tamT,mot[i].idTipo,tipo);
				printf("%-4d           %-10s            %-10s             %-10s             %-4dcc              %-4d\n",mot[i].id,mot[i].marca,tipo,color,mot[i].cilindrada,mot[i].puntaje);
			}
		}
	}
}

int buscarMoto(eMoto mot[],int tamM,int id,int* pIndice)
{
	int todoOk = 0;

	if(mot!=NULL && tamM > 0 && pIndice!=NULL)
	{
		*pIndice = -1;
		for(int i = 0; i<tamM; i++)
		{
			if(!mot[i].isEmpty && mot[i].id == id)
			{
				*pIndice = i;
				break;
			}

		}
		todoOk = 1;
	}

	return todoOk;
}

int menuModificacion()
{
	int opcion;
	int cant;

	printf("   ****MENU DE MODIFICACION****   \n\n");
	printf("1)Modificar color.\n");
	printf("2)Modificar puntaje.\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	cant=scanf("%d", &opcion);
	if(cant == 0 || (opcion <1 || opcion>2))
	{
		printf("opcion ingresada incorrecta\n");
		system("pause");
	}

	return opcion;

}

int modificarMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int cant;

    if(mot!=NULL && tip!=NULL && col!=NULL && (tamM && tamT && tamC > 0))
    {
    	system("cls");
    	listarMotos(mot,tamM,tip,tamT,col,tamC);

        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d",&id);

        buscarMoto(mot,tamM,id,&indice);

        if(indice == -1)
        {
            printf("No existe una moto con id: %d en el sistema\n", id);
            system("pause");
        }
        else
        {
        	mostrarMoto(mot,tamT,tip,tamT,col,tamC,id);

        	switch(menuModificacion())
        	{
        		case 1:
        			coloresLista(col,tamC);
        			printf("Ingrese el nuevo id segun el color de moto:\n");
        			fflush(stdin);
        			cant=scanf("%d",&mot[indice].idColor);
        			if(cant == 0 || (mot[indice].idColor <10000 || mot[indice].idColor>10004))
        			{
        				printf("Error,id ingresado invalido:\n");
        				system("pause");

        			}
        			printf("Color cambiado con exito!!\n");
        			system("pause");
        		break;
        		case 2:
        			printf("Ingrese el nuevo puntaje calificando entre 1 y 10:\n");
        			fflush(stdin);
        			cant=scanf("%d",&mot[indice].puntaje);
        			if(cant == 0 || (mot[indice].puntaje <1 || mot[indice].puntaje>10))
        			{
        				printf("Error,puntaje ingresado invalido.\n");
        				system("pause");
        			}
        			printf("Puntaje cambiado con exito!!\n");
        			system("pause");
        		break;
        	}
        }
    }
        return todoOk;

}

void mostrarMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC,int id)
{
	char color[15];
	char tipo[15];

	if(mot!=NULL && tip!=NULL && col!=NULL && (tamM && tamT && tamC > 0))
	{
		for(int i = 0; i < tamM; i++)
		{
			if(mot[i].id == id)
			{
				descripcionColor(col,tamC,mot[i].idColor,color);
				descripcionTipo(tip,tamT,mot[i].idTipo,tipo);

				printf("id: %d\n",mot[i].id);
				printf("marca: %s\n",mot[i].marca);
				printf("tipo: %s\n",tipo);
				printf("color: %s\n",color);
				printf("cilindrada: %d\n",mot[i].cilindrada);
				printf("puntaje: %d\n",mot[i].puntaje);
			}
		}
	}
}

int bajaMoto(eMoto mot[],int tamM,eTipo tip[],int tamT,eColor col[],int tamC)
{
	int todoOk = 0;
	int indice;
	int id;
	char opcion;

	if(mot!=NULL && tip!=NULL && col!=NULL && (tamM && tamT && tamC > 0))
	{
	   system("cls");
	   listarMotos(mot,tamM,tip,tamT,col,tamC);

	   printf("Ingrese el id que quiere dar de baja: ");
	   fflush(stdin);
	   scanf("%d", &id);

	   buscarMoto(mot,tamM,id,&indice);

	   if(indice == -1)
	   {
          printf("No existe una moto con id: %d en el sistema\n", id);
          system("pause");
	   }
	   else
	   {
		   mostrarMoto(mot,tamM,tip,tamT,col,tamC,id);
		   printf("confirmar baja? s/n\n");
		   fflush(stdin);
		   scanf("%c",&opcion);
		   if(opcion == 's' || opcion == 'S')
		   {
			   mot[indice].isEmpty = 1;
			   printf("Baja realizada con exito!!\n");
			   system("pause");
		   }
		   else
		   {
			   printf("Baja no realizada!!\n");
			   system("pause");

		   }

	   }
	   todoOk = 1;
	}
	return todoOk;
}

int ordenarMotosTipoId(eMoto mot[],int tamM)
{
    int todoOk = 0;
    eMoto auxMoto;

    if( mot != NULL && tamM > 0)
    {
        for(int i=0; i < tamM - 1; i++)
        {
            for(int j= i+1; j < tamM; j++)
            {

                if((mot[i].idTipo == mot[j].idTipo && (mot[i].id > mot[j].id))
                        ||(mot[i].idTipo != mot[j].idTipo && (mot[i].idTipo > mot[j].idTipo)))
                {
                	auxMoto = mot[i];
                    mot[i] = mot[j];
                    mot[j] = auxMoto;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}







