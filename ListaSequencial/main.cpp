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

void addFinalSequencial(pessoa *&ponteiro, int *tamanho, string nome, int rg){

    pessoa *novoSequencial = new pessoa[*tamanho + 1];

    for(int i = 0; i < *tamanho; i++){
        novoSequencial[i].nome = ponteiro[i].nome;
        novoSequencial[i].rg = ponteiro[i].rg;
    }

    novoSequencial[*tamanho].nome = nome;
    novoSequencial[*tamanho].rg = rg;

    *tamanho = *tamanho + 1;

    ponteiro = novoSequencial;
}

int main(){

    int funcaoUsuario = 0;
    int tamanho = 0;

    pessoa *ponteiroSequencial;


    while(funcaoUsuario != 9 && funcaoUsuario > -1){

        imprimeSequencial(ponteiroSequencial, tamanho);
        cout << "funcao 1: insercao de uma pessoa no inicio da lista\n";
        cout << "funcao 2: insercao de uma pessoa no final da lista\n";
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
                cout << "Voce selecionou a funcao 1:  insercao de uma pessoa no inicio da lista\n\n";
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                addComecoSequencial(ponteiroSequencial, &tamanho, nome, rg);

                cout << "\nUsuario: " << nome << ", RG: " << rg << " Adicionado ao inicio da lista com sucesso!\n";

                break;

            case 2:

                cout << "Voce selecionou a funcao 2: insercao de uma pessoa no final da lista\n\n";
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                if(tamanho == 0){
                    addComecoSequencial(ponteiroSequencial, &tamanho, nome, rg);
                }else{
                    addFinalSequencial(ponteiroSequencial, &tamanho, nome, rg);
                }

                cout << "\nUsuario: " << nome << ", RG: " << rg << " Adicionado ao final da lista com sucesso!\n";

                break;

            case 3:
                cout << "Voce selecionou a funcao 3:  \n\n";
                break;

            case 4:
                cout << "Voce selecionou a funcao 4:  \n\n";
                break;

            case 5:
                cout << "Voce selecionou a funcao 5:  \n\n";
                break;

            case 6:
                cout << "Voce selecionou a funcao 6:  \n\n";
                break;

            case 7:
                cout << "Voce selecionou a funcao 7:  \n\n";
                break;

            case 8:
                cout << "Voce selecionou a funcao 8:  \n\n";
                break;

            case 9:
                cout << "Voce selecionou a funcao 9:  \n\n";
                break;
        }

    }

    return 0;
}
