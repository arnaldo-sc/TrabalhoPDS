#include "laticinios.hpp"

// Inicializando o construtor com os atributos necessários
Laticinios::Laticinios(string _nome, float _precoAtual, float _precoAnterior) {
    nomeProduto = _nome;
    precoAtual = _precoAtual;
    precoAnterior = _precoAnterior;
}

// Função que calcula a variação percentual do preço
float Laticinios::calcularVariacao() const {
    if (precoAnterior == 0) return 0;
    return ((precoAtual - precoAnterior) / precoAnterior) * 100;
}

// Métodos para obter os atributos privados
string Laticinios::getNomeProduto() const {
    return nomeProduto;
}

float Laticinios::getPrecoAtual() const {
    return precoAtual;
}

float Laticinios::getPrecoAnterior() const {
    return precoAnterior;
}

// Lê um arquivo CSV contendo informações sobre os laticínios e retorna um vetor de objetos
vector<Laticinios> Laticinios::carregarDadosCSV(string nomeArquivo) {
    vector<Laticinios> laticinios;
    ifstream arquivo(nomeArquivo);
    string linha, nomeProduto;
    float precoAtual, precoAnterior;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return laticinios;
    }

    // Ignora o cabeçalho
    getline(arquivo, linha);

    // Lê cada linha do arquivo CSV e extrai os dados
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        getline(ss, nomeProduto, ';');
        ss >> precoAtual;
        ss.ignore(); // Ignora o separador
        ss >> precoAnterior;

        // Adiciona um objeto Laticinios ao vetor
        laticinios.emplace_back(nomeProduto, precoAtual, precoAnterior);
    }

    arquivo.close(); // Fecha o arquivo após a leitura
    return laticinios;
}

// Identifica os laticínios com maior e menor variação de preço dentro de uma lista
void Laticinios::encontrarExtremos(const vector<Laticinios>& lista, Laticinios& maiorLaticinio, Laticinios& menorLaticinio) {
    for (const Laticinios& item : lista) {
        if (item.calcularVariacao() > maiorLaticinio.calcularVariacao()) {
            maiorLaticinio = item;
        }
        if (item.calcularVariacao() < menorLaticinio.calcularVariacao()) {
            menorLaticinio = item;
        }
    }
}
