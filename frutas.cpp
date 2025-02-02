#include <iostream>
#include <vector>
#include <string>
#include "frutas.hpp"

int main() {
    // Lê os dados do arquivo CSV
    vector<Frutas> listaFrutas = Frutas::lerArquivoCSV("frutas.csv");

    // Verifica se a lista não está vazia
    if (listaFrutas.empty()) {
        cout << "Nenhuma fruta encontrada no arquivo!" << endl;
        return 1;
    }

    // Encontra a fruta com maior e menor variação de preço
    Frutas maiorFruta("", 0, 0);
    Frutas menorFruta("", 0, 0);
    Frutas::encontrarMaiorMenorVariacao(listaFrutas, maiorFruta, menorFruta);

    // Exibe os resultados
    cout << "Fruta com maior aumento de preço: " << maiorFruta.getNome() 
         << " (R$ " << maiorFruta.variacaoPreco() << ")" << endl;
    cout << "Fruta com menor aumento de preço: " << menorFruta.getNome() 
         << " (R$ " << menorFruta.variacaoPreco() << ")" << endl;

    return 0;
}