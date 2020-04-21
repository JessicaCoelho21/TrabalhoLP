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
#include "prices.h"
#include "viagem.h"

/**Guarda num ficheiro.txt as informaçoes relativas aos clientes
 * 
 * @param clientes - apontador duplo para o endereço do primeiro elemento da lista clientes
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * 
 */
void guardarCliente(cliente **clientes, int *quantos){
    int i;
    FILE *client= fopen("clientes.txt","a+");
    
    if(client==NULL)
    {
        printf("Erro ao abrir/criar o ficheiro clientes.txt!!!\n");
    }
    
    else
    {
        for (i = 0; i < *quantos; i++)
        {
            fprintf(client,"Nome: %s\n\r", (*clientes)[i].nome);
            fprintf(client,"Numero de cartao de cidadao: %d\n\r", (*clientes)[i].cc);
            fprintf(client,"Numero de identificacao fiscal: %d\n\r", (*clientes)[i].nif);
            fprintf(client,"Numero de identificacao bancaria: %s\n\r", (*clientes)[i].nib);
            fprintf(client,"Informacoes sobre a morada:\n     Rua: %s\n\r", (*clientes)[i].morada.rua);
            fprintf(client,"     Numero de porta: %d\n\r", (*clientes)[i].morada.num);
            fprintf(client,"     Localidade: %s\n\r", (*clientes)[i].morada.localidade);
            fprintf(client,"     Concelho: %s\n\r", (*clientes)[i].morada.concelho);
            fprintf(client,"     Distrito: %s\n\r", (*clientes)[i]. morada.distrito);
            fprintf(client,"     Codigo postal: %s\n\r", (*clientes)[i].morada.cpostal);
            fprintf(client,"Informacoes sobre a viatura:\n\r     Matricula: %s\n\r", (*clientes)[i].viatura.matricula);
            fprintf(client,"     Marca: %s\n\r", (*clientes)[i].viatura.marca);
            fprintf(client,"     Modelo: %s\n\r", (*clientes)[i].viatura.modelo);
            fprintf(client,"     Categoria: %d\n\n\r", (*clientes)[i].viatura.categoria);
            printf("Dados exportados com sucesso!\n\n");
        }
    }
    fclose(client);
}

/**Guarda num ficheiro.txt as informaçoes relativas as viagens
 * 
 * @param clientes - array de clientes
 * @param viagens - array de viagens
 * @param quantos- apontador para o numero de clientes que existem atualmente 
 * no array clientes
 * @param quantviagem-apontador para o numero de clientes que existem atualmente 
 * no array viagens
 * 
 */
void guardarViagem(cliente **clientes, Viagem **viagens, int *quantos, int *quantviagem){
    int i, j;
    
    FILE *travel = fopen("viagens.txt", "a+");
    
    Viagem matriz[NUM_PORTAGENS][NUM_PORTAGENS];
    
    preencheMatriz((Viagem*) matriz, "Distancias.txt", true);
    
    if(travel == NULL)
    {
        printf("Erro ao abrir/criar o ficheiro clientes.txt!!!\n");
    }
    
    else
    {
        for(i = 0; i < *quantos; i++)
        {
            fprintf(travel, "Numero de cartao de cidadao: %d\n\r", (*clientes)[i].cc);
            
            for(j = 0; j < *quantviagem; j++)
            {
                fprintf(travel, "Data: %s\n\r", (*viagens)[j].data);
                fprintf(travel, "Hora: %s\n\r", (*viagens)[j].hora);
                fprintf(travel, "Portico de entrada: %u\n\r", (*viagens)[j].entrada);
                fprintf(travel, "Portico de saida: %u\n\r", (*viagens)[j].saida);
                fprintf(travel, "Distancia da viagem: %f\n\r", (*viagens)[j].distancia);
            }
            
            printf("Dados exportados com sucesso!\n\n");
        }
    }
    
    fclose(travel);
}