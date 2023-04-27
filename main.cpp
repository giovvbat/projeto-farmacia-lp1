#include <iostream>
#include <fstream>
#include "gerente.cpp"
#include "cliente.cpp"
using namespace std;

int main(int argc, char *argv[]) {
    
    string perfil=argv[1];
    ofstream arquivo("medicamentos.txt");

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
            if(option==1) 
                listarMeds();
            else if(option==2) {
                string medDesejado;
                cout<<"Digite o nome do medicamento desejado:"<<endl;
                getline(cin, medDesejado);
                if(buscarMed(medDesejado))
                    cout<<"Medicamento encontrado!"<<endl;
                else
                    cout<<"Medicamento não encontrado!"<<endl;
            }
            else if(option==3) {
                string medDesejado;
                cout<<"Digite o nome do medicamento desejado:"<<endl;
                getline(cin, medDesejado);
                if(buscarMed(medDesejado)) 
                    adicionarNoCarrinho(medDesejado);
                else
                    cout<<"Medicamento indisponível!"<<endl;
            }
            else if(option==4) {
                cout<<"O valor atual do carrinho é: "<<calcularValorCarrinho()<<" reais!"<<endl;
            }
            else if(option==4) {
                cout<<"Digite o remédio a ser excluído do carrinho: "<<endl;
                string remedioExcl;
                getline(cin, remedioExcl);
                excluirDoCarrinho(remedioExcl);
            }
            else if(option==6)
                break;
        }
    }
    else if(perfil=="gerente") {
        string senha;
        cout<<"Digite a senha: "<<endl;
        getline(cin, senha);
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
                if(option==1) 
                    listarMedsWithPrices();
                else if(option==2) {
                    string nomeMed;
                    double precoMed;
                    cout<<"Digite o nome do medicamento:"<<endl;
                    getline(cin, nomeMed);
                    cout<<"Digite o preço do medicamento:"<<endl;
                    cin>>precoMed;
                    adicionarMed(arquivo, nomeMed, precoMed);
                }
                else if(option==3) {
                    string medDesejado;
                    cout<<"Digite o nome do medicamento desejado:"<<endl;
                    getline(cin, medDesejado);
                    if(buscarMed(medDesejado))
                        cout<<"Medicamento encontrado!"<<endl;
                    else
                        cout<<"Medicamento não encontrado!"<<endl;
                }
                else if(option==6)
                    break;
            }
        }
    }

    return 0;
}