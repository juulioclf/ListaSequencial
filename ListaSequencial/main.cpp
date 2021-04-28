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

void addPosicaoSequencial(pessoa *&ponteiro, int *tamanho, string nome, int rg, int posicao){

    pessoa *novoSequencial = new pessoa[*tamanho + 1];

    for(int i = 0; i < posicao; i++){
        novoSequencial[i].nome = ponteiro[i].nome;
        novoSequencial[i].rg = ponteiro[i].rg;
    }

    novoSequencial[posicao].nome = nome;
    novoSequencial[posicao].rg = rg;

    for(int i = posicao + 1; i < *tamanho + 1; i++ ){
        novoSequencial[i].nome = ponteiro[i-1].nome;
        novoSequencial[i].rg = ponteiro[i-1].rg;
    }
    *tamanho = *tamanho + 1;

    ponteiro = novoSequencial;

}

void popComecoSequencial(pessoa *&ponteiro, int *tamanho){

    pessoa *novoSequencial = new pessoa[*tamanho - 1];

    for(int i = 0; i < *tamanho-1; i++){
        novoSequencial[i].nome = ponteiro[i+1].nome;
        novoSequencial[i].rg = ponteiro[i+1].rg;
    }

    ponteiro = novoSequencial;

    *tamanho = *tamanho - 1;
}

void popFinalSequencial(pessoa *&ponteiro, int *tamanho){

    pessoa *novoSequencial = new pessoa[*tamanho - 1];

    for(int i = 0; i < *tamanho - 1; i++){
        novoSequencial[i].nome = ponteiro[i].nome;
        novoSequencial[i].rg = ponteiro[i].rg;

    }

    ponteiro = novoSequencial;

    *tamanho = *tamanho - 1;
}

void popPosicaoSequencial(pessoa *&ponteiro, int *tamanho, int posicao){

    pessoa *novoSequencial = new pessoa[*tamanho - 1];

    for(int i = 0; i < *tamanho - 1; i++){

        if(i < posicao){
            novoSequencial[i].nome = ponteiro[i].nome;
            novoSequencial[i].rg = ponteiro[i].rg;
        }else{
            novoSequencial[i].nome = ponteiro[i+1].nome;
            novoSequencial[i].rg = ponteiro[i+1].rg;
        }
    }
    *tamanho = *tamanho - 1;

    ponteiro = novoSequencial;

}

string retornaNome(pessoa *ponteiro, int *tamanho, int rg){

    string nome = "Nome nao encontrado";

    for(int i = 0; i < *tamanho; i++){
        if(ponteiro[i].rg == rg){

            nome = ponteiro[i].nome;
        }
    }
    return nome;

}

int main(){

    int funcaoUsuario = 0, tamanho = 0, rg, posicao;
    string nome;

    pessoa *ponteiroSequencial;

    while(funcaoUsuario != 9){

        cout << "funcao 1: insercao de uma pessoa no inicio da lista\n";
        cout << "funcao 2: insercao de uma pessoa no final da lista\n";
        cout << "funcao 3: insercao de uma pessoa na posicao N\n";
        cout << "funcao 4: remocao de uma pessoa no inicio da lista\n";
        cout << "funcao 5: remocao de uma pessoa no final da lista\n";
        cout << "funcao 6: remocao de uma pessoa na posicao N\n";
        cout << "funcao 7: procurar um Nome pelo RG\n";
        cout << "funcao 8: mostrar a lista\n";
        cout << "funcao 9: sair do sistema\n";
        cout << "\ndigite a opcao desejada e pressione ENTER: ";
        cin >> funcaoUsuario;
        limparTela();

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

                cout << "Voce selecionou a funcao 2: insercao de uma pessoa na posicao N\n\n";
                cout << "Digite a posicao: ";
                cin >> posicao;
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                if(posicao == 0){
                    addComecoSequencial(ponteiroSequencial, &tamanho, nome, rg);
                }else if(posicao == tamanho){
                    addFinalSequencial(ponteiroSequencial, &tamanho, nome, rg);
                }else{
                    addPosicaoSequencial(ponteiroSequencial, &tamanho, nome, rg, posicao);
                }

                cout << "\nUsuario: " << nome << ", RG: " << rg << " Adicionado ao final da lista com sucesso!\n";

                break;

            case 4:

                cout << "Voce selecionou a funcao 4: remocao de uma pessoa no inicio da lista\n\n";

                if(tamanho == 0){
                    cout << "A lista esta vazia!\n";
                }else{
                    popComecoSequencial(ponteiroSequencial, &tamanho);
                }

                break;

            case 5:

                cout << "Voce selecionou a funcao 5: remocao de uma pessoa no final da lista\n\n";

                 if(tamanho == 0){
                    cout << "A lista esta vazia!\n";
                }else{
                    popFinalSequencial(ponteiroSequencial, &tamanho);
                }

                break;

            case 6:

                cout << "Voce selecionou a funcao 6: remocao de uma pessoa na posicao N\n\n";
                cout << "Digite a posicao: ";
                cin >> posicao;

                if(posicao == 0){
                    popComecoSequencial(ponteiroSequencial, &tamanho);
                }else if(posicao == tamanho){
                    popFinalSequencial(ponteiroSequencial, &tamanho);
                }else{
                    popPosicaoSequencial(ponteiroSequencial, &tamanho, posicao);
                }

                break;

            case 7:

                cout << "Voce selecionou a funcao 7: procurar um Nome pelo RG\n\n";
                cout << "Digite um RG: ";
                cin >> rg;

                cout << "\nNome do rg " << rg << ": " << retornaNome(ponteiroSequencial, &tamanho, rg) << "\n";

                break;

            case 8:

                cout << "Voce selecionou a funcao 8: sair do sistema\n\n";

                imprimeSequencial(ponteiroSequencial, tamanho);

                break;

            case 9:

                cout << "saindo do sistema...\n\n";

                break;

            default:

                cout << "Por favor, digite um codigo valido\n\n";

        }

    }

    return 0;
}
