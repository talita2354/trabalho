#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Prato {
    char nome[100];
    struct Prato* proximo;
} Prato;

void adicionarPrato(Prato** topo) {
    Prato* novoPrato = (Prato*)malloc(sizeof(Prato));
    printf("Digite o nome do prato: ");
    scanf("%s", novoPrato->nome);
    novoPrato->proximo = *topo;
    *topo = novoPrato;
    printf("Prato %s adicionado à pilha.\n", novoPrato->nome);
}


void removerPrato(Prato** topo) {
    if (*topo == NULL) {
        printf("A pilha está vazia.\n");
    } else {
        Prato* temp = *topo;
        *topo = (*topo)->proximo;
        printf("Prato %s removido da pilha.\n", temp->nome);
        free(temp);
    }
}

void exibirPratos(Prato* topo) {
    if (topo == NULL) {
        printf("A pilha está vazia.\n");
    } else {
        Prato* temp = topo;
        printf("Pratos na pilha:\n");
        while (temp != NULL) {
            printf("%s\n", temp->nome);
            temp = temp->proximo;
        }
    }
}

int main() {
    Prato* pilha = NULL;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar prato à pilha\n");
        printf("2. Remover prato do topo da pilha\n");
        printf("3. Exibir pratos na pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPrato(&pilha);
                break;
            case 2:
                removerPrato(&pilha);
                break;
            case 3:
                exibirPratos(pilha
