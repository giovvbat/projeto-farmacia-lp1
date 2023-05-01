#include <iostream>
#include <fstream>
#include <map>
#include "h-gerente.hpp"
using namespace std;

map<string, double>medicamentos;

void inicializarArquivo() {
    ofstream arquivo;
    arquivo.open("medicamentos.txt", ios::out);
    arquivo<<"Ibuprofeno"<<endl;
    arquivo<<"10.85"<<endl;
    arquivo<<"Dorflex"<<endl;
    arquivo<<"13.33"<<endl;
    arquivo<<"Buscopan"<<endl;
    arquivo<<"15.71"<<endl;
    arquivo<<"Rivotril"<<endl;
    arquivo<<"79.90"<<endl;
    arquivo<<"Amoxilina"<<endl;
    arquivo<<"71.85"<<endl;
    arquivo.close();
}

void adicionarArquivoNoMapa() {
    ifstream file("medicamentos.txt");
    string medicamento, preco;
    double precoD;
    while(getline(file, medicamento)) {
        getline(file, preco);
        precoD=stod(preco);
        medicamentos[medicamento]=precoD;
    }
    file.close();
}

bool buscarMed(string medDesejado) {
    for(auto i:medicamentos) {
        if(i.first==medDesejado)
            return true;
    }
    return false;
}

void adicionarMed(string nomeMed, double precoMed) {
    medicamentos[nomeMed]=precoMed;
    cout<<"Medicamento adicionado com sucesso!"<<endl;
}

void listarMedsWithPrices() {
    if(!(medicamentos.empty())) {
        cout<<"Medicamentos disponíveis: "<<endl;
        for(auto i:medicamentos)
            cout<<"Medicamento: "<<i.first<<", preço: "<<i.second<<endl;
    }
    else
        cout<<"Nenhum medicamento disponível!"<<endl;
}

int alterarPreco(string medicamento, double novoPreco) {
    for(auto i:medicamentos) {
        if(i.first==medicamento) {
            i.second=novoPreco;
            cout<<"Preço atualizado com sucesso!"<<endl;
            return 1;
        }
    }
    cout<<"Medicamento não encontrado no estoque!"<<endl;
    return 0;
}

int excluirMed(string medicamento) {
    for(auto i:medicamentos) {
        if(i.first==medicamento) {
            medicamentos.erase(i.first);
            return 1;
        }
    }
    cout<<"Medicamento não encontrado no estoque!"<<endl;
    return 0;
}

double procurarPreco(string medicamento) {
    for(auto i:medicamentos) {
        if(i.first==medicamento)
            return i.second;
    }
}

void transferirMedsNoArquivo() {
    ofstream arquivo;
    arquivo.open("medicamentos.txt", ios::out);
    for(auto i:medicamentos) {
        arquivo<<i.first<<endl;
        arquivo<<i.second<<endl;
    }
    arquivo.close();
}