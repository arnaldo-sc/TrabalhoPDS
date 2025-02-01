#include "legumes.hpp"

//Inicializando o construtor
Legumes::Legumes(string _nome, float _pAtual, float _pAnterior) {

    nome = _nome;
    pAtual = _pAtual;
    pAnterior = _pAnterior;

}

//definindo a funcao que calcula a variação de preco
float Legumes::variacaoPreco() const{
    if (pAnterior == 0) return 0;  
    return ((pAtual - pAnterior) / pAnterior) * 100;
}

//essas tres funções sao só mesmo para acessar os atributos privados 
string Legumes::getNome() const{ 
    return nome; 
}
float Legumes::getPAtual() const{ 
    return pAtual; 
}

float Legumes::getPAnterior() const{ 
    return pAnterior; 
}

//usada para ler o arquivo legumes.csv
vector<Legumes> Legumes::lerArquivoCSV(std::string nomeArquivo) {
    vector<Legumes> legumes;  // Vetor para armazenar os objetos
    ifstream arquivo(nomeArquivo);
    string linha, nome;
    float pAtual, pAnterior;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return legumes;
    }

    // Ignora a primeira linha (cabeçalho)
    getline(arquivo, linha);

    // Lê cada linha do arquivo CSV
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        getline(ss, nome, ';');  // Lê o nome
        ss >> pAtual;          // Lê o preço anterior
        ss.ignore();                  // Ignora a vírgula
        ss >> pAnterior;             // Lê o preço atual

        // Adiciona um novo objeto Legumes ao vetor
        legumes.push_back(Legumes(nome, pAtual, pAnterior));
    }

    arquivo.close();  // Fecha o arquivo
    return legumes;
}

void Legumes::encontrarMaiorMenorVariacao(const vector<Legumes>& lista, Legumes& maiorLegume, Legumes& menorLegume) {
    for (const Legumes& legume : lista) {  // para nao modificar a lista
        if (legume.variacaoPreco() > maiorLegume.variacaoPreco()) {
            maiorLegume = legume;
        }
        if (legume.variacaoPreco() < menorLegume.variacaoPreco()) {
            menorLegume = legume;
        }
    }
}

