#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
//
#include "ficheiros.h"
//Biblioteca própria que contem as estruturas e as constantes utilizadas no projeto
#include "structs.h"
//Biblioteca própria que contem a gestão de utilizadores (adicionar, editar, remover, etc.)
#include "util.h"
//Biblioteca própria que contem a gestão de viagens (adicionar, etc.)
#include "viagem.h"
//Biblioteca própria que contem as funções extra implementadas
#include "extras.h"
//
#include "export.h"
//Biblioteca própria que contem a gestão de preços (editar e listar preços)
#include "prices.h"
//Bibliotecas fornecidas
#include "API_Leitura.h"
#include "API_Utils.h"

//Menus principal e secundários
int main(int argc, char** argv) {
    int opcao = 0, a = 0, b = 0, x = 0, y = 0, opt = 0;
    cliente *clientes;
    Viagem *viagens;
    int quantos;
    int tam_max;
    int quantviagem;
    int viagem_max;
    
    clientes = (cliente*) malloc(TAM_INICIAL*sizeof(cliente));
    viagens = (Viagem*) malloc(VIAGEM*sizeof(Viagem));

    if(clientes == NULL)
    {
        printf("Erro\n");
    }
    
    else
    {
        tam_max = TAM_INICIAL;
        viagem_max = VIAGEM;
    
        printf("Bem vindo a Via Verde\n");
        printf("Selecione a operacao que pretende efetuar\n");
        
        do
        {
            do
            {
                printf("1 - Gestao de utilizadores\n");
                printf("2 - Gestao de viagens\n");
                printf("3 - Gestao de precos\n");
                printf("4 - Gestao de faturas\n");
                printf("5 - Presistencia de dados\n");
                printf("6 - Informacoes extra\n");
                printf("0 - Sair\n");
                printf("Selecione a opcao: ");
                readInt(&opcao, 0, 6, "");
            } while(opcao < 0 || opcao > 6);
        
            switch (opcao)
            {
                case 1: //Gestão de utilizadores
                    do
                    {
                        do
                        {
                            printf("1 - Criar cliente\n");
                            printf("2 - Editar cliente\n");
                            printf("3 - Remover cliente\n");
                            printf("4 - Pesquisar por cliente\n");
                            printf("5 - Listar clientes\n");
                            printf("0 - Voltar ao inicio\n");
                            printf("Selecione a opcao: ");
                            readInt(&a, 0, 5, "");
                        } while(a < 0 || a > 5);
                    
                        switch (a)
                        {
                            case 1: //Adicionar um cliente
                                add_client(&clientes, &quantos, &tam_max);
                                break;
                        
                            case 2: //Editar dados de um cliente já existente
                                editar_user(&clientes, &quantos, &tam_max);
                                break;
                            
                            case 3: //Remover cliente já existente
                                removeclient(&clientes, &quantos, &tam_max);
                                break;
                            
                            case 4: //Pesquisar por cliente a partir do número de cartão de cidadão
                                pesquisar_cliente(&clientes, &quantos, tam_max);
                                break;
                            
                            case 5: //Imprimir a lista dos clientes registados
                                listar_user(&clientes, &quantos);
                                break;    
                        }
                    } while(a != 0);
                    break;
                
                case 2: //Gestão de viagens
                    do
                    {
                        do
                        {
                            printf("1 - Adicionar uma viagem\n");
                            printf("2 - Pesquisar viagens\n");
                            printf("0 - Voltar ao inicio\n");
                            printf("Selecione a opcao: ");
                            readInt(&b, 0, 2, "");
                        } while(b < 0 || b > 2);
                    
                        switch(b)
                        {
                            case 1: //Adicionar uma viagem a um determinado cliente
                                add_viagem(&clientes, &quantos, &tam_max);
                                break;
                            
                            case 2: //Pesquisar por uma determinada viagem já existente
                                pesquisar_viagens(&clientes, &quantos, &quantviagem);
                                break;
                        }
                    
                    } while (b != 0);
                    break;
                
                case 3: //Gestão de preços
                    do
                    {
                        do
                        {
                            printf("1 - Editar precos\n");
                            printf("2 - Listar precos\n");
                            printf("0 - Voltar ao inicio\n");
                            printf("Selecione a opcao: ");
                            readInt(&x, 0, 2, "");
                        } while (x < 0 || x > 2);
                        
                        switch(x)
                        {
                            case 1: //Edição de preços
                                edit_precos();
                                break;
                                
                            case 2: //listagem de preços
                                list_precos();
                                break;
                        }
                        
                    } while (x != 0);
                    break;
                
                case 4: //Gestão de faturas
                    printf("Gerar fatura: \n");
                    fatura(&clientes, &viagens, &quantos, &quantviagem);
                    break;
                
                case 5: //Presistência de dados - exportar
                    do
                    {
                        do
                        {
                            printf("1 - Gravar Dados dos Clientes\n");
                            printf("2 - Gravar Dados das Viagens\n");
                            printf("0 - Voltar ao inicio\n");
                            printf("Escolha uma opcao: ");
                            readInt(&opt, 0, 2, "");
                        } while(opt < 0 || opt > 2);
        
                    switch(opt)
                    {
                        case 1: guardarCliente(&clientes, &quantos);
                            break;
            
                        case 2: guardarViagem(&clientes, &viagens, &quantos, &quantviagem);
                            break;
                    }
        
                    }while(opt!=0);
                    
                    break;
                    
                case 6: //Funções extra
                    do
                    {
                        do
                        {
                            printf("1 - Informacao sobre multas\n");
                            printf("2 - Informacao sobre radares\n");
                            printf("3 - Reclamacoes\n");
                            printf("0 - Voltar ao inicio\n");
                            printf("Selecione a opcao: ");
                            readInt(&y, 0, 3, "");
                        }while(y < 0 || y > 3);
                        
                        switch(y)
                        {
                            case 1: //Multas de velocidade e excesso de alcool
                                tipomulta();
                                break;
                                
                            case 2: //Radares
                                menuRadar();
                                break;
                                
                            case 3: //Reclamações
                                menuReclama();
                                break;
                        }
                        
                    }while (y != 0);
                    
                    break;
            }
        
        }while(opcao != 0);
        
        free(clientes);
    }
    
    return (EXIT_SUCCESS);
}
