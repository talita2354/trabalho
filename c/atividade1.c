#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    char nome[100];
    struct Cliente* proximo;
} Cliente;

void adicionarCliente(Cliente** head) {
    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente->nome);
    novoCliente->proximo = NULL;

    if (*head == NULL) {
        *head = novoCliente;
    } else {
        Cliente* temp = *head;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoCliente;
    }
    printf("Cliente %s adicionado à fila de espera.\n", novoCliente->nome);
}

void atenderCliente(Cliente** head) {
    if (*head == NULL) {
        printf("A fila de espera está vazia.\n");
    } else {
        Cliente* temp = *head;
        *head = (*head)->proximo;
        printf("Cliente %s está sendo atendido.\n", temp->nome);
        free(temp);
    }
}

void exibirClientes(Cliente* head) {
    if (head == NULL) {
        printf("A fila de espera está vazia.\n");
    } else {
        Cliente* temp = head;
        printf("Clientes na fila de espera:\n");
        while (temp != NULL) {
            printf("%s\n", temp->nome);
            temp = temp->proximo;
        }
    }
}

int main() {
    Cliente* fila = NULL;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar cliente à fila\n");
        printf("2. Atender cliente\n");
        printf("3. Exibir clientes na fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente(&fila);
                break;
            case 2:
                atenderCliente(&fila);
                break;
            case 3:
                exibirClientes(fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    while (fila != NULL) {
        Cliente* temp = fila;
        fila = fila->proximo;
        free(temp);
    }

    return 0;
}
