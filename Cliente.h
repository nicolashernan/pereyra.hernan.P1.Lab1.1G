/*
 * Cliente.h
 *
 *  Created on: 20 may. 2022
 *      Author: nico
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo;
}eCliente;

void ClienteLista(eCliente cli[],int tamCLI);
int descripcionCliente(eCliente cli[],int tamCLI,int id,char cliente[]);

#endif /* CLIENTE_H_ */
