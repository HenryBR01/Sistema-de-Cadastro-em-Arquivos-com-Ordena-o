#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Frutas{
    int id;
    int calorias;
    string nome;
    string continente;
    string coloracao;
};
void adicionar_elementos(Frutas*& vetor, int&tamanho){
    Fruta* novo_vetor = new Fruta[tamanho+10];
    for (int i = 0; i < tamanho){
        novo_vetor[i] = vetor[i];
    }
    delete[] vetor;
    vetor = novo_vetor;
    tamanho += 10;
}
void carregar(){
    string linha_inutil, linha;
    string id_csv, nome_csv, continente_csv, calorias_csv, coloracao_csv;
    fstream arquivo("frutastropicais.csv");
    getline(arquivo, linha_inutil);
    getline(arquivo, linha_inutil);
    while(arquivo){
        getline(arquivo, id_csv, ',');
        getline(arquivo, nome_csv, ',');
        getline(arquivo, continente_csv, ',');
        getline(arquivo, calorias_csv, ',');
        getline(arquivo, coloracao_csv, ',');
    }

}
int main(void){
    Frutas* vetor = new Frutas[40];
    carregar();
    return 0;
}
