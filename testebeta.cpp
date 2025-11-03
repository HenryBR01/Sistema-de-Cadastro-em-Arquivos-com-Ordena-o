#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void adicionar(string elementos, int TAMANHO){
    string* novovetor = new string[TAMANHO+10];
    for (int i =0; i < TAMANHO; i++){
        novovetor[i] = elementos[i];
    }
    TAMANHO += 10;
    for(int i = 0; i < 10; i++){
        novovetor[TAMANHO]
    }
}
int main(void){
    int id, TAMANHO;
    string produto, categoria, estoque, linha;
    string* elementos = new string[40];
    float preço;
    fstream arquivo("roupas.csv");
    adicionar(&elementos, TAMANHO);
    return 0;
}
