#ifndef _GERENTE_HPP
#define _GERENTE_HPP
using namespace std;

/*funções utilizadas pelo gerente*/

void inicializarArquivo();
void adicionarMed(string nomeMed, double precoMed);
void listarMedsWithPrices();
void adicionarArquivoNoMapa();
int alterarPreco(string medicamento, double novoPreco);
int excluirMed(string medicamento);
bool buscarMed(string medDesejado);
double procurarPreco(string medicamento);
void transferirMedsNoArquivo();

#endif