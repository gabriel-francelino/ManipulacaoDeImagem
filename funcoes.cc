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
    int d[col][lin];    //matriz que será usada para colocar os valores manipulados da matriz anterior
    int tam = lin*col;  //tamanho da matriz
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
        p1 = &d[0][0];
        for (i = 0; i < col; i++) {
            for (j = 0; j < lin; j++) {
                myfile << *p1 << " ";
                p1++;
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

void inverteVertical(int lin, int col, int tons, int m[1000][1000]) {
    int *p, *p1, *q, *r;
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;

        //espelhar verticalmente
        p1 = &d[0][0];
        for ( p = &m[0][0]+(tam-col); p>=&m[0][0]; ) {
            for ( q=p; q < p+col ; q++ ) {
                *p1 = *q; 
                p1++;
            } 
            p-=col;
        }
        
        //escrever a matriz no arquivo
        r = &d[0][0];
        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                myfile << *r << " ";
                r++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível girar a matriz!";
}

void inverteHorizontal(int lin, int col, int tons, int m[1000][1000]) {
    int *p, *p1, *q, *r;
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;

        //espelhar horizontalmente
        p1 = &d[0][0];
        for ( p = &m[0][0]+(col-1); p<&m[0][0]+tam; ) {
            for ( q=p; q > p-col ; q-- ) {
                *p1 = *q; 
                p1++;
            } 
            p+=col;
        }
        
        //escrever a matriz no arquivo
        r = &d[0][0];
        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                myfile << *r << " ";
                r++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível girar a matriz!";
}

// Função para escurecer um pixel e retornar o novo valor
float escurecerPixel(int pixel, int sub){
    int result = pixel - sub;
    if(result < 0) {
        result = 0;
    } 
    return result;
}
/*
void escureceBordas(int lin, int col, int tons, int m[1000][1000]){
    int *pIndex, *pIndexAux;
    int darkMat[lin][col];
    int tam = lin*col;

    // Valor que vai ser decrescido da borda da matriz 
    int valorEscurece = 200;
    
    int i, j, k;
    int alterados = 0;

    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;

        //Escurecer a borda da matriz -->

        // Completar a matriz - copia a matriz m para darkMat
        pIndex = &darkMat[0][0];
        pIndexAux = &m[0][0];
        for(i = 0; i < lin; i++){ // Pode ser feito com tamanho? 
            for (j = 0; j < col; j++){
                *pIndex = *pIndexAux;
                pIndexAux++;
                pIndex++;
            }
        }
        
        for(k = 0; k < valorEscurece; k++){

            // Altera a borda superior da camada 
            if(alterados < tam){
                pIndex = &darkMat[k][k];
                for(i = 0; i < (col - (2*k)); i++){
                    *pIndex = escurecerPixel(*pIndex, (valorEscurece - k));
                    alterados++;
                    pIndex++;
                }
            }
            
            // Alter a borda inferior da camdada
            if(alterados < tam){
                // Ultima linha da camada
                pIndex = &darkMat[lin - 1 - k][k];
                for(i = 0; i < (col - (2*k)); i++){
                    *pIndex = escurecerPixel(*pIndex, (valorEscurece - k));
                    alterados++;
                    pIndex++;
                }
            }
            
            // Altera a borda esquerda da camada
            if(alterados < tam){
                pIndex = &darkMat[k+1][k];
                for(i = 0; i < (lin - (2*k) - 2); i++){
                    *pIndex = escurecerPixel(*pIndex, (valorEscurece - k));
                    alterados++;
                    pIndex += col;
                }
            }

            // Altera a borda direita da camada
            if(alterados < tam){
                pIndex = &darkMat[k + 1][col - 1 - k];
                for(i = 0; i < (lin - (2*k) - 2); i++){
                    *pIndex = escurecerPixel(*pIndex, (valorEscurece - k));
                    alterados++;
                    pIndex += col;
                }
            }
        }

        // Escrever a matriz no arquivo
        pIndex = &darkMat[0][0];
        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                myfile << *pIndex << " ";
                pIndex++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível escurecer a borda da matriz!";
}
*/

void escureceBordas(int lin, int col, int tons, int m[1000][1000]){
    int *p, *p1, *q, *q1, *r, *s;
    int d[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open("teste3.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;
        
        //passar os valores da matriz m para uma nova matriz 
        //para poder reutilizar os valores originais em outra função
        s=&d[0][0];
        for(r=&m[0][0]; r<&m[0][0]+tam; r++){
            *s = *r;
            s++;
        }

        //escurecer bordas
        p=&d[0][0];
        p1=&d[0][0]+col-1;
        q=&d[0][0]+tam-1;
        q1=&d[0][0]+tam-col;
        int k=100; //quantidade a ser escurecida
        for(i=0, j=k; i<k; i++){
            //borda superior
            for(r=p; r<p1; ){
                *r = escurecerPixel(*r, (k-i));
                r++;
            }
            //borda direita
            for(r=p1; r<q; ){
                //código
                *r = escurecerPixel(*r, (k-i));
                r+=col;
            }
            //borda inferior
            for(r=q; r>q1; ){
                //código
                *r = escurecerPixel(*r, (k-i));
                r--;
            }
            //borda esquerda
            for(r=q1; r>p; ){
                //código
                *r = escurecerPixel(*r, (k-i));
                r-=col;
            }
            p+=col+1;
            p1+=col-1;
            q-=col+1;
            q1-=col-1;
            j--;
        }
        
        //escrever a matriz no arquivo
        r = &d[0][0];
        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                myfile << *r << " ";
                r++;
            }
            myfile << endl;
        }
        myfile.close();
    } else
        cout << "Não foi posssível girar a matriz!";
}
