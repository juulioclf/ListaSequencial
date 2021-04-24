#include <stdlib.h>
#include <new>
#include <iostream>

using namespace std;

void limparTela(){
    system("CLS");
}

int main(){

    int funcaoUsuario = 0;

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
