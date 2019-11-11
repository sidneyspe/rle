/*
 * main.c
 *
 *  Created on: 08/11/2012
 *      Author: sidney
 */

#include "rle.h"

int main (int argc, char* argv[]){

	printf ("Informe o nome do arquivo de origem: ");
	scanf ("%s",inFile); // = argv[1];

	printf("Deseja Comprimir ou Descomprimir? \n 1: Comprimir\n 2: Descomprimir: ");
	scanf ("%d",&opcao);

	switch (opcao)
	{
			case 1:{

			strcpy (outFile,inFile); /* Copia a string inFile para outFile */
			strtok(outFile, "."); /* Extrai somente o prefixo antes do "." */
			strcat(outFile ,"_converted.rle"); /* Concatena o nome do arquivo com o sufixo */

			rleCompress(inFile, outFile);

			break;
			}
			case 2:{
			strcpy (outFile,inFile); /* Copia a string inFile para outFile */
			strtok(outFile, "_"); /* Extrai somente o prefixo antes do "_" */
			strcat(outFile ,".pgm"); /* Concatena o nome do arquivo com o sufixo */

			rleDecompress(inFile, outFile);

			break;
			}
	}

	return 0;
}
