#ifndef _CLIENTE_HPP
#define _CLIENTE_HPP
using namespace std;

bool buscarMed(string medDesejado);
void listarMeds();
void adicionarNoCarrinho(string medDesejado);
double calcularValorCarrinho();
int excluirDoCarrinho(string remedioExcl);

#endif