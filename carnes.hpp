#ifndef CARNES_HPP
#define CARNES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Carnes {
protected:
    string nome;
    string marca;
    float valor_anterior;
    float valor_atual;
    static vector<pair<float, string>> variacoes; 

public:
    // Construtor
    Carnes(string nome = "a", string marca = "a", float valor_anterior = -1, float valor_atual = -1);

    // Método para calcular a variação percentual de preço
    float CalculaVariacao() const;

    // Método estático para calcular a maior e menor variação e escrever no arquivo
    static void MaiorVariacao();

    // Método para gravar as informações em um bloco de notas
    void GravaInformacao();

    // Método estático para ler e exibir o conteúdo do arquivo
    static void LeInformacao();
};

// Inicializa o vetor de variações
extern vector<pair<float, string>> variacoes;

// Classes derivadas
class Picanha : public Carnes {
public:
    Picanha(string marca, float valor_anterior, float valor_atual);
};

class PeitoDeFrango : public Carnes {
public:
    PeitoDeFrango(string marca, float valor_anterior, float valor_atual);
};

class Bacon : public Carnes {
public:
    Bacon(string marca, float valor_anterior, float valor_atual);
};

#endif // CARNES_HPP
