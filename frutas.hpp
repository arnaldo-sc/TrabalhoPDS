#ifndef FRUTAS_HPP
#define FRUTAS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Frutas {
private:
    string nome;
    float pAtual;
    float pAnterior;

public:
    // Construtor
    Frutas(string _nome, float _pAtual, float _pAnterior)
        : nome(_nome), pAtual(_pAtual), pAnterior(_pAnterior) {}

    // Método para calcular a variação de preço
    float variacaoPreco() const {
        return pAtual - pAnterior;
    }

    // Getters
    string getNome() const {
        return nome;
    }

    float getPAtual() const {
        return pAtual;
    }

    float getPAnterior() const {
        return pAnterior;
    }

    // Método estático para ler dados de um arquivo CSV
    static vector<Frutas> lerArquivoCSV(string nomeArquivo) {
        vector<Frutas> listaFrutas;
        ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo!" << endl;
            return listaFrutas;
        }

        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            string nome, pAtualStr, pAnteriorStr;

            getline(ss, nome, ',');
            getline(ss, pAtualStr, ',');
            getline(ss, pAnteriorStr, ',');

            float pAtual = stof(pAtualStr);
            float pAnterior = stof(pAnteriorStr);

            listaFrutas.push_back(Frutas(nome, pAtual, pAnterior));
        }

        arquivo.close();
        return listaFrutas;
    }

    // Método estático para encontrar a maior e menor variação de preço
    static void encontrarMaiorMenorVariacao(const vector<Frutas>& lista, Frutas& maiorFruta, Frutas& menorFruta) {
        if (lista.empty()) {
            cerr << "Lista vazia!" << endl;
            return;
        }

        maiorFruta = lista[0];
        menorFruta = lista[0];

        for (const auto& fruta : lista) {
            if (fruta.variacaoPreco() > maiorFruta.variacaoPreco()) {
                maiorFruta = fruta;
            }
            if (fruta.variacaoPreco() < menorFruta.variacaoPreco()) {
                menorFruta = fruta;
            }
        }
    }
};

#endif