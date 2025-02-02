#include "Carnes.hpp"

vector<pair<float, string>> Carnes::variacoes;

// Construtor
Carnes::Carnes(string nome, string marca, float valor_anterior, float valor_atual) {
    this->nome = nome;
    this->marca = marca;
    this->valor_anterior = valor_anterior;
    this->valor_atual = valor_atual;
}

// Método para calcular a variação percentual de preço
float Carnes::CalculaVariacao() const {
    return ((valor_atual - valor_anterior) / valor_anterior) * 100;
}

// Método estático para calcular a maior e menor variação e escrever no arquivo
void Carnes::MaiorVariacao() {
    ofstream arquivo("CortesDeCarne.txt", ios::app); // Abre o arquivo para adicionar as informações

    if (arquivo.is_open()) {
        if (!variacoes.empty()) {
            auto min_max = minmax_element(variacoes.begin(), variacoes.end(),
                                          [](const pair<float, string>& a, const pair<float, string>& b) {
                                              return a.first < b.first; // Comparar pela variação
                                          });

            // Exibe as informações sobre a maior e menor variação no arquivo
            arquivo << "---------------------------\n";
            arquivo << "Maior diminuição: " << -1 * min_max.first->first << "% (" << min_max.first->second << ")\n";
            arquivo << "Maior aumento: " << min_max.second->first << "% (" << min_max.second->second << ")\n";
        } else {
            arquivo << "Nenhuma variação de preço encontrada." << endl;
        }
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para gravação da variação!" << endl;
    }
}

// Método para gravar as informações em um bloco de notas
void Carnes::GravaInformacao() {
    ofstream arquivo("CortesDeCarne.txt", ios::app); // Abre o arquivo para gravação

    if (arquivo.is_open()) {
        float variacao = CalculaVariacao(); // Chama o método para calcular a variação
        string descricao = nome + " (" + marca + ")"; // Descrição com nome e marca
        variacoes.push_back({variacao, descricao}); // Armazena a variação e a descrição

        arquivo << "---------------------------\n";
        arquivo << "Tipo: " << nome << "\n"
                 << "Marca: " << marca << "\n"
                 << "Valor anterior: " << valor_anterior << "\n"
                 << "Valor atual: " << valor_atual << "\n";

        if (variacao < 0) {
            arquivo << "Diminuiu: " << (-1 * variacao) << "%\n";
        } else if (variacao > 0) {
            arquivo << "Aumentou: " << variacao << "%\n";
        } else {
            arquivo << "Não houve variação de preço\n";
        }
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para gravação!" << endl;
    }
}

// Método estático para ler e exibir o conteúdo do arquivo
void Carnes::LeInformacao() {
    ifstream arquivoE("CortesDeCarne.txt");
    string linha;
    if (arquivoE.is_open()) {
        while (getline(arquivoE, linha)) {
            cout << linha << endl;
        }
        arquivoE.close();
    } else {
        cerr << "Erro ao abrir o arquivo para leitura!" << endl;
    }
}

// Definições das classes derivadas

Picanha::Picanha(string marca, float valor_anterior, float valor_atual)
    : Carnes("Picanha", marca, valor_anterior, valor_atual) {}

PeitoDeFrango::PeitoDeFrango(string marca, float valor_anterior, float valor_atual)
    : Carnes("Peito de frango", marca, valor_anterior, valor_atual) {}

Bacon::Bacon(string marca, float valor_anterior, float valor_atual)
    : Carnes("Bacon", marca, valor_anterior, valor_atual) {}
