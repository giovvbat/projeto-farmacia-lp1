#include <iostream>
#include <fstream>
#include "h-gerente.hpp"
using namespace std;

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

void adicionarMed(ofstream& arquivo, string nomeMed, double precoMed) {
    arquivo<<nomeMed<<endl;
    arquivo<<precoMed<<endl;
}

void listarMedsWithPrices() {
    string nomeMed, precoMed;
    ifstream file("medicamentos.txt");
    cout<<"Medicamentos disponíveis:"<<endl;
    while(getline(file, nomeMed)) {
        getline(file, precoMed);
        cout<<"Nome: "<<nomeMed<<", preço: "<<precoMed<<endl;
    }
}