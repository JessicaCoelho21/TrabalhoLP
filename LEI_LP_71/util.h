/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   util.h
 * Author: Jéssica Beatriz
 *
 * Created on 27 de Dezembro de 2018, 18:54
 */

#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "structs.h"
#include "ficheiros.h"
    
    void leCliente(cliente *clientes, int *quantos, int ncc);
    int pesquisa(cliente *clientes, int quantos, int ncc);
    void ler_dados(cliente **clientes, int *quantos, int *tam_max);
    int add_client(cliente **clientes, int *quantos, int *tam_max);
    void editar_user(cliente **clientes, int* quantos, int* tam_max);
    void removeclient(cliente **clientes, int *quantos, int *tam_max);
    void print_pesquisa(cliente *clientes, int *quantos);
    int pesquisar_cliente(cliente **clientes, int *quantos, int tam_max);
    void listar_user(cliente **clientes, int *quantos);


#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */

