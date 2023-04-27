#include <iostream>
#include <fstream>
#include "h-gerente.hpp"
using namespace std;

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