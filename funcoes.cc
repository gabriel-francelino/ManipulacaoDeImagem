/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int lin, col, i, j, tons, *p;
int m[404][600]; //fazer alocação de memoria ******
string tipo;

int leMatriz(char *nome) {
    ifstream myfile(nome);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            //ler o tipo
            myfile >> tipo;
            if (tipo != "P2") {
                cout << "Erro. Tipo errado.";
                return 1;
            }
            //pular linhas de comentário

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
                    //cout << "  mat[" << i << "][" << j << "]: " << m[i][j];
                }
                //cout << endl;
            }
            //cout << endl;

        }
        myfile.close();
    } else
        cout << "Não foi possível ler o arquivo." << endl;
    return m[lin][col];
}

void escreveMatriz(char *nome){
    ofstream myfile2;
    myfile2.open(nome);
    if(myfile2.is_open()){
        myfile2 << "P2" << endl;
        //myfile2 << "#Create by Gabriel..." << endl;
        myfile2 << col << " " << lin <<endl;

        for(i=0; i<lin; i++){
            for(j=0; j<col; j++){
                myfile2 << m[i][j] << " ";
            }
            myfile2 << endl;
        }
        myfile2.close();

    }
    else
        cout << "Não foi possível escrever no arquivo" << endl;
 
}

void inverteMatriz(char *nome, char *nome1){
    leMatriz(nome);
    ofstream myfile;
    myfile.open(nome1);
    if (myfile.is_open()){
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;
        for( i=0; i<lin; i++){
            for( j=0; j<col; j++){
                myfile << tons - m[i][j] << " ";
            }
            myfile << endl;
        }
        myfile.close();
    }
    else
        cout << "Não foi posssível inverter a matriz!";
 
}
