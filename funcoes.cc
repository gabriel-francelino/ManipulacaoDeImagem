/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int lin, col, i, j, tons;
int m[1000][1000]; 
string tipo;
char line[80];

int leMatriz(const char *nome) {
    ifstream myfile(nome);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            //ler o tipo
            myfile >> tipo;
            if (tipo != "P2") {
                cout << "Erro. Tipo errado.";
                return 1;
            }
            
            //ler a matriz
            myfile >> col;
            cout << "    Colunas: " << col;
            myfile >> lin;
            cout << "    Linhas: " << lin;
            cout << endl;
            myfile >> tons;

            if (lin < 1 || col < 1) {
                cout << "Não foi possível ler o arquivo!" << endl;
                return -1;
            }
            
            int *p = &m[0][0];
            for (int i = 0; i < lin; i++) {
                for (int j = 0; j < col; j++) {
                    myfile >> *p;
                    p++;
                }
            }
        }
        myfile.close();
    } else
        cout << "Não foi possível ler o arquivo." << endl;
    return 0;
}

void escreveMatriz(const char *nome) {
    ofstream myfile2;
    myfile2.open(nome);
    if (myfile2.is_open()) {
        myfile2 << "P2" << endl;
        //myfile2 << "#Create by Gabriel..." << endl;
        myfile2 << col << " " << lin << endl;

        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                myfile2 << m[i][j] << " ";
            }
            myfile2 << endl;
        }
        myfile2.close();

    } else
        cout << "Não foi possível escrever no arquivo" << endl;

}

void inverteMatriz(const char *nome,const char *nome1) {
    leMatriz(nome);
    ofstream myfile;
    myfile.open(nome1);
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;
        int *p = &m[0][0];
        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                myfile << tons - *p << " ";
                p++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível inverter a matriz!";

}

void giraDireita(const char *nome,const char *nome1) {
    int *p, *p1, *q, *r;
    leMatriz(nome);
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open(nome1);
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

void giraEsquerda(const char *nome,const char *nome1) {
    int *p, *p1, *q, *aux, *r;
    leMatriz(nome);
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open(nome1);
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
