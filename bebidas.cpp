#include <iostream>
#include <vector>
#include <string>
#include "bebidas.hpp"

// Inicializando o construtor
Bebidas::Bebidas(string _nome, float _pAtual, float _pAnterior) {
    nome = _nome;
    pAtual = _pAtual;
    pAnterior = _pAnterior;
}

// Função que calcula a variação de preço
float Bebidas::variacaoPreco() const {
    if (pAnterior == 0) return 0;  
    return ((pAtual - pAnterior) / pAnterior) * 100;
}

// Métodos de acesso aos atributos privados
string Bebidas::getNome() const { 
    return nome; 
}
float Bebidas::getPAtual() const { 
    return pAtual; 
}
float Bebidas::getPAnterior() const { 
    return pAnterior; 
}

// Método para ler um arquivo CSV e criar um vetor de objetos Bebidas
vector<Bebidas> Bebidas::lerArquivoCSV(std::string nomeArquivo) {
    vector<Bebidas> bebidas;
    ifstream arquivo(nomeArquivo);
    string linha, nome;
    float pAtual, pAnterior;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return bebidas;
    }

    // Ignora a primeira linha (cabeçalho)
    getline(arquivo, linha);

    // Lê cada linha do arquivo CSV
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        getline(ss, nome, ';');  // Lê o nome
        ss >> pAtual;          // Lê o preço anterior
        ss.ignore();           // Ignora a vírgula
        ss >> pAnterior;       // Lê o preço atual

        // Adiciona um novo objeto Bebidas ao vetor
        bebidas.push_back(Bebidas(nome, pAtual, pAnterior));
    }

    arquivo.close();
    return bebidas;
}

// Método para encontrar a bebida com maior e menor variação de preço
void Bebidas::encontrarMaiorMenorVariacao(const vector<Bebidas>& lista, Bebidas& maiorBebida, Bebidas& menorBebida) {
    for (const Bebidas& bebida : lista) {
        if (bebida.variacaoPreco() > maiorBebida.variacaoPreco()) {
            maiorBebida = bebida;
        }
        if (bebida.variacaoPreco() < menorBebida.variacaoPreco()) {
            menorBebida = bebida;
        }
    }
}
