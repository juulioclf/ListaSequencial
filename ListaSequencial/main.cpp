#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>

using namespace std;

void limparTela(){
    system("CLS");
}


struct pessoa{
    string nome;
    int rg;

};

void imprimeSequencial(pessoa *ponteiro, int tamanho){

    for(int i = 0; i < tamanho; i++){
        cout << i << "-nome: " << ponteiro[i].nome <<" rg: " << ponteiro[i].rg << "\n";
    }
}

void addComecoSequencial(pessoa *&ponteiro, int *tamanho, string nome, int rg){

    if(*tamanho == 0){

        pessoa *novoSequencial = new pessoa[1];

        novoSequencial[0].nome = nome;
        novoSequencial[0].rg = rg;

        ponteiro = novoSequencial;

    }else{
        pessoa *novoSequencial = new pessoa[*tamanho + 1];

        novoSequencial[0].nome = nome;
        novoSequencial[0].rg = rg;

        for(int i = 0; i < *tamanho; i++){
            novoSequencial[i+1].nome = ponteiro[i].nome;
            novoSequencial[i+1].rg = ponteiro[i].rg;
        }

        ponteiro = novoSequencial;

    }

    *tamanho = *tamanho + 1;

}


int main(){

    int funcaoUsuario = 0;
    int tamanho = 0;

    pessoa *ponteiroSequencial;


    while(funcaoUsuario != 9 && funcaoUsuario > -1){

        cout << "funcao 1: insercao de uma pessoa no inicio da lista\n";
        cout << "funcao 2: \n";
        cout << "funcao 3: \n";
        cout << "funcao 4: \n";
        cout << "funcao 5: \n";
        cout << "funcao 6: \n";
        cout << "funcao 7: \n";
        cout << "funcao 8: \n";
        cout << "funcao 9: \n";
        cout << "\ndigite a opcao desejada e pressione ENTER: ";
        cin >> funcaoUsuario;
        limparTela();

        string nome;
        int rg;

        switch (funcaoUsuario){
            case 1:
                cout << "Voce selecionou a funcao 1:  insercao de uma pessoa no inicio da lista\n\n";\
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                addComecoSequencial(ponteiroSequencial, &tamanho, nome, rg);

                cout << "\nUsuario: " << nome << ",RG: " << rg << " Adicionado ao inicio da lista com sucesso!\n";

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
        }

    }

    return 0;
}
