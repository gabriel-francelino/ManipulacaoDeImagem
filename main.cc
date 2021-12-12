
#include <iostream>
#include <fstream>
#include <string.h>

#include "funcoes.h"

using namespace std;

int main(int argc, char**argv) {

    /*
    int lin, col, i, j, *p;
    int m[3][3];
    string tipo;

    ifstream myfile("teste.txt");
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            //ler o tipo
            myfile >> tipo;
            if(tipo != "P2"){
                cout << "Erro. Tipo errado.";
                return 1;
            }
            //pular linhas de comentário
            getline(myfile, tipo);
            while(tipo[0] == '#'){
                getline(myfile, tipo);
            }
            
            myfile >> lin;
            cout << "    Linhas: " << lin;
            myfile >> col;
            cout << "    Colunas: " << col;
            cout << endl;

            if (lin < 1 || col < 1) {
                cout << "Não foi possível ler o arquivo!" << endl;
                return -1;
            }

            int *p = &m[0][0];
            for (int i = 0; i < lin; i++) {
                for (int j = 0; j < col; j++) {
                    myfile >> *p;
                    p++;
                    cout << "  mat[" << i << "][" << j << "]: " << m[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
        myfile.close();
    }
    else
        cout << "Não foi possível ler o arquivo" << endl;
    
    ofstream myfile;
    myfile.open("teste2.txt");
    if(myfile.is_open()){
        myfile << "P2" << endl;
        myfile << "#Create by Gabriel..." << endl;
        myfile << col << " " << lin <<endl;
        
        for(i=0; i<lin; i++){
            for(j=0; j<col; j++){
                cout << m[i][j] << " " << endl;
            }
            cout << endl;
        }
        myfile.close();
        
    }
    else
        cout << "Não foi possível escrever no arquivo" << endl;
    */
    //leMatriz("teste.txt");
    //escreveMatriz("teste2.txt");
    
    //inverteMatriz("stanford1.pgm", "teste3.pgm");
    //giraDireita("stanford1.pgm", "teste4.pgm");
    //giraDireita("teste3.pgm", "teste4.pgm");
    giraEsquerda("teste.txt", "teste3.txt");
    return 0;
}
