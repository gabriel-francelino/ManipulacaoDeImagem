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
    myfile.open("negativo.pgm");
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
    myfile.open("giradoDireita.pgm");
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
    myfile.open("giradoEsquerda.pgm");
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
    myfile.open("invertidoVerticalmente.pgm");
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
    myfile.open("invertidoHorizontalmente.pgm");
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

void escureceBordas(int lin, int col, int tons, int m[1000][1000]){
    int *p, *p1, *q, *q1, *aux, *pIndex, k;
    int darkMat[col][lin];
    int tam = lin*col;
    ofstream myfile;
    myfile.open("bordasEscurecidas.pgm");
    if (myfile.is_open()) {
        myfile << "P2" << endl;
        myfile << col << " " << lin << endl;
        myfile << tons << endl;
        
        //passar os valores da matriz m para uma nova matriz 
        //para poder reutilizar os valores originais em outra função
        pIndex=&darkMat[0][0];
        for(aux=&m[0][0]; aux<&m[0][0]+tam; aux++){
            *pIndex = *aux;
            pIndex++;
        }

        //escurecer bordas
        p=&darkMat[0][0];
        p1=&darkMat[0][0]+col-1;
        q=&darkMat[0][0]+tam-1;
        q1=&darkMat[0][0]+tam-col;
        
        //quantidade a ser escurecida
        k=80;
                    
        for(i=0, j=k; i<k; i++){
            //borda superior
            for(pIndex=p; pIndex<p1; ){
                *pIndex = escurecerPixel(*pIndex, (k-i));
                pIndex++;
            }
            //borda direita
            for(pIndex=p1; pIndex<q; ){
                //código
                *pIndex = escurecerPixel(*pIndex, (k-i));
                pIndex+=col;
            }
            //borda inferior
            for(pIndex=q; pIndex>q1; ){
                //código
                *pIndex = escurecerPixel(*pIndex, (k-i));
                pIndex--;
            }
            //borda esquerda
            for(pIndex=q1; pIndex>p; ){
                //código
                *pIndex = escurecerPixel(*pIndex, (k-i));
                pIndex-=col;
            }
            p+=col+1;
            p1+=col-1;
            q-=col+1;
            q1-=col-1;
            j--;
        }
        
        //escrever a matriz no arquivo
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
        cout << "Não foi posssível escurecer as bordas da matriz!";
}
