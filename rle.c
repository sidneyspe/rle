/*
 * RLE.c
 *
 *  Created on: 08/11/2012
 *      Author: sidney
 */


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


/* Comprime uma imagem usando RLE */
int rleCompress(char *inFile, char *outFile)
{
    FILE *entrada;                         	/* Entrada original */
    FILE *saida;                       		/* Saida comprimida */
    int atual, anterior;             		/* caractere atual e caractere anterior */
    unsigned char frequencia;              	/* contador usado para frequencia de repetições de determinado caractere*/

    /* Abre arquivos de entrada e saida */
    if ((entrada = fopen(inFile, "rb")) == NULL)
    {
        perror(inFile);
        return 0;
    }

    if (outFile == NULL)
    {
        saida = stdout;     /* default to stdout */
    }
    else
    {
        if ((saida = fopen(outFile, "wb")) == NULL)
        {
            fclose(entrada);
            perror(outFile);
            return 0;
        }
    }

    anterior = EOF;     /* força o proximo caractere a ser diferente */
    frequencia = 0;

    /* Ler a entrada até que não haja mais nada */
    while ((atual = fgetc(entrada)) != EOF)
    {
        fputc(atual, saida);

        /* verifica se a variavel atual é igual a variavel anterior */
        if (atual == anterior)
        {
            /* começa a usar a frequencia de repetições para determinado numero*/
            frequencia = 0;

            while ((atual = fgetc(entrada)) != EOF)
            {
                if (atual == anterior)
                {
                    frequencia++;

                    if (frequencia == UCHAR_MAX) /* UCHAR_MAX é definido na biblioteca limits.h*/
                    {
                        /* se chegar ao maximo que o contador poder chegar, então ponha no arquivo */
                        fputc(frequencia, saida);

                        /* força o proximo caractere a ser diferente */
                        anterior = EOF;
                        break;
                    }
                }
                else
                {
                    /* run ended */
                    fputc(frequencia, saida);
                    fputc(atual, saida);
                    anterior = atual;
                    break;
                }
            }
        }
        else
        {
            /* proximo caractere */
            anterior = atual;
        }

        if (atual == EOF)
        {
            /* execução terminou por causa do EOF ? */
            fputc(frequencia, saida);
            break;
        }
    }

    /* Fecha todos os arquivos abertos */
    fclose(saida);
    fclose(entrada);
    printf("Compressão Realizada com Sucesso!\n");
    return 1;
}

/* Descomprime um arquivo em rle para o arquivo original pgm */
int rleDecompress(char *inFile, char *outFile)
{
    FILE *entrada;                      /* Entrada original */
    FILE *saida;                       	/* Saida comprimida */
    int atual, anterior;             	/* caractere atual e caractere anterior */
    unsigned char frequencia;           /* contador usado para frequencia de repetições de determinado caractere*/

    /* Abre arquivos de entrada e saida */
    if ((entrada = fopen(inFile, "rb")) == NULL)
    {
        perror(inFile);
        return 0;
    }

    if (outFile == NULL)
    {
        saida = stdout;     /* default to stdout */
    }
    else
    {
        if ((saida = fopen(outFile, "wb")) == NULL)
        {
            fclose(entrada);
            perror(outFile);
            return 0;
        }
    }

    /* inicia a descompressão */
    anterior = EOF;

    /* ler a entrada até que não haja mais nada */
    while ((atual = fgetc(entrada)) != EOF)
    {
        fputc(atual, saida);

        if (atual == anterior)
        {
            /* pega o valor da entrada e coloca na saida, repetindo o mesmo numero por causa da frequencia. */
            frequencia = fgetc(entrada);
            while (frequencia > 0)
            {
                fputc(atual, saida);
                frequencia--;
            }

            anterior = EOF;
        }
        else
        {
            anterior = atual;
        }
    }

    /* fecha todos os arquivos */
    fclose(saida);
    fclose(entrada);
    printf("Descompressão Realizada com Sucesso!\n");
    return 1;
}
