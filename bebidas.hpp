#ifndef BEBIDAS_HPP
#define BEBIDAS_HPP

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Bebidas {
private:
    string nome;
    float pAtual;
    float pAnterior;

public:
    Bebidas(string _nome, float _pAtual, float _pAnterior);

    float variacaoPreco() const;

    string getNome() const;
    float getPAtual() const;
    float getPAnterior() const;

    static vector<Bebidas> lerArquivoCSV(std::string nomeArquivo);
    static void encontrarMaiorMenorVariacao(const vector<Bebidas>& lista, Bebidas& maiorBebida, Bebidas& menorBebida);
};

#endif
