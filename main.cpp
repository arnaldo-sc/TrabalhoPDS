#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>

#include "legumes.hpp"  // Incluir as outras classes aqui também

//essa funcao aqui vai mostrar a variacao e os dados da classes legume
void gerarArquivoCSVLegumes(const std::vector<Legumes>& listaLegumes) {
    std::ofstream arquivo("legumesResultado.csv");
    for (const auto& legume : listaLegumes) {
       arquivo << "Nome: " << legume.getNome() << " ; Preço Atual: " 
        << legume.getPAtual() << " ; Preço Anterior: " 
        << legume.getPAnterior() << " ; Variação do preço: "
        << legume.variacaoPreco() << "%" << std::endl;
    }
    arquivo.close();
}

//essa função vai gerar um arquivo que vai conter a maior e a menor variacao de cada classes
void gerarArquivoCSVMaiorMenorAumento(const std::vector<Legumes>& listaLegumes) {
    std::ofstream arquivo("maior_menor_aumento.csv");

    Legumes maiorLegume("", 0, 0), menorLegume("", 0, 0);
    Legumes::encontrarMaiorMenorVariacao(listaLegumes, maiorLegume, menorLegume);
    
    arquivo << "Legumes - Maior Aumento: " << maiorLegume.getNome() << " - " 
            << maiorLegume.variacaoPreco() << "%" << std::endl;
    arquivo << "Legumes - Menor Aumento: " << menorLegume.getNome() << " - " 
            << menorLegume.variacaoPreco() << "%" << std::endl;

    arquivo.close();
}

void exibirMenu() {
    
    int escolha;
    
    std::vector<Legumes> listaLegumes; // tem que inicializar as outras listas de produtos aqui também

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Processar Legumes\n";
        std::cout << "2. Processar Carnes\n";
        std::cout << "3. Processar Laticinios\n";
        std::cout << "4. Processar Bebidas\n";
        std::cout << "5. Processar Frutas\n";
        std::cout << "6. Gerar arquivo com maior e menor aumento de todas as classes\n";
        std::cout << "0. Finalizar\n";  
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;

switch (escolha) {
            case 1: {
                listaLegumes = Legumes::lerArquivoCSV("legumes.csv"); //atribui a leitura à lista
                gerarArquivoCSVLegumes(listaLegumes);  // Gera o arquivo CSV dos legumes
                break;
            }
            case 2: {
                //chamar a função carnes aqui, lembrar de ler o arquivo antes
                break;
            }
            case 3: {
                // função laticinios
                break;
            }
            case 4: {
                // funcao bebidas
                break;
            }
            case 5: {
                // funcao frutas
                break;
            }
            case 6: {
                // aqui vai chamar a função que calcula as maiores e menores variações no geral
                //tem que ler o arquivo de todas as classes antes
                // colocar as listas de todas as classes nos parametros da função, por enquanto tá só a dos legumes
                gerarArquivoCSVMaiorMenorAumento(listaLegumes);
                break;
            }
            case 0: {
                std::cout << "Finalizando o programa. Ate logo!" << std::endl;
                break;
            }
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                break;
        }
    } while (escolha != 0);  

}

int main() {
    
    exibirMenu();  // Chama a função para exibir o menu
    return 0;

    return 0;
}