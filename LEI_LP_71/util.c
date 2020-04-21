/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

/**
 * Esta função adiciona os dados de um determinado cliente
 * 
 * @param clientes - apontador para a estrutura cliente
 * @param quantos - apontador que identifica quantos elementos se encontram na estrutura clientes
 * @param ncc - numero do cartão de cidadão, principal elemento identificador do cliente
 */
void leCliente(cliente *clientes, int *quantos, int ncc){
    
    readString(clientes[*quantos].nome, (TAM_STR - 1), "Introduza o nome do cliente: ");
    clientes[*quantos].cc = ncc;
    readInt(&clientes[*quantos].nif, 100000000,999999999, "Introduza o NIF: ");
    readString(clientes[*quantos].nib, 22, "Introduza o NIB: ");
    readString(clientes[*quantos].morada.rua, (TAM_STR - 1), "Introduza as informacoes sobre a morada:\nRua: ");
    readInt(&clientes[*quantos].morada.num, 1, 2000, "Numero de porta: ");
    readString(clientes[*quantos].morada.localidade, (TAM_STR - 1), "Localidade: ");
    readString(clientes[*quantos].morada.concelho, (TAM_STR - 1), "Concelho: ");
    readString(clientes[*quantos].morada.distrito, (TAM_STR - 1), "Distrito: ");
    readString(clientes[*quantos].morada.cpostal, 9, "Codigo postal: ");
    readString(clientes[*quantos].viatura.matricula,7, "Introduza as informações sobre a viatura:\nMatricula, no formato 00AA00: ");
    readString(clientes[*quantos].viatura.marca, (TAM_STR - 1), "Marca: ");
    readString(clientes[*quantos].viatura.modelo, (TAM_STR - 1), "Modelo: ");
    readInt(&clientes[*quantos].viatura.categoria, 1, 4, "Categoria: ");
    (*quantos)++;
    
    printf("Cliente adicionado com sucesso!\n\n");
}

/**
 * Esta função devolve a posição em que ocorre o cliente com o número de cartão de cidadão dado
 * 
 * @param clientes - apontador para a estruruta cliente
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * @param ncc - numero do cartão de cidadão, principal elemento identificador do cliente
 * @return indíce do aluno, caso este exista, ou -1 caso não exista
 */
int pesquisa(cliente *clientes, int quantos, int ncc){
    int i = 0;
    
    while(i < quantos && clientes[i].cc != ncc)
    {
        i++;
    }
    
    if (i == quantos)
    {
        return -1;
    }
    
    else
    {
        return i;
    }
}

/**Adiciona Cliente a lista de de clientes, se possivel
 * @param clientes - apontador duplo para o endereço do primeiro elemento da lista clientes
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * @param tam_max - apontador para o tamnho do array
 */
int add_client(cliente **clientes, int *quantos, int *tam_max){
    cliente *novo;
    int ncc = 0, pos = 0;
    
    readInt(&ncc, 0, 99999999, "\nIntroduza o numero do cartao de cidadao do cliente: ");
    pos = pesquisa(*clientes, *quantos, ncc);
    
    if (pos == -1)
    {
        if (*quantos == *tam_max)
        {
            novo = realloc(*clientes, ((*quantos)+TAM_INCREMENTO)*sizeof(cliente));
            
            if (novo == NULL)
            {
                printf("O cliente não foi adicionado.\n\n");
            }
            
            else
            {
                *clientes = novo;
                (*tam_max) += TAM_INCREMENTO;
                leCliente(*clientes, quantos, ncc);
                printf("Cliente adicionado com sucesso!\n\n");
            }
        } 
        
        else
        {
            leCliente(*clientes, quantos, ncc);
        }
    }
    
    else
    {
        printf("O numero de cartao de cidadao introduzido ja existe!\n\n");
    }
}

/**Edita a informação de um cliente, se existir
 * 
 * @param clientes - apontador duplo para o endereço do primeiro elemento da lista clientes
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * @param tam_max - apontador para o tamanho do array
 */
void editar_user(cliente **clientes, int* quantos, int* tam_max){
    int encontrou;
    int escolha;
    int ncc;
    
    readInt(&ncc, 0, 99999999, "\nIntroduza o numero do cartao de cidadao do cliente: ");
    encontrou = pesquisa(*clientes, *quantos, ncc);
    
    if (ncc == -1)
    {
        printf("O numero de cartao de cidadao introduzido nao existe!\n");
    }
    
    else
    {
    do
    {
        do
        {
            printf("O que deseja Editar?\n");
            printf("1 - Editar Nome\n");
            printf("2 - Editar Numero de Cartão de Cidadão\n");
            printf("3 - Editar NIF\n");
            printf("4 - Editar NIB\n");
            printf("Editar Morada:\n5 - Editar Rua\n");
            printf("6 - Editar Numero de Porta\n");
            printf("7 - Editar Localidade\n");
            printf("8 - Editar Concelho\n");
            printf("9 - Editar Distrito\n");
            printf("10 - Editar Codigo Postal\n");
            printf("Editar Viatura:\n");
            printf("11 - Editar Matrícula\n");
            printf("12 - Editar Marca\n");
            printf("13 - Editar Modelo\n");
            printf("14 - Editar Categoria\n");
            printf("0 - Voltar ao inicio\n");
            printf("Selecione a opcao que deseja efetuar: ");
            readInt(&escolha, 0, 14, "");
        }while(escolha < 0 || escolha > 14);
        
        switch(escolha)
        {
            case 1: 
                    printf("Novo Nome: ");
                    scanf("%s", &clientes[encontrou]->nome);
                    printf("Dado alterado com sucesso!\n");
                break;
        
            case 2:
                    printf("Novo Numero de Cartao de Cidadao: ");
                    scanf("%d", &clientes[encontrou]->cc);
                    printf("Dado alterado com sucesso!\n");
                break; 
        
            case 3:
                    printf("Novo NIF: ");
                    scanf("%d", &clientes[encontrou]->nif);
                    printf("Dado alterado com sucesso!\n");
                break; 
        
            case 4:
                    printf("Novo NIB: ");
                    scanf("%d", &clientes[encontrou]->nib);
                    printf("Dado alterado com sucesso!\n");
                break; 
        
            case 5:
                    printf("Nova Rua: ");
                    scanf("%s", &clientes[encontrou]->morada.rua);
                    printf("Dado alterado com sucesso!\n");
                break; 
        
            case 6:
                    printf("Novo Numero de Porta: ");
                    scanf("%d", &clientes[encontrou]->morada.num);
                    printf("Dado alterado com sucesso!\n");
                break;
        
            case 7:
                    printf("Nova Localidade: ");
                    scanf("%s", &clientes[encontrou]->morada.localidade);
                    printf("Dado alterado com sucesso!\n");
                break;
        
            case 8:
                    printf("Novo Concelho: ");
                    scanf("%s", &clientes[encontrou]->morada.concelho);
                    printf("Dado alterado com sucesso!\n");
                break;
        
            case 9:
                    printf("Novo Distrito: ");
                    scanf("%s", &clientes[encontrou]->morada.distrito);
                    printf("Dado alterado com sucesso!\n");
                break;
                
            case 10:
                    printf("Novo Codigo Postal: ");
                    scanf("%s", &clientes[encontrou]->morada.cpostal);
                    printf("Dado alterado com sucesso!\n");
                break;
                
            case 11:
                    printf("Nova Matricula: ");
                    scanf("%s", &clientes[encontrou]->viatura.matricula);
                    printf("Dado alterado com sucesso!\n");
                break;
                
            case 12:
                    printf("Nova Marca: ");
                    scanf("%s", &clientes[encontrou]->viatura.marca);
                    printf("Dado alterado com sucesso!\n");
                break;
                
            case 13:
                    printf("Novo Modelo: ");
                    scanf("%s", &clientes[encontrou]->viatura.modelo);
                    printf("Dado alterado com sucesso!\n");
                break;
                
            case 14:
                    printf("Nova Categoria: ");
                    scanf("%d", &clientes[encontrou]->viatura.categoria);
                    printf("Dado alterado com sucesso!\n");
                break;
        }
    }while (escolha != 0);
    }
}    

/**Remove o cliente da lista, se existir
 * @param clientes - apontador duplo para o endereço do primeiro elemento da lista clientes
 * @param quantos - identifica quantos elementos se encontram na estrutura clientes
 * @param tam_max - apontador para o tamnho do array
 */
void removeclient(cliente **clientes, int *quantos, int *tam_max){
    cliente *novo;
    int pos;
    int ncc = 0;
    
    readInt(&ncc, 0, 99999999, "\nIntroduza o numero do cartao de cidadao do cliente: ");
    
    pos = pesquisa(*clientes, *quantos, ncc);
    
    if (pos > -1)
    {
        while(pos < (*quantos) - 1)
        {
            (*clientes)[pos] = (*clientes)[pos + 1];
            pos++;
        }
        
        (*quantos)--;
        printf("Cliente removido!\n\n");
        
        if(*tam_max - *quantos >= TAM_DECREMENTO)
        {
            novo = realloc(*clientes, ((*tam_max) * sizeof(cliente)) - TAM_DECREMENTO * sizeof(cliente));
            
            if(novo == NULL)
            {
                printf("Realocação de memória falhou.\n\n");
            }
            
            else
            {
                *clientes = novo;
                (*tam_max) -= TAM_DECREMENTO;
            }
        }
    }
    
    else
    {
        printf("O cliente com o cartao de cidadao numero %d nao existe!\n\n", ncc);
    }
}

/**Imprime os dados de determinadao cliente, se existir
 * @param clientes - array de clientes
 * @param quantos - identifica quantos elementos se encontram no array
 */
void print_pesquisa(cliente *clientes, int *quantos){
    
    printf("Nome: %s\n", clientes[*quantos].nome);
    printf("Numero de cartao de cidadao: %d\n", clientes[*quantos].cc);
    printf("Numero de identificacao fiscal: %d\n", clientes[*quantos].nif);
    printf("Numero de identificacao bancaria: %s\n", clientes[*quantos].nib);
    printf("Morada completa:\nRua: %s\n", clientes[*quantos].morada.rua);
    printf("Numero de porta: %d\n", clientes[*quantos].morada.num);
    printf("Localidade: %s\n", clientes[*quantos].morada.localidade);
    printf("Concelho: %s\n", clientes[*quantos].morada.concelho);
    printf("Distrito: %s\n", clientes[*quantos].morada.distrito);
    printf("Codigo postal: %s\n", clientes[*quantos].morada.cpostal);
    printf("Informacoes sobre a viatura:\nMatricula: %s\n", clientes[*quantos].viatura.matricula);
    printf("Marca: %s\n", clientes[*quantos].viatura.marca);
    printf("Modelo: %s\n", clientes[*quantos].viatura.modelo);
    printf("Categoria: %d\n\n", clientes[*quantos].viatura.categoria);
}

/**Pesquisa cliente pelo seu numero de cartão de cidadão, se existir
 * @param clientes - array de clientes
 * @param quantos - identifica quantos elementos se encontram no array clientes
 * @param tam_max - apontador para o tamnho do array
 * @return -posiçao/indice do cliente
 */
int pesquisar_cliente(cliente **clientes, int *quantos, int tam_max){
    int ncc = 0, pos = 0;
    
    readInt(&ncc, 0, 99999999, "\nIntroduza o numero do cartao de cidadao do cliente: ");
    pos = pesquisa(*clientes, *quantos, ncc);
    
    if (pos == -1)
    {
        printf("O numero de cartao de cidadao introduzido nao existe!\n");
    }
    
    else
    {
        print_pesquisa(*clientes, quantos);
    }
    return pos;
}

/**Lista os clientes guradados no programa
 * @param clientes - array de clientes
 * @param quantos - identifica quantos elementos se encontram no array clientes
 */
void listar_user(cliente **clientes, int *quantos){
    int i;
   FILE *client= fopen("clientes.txt","r");
    
    if(client==NULL)
    {
        printf("Erro ao abrir/criar o ficheiro clientes.txt!!!\n");
    }
    
    else
    {
        printf("Listagem de Clientes: \n");
    
        for (i = 0; i < *quantos; i++)
        {
            printf("Nome: %s\n", (*clientes)[i].nome);
            printf("Numero de cartao de cidadao: %d\n", (*clientes)[i].cc);
            printf("Numero de identificacao fiscal: %d\n", (*clientes)[i].nif);
            printf("Numero de identificacao bancaria: %s\n", (*clientes)[i].nib);
            printf("Informacoes sobre a morada:\n     Rua: %s\n", (*clientes)[i].morada.rua);
            printf("     Numero de porta: %d\n", (*clientes)[i].morada.num);
            printf("     Localidade: %s\n", (*clientes)[i].morada.localidade);
            printf("     Concelho: %s\n", (*clientes)[i].morada.concelho);
            printf("     Distrito: %s\n", (*clientes)[i]. morada.distrito);
            printf("     Codigo postal: %s\n", (*clientes)[i].morada.cpostal);
            printf("Informacoes sobre a viatura:\n     Matricula: %s\n", (*clientes)[i].viatura.matricula);
            printf("     Marca: %s\n", (*clientes)[i].viatura.marca);
            printf("     Modelo: %s\n", (*clientes)[i].viatura.modelo);
            printf("     Categoria: %d\n\n", (*clientes)[i].viatura.categoria);
        
        }
        fclose(client);
    }
   }
