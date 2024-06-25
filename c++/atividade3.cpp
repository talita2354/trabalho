#include <iostream>
#include <stack>
#include <string>

using namespace std;

void adicionarPrato(stack<string>& pilha) {
    string nome;
    cout << "Digite o nome do prato: ";
    cin >> nome;
    pilha.push(nome);
    cout << "Prato " << nome << " adicionado à pilha.\n";
}

void removerPrato(stack<string>& pilha) {
    if (pilha.empty()) {
        cout << "A pilha está vazia.\n";
    } else {
        cout << "Prato " << pilha.top() << " removido da pilha.\n";
        pilha.pop();
    }
}
void exibirPratos(const stack<string>& pilha) {
    if (pilha.empty()) {
        cout << "A pilha está vazia.\n";
    } else {
        stack<string> copiaPilha = pilha;
        cout << "Pratos na pilha:\n";
        while (!copiaPilha.empty()) {
            cout << copiaPilha.top() << "\n";
            copiaPilha.pop();
        }
    }
}

int main() {
    stack<string> pilha;
    int opcao;

    do {
        cout << "\nMenu:\n";
        cout << "1. Adicionar prato à pilha\n";
        cout << "2. Remover prato do topo da pilha\n";
        cout << "3. Exibir pratos na pilha\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarPrato(pilha);
                break;
            case 2:
                removerPrato(pilha);
                break;
            case 3:
                exibirPratos(pilha);
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 4);

    return 0;
}
