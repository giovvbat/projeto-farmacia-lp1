#include <iostream>
#include <fstream>
#include "h-cliente.hpp"
#include "h-gerente.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    
    /*capturando o tipo de usuário para inicializar o programa de maneira correta*/
    string perfil=argv[1];

    /*transferindo os elementos já presentes no arquivo para o mapa*/
    adicionarArquivoNoMapa();

    /*teste para saber qual perfil de usuário inicializou o programa*/
    if(perfil=="cliente") {
        while(1) {
            cout<<"Escolha uma das opções: "<<endl;
            cout<<"1 - Listar medicamentos cadastrados"<<endl;
            cout<<"2 - Buscar um medicamento por nome"<<endl;
            cout<<"3 - Adicionar medicamento em carrinho de compras"<<endl;
            cout<<"4 - Calcular o valor do carrinho de compras"<<endl;
            cout<<"5 - Excluir um medicamento do carrinho de compras"<<endl;
            cout<<"6 - Sair"<<endl;
            int option;
            cin>>option;
            /*checando qual operação deseja ser realizada pelo cliente*/
            if(option==1) 
                listarMedsWithPrices();
            else if(option==2) {
                string medDesejado;
                cout<<"Digite o nome do medicamento desejado:"<<endl;
                cin.ignore();
                getline(cin, medDesejado);
                /*teste para verificar a presença do medicamento desejado no map*/
                if(buscarMed(medDesejado))
                    cout<<"Medicamento encontrado!"<<endl;
                else
                    cout<<"Medicamento não encontrado!"<<endl;
            }
            else if(option==3) {
                string medDesejado;
                cout<<"Digite o nome do medicamento desejado:"<<endl;
                cin.ignore();
                getline(cin, medDesejado);
                /*testando se o medicamento está disponível no estoque*/
                if(buscarMed(medDesejado)) {
                    /*buscando o preço do remédio a ser adicionado no carrinho*/
                    double precoMed=procurarPreco(medDesejado);
                    /*inserindo a string referente ao medicamento e seu preço no map*/
                    adicionarNoCarrinho(medDesejado, precoMed);
                    cout<<"Medicamento adicionado no carrinho com sucesso!"<<endl;
                }
                else
                    cout<<"Medicamento indisponível!"<<endl;
            }
            else if(option==4) {
                /*caso a função retorne 0, não há medicamentos no carrinho*/
                if(!(calcularValorCarrinho()==0))
                    cout<<"O valor atual do carrinho é: "<<calcularValorCarrinho()<<" reais!"<<endl;
            }
            else if(option==5) {
                cout<<"Digite o remédio a ser excluído do carrinho: "<<endl;
                string remedioExcl;
                cin.ignore();
                getline(cin, remedioExcl);
                /*excluindo remédio do carrinho com a função*/
                excluirDoCarrinho(remedioExcl);
            }
            else if(option==6)
                /*fechando o programa após todas as operações terem sido feitas pelo cliente*/
                break;
            else
                /*a opção escolhida pelo cliente deve ser um número de 1 a 5, algo além disso é inválido*/
                cout<<"Opção inválida!"<<endl;
        }
    }
    else if(perfil=="gerente") {
        /*exigindo digitação de senha para que operações possam ser feitas como gerente*/
        string senha;
        cout<<"Digite a senha: "<<endl;
        getline(cin, senha);
        /*a senha é 'souGerente'*/
        if(senha=="souGerente") {
            while(1) {
                cout<<"Escolha uma das opções: "<<endl;
                cout<<"1 - Listar medicamentos cadastrados e seus preços"<<endl;
                cout<<"2 - Adicionar medicamento"<<endl;
                cout<<"3 - Buscar um medicamento"<<endl;
                cout<<"4 - Atualizar preço de um medicamento"<<endl;
                cout<<"5 - Excluir um medicamento"<<endl;
                cout<<"6 - Sair"<<endl;
                int option;
                cin>>option;
                /*checando qual operação o gerente deseja realizar*/
                if(option==1) 
                    listarMedsWithPrices();
                else if(option==2) {
                    string medicamento;
                    double preco;
                    cout<<"Digite o nome do medicamento:"<<endl;
                    cin.ignore();
                    getline(cin, medicamento);
                    cout<<"Digite o preço do medicamento:"<<endl;
                    cin>>preco;
                    /*adicionando um novo medicamento ao map de acordo com seu nome e preço*/
                    adicionarMed(medicamento, preco);
                }
                else if(option==3) {
                    string medDesejado;
                    cout<<"Digite o nome do medicamento desejado:"<<endl;
                    cin.ignore();
                    getline(cin, medDesejado);
                    /*buscando o remédio no map*/
                    if(buscarMed(medDesejado))
                        cout<<"Medicamento encontrado!"<<endl;
                    else
                        cout<<"Medicamento não encontrado!"<<endl;
                }
                else if(option==4) {
                    string medicamento, novoPr;
                    double novoPreco;
                    cout<<"Digite o nome do medicamento cujo preço será modificado: "<<endl;
                    cin.ignore();
                    getline(cin, medicamento);
                    if(buscarMed(medicamento)) {
                        cout<<"Digite o novo preço do medicamento: "<<endl;
                        /*lendo como string (para ser possível a utilização do getline) o preço novo do remédio e depois transformando para double*/
                        getline(cin, novoPr);
                        novoPreco=stod(novoPr);
                        /*alterando o preço do remédio, usando seu nome e seu novo preço*/
                        alterarPreco(medicamento, novoPreco);
                    }
                }
                else if(option==5) {
                    string medicamento;
                    cout<<"Digite o nome do medicamento a ser excluído: "<<endl;
                    cin.ignore();
                    getline(cin, medicamento);
                    /*excluindo o medicamento do map a partir de seu nome*/
                    excluirMed(medicamento);
                }
                else if(option==6) {
                    /*função para transferir as modificações feitas no map para o arquivo, para depois encerrar o programa*/
                    transferirMedsNoArquivo();
                    break;
                }
                else
                    /*a opção escolhida pelo cliente deve ser um número de 1 a 5, algo além disso é inválido*/
                    cout<<"Opção inválida!"<<endl;
            }
        }
        else
            /*else para avisar que digitação da senha do gerente foi incorreta*/
            cout<<"Senha inválida!"<<endl;
    }
    else
        /*não é possível iniciar o programa sem a informação correta de qual é o perfil do usuário*/
        cout<<"Perfil inválido!"<<endl;

    return 0;
}