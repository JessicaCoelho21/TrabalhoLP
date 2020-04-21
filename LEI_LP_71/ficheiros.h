/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ficheiros.h
 * Author: Jéssica Beatriz
 *
 * Created on 27 de Dezembro de 2018, 18:41
 */

#ifndef FICHEIROS_H
#define FICHEIROS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "structs.h"

    bool preencheMatriz(Viagem *matriz, char *ficheiro, bool distancia);
    void fatura(cliente **clientes, Viagem **viagens, int *quantos, int *quantviagem);

#ifdef __cplusplus
}
#endif

#endif /* FICHEIROS_H */

