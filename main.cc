
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>

#include "funcoes.h"

using namespace std;

int lin, col, tons;
int m[1000][1000], *p;
string tipo;

void interface() {
    cout << "+--------------------------------------+" << endl;
    cout << "|      PROCESSAMENTO DE IMAGENS        |" << endl;
    cout << "|   Escolha qual comando deseja fazer: |" << endl;
    cout << "|     1)Inverter negativamente.        |" << endl;
    cout << "|     2)Girar para direita.            |" << endl;
    cout << "|     3)Girar para esquerda.           |" << endl;
    cout << "|     4)Inverter verticalmente.        |" << endl;
    cout << "|     5)Inverter horizontalmente.      |" << endl;
    cout << "|     6)Escurecer bordas.              |" << endl;
    cout << "|     0)Encerrar o programa.           |" << endl;
    cout << "+--------------------------------------+" << endl;
}

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
            myfile >> lin;
            myfile >> tons;

            if (lin < 1 || col < 1) {
                cout << "Não foi possível ler o arquivo!" << endl;
                return -1;
            }

            p = &m[0][0];
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

int main(int argc, char**argv) {
    int comando;
    //char nome[20];
    //cout << "Digite o nome do arquivo a ser lido: (exemplo.pgm)" << endl;
    //cin >> nome;
    leMatriz("stanford1.pgm");
    //leMatriz("teste.txt");
    
    do {
        sleep(1);
        interface();
        cout << "COMANDO: ";
        cin >> comando;
        cout << endl;

        switch (comando) {
            case 1:
                negativo( lin, col, tons, m); 
                break;
            case 2:
                giraDireita( lin, col, tons, m);
                break;
            case 3:
                giraEsquerda( lin, col, tons, m);
                break;
            case 4:
                inverteVertical( lin, col, tons, m);
                break;
            case 5:
                inverteHorizontal( lin, col, tons, m);
                break;
            case 6:
                cout << "Saturday";
                break;
            case 0:
                cout << "FIM DE PROGRAMA!    " << endl;
                //return 0;
                break;
        }
        if(comando>6){
            cout << "OPIÇÃO INVÁLIDA     " << endl;
        }else
            cout << "COMANDO " << comando << " EXECUTADO COM SUCESSO!  " << endl;
        
    } while (comando != 0);
    
    return 0;
}
