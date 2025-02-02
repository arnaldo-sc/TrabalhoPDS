#include <iostream>
#include <vector>
#include <string>
#include "frutas.hpp"

Frutas::Frutas(string _nome, float _pAtual, float _pAnterior) {
    
    nome = _nome;
    pAtual = _pAtual;
    pAnterior = _pAnterior;

}

float Frutas::calcVariacaoPreco() const {

    if (pAnterior == 0) return 0;  
    return ((pAtual - pAnterior) / pAnterior) * 100;

}

vector<Frutas> Frutas::lerArquivoCSV(string nomeArquivo){

    vector<Frutas> frutas;  
    ifstream arquivo(nomeArquivo);
    string linha, nome;
    float pAtual, pAnterior;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return frutas;
    }

    getline(arquivo, linha);

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        getline(ss, nome, ';');  
        ss >> pAtual;          
        ss.ignore();                  
        ss >> pAnterior;             
      
        frutas.push_back(Frutas(nome, pAtual, pAnterior));
    }

    arquivo.close();  
    return frutas;

}

void Frutas::MaiorMenorExtremos(const vector<Frutas>& lista, Frutas& maiorFruta, Frutas& menorFruta) {
    for (const Frutas& fruta : lista) {  // para nao modificar a lista
        if (fruta.calcVariacaoPreco() > maiorFruta.calcVariacaoPreco()) {
            maiorFruta = fruta;
        }
        if (fruta.calcVariacaoPreco() < menorFruta.calcVariacaoPreco()) {
            menorFruta = fruta;
        }
    }
}

