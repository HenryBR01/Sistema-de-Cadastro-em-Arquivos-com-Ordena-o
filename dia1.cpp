/*
 * Membros da Equipe:
 * - Matheus Fellipe Araujo Marques
 * - Henrique Furtini
 *
 * Tema do Trabalho:
 * - Cadastro de Frutas Tropicais
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <limits> 
using namespace std;
// Definição da estrutura
struct Frutas{
    int id;
    int calorias;
    string nome;
    string continente;
    string coloracao;
};
// FUNÇÕES USADAS
// Funções de Gerenciamento do Vetor
void adicionar_elementos(Frutas*& vetor, int& capacidade);
void carregar(Frutas*& vetor, int& n_elementos, int& capacidade);
void gravarArquivo(Frutas* vetor, int n_elementos);
// Funções do Menu e CRUD
void exibirMenu();
// FUNÇÃO PRINCIPAL 
int main(){
    int capacidade_total = 40; // Tamanho inicial
    int n_elementos_vetor = 0; // Quantidade de itens realmente cadastrados

    // Flag para busca binária
    string ordenadoPor = "nenhum"; // "nenhum", "id", "nome"
    Frutas* vetor = new Frutas[capacidade_total];
    // Chama a função de carga
    carregar(vetor, n_elementos_vetor, capacidade_total);
    int opcao;
    do {
        exibirMenu();
        cin >> opcao;
        
        // Limpa o buffer do cin para evitar problemas com getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcao) {
            case 1:
                cout << "Opcao 1 (Inserir) ainda nao implementada." << endl;
                break;
            case 2:
                cout << "Opcao 2 (Remover) ainda nao implementada." << endl;
                break;
            case 3:
                cout << "Opcao 3 (Buscar) ainda nao implementada." << endl;
                break;
            case 4:
                cout << "Opcao 4 (Mostrar) ainda nao implementada." << endl;
                break;
            case 5:
                cout << "Opcao 5 (Ordenar) ainda nao implementada." << endl;
                break;
            case 6:
                gravarArquivo(vetor, n_elementos_vetor);
                break;
            case 0:
                cout << "Saindo do programa. Alteracoes nao salvas (se existirem) serao perdidas." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);
    delete[] vetor;
    return 0;
}

//  IMPLEMENTAÇÃO DAS FUNÇÕES 
// Função de redimensionamento
void adicionar_elementos(Frutas*& vetor, int& capacidade){
    Frutas* novo_vetor = new Frutas[capacidade + 10];
    
    for (int i = 0; i < capacidade; i++){
        novo_vetor[i] = vetor[i];
    }
    
    delete[] vetor;
    vetor = novo_vetor;
    capacidade += 10;
}

//FUNÇÃO CARREGAR
void carregar(Frutas*& vetor, int& n_elementos, int& capacidade){
    fstream arquivo("frutastropicais.csv");
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo frutastropicais.csv" << endl;
        return;
    }

    string linha;
    getline(arquivo, linha);   // Pula a linha 1

    // Loop principal: lê uma linha inteira de cada vez
    while(getline(arquivo, linha)){
        if (linha.empty()) {
            continue;
        }

        // Usa stringstream para "quebrar" a linha usando a vírgula
        stringstream ss(linha);
        string id_csv, nome_csv, continente_csv, calorias_csv, coloracao_csv;

        // Tenta ler cada campo separado por vírgula
        if (!getline(ss, id_csv, ',')) continue;
        if (!getline(ss, nome_csv, ',')) continue;
        if (!getline(ss, continente_csv, ',')) continue;
        if (!getline(ss, calorias_csv, ',')) continue;
        getline(ss, coloracao_csv); // O último campo
        
        // Se o vetor está cheio, redimensiona
        if (n_elementos == capacidade){
            adicionar_elementos(vetor, capacidade);
        }
        
        // Tenta converter e adicionar
        try {
            vetor[n_elementos].id = stoi(id_csv);
            vetor[n_elementos].calorias = stoi(calorias_csv);
            vetor[n_elementos].nome = nome_csv;
            vetor[n_elementos].continente = continente_csv;
            vetor[n_elementos].coloracao = coloracao_csv;
            n_elementos++;

        } catch (const std::invalid_argument& e) {
            // Ignora linhas mal formatadas
        }
    }
    arquivo.close();
    cout << "Carga finalizada. " << n_elementos << " frutas carregadas." << endl;
}

// Salva o vetor de volta no arquivo
void gravarArquivo(Frutas* vetor, int n_elementos){
    ofstream arquivo("frutastropicais.csv");
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo para gravacao." << endl;
        return;
    }

    // Escreve a linha 1 como no arquivo original
    arquivo << "#ID,Nome da Fruta,Continente de Origem,Calorias (aprox. por 100g),Coloracao\n";
    for (int i = 0; i < n_elementos; i++){
        arquivo << vetor[i].id << ","
                << vetor[i].nome << ","
                << vetor[i].continente << ","
                << vetor[i].calorias << ","
                << vetor[i].coloracao << "\n";
    }
    arquivo.close();
    cout << "Dados gravados com sucesso no arquivo 'frutastropicais.csv'." << endl;
}


void exibirMenu(){
    cout << "\n--- SISTEMA DE CADASTRO DE FRUTAS ---" << endl;
    cout << "1. Inserir nova fruta" << endl;
    cout << "2. Remover fruta (por ID)" << endl;
    cout << "3. Buscar fruta" << endl;
    cout << "4. Mostrar dados" << endl;
    cout << "5. Ordenar dados" << endl;
    cout << "6. Salvar alteracoes no arquivo" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

