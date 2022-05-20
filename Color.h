/*
 * Color.h
 *
 *  Created on: 18 may. 2022
 *      Author: nico
 */

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;


#endif /* COLOR_H_INCLUDED */

void coloresLista(eColor vec[],int tamC);
int descripcionColor(eColor vec[], int tamC, int id, char color[]);
