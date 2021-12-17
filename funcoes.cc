/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int i, j;

void negativo( int lin, int col, int tons, int m[1000][1000]) {
    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;
        int *p = &m[0][0];
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                myfile << tons - *p << " ";
                p++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível inverter a matriz!";

}

void giraDireita(int lin, int col, int tons, int m[1000][1000]) {
    int *p, *p1, *q, *r;
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << lin << " " << col << endl;
        myfile << tons << endl;

        //girar a matriz para direita
        p1 = &d[0][0];
        for (p = &m[0][0]+(tam - (col)); p<&m[0][0] + tam; p++) {
            for (q = p; q >= &m[0][0]; q -= col) {
                *p1 = *q;
                p1++;
            }
        }
        //escrever a matriz no arquivo
        r = &d[0][0];
        for (i = 0; i < col; i++) {
            for (j = 0; j < lin; j++) {
                myfile << *r << " ";
                r++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível girar a matriz!";

}

void giraEsquerda(int lin, int col, int tons, int m[1000][1000]) {
    int *p, *p1, *q, *aux, *r;
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << lin << " " << col << endl;
        myfile << tons << endl;

        //girar a matriz para esquerda
        p1 = &d[0][0];
        aux = &m[0][0]+(col-1);
        for ( p = &m[0][0]+(tam-1); p>=&m[0][0] + (tam-col); p--) {
            for ( q=aux; q <= p ; q += col ) {
                *p1 = *q;
                p1++;  
            }
            aux--;  
        }
        
        //escrever a matriz no arquivo
        r = &d[0][0];
        for (i = 0; i < col; i++) {
            for (j = 0; j < lin; j++) {
                myfile << *r << " ";
                r++;
            }
            myfile << endl;
        }
        
        myfile.close();
    } else
        cout << "Não foi posssível girar a matriz!";

}

void inverteVertical() {

}

void inverteHorizontal() {

}

void escureceBordas(){
    
}
