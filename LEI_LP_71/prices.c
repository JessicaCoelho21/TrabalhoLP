#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "API_Leitura.h"
#include "API_Utils.h"
#include "ficheiros.h"
#include "structs.h"
#include "util.h"
#include "export.h"
#include "extras.h"
#include "viagem.h"
#include "prices.h"

/**
 * Lista as matrizes dos preços, fornecida o ficheiro Precos.txt
 */
int list_precos(){
    Viagem matriz[NUM_PORTAGENS][NUM_PORTAGENS];
    
    preencheMatriz((Viagem*) matriz, "Precos.txt", false);
    
    //imprimir conteúdos lidos de ficheiro, conjuntamente
    int i, j;
    
    for (i = 0; i < NUM_PORTAGENS; i++)
    {
        for (j = 0; j < NUM_PORTAGENS; j++)
        {
            printf("%f\t", matriz[i][j].preco);
        }
        
        printf("\n");
    }
        
}

/**
 * Edita/altera os preços das portagens
 */
int edit_precos(){
    Viagem matriz[NUM_PORTAGENS][NUM_PORTAGENS];
    int beg, fin;
    float novo_preco;
    
    preencheMatriz((Viagem*) matriz, "Distancias.txt", true);
    preencheMatriz((Viagem*) matriz, "Precos.txt", false);
    
    readInt(&beg, 0, 4, "Introduza o lanço de entrada: ");
    readInt(&fin, 0, 4, "Introduza o lanço de saida: ");
    readFloat(&novo_preco, 0.0, 100.0, "Introduza o novo preço entre os lanços que inseriu: ");
    
    matriz[beg][fin].preco = novo_preco;
    
    FILE *fp = fopen("Precos.txt", "w");
    
    fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",matriz[0][0].preco, matriz[0][1].preco, matriz[0][2].preco, matriz[0][3].preco, matriz[0][4].preco);
    fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",matriz[1][0].preco, matriz[1][1].preco, matriz[1][2].preco, matriz[1][3].preco, matriz[1][4].preco);
    fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",matriz[2][0].preco, matriz[2][1].preco, matriz[2][2].preco, matriz[2][3].preco, matriz[2][4].preco);
    fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",matriz[3][0].preco, matriz[3][1].preco, matriz[3][2].preco, matriz[3][3].preco, matriz[3][4].preco);
    fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",matriz[4][0].preco, matriz[4][1].preco, matriz[4][2].preco, matriz[4][3].preco, matriz[4][4].preco);
    
    fclose(fp);
}
