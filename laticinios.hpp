#ifndef LATICINIOS_HPP
#define LATICINIOS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Laticinios {
    private:
        string nomeProduto; // Nome do produto
        float precoAtual;
        float precoAnterior;
    
    public:
        // Construtor
        Laticinios(string _nomeProduto, float _precoAtual, float _precoAnterior);
        
        // Método para calcular a variação de preço
        float calcularVariacao() const;
        
        // Métodos para acessar os atributos
        string getNomeProduto() const;
        float getPrecoAtual() const;
        float getPrecoAnterior() const;
        
        // Método para leitura de arquivo CSV
        static vector<Laticinios> carregarDadosCSV(string nomeArquivo);
        
        // Método para identificar maior e menor variação de preço
        static void encontrarExtremos(const vector<Laticinios>& lista, Laticinios& maiorLaticinio, Laticinios& menorLaticinio);
};

#endif
