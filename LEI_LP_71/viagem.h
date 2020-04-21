/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   viagem.h
 * Author: Jéssica Beatriz
 *
 * Created on 27 de Dezembro de 2018, 19:02
 */

#ifndef VIAGEM_H
#define VIAGEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "structs.h"
    
void leviagem(cliente *clientes, int *i, int inicial, int final);
int add_viagem(cliente **clientes, int *quantos, int tam_max);
void print_pesquisa_viagens(cliente *clientes, int quantviagem);
int pesquisar_viagens(cliente **clientes, int *quantos, int *quantviagem);

#ifdef __cplusplus
}
#endif

#endif /* VIAGEM_H */

