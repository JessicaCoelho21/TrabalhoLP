/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: Jéssica Beatriz
 *
 * Created on 27 de Dezembro de 2018, 18:50
 */

#ifndef STRUCTS_H

#define STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

#define TAM_STR 100
#define TAM_INICIAL 100
#define TAM_INCREMENTO 3
#define TAM_DECREMENTO 3
#define VIAGEM 5
#define NUM_PORTAGENS 5
#define TAM_MAX_STR 150

    
typedef struct local{
    char rua[TAM_STR];
    int num;
    char localidade[TAM_STR];
    char concelho[TAM_STR];
    char distrito[TAM_STR];
    char cpostal[9];
}Local;

typedef struct travel{
    char data[11];
    char hora[6];
    float distancia;
    float preco;
    unsigned int entrada;
    unsigned int saida;
}Viagem;

typedef struct carro{
    char matricula[7];
    char marca[TAM_STR];
    char modelo[TAM_STR];
    int categoria;
}Carro;

typedef struct util{
    char nome[TAM_STR];
    int cc;
    int nif;
    char nib[22];
    Local morada;
    Carro viatura;
    Viagem viagem[VIAGEM];
}cliente;


#ifdef __cplusplus
}
#endif

#endif /* STRUCTS_H */

