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
        cout << "linha: " << i << " nome: " << ponteiro[i].nome <<" rg: " << ponteiro[i].rg << "\n";
    }
}


int main(){

    int funcaoUsuario = 0;
    int tamanho;

    pessoa *ponteiroSequencial;


    //exemplo:

    pessoa *exemploSequencial = new pessoa[2];

    exemploSequencial[0].nome = "julio";
    exemploSequencial[0].rg = 123;
    exemploSequencial[1].nome = "gabe";
    exemploSequencial[1].rg = 321;

    ponteiroSequencial = exemploSequencial;

    imprimeSequencial(ponteiroSequencial, 2);


    while(funcaoUsuario != 9 && funcaoUsuario > -1){

        cout << "funcao 1: \n";
        cout << "funcao 2: \n";
        cout << "funcao 3: \n";
        cout << "funcao 4: \n";
        cout << "funcao 5: \n";
        cout << "funcao 6: \n";
        cout << "funcao 7: \n";
        cout << "funcao 8: \n";
        cout << "funcao 9: \n";
        cout << "digite a opcao desejada: ";
        cin >> funcaoUsuario;
        limparTela();

    }

    return 0;
}
