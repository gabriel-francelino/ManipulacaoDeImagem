/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcoes.h
 * Author: anaca
 *
 * Created on 17 de Dezembro de 2021, 10:55
 */

#ifndef FUNCOES_H
#define FUNCOES_H

int leMatriz(const char *nome);
void escreveMatriz(const char *nome);
void negativo( int lin, int col, int tons, int m[1000][1000]);
void giraDireita(int lin, int col, int tons, int m[1000][1000]);
void giraEsquerda(int lin, int col, int tons, int m[1000][1000]);
void inverteVertical(int lin, int col, int tons, int m[1000][1000]);
void inverteHorizontal(int lin, int col, int tons, int m[1000][1000]);
void escureceBordas(int lin, int col, int tons, int m[1000][1000]);

#endif /* FUNCOES_H */

