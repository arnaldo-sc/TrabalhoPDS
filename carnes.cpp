#include "carnes.hpp"

// Construtor
Carnes::Carnes(string nome, float valor_atual, float valor_anterior) {
    this->nome = nome;
    this->valor_atual = valor_atual;
    this->valor_anterior = valor_anterior;
}

// Método que calcula a variação de preço
float Carnes::calcularVariacao() const {
    if (valor_anterior == 0) return 0;
    return ((valor_atual - valor_anterior) / valor_anterior) * 100;
}

// Atributos do produto
string Carnes::getNome() const {
    return nome;
}
float Carnes::getValor_atual() const {
    return valor_atual;
}
float Carnes::getValor_anterior() const {
    return valor_anterior;
}

// Usada para ler o arquivo carnes.csv
vector<Carnes> Carnes::lerArquivoCSV(std::string nomeArquivo) {
    vector<Carnes> carnes;  // Vetor para armazenar os objetos
    ifstream arquivo(nomeArquivo);
    string linha, nome;
    float valor_atual, valor_anterior;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return carnes;
    }

    // Ignora a primeira linha (cabeçalho)
    getline(arquivo, linha);

    // Lê cada linha do arquivo CSV
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        getline(ss, nome, ';');  // Lê o nome
        ss >> valor_atual;       // Lê o preço atual
        ss.ignore();             // Ignora a vírgula
        ss >> valor_anterior;    // Lê o preço anterior

        // Adiciona um novo objeto Carnes ao vetor
        carnes.push_back(Carnes(nome, valor_atual, valor_anterior));
    }

    arquivo.close();  // Fecha o arquivo
    return carnes;
}

void Carnes::encontrarMaiorMenorVariacao(const vector<Carnes>& lista, Carnes& maiorCarne, Carnes& menorCarne) {
    for (const Carnes& carne : lista) {  // Para não modificar a lista
        if (carne.calcularVariacao() > maiorCarne.calcularVariacao()) {
            maiorCarne = carne;
        }
        if (carne.calcularVariacao() < menorCarne.calcularVariacao()) {
            menorCarne = carne;
        }
    }
}
