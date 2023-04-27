#include <iostream>
#include <fstream>
#include "h-cliente.hpp"
#include <map>
using namespace std;

map<string, double>carrinho;

bool buscarMed(string medDesejado) {
    ifstream file("medicamentos.txt");
    string medicamento;
    while(getline(file, medicamento)) {
        if(medicamento==medDesejado)
            return true;
    }
    file.close();
    return false;
}

void listarMeds() {
    string nomeMed, precoMed;
    ifstream file("medicamentos.txt");
    cout<<"Medicamentos disponíveis:"<<endl;
    while(getline(file, nomeMed)) {
        getline(file, precoMed);
        cout<<nomeMed<<endl;
    }
}

void adicionarNoCarrinho(string medDesejado) {
    ifstream file("medicamentos.txt");
    string medicamento;
    double precoMed;
    while(getline(file, medicamento)) {
        file>>precoMed;
        if(medicamento==medDesejado) {
            carrinho[medicamento]=precoMed;
        }
    }
    file.close();
}

double calcularValorCarrinho() {
    double total;
    for(auto i:carrinho)
        total=i.second+total;
    return total;
}

int excluirCarrinho(string remedioExcl) {
    for(auto i:carrinho) {
        if(i.first==remedioExcl) {
            carrinho.erase(i.first);
            cout<<"Remédio excluído do carrinho!"<<endl;
            return 1;
        }
    }
    cout<<"Remédio não encontrado no carrinho!"<<endl;
    return 0;
}