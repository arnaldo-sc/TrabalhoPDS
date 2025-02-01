#ifndef LEGUMES_HPP
#define LEGUMES_HPP

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Legumes {
   
    private:
        string nome;                 //inicializando os atributos
        float pAtual, pAnterior;
    
    public: 
        Legumes(string _nome, float _pAtual, float _pAnterior); //construtor 
        float variacaoPreco () const; //calcula a variacao de preco
        string getNome () const; // sao funcoes pra acessar os atributos
        float getPAtual () const;
        float getPAnterior () const;
        static vector<Legumes> lerArquivoCSV(string nomeArquivo); //leitura do arquivo
        static void encontrarMaiorMenorVariacao(const vector<Legumes>& lista, Legumes& maiorLegume, Legumes& menorLegume); //exibe a maior e menor variacao
};


#endif
