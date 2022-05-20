/*
 * Funcionvalidar.c
 *
 *  Created on: 20 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarPalabra(char palabra[])
{
	for(int i = 0;i<strlen(palabra);i++)
	{
		if(!(isalpha(palabra[i])))
		{
			return 0;
		}
	}

	return  1;
}


