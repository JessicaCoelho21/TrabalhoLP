/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   export.h
 * Author: Jéssica Beatriz
 *
 * Created on 31 de Dezembro de 2018, 9:55
 */

#ifndef EXPORT_H
#define EXPORT_H

#ifdef __cplusplus
extern "C" {
#endif

void guardarCliente(cliente **clientes, int *quantos);
void guardarViagem(cliente **clientes, Viagem **viagens, int *quantos, int *quantviagem);

#ifdef __cplusplus
}
#endif

#endif /* EXPORT_H */

