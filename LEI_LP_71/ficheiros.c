#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "API_Leitura.h"
#include "API_Utils.h"
#include "ficheiros.h"
#include "structs.h"
#include "export.h"
#include "extras.h"
#include "util.h"
#include "viagem.h"

/**
 * Funçao booleana que lê matriz de um ficheiro e prenche os uma matriz
 * @param matriz- apontador para viagem 
 * @param ficheiro- apontador para ficheiro que queremos abrir
 * return false se o ficheiro der erro ao abrir, true se correr tudo como esperado
 */
bool preencheMatriz(Viagem *matriz, char *ficheiro, bool distancia) {
    FILE * fp;
    char * linha = NULL;
    size_t len = 0;
    const char s[] = "\t\n\0";
    char *token;
    int i = 0, j = 0;

    fp = fopen(ficheiro, "r");
    
    if (fp == NULL)
    {
        return false;
    }

    while ((getline(&linha, &len, fp)) != -1)
    {
        j = 0;    
        token = strtok(linha, s);
        
        if (distancia)
        {
            matriz[i * NUM_PORTAGENS + j].distancia = atof(token);
        }
        
        else 
        {
            matriz[i * NUM_PORTAGENS + j].preco = atof(token);
        }
        
        j++;
        
        while(token != NULL ) 
        {
            token = strtok(NULL, s);
            
            if(token != NULL)
            {
                if (distancia) 
                {
                    matriz[i * NUM_PORTAGENS + j].distancia = atof(token);
                }
                
                else 
                {
                    matriz[i * NUM_PORTAGENS + j].preco = atof(token);
                }
            }
            j++;
        }
        i++;
    }

    fclose(fp);
    
    if (linha)
    {
        free(linha);
    }
    
    return true;
}

/**Gera fatura 
 * @param clientes - array de clientes
 * @param viagens - array de viagens
 * @param quantos- apontador para o numero de clientes que existem atualmente 
 * no array clientes
 * @param quantviagem-apontador para o numero de clientes que existem atualmente 
 * no array viagens
 * 
 */
void fatura(cliente **clientes, Viagem **viagens, int *quantos, int *quantviagem){
    int ncc = 0, pos = 0, i=0;
    FILE *client= fopen("clientes.txt","r");
    
    if(client==NULL)
    {
         printf("Erro ao abrir/criar o ficheiro clientes.txt!!!\n");
    }
    
    else
    {
    readInt(&ncc, 0, 99999999, "\nIntroduza o numero do cartao de cidadao do cliente: ");
    
    pos = pesquisa(*clientes, *quantos, ncc);
    
        if (pos == -1)
        {
            printf("O numero de cartao de cidadao introduzido nao existe!\n");
        }
    
        else
        {
            while(ncc!=clientes[i]->cc)
            {
                i++;
            }
            printf("Nome: %s\n",clientes[i]->nome);
            printf("Numero de cartao de cidadao: %d\n",clientes[i]->cc);
            printf("Numero de identificacao fiscal: %d\n",clientes[i]->nif);
            printf("Numero de identificacao bancaria: %s\n",clientes[i]->nib);
            printf("Matricula: %s\n",clientes [i]->viatura.matricula);
            printf("Data da viagem: %s\n", clientes[i]->viagem[i].data);
            printf("Hora de passagem no ultimo portico: %s\n",clientes[i]->viagem[i].hora);
            printf("Portico de entrada: %u\n", clientes[i]->viagem[i].entrada);
            printf("Portico de saida: %u\n", clientes[i]->viagem[i].saida);
            printf("Distancia da viagem: %f km\n", clientes[i]->viagem[i].distancia);
            printf("Preco da viagem: %f euros\n", clientes[i]->viagem[i].preco);
        }
    }
}
