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
#include "extras.h"
#include "export.h"
#include "viagem.h"

/**Define o valor da multa a aplicar por execeso de velocidade a um veiculo pesado
 * 
 * @param velo- velocidade limite do local
 * @param mvelo- velocidade a que o condutor circulava
 */
void velocidadePesado(float velo, float mvelo){
    int dif = 0;
    
    dif = mvelo - velo;
    
    if(dif >= 10 && dif < 20)
    {
        printf("\nCoima entre os 60 e os 300 euros\n\n");
    }
    
    else if(dif > 20 && dif <= 60)
    {
        printf("\nCoima entre os 120 e os 600 euros\n");
        printf("Contraordenacao grave:\n");
        printf("Inibicao de conduzir 1 mes a 1 ano.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Perda de 2 pontos na carta de conducao.\n\n");  
    }
    
    else if(dif > 40 && dif <= 60)
    {
        printf("\nCoima entre os 300 e os 1500 euros  \n");
        printf("Contraordenacao muito grave:\n");
        printf("Inibicao de conduzir 2 meses a 2 anos.\n"); 
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Perda de 4 pontos na carta de conducao.\n");
        printf("Perda da carta de conducao se esta for provisoria.\n\n");
    }
    
    else if(dif > 60)
    {
        printf("\nCoima entre os 500 e os 2500 euros\n");
        printf("Coima entre os 300 e os 1500 euros\n");
        printf("Contraordenacao muito grave:\n");
        printf("Inibicao de conduzir 2 meses a 2 anos.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Perda de 4 pontos na carta de conducao.\n");
        printf("Perda da carta de conducao se esta for provisoria.\n\n");        
    }
    
    else if (dif < 10)
    {
        printf("\nNao cometeu nenhuma contraordenacao.\n\n");
    }
}

/**Define o valor da multa a aplicar por execeso de velocidade a um veiculo ligeiro
 * 
 * @param velo- velocidade limite do local
 * @param mvelo- velocidade a que o condutor circulava
 */
void velocidadeLigeiro(float mvelo, float velo){
    int dif = 0;
    
    dif = mvelo - velo;
    
    if(dif <= 30 && dif >= 0)
    {
        printf("\nCoima entre os 60 e os 300 euros\n\n");
    }
    
    else if(dif > 30 && dif <= 60)
    {
        printf("\nCoima entre os 120 e os 600 euros\n");
        printf("Contraordenacao grave:\n");
        printf("Inibicao de conduzir 1 mes a 1 ano.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Perda de 2 pontos na carta de conducao.\n\n");
    }
    
    else if(dif > 60 && dif <= 80)
    {
        printf("\nCoima entre os 300 e os 1500 euros\n");
        printf("Contraordenacao muito grave:\n");
        printf("Inibicao de conduzir 2 meses a 2 anos.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Perda de 4 pontos na carta de conducao.\n");
        printf("Perda da carta de conducao se esta for provisoria.\n\n");        
    }
    
    else if(dif > 80)
    {
        printf("\nCoima entre os 500 e os 2500 euros\n");
        printf("Contraordenacao muito grave:\n");
        printf("Inibicao de conduzir 2 meses a 2 anos.\n");
        printf("Cadastro rodovario manchado durante 5 anos.\n");
        printf("Perda de 4 pontos na carta de conducao.\n");
        printf("Perda da carta de conducao se esta for provisoria.\n\n");        
    }
    
    else if (dif < 0)
    {
        printf("\nNao cometeu nenhuma contraordenacao.\n\n");
    }
}

/**
 *  Define o valor da multa a aplicar por execeso de alcool no sangue
 */
void multaTaxa(){
    float taxa;
    
    readFloat(&taxa,0,20,"Insira a taxa de alcool no sangue: ");
    
    if(taxa >= 0.5 && taxa < 0.8)
    {
        printf("\nContraordenacao Grave.\n");
        printf("Coima entre os 250 e os 1250 euros.\n");
        printf("Perda de 3 pontos na carta de conducao.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Inibicao de conduzir de 1 mes a 1 ano.\n\n");
    }
    
    else if(taxa >= 0.8 && taxa < 1.2)
    {
        printf("\nContraordenacao Muito Grave.\n");
        printf("Coima entre os 500 e os 2500 euros.\n");
        printf("Perda de 5 pontos.\n");
        printf("Inibicao de conduzir de 2 meses a 2 anos.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n");
        printf("Perda da carta de conducao se esta for provisoria.\n\n");
    }
    
    else if(taxa > 1.2)
    {
        printf("\nCRIME\n");
        printf("Pena de Prisao ate 1 ano ou 120 dias de trabalho comunitario.\n");
        printf("Proibicao de conduzir de 3 meses a 3 anos.\n");
        printf("Cadastro rodoviario manchado durante 5 anos.\n\n");   
    }
    
    else
    {
        printf("\nNao cometeu nenhuma contraordenacao.\n\n");
    }
}

/**
 * Menu de multas por excesso de velocidade
 */
void multaVelocidade(){
    float velo, mvelo;
    int categ;
      
    do
    {
        do
        {
            printf("\t\t======Calculadora de multas por excesso de velocidade======\n");
            printf("1 - Motociclo.\n");
            printf("2 - Triciclo.\n");
            printf("3 - Automovel ligeiro de passageiros.\n");
            printf("4 - Automovel ligeiro de mercadorias.\n");
            printf("5 - Automovel pesado de passageiros.\n");
            printf("6 - Automovel pesado de mercadorias.\n");
            printf("7 - Maquina Industrial.\n");
            printf("0 - Voltar ao Menu Principal\n");
            readInt(&categ, 0, 7,"Qual a categoria do seu veiculo?: ");
        } while (categ < 0 || categ > 7);
        
        switch(categ)
        {
            case 1: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadePesado(mvelo, velo);
                break;
                    
            case 2: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadeLigeiro(mvelo, velo);
                break;  
                    
            case 3: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadeLigeiro(mvelo, velo);
                break;
                    
            case 4: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadePesado(mvelo, velo);
                break; 
                    
            case 5: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadePesado(mvelo, velo);
                break;
                    
            case 6: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadePesado(mvelo, velo);
                break; 
                    
            case 7: readFloat(&velo,0,120,"Qual o limite de velocidade do local?: ");
                    readFloat(&mvelo,0,500,"A que velocidade vinha?: ");
                    velocidadePesado(mvelo, velo);
                break;
        }
        
    }while(categ!=0);
}

/**
 * Menu para escolher que tipo de infração queremos calcular
 */
void tipomulta(){
    int opt;
    
    do
    {
        do
        {
            printf("1 - Excesso de velocidade.\n");
            printf("2 - Excesso de alcool no sangue.\n");
            printf("0 - Voltar ao Menu Principal\n");
            readInt(&opt, 0, 3,"Insira uma opcao: ");
        } while (opt < 0 || opt > 3);
        
        switch(opt)
        {
            case 1: multaVelocidade();
                break;
                
            case 2:multaTaxa();
                break;
        }
        
    }while(opt!=0);
}

/**
 * Adiciona um radar, com a sua localização,e guarda num ficheiro para mais
 * tarde ser consultado
 */
void criarRadar(){
    FILE *radar = fopen("radar.txt", "a+");
    
    char str1[]="ATENCAO: ao km ", str2[]=" do lanco ",str3[]=" ao lanco ",str4[]=" existe um radar!!!!\n";
    int inicio, fim;
    float distancia[5][5]={{0.0, 3.4, 6.0, 5.0, 9.0},
                           {3.5, 0.0, 7.0, 6.0, 12.0},
                           {6.0, 7.2, 0.0, 1.0, 20.0},
                           {5.5, 6.0, 1.2, 0.0, 5.0},
                           {9.0, 12.0, 18.0, 4.5, 0.0}};
    float dist;
    
    do
    {
        readInt(&inicio,0,4,"Insira o Portico de Origem: ");
        readInt(&fim,0,4,"Insira o Portico de Destino: ");
        
        if(inicio==fim)
        {
            printf("ERRO: portico de origem e destino iguais!!!\n");
        }
        
    } while(inicio==fim);
    
    do
    {
        readFloat(&dist,0.0,20.0,"Insira em que km aparece o radar: ");
        if(dist> distancia[inicio][fim])
        {
            printf("ERRO: a estrada so tem %.2f Km!!!\n",distancia[inicio][fim]);
        }
        
    } while(dist>distancia[inicio][fim]);
    
    if(radar==NULL)
    {
        printf("ERRO ao abrir o ficheiro!!!\n");
    }
    
    else
    {
        fprintf(radar, "%s%.2f%s%d%s%d%s", str1, dist, str2, inicio, str3, fim, str4);
    }
    
    fclose(radar);
}

/**
 * Lista todos os radares que estão guardados no ficheiro radar.txt
 */
void listRadares(){
    int c;
    FILE *radar = fopen("radar.txt", "r");
    
    while(1)
    {
        c=fgetc(radar);
        
        if(feof(radar))
        {
            break;
        }
        
        printf("%c", c);
    }
    
    fclose(radar);
}

/**
 * Menu para as funçoes Radar
 */
void menuRadar(){
    int opt;
    
    do
    {
        do
        {
            printf("1 - Listar Radares.\n");
            printf("2 - Adicionar Radar.\n");
            printf("0 - Voltar ao Menu Principal.\n");
            readInt(&opt, 0, 2,"Escolha uma opcao: ");
        } while(opt < 0 || opt > 2);
        
        switch(opt)
        {
            case 1: listRadares();
                break;
            
            case 2: criarRadar();
                break;
            
            default: printf("Opcao invalida!!!\n");
        }
        
    }while(opt!=0);
}

/**
 * Permite ao utilizador escrever uma reclamação e grava-la num ficheiro
 */
void criarReclama(){
    
    FILE *reclama = fopen("reclamacao.txt", "a+");
    char data[11], str1[TAM_MAX_STR], str2[TAM_MAX_STR],str3[]="\t\t\tReclamação: \n",str4[]="\t\t\tSugestão de melhoria:\n";
    
    readString(data, 11, "\t\t\tInsira a Data:[no formato 00-00-0000]\n");
    readString(str1,TAM_MAX_STR,"\t\t\tReclamação:\n");
    readString(str2,TAM_MAX_STR,"\t\t\tSugestão de Melhoria:\n");
    
    if(reclama==NULL)
    {
        printf("ERRO ao abrir o ficheiro!!!\n");
    }
    
    else
    {
        fprintf(reclama, "%s\n%s%s\n%s%s\n\n", data, str3, str1,  str4, str2);
    }
    
    fclose(reclama);
}

/**
 * Permite ao utilizador listar todas as reclamações que existem no ficheiro
 * reclamacao.txt
 */
void listReclama(){
    char str[350];
    FILE *reclama = fopen("reclamacao.txt", "r");
    
    if(reclama==NULL)
    {
        printf("ERRO ao abrir o ficheiro reclamacao.txt!!!\n");
    }
    
    while(fgets(str,sizeof(str),reclama)!=NULL)
    {
        printf("\n%s\n", str);
    }
    
    fclose(reclama);
}

/**
 * Menu para as funçoes Reclamações
 */
void menuReclama(){
    int opt;
    
    do
    {
        do
        {
            printf("1 - Criar Reclamação.\n");
            printf("2 - Listar Reclamações.\n");
            printf("0 - Voltar ao Menu Principal.\n");
            readInt(&opt, 0, 2,"Escolha uma opcao: ");
        } while(opt < 0 || opt > 2);
        
        switch(opt)
        {
            case 1: criarReclama();
                break;
            
            case 2: listReclama();
                break;
        }
        
    }while(opt!=0);
}
