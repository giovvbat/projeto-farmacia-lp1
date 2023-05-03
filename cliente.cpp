#include <iostream>
#include <fstream>
#include "h-cliente.hpp"
#include <map>
using namespace std;

map<string, double>carrinho;

/*adiciona um medicamento selecionado pleo cliente no mapa do carrinho*/
void adicionarNoCarrinho(string medDesejado, double preco) {
    /*a chave é uma string armazenando o nome do medicamento e o valor armazena seu preço*/
    carrinho[medDesejado]=preco;
}

/*calculando o valor total do carrinho, armazenado na variável 'total'*/
double calcularValorCarrinho() {
    double total=0;
    /*se o carrinho estiver vazio, é impresso um aviso e a função é encerrada, retornando 0*/
    if(carrinho.empty()) {
        cout<<"Carrinho vazio!"<<endl;
        return 0;
    }
    /*se o carrinho estiver preenchido, acrescentamos ao total todos os preços dos medicamentos presentes nele. ao fim, retornamos o total*/
    for(auto i:carrinho)
        total=i.second+total;
    return total;
}

/*excluindo um medicamento do carrinho*/
int excluirDoCarrinho(string remedioExcl) {
    /*buscando o medicamento a ser excluído no carrinho*/
    for(auto i:carrinho) {
        /*achando o medicamento, excluindo ele do map e fechando a função com retorno 1*/
        if(i.first==remedioExcl) {
            carrinho.erase(i.first);
            cout<<"Medicamento excluído do carrinho com sucesso!"<<endl;
            return 1;
        }
    }
    /*caso a função não tenha sido fechada, o remédio a ser excluído não está no carrinho, logo, é impresso um aviso e a função retorna 0*/
    cout<<"Medicamento não encontrado no carrinho!"<<endl;
    return 0;
}