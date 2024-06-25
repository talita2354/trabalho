#include <iostream>
#include <queue>
#include <string>

class Banco {
private:
    std::queue<std::string> filaDeEspera;

public:
    void adicionarCliente(const std::string& nome) {
        filaDeEspera.push(nome);
        std::cout << "Cliente " << nome << " adicionado à fila de espera.\n";
    }

    void atenderCliente() {
        if (filaDeEspera.empty()) {
            std::cout << "Nenhum cliente na fila de espera para atender.\n";
        } else {
            std::string cliente = filaDeEspera.front();
            filaDeEspera.pop();
            std::cout << "Cliente " << cliente << " atendido.\n";
        }
    }

    void exibirClientes() {
        if (filaDeEspera.empty()) {
            std::cout << "Nenhum cliente na fila de espera.\n";
        } else {
            std::queue<std::string> tempQueue = filaDeEspera;
            std::cout << "Clientes na fila de espera:\n";
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << "\n";
                tempQueue.pop();
            }
        }
    }
};

int main() {
    Banco banco;
    int opcao;
    std::string nome;

    do {
        std::cout << "\n1. Adicionar cliente à lista de espera\n";
        std::cout << "2. Atender cliente\n";
        std::cout << "3. Exibir todos os clientes na lista de espera\n";
        std::cout << "4. remover\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Digite o nome do cliente: ";
                std::cin >> nome;
                banco.adicionarCliente(nome);
                break;
            case 2:
                banco.atenderCliente();
                break;
            case 3:
                banco.exibirClientes();
                break;
            case 4:
                std::cout << "removendo...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 4);

    return 0;
}
