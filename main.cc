
#include <iostream>
#include <fstream>
#include <string.h>

#include "funcoes.h"

using namespace std;

int main(int argc, char**argv) {

    inverteMatriz("stanford1.pgm", "teste3.pgm");
    giraDireita("stanford1.pgm", "teste4.pgm");
    giraEsquerda("stanford1.pgm", "teste5.txt");
    return 0;
}
