#include <iostream>
#include <fstream>
#include <map>
#include "h-gerente.hpp"
using namespace std;

/*criando o map onde serão armazenado os medicamentos com seus preços*/
map<string, double>medicamentos;

/*adicionando 5 elementos iniciais no arquivo como padrão*/
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

/*adicionando os elementos adicionados no map*/
void adicionarArquivoNoMapa() {
    ifstream file("medicamentos.txt");
    string medicamento, preco;
    double precoD;
    /*lendo cada linha do arquivo, referentes aos nomes dos medicamentos*/
    while(getline(file, medicamento)) {
        /*lendo a linha logo após cada nome de medicamento (utilizando getline), ou seja, lendo seu preço e transformando a string lida em double*/
        getline(file, preco);
        precoD=stod(preco);
        /*armazenando no map, sendo a chave o nome do medicamento e o valor seu preço*/
        medicamentos[medicamento]=precoD;
    }
    file.close();
}

/*buscando a presença de um determinado medicamento no map a partir de seu nome(string)*/
bool buscarMed(string medDesejado) {
    for(auto i:medicamentos) {
        /*se encontrado, função retorna true*/
        if(i.first==medDesejado)
            return true;
    }
    /*se a função não retornar true após 'varrer' todas as chaves do map (todos os nomes de medicamentos), ela retorna false*/
    return false;
}

/*adicionando um medicamento no map*/
void adicionarMed(string nomeMed, double precoMed) {
    /*adicionando o medicamento, tendo seu nome como chave e seu preço como valor*/
    medicamentos[nomeMed]=precoMed;
    cout<<"Medicamento adicionado com sucesso!"<<endl;
}

/*listando os medicamentos e seus preços*/
void listarMedsWithPrices() {
    /*caso o mapa não esteja vazio todos os elementos são listados*/
    if(!(medicamentos.empty())) {
        cout<<"Medicamentos disponíveis: "<<endl;
        for(auto i:medicamentos)
            cout<<"Medicamento: "<<i.first<<", preço: "<<i.second<<endl;
    }
    /*caso o mapa esteja vazio um aviso é impresso*/
    else
        cout<<"Nenhum medicamento disponível!"<<endl;
}

/*alterando o preço de um medicamento*/
int alterarPreco(string medicamento, double novoPreco) {
    /*buscando o medicamento no map*/
    for(auto i:medicamentos) {
        if(i.first==medicamento) {
            /*um vez encontrado o medicamento, o novo preço é inserido como valor no map e a função é encerrada retornando 1*/
            medicamentos[medicamento]=novoPreco;
            cout<<"Preço atualizado com sucesso!"<<endl;
            return 1;
        }
    }
    /*mensagem impressa caso o medicamento não seja encontrado no map*/
    cout<<"Medicamento não encontrado no estoque!"<<endl;
    return 0;
}

/*excluindo um medicamento do map*/
int excluirMed(string medicamento) {
    /*buscando o medicamento no map*/
    for(auto i:medicamentos) {
        if(i.first==medicamento) {
            /*um vez encontrado o medicamento, ele é excluído e a função é encerrada retornando 1*/
            medicamentos.erase(i.first);
            cout<<"Medicamento excluído com sucesso!"<<endl;
            return 1;
        }
    }
    /*mensagem impressa caso o medicamento não seja encontrado no map*/
    cout<<"Medicamento não encontrado no estoque!"<<endl;
    return 0;
}

/*função que retorna o preço de um medicamento que é passado como parâmetro*/
/*essa função é usada como auxiliar para que a função que adiciona um medicamento no carrinho do cliente não precise ter acesso ao map de medicamentos*/
double procurarPreco(string medicamento) {
    for(auto i:medicamentos) {
        /*o medicamento é buscado e a função retorna o seu preço*/
        if(i.first==medicamento)
            return i.second;
    }
}

/*função usada para transferir as alterações feitas no map para o arquivo original*/
void transferirMedsNoArquivo() {
    /*de clarando o arquivo e esvaziando ele*/
    ofstream arquivo;
    arquivo.open("medicamentos.txt", ios::out);
    /*imprimindo cada elemento do map em duas linhas no arquivo e fechando o arquivo em seguida*/
    for(auto i:medicamentos) {
        arquivo<<i.first<<endl;
        arquivo<<i.second<<endl;
    }
    arquivo.close();
}