#ifndef CARNES_HPP
#define CARNES_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Carnes {
private:
    string nome;
    float valor_atual;
    float valor_anterior;

public:
    // Construtor
    Carnes(string nome, float valor_atual, float valor_anterior);

    // Método que calcula a variação de preço
    float calcularVariacao() const;

    // Métodos para acessar os atributos
    string getNome() const;
    float getValor_atual() const;
    float getValor_anterior() const;

    // Método para ler o arquivo CSV
    static vector<Carnes> lerArquivoCSV(string nomeArquivo);

    // Método para encontrar maior e menor variação de preço
    static void encontrarMaiorMenorVariacao(const vector<Carnes>& lista, Carnes& maiorCarne, Carnes& menorCarne);
};

#endif // CARNES_HPP
