#ifndef _GERENTE_HPP
#define _GERENTE_HPP
using namespace std;

bool buscarMed(string medDesejado);
void adicionarMed(ofstream& arquivo, string nomeMed, double precoMed);
void listarMedsWithPrices();

#endif