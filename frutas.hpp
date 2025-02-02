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
    Frutas(string _nome, float _pAtual, float _pAnterior);

    // Método para calcular a variação de preço
    float calcVariacaoPreco() const ;
    
    // Getters
    string getNome() const;
    float getPAtual() const;
    float getPAnterior() const;

    // Método estático para ler dados de um arquivo CSV
    static vector<Frutas> lerArquivoCSV(string nomeArquivo);
        
    // Método estático para encontrar a maior e menor variação de preço
    static void MaiorMenorExtremos(const vector<Frutas>& lista, Frutas& maiorFruta, Frutas& menorFruta);
       
};

#endif
