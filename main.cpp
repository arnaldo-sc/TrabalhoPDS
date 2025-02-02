#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>

#include "legumes.hpp"  // Incluir as outras classes aqui também
#include "Carnes.hpp"
#include "bebidas.hpp"
#include "laticinios.hpp"
#include "frutas.hpp"

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

void gerarArquivoCSVCarnes(const std::vector<Carnes>& listaCarnes) {
    std::ofstream arquivo("carnesResultado.csv");
    for (const auto& carne : listaCarnes) {
       arquivo << "Nome: " << carne.getNome() << " ; Preço Atual: " 
        << carne.getValor_atual() << " ; Preço Anterior: " 
        << carne.getValor_anterior() << " ; Variação do preço: "
        << carne.calcularVariacao() << "%" << std::endl;
    }
    arquivo.close();
}


void gerarArquivoCSVLaticinios(const std::vector<Laticinios>& listaLaticinios) {
    std::ofstream arquivo("laticiniosResultado.csv");
    for (const auto& item : listaLaticinios) {
       arquivo << "Nome: " << item.getNomeProduto() << " ; Preço Atual: " 
        << item.getPrecoAtual() << " ; Preço Anterior: " 
        << item.getPrecoAnterior() << " ; Variação do preço: "
        << item.calcularVariacao() << "%" << std::endl;
    }
    arquivo.close();
}

void gerarArquivoCSVBebidas(const std::vector<Bebidas>& listaBebidas) {
    std::ofstream arquivo("bebidasResultado.csv");
    for (const auto& bebida : listaBebidas) {
       arquivo << "Nome: " << bebida.getNome() << " ; Preço Atual: " 
        << bebida.getPAtual() << " ; Preço Anterior: " 
        << bebida.getPAnterior() << " ; Variação do preço: "
        << bebida.variacaoPreco() << "%" << std::endl;
    }
    arquivo.close();
}

void gerarArquivoCSVFrutas(const std::vector<Frutas>& listaFrutas) {
    std::ofstream arquivo("frutasResultado.csv");
    for (const auto& fruta : listaFrutas) {
       arquivo << "Nome: " << fruta.getNome() << " ; Preço Atual: " 
        << fruta.getPAtual() << " ; Preço Anterior: " 
        << fruta.getPAnterior() << " ; Variação do preço: "
        << fruta.calcVariacaoPreco() << "%" << std::endl;
    }
    arquivo.close();
}


//Essa função vai gerar um arquivo que vai conter a maior e a menor variacao de cada uma das classes
void gerarArquivoCSVMaiorMenorAumento(const std::vector<Legumes>& listaLegumes, const std::vector<Carnes>& listaCarnes, const std::vector<Laticinios>& listaLaticinios, const std::vector<Bebidas>& listaBebidas, const std::vector<Frutas>& listaFrutas) {
    std::ofstream arquivo("maior_menor_aumento.csv");

    Legumes maiorLegume("", 0, 0), menorLegume("", 0, 0);
    Legumes::encontrarMaiorMenorVariacao(listaLegumes, maiorLegume, menorLegume);
    Laticinios maiorLaticinio("", 0, 0), menorLaticinio("", 0, 0);
    Laticinios::encontrarExtremos(listaLaticinios, maiorLaticinio, menorLaticinio);
    Carnes maiorCarne("", 0, 0), menorCarne("", 0, 0);
    Carnes::encontrarMaiorMenorVariacao(listaCarnes, maiorCarne, menorCarne);
    Bebidas maiorBebida("", 0, 0), menorBebida("", 0, 0);
    Bebidas::encontrarMaiorMenorVariacao(listaBebidas, maiorBebida, menorBebida);
    Frutas maiorFruta("", 0, 0), menorFruta("", 0, 0);
    Frutas::MaiorMenorExtremos(listaFrutas, maiorFruta, menorFruta);
    
    arquivo << "Legumes - Maior Aumento: " << maiorLegume.getNome() << " - " 
            << maiorLegume.variacaoPreco() << "%" << std::endl;
    arquivo << "Legumes - Menor Aumento: " << menorLegume.getNome() << " - " 
            << menorLegume.variacaoPreco() << "%" << std::endl;
    arquivo << "Carnes - Maior Aumento: " << maiorCarne.getNome() << " - " 
            << maiorCarne.calcularVariacao() << "%" << std::endl;
    arquivo << "Carnes - Menor Aumento: " << menorCarne.getNome() << " - " 
            << menorCarne.calcularVariacao() << "%" << std::endl;   
    arquivo << "Laticinios - Maior Aumento: " << maiorLaticinio.getNomeProduto() << " - " 
            << maiorLaticinio.calcularVariacao() << "%" << std::endl;
    arquivo << "Laticinios - Menor Aumento: " << menorLaticinio.getNomeProduto() << " - " 
            << menorLaticinio.calcularVariacao() << "%" << std::endl;
    arquivo << "Bebidas - Maior Aumento: " << maiorBebida.getNome() << " - " 
            << maiorBebida.variacaoPreco() << "%" << std::endl;
    arquivo << "Bebidas - Menor Aumento: " << menorBebida.getNome() << " - " 
            << menorBebida.variacaoPreco() << "%" << std::endl;
    arquivo << "Frutas - Maior Aumento: " << maiorFruta.getNome() << " - " 
            << maiorFruta.calcVariacaoPreco() << "%" << std::endl;
    arquivo << "Frutas - Menor Aumento: " << menorFruta.getNome() << " - " 
            << menorFruta.calcVariacaoPreco() << "%" << std::endl;
    arquivo.close();
}

void exibirMenu() {
    
    int escolha;
    
    std::vector<Legumes> listaLegumes; // tem que inicializar as outras listas de produtos aqui também
    std::vector<Laticinios> listaLaticinios;
    std::vector<Carnes> listaCarnes;
    std::vector<Bebidas> listaBebidas;
    std::vector<Frutas> listaFrutas;

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
                listaCarnes = Carnes::lerArquivoCSV("carnes.csv");
                gerarArquivoCSVCarnes(listaCarnes);
                break;
            }
            case 3: {
                listaLaticinios = Laticinios::carregarDadosCSV("laticinios.csv");
                gerarArquivoCSVLaticinios(listaLaticinios);
                break;
            }
            case 4: {
                listaBebidas = Bebidas::lerArquivoCSV("bebidas.csv");
                gerarArquivoCSVBebidas(listaBebidas);
                break;
            }
            case 5: {
                listaFrutas = Frutas::lerArquivoCSV("frutas.csv");
                gerarArquivoCSVFrutas(listaFrutas);
                break;
            }
            case 6: {
                // aqui vai chamar a função que calcula as maiores e menores variações no geral
                //tem que ler o arquivo de todas as classes antes
                // colocar as listas de todas as classes nos parametros da função, por enquanto tá só a dos legumes
                listaLegumes = Legumes::lerArquivoCSV("legumes.csv");
                listaLaticinios = Laticinios::carregarDadosCSV("laticinios.csv");
                listaCarnes = Carnes::lerArquivoCSV("carnes.csv");
                listaBebidas = Bebidas::lerArquivoCSV("bebidas.csv");
                listaFrutas = Frutas::lerArquivoCSV("frutas.csv");
                gerarArquivoCSVMaiorMenorAumento(listaLegumes, listaCarnes, listaLaticinios, listaBebidas, listaFrutas);
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
