#include "laticinios.hpp"

// Inicializando o construtor com os atributos necessários
Laticinios::Laticinios(string _nome, float _precoAtual, float _precoAnterior) {
    nome = _nome;
    precoAtual = _precoAtual;
    precoAnterior = _precoAnterior;
}

// Função que calcula a variação percentual do preço
float Laticinios::calcularVariacao() const {
    if (precoAnterior == 0) return 0;
    return ((precoAtual - precoAnterior) / precoAnterior) * 100;
}

// Métodos para obter os atributos privados
string Laticinios::getNome() const {
    return nome;
}

float Laticinios::getPrecoAtual() const {
    return precoAtual;
}

float Laticinios::getPrecoAnterior() const {
    return precoAnterior;
}

// Lê um arquivo CSV contendo informações sobre os laticínios e retorna um vetor de objetos
vector<Laticinios> Laticinios::carregarDadosCSV(string nomeArquivo) {
    vector<Laticinios> listaLaticinios;
    ifstream arquivo(nomeArquivo);
    string linha, nome;
    float precoAtual, precoAnterior;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return listaLaticinios;
    }

    // Ignora o cabeçalho
    getline(arquivo, linha);

    // Lê cada linha do arquivo CSV e extrai os dados
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        getline(ss, nome, ';');
        ss >> precoAtual;
        ss.ignore(); // Ignora o separador
        ss >> precoAnterior;

        // Adiciona um objeto Laticinios ao vetor
        listaLaticinios.emplace_back(nome, precoAtual, precoAnterior);
    }

    arquivo.close(); // Fecha o arquivo após a leitura
    return listaLaticinios;
}

// Identifica os laticínios com maior e menor variação de preço dentro de uma lista
void Laticinios::encontrarExtremos(const vector<Laticinios>& lista, Laticinios& maior, Laticinios& menor) {
    for (const Laticinios& item : lista) {
        if (item.calcularVariacao() > maior.calcularVariacao()) {
            maior = item;
        }
        if (item.calcularVariacao() < menor.calcularVariacao()) {
            menor = item;
        }
    }
}
