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
#include "viagem.h"
#include "export.h"
#include "extras.h"

/**Leitura de dados para gestao de viagens
 * @param clientes - array de clientes
 * @param quantos- apontador para o numero de clientes que existem atualmente 
 * no array clientes
 * @param inicial - numero do lanço de entrada
 * @param final - numero do lanço de saida
 */

//Adicionar detalhes sobre a viagem
void leviagem(cliente *clientes, int *i, int inicial, int final){

    Viagem matriz[NUM_PORTAGENS][NUM_PORTAGENS];

    preencheMatriz((Viagem*) matriz, "Distancias.txt", true);

    clientes[*i].viagem->distancia = matriz[inicial][final].distancia;
    clientes[*i].viagem->entrada = inicial;
    clientes[*i].viagem->saida = final;
    readString(clientes[*i].viagem->data, 11, "Introduza a data, no formato DD-MM-AAAA: ");
    readString(clientes[*i].viagem->hora, 6, "Introduza a hora na qual passou no portico de saida, no formato HH:MM: ");

}

//Adicionar uma viagem a um determinado cliente existente
int add_viagem(cliente **clientes, int *quantos, int tam_max){
    int ncc = 0, pos = 0, inicial = 0, final = 0,i=0;

    readInt(&ncc, 0, 99999999, "Introduza o numero do cartao de cidadao do cliente: ");
    pos = pesquisa(*clientes, *quantos, ncc);

    if (pos != -1)
    {


        readInt(&inicial, 0, 4, "Introduza o portico de entrada: ");
        readInt(&final, 0, 4, "Introduza o portico de saida: ");
        leviagem(*clientes, &pos, inicial, final);


        }

        else
        {
        printf("O cliente não existe!!");
        }

}


/*void leviagem(cliente *clientes, int i, int inicial, int final){

    Viagem matriz[NUM_PORTAGENS][NUM_PORTAGENS];

    preencheMatriz((Viagem) matriz, "Distancias.txt", true);

    clientes[i].viagem->distancia = matriz[inicial][final].distancia;
    clientes[i].viagem->entrada = inicial;
    clientes[i].viagem->saida = final;
    readString(clientes[i].viagem->data, 11, "Introduza a data, no formato DD-MM-AAAA: ");
    readString(clientes[*i].viagem->hora, 6, "Introduza a hora na qual passou no portico de saida, no formato HH:MM: ");

}
*/

/**Adiciona viagem
 * @param clientes - apontador duplo para o endereço do primeiro elemento da lista clientes
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * @param tam_max - apontador para o tamnho do array
 */
/*int add_viagem(cliente **clientes, int *quantos, int tam_max){
    int ncc = 0, pos = 0, inicial = 0, final = 0,i=0;

    readInt(&ncc, 0, 99999999, "Introduza o numero do cartao de cidadao do cliente: ");
    pos = pesquisa(clientes, quantos, ncc);

    if (pos != -1)
    {


        readInt(&inicial, 0, 4, "Introduza o portico de entrada: ");
        readInt(&final, 0, 4, "Introduza o portico de saida: ");
        leviagem(clientes, &pos, inicial, final);


        }

        else
        {
        printf("O cliente não existe!!");
        }

}*/

/**Leitura para pesquisar viagens
 * @param clientes - array de clientes
 * @param quantviagem - numero de elementos que existem no array
 */
void print_pesquisa_viagens(cliente *clientes, int quantviagem){
    int i = 0;
    
    for(i = 0; i < quantviagem; i++)
    {
        printf("Nome do cliente: %s\n", clientes->nome);
        printf("Informacoes sobre a viagem:\nData: %s\n", clientes->viagem->data);
        printf("Hora de saida: %s\n", clientes->viagem->hora);
        printf("Portico de entrada: %u\n", clientes->viagem->entrada);
        printf("Portico de saida: %u\n", clientes->viagem->saida);
    }
}

/**Pesquisa viagens 
 * 
 * @param clientes - apontador duplo para o endereço do primeiro elemento da lista clientes
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * @param tam_max - apontador para o tamnho do array
 */
int pesquisar_viagens(cliente **clientes, int *quantos, int *quantviagem){
    int ncc = 0, pos = 0;
    
    readInt(&ncc, 0, 99999999, "Introduza o numero do cartao de cidadao do cliente: ");
    pos = pesquisa(*clientes, *quantos, ncc);
    
    if (pos == -1)
    {
        printf("O numero de cartao de cidadao introduzido nao existe!\n");
    }
    
    else
    {
        print_pesquisa_viagens(*clientes, *quantviagem);
    }
}
 