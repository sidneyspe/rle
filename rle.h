/*
 * RLE.h
 *
 *  Created on: 08/11/2012
 *      Author: sidney
 */

#ifndef _RLE_H_
#define _RLE_H_

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


char inFile[50], outFile[50];  /* array definido para o nome do arquivo que será criado e utilizado para um novo arquivo */
int opcao;


/* Prototipos */

int rleCompress(char *inFile, char *outFile); /* Comprime para arquivo .rle */
int rleDecompress(char *inFile, char *outFile); /* Descomprime para arquivo .pgm */

#endif  /* ndef _RLE_H_ */
