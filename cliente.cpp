#include <iostream>
#include <fstream>
#include "h-cliente.hpp"
#include <map>
using namespace std;

map<string, double>carrinho;

void adicionarNoCarrinho(string medDesejado, double preco) {
    carrinho[medDesejado]=preco;
}

double calcularValorCarrinho() {
    double total=0;
    if(carrinho.empty()) {
        cout<<"Carrinho vazio!"<<endl;
        return 0;
    }
    for(auto i:carrinho)
        total=i.second+total;
    return total;
}

int excluirDoCarrinho(string remedioExcl) {
    for(auto i:carrinho) {
        if(i.first==remedioExcl) {
            carrinho.erase(i.first);
            cout<<"Medicamento excluído do carrinho com sucesso!"<<endl;
            return 1;
        }
    }
    cout<<"Medicamento não encontrado no carrinho!"<<endl;
    return 0;
}