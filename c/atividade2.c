#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estacao {
    char nome[100];
    struct Estacao* proxima;
} Estacao;

Estacao* criarEstacao(char* nome) {
    Estacao* novaEstacao = (Estacao*)malloc(sizeof(Estacao));
    strcpy(novaEstacao->nome, nome);
    novaEstacao->proxima = NULL;
    return novaEstacao;
}

void adicionarEstacao(Estacao** head, char* nome) {
    Estacao* novaEstacao = criarEstacao(nome);
    if (*head == NULL) {
        *head = novaEstacao;
    } else {
        Estacao* temp = *head;
        while (temp->proxima != NULL) {
            temp = temp->proxima;
        }
        temp->proxima = novaEstacao;
    }
    printf("Estação %s adicionada à linha.\n", nome);
}

void removerEstacao(Estacao** head, char* nome) {
    if (*head == NULL) {
        printf("A linha está vazia.\n");
        return;
    }
    Estacao* temp = *head;
    Estacao* anterior = NULL;

    if (strcmp(temp->nome, nome) == 0) {
        *head = temp->proxima;
        free(temp);
        printf("Estação %s removida da linha.\n", nome);
        return;
    }

    while (temp != NULL && strcmp(temp->nome, nome) != 0) {
        anterior = temp;
        temp = temp->proxima;
    }

    if (temp == NULL) {
        printf("Estação %s não encontrada na linha.\n", nome);
        return;
    }

    anterior->proxima = temp->proxima;
    free(temp);
    printf("Estação %s removida da linha.\n", nome);
}


void exibirEstacoes(Estacao* head) {
    if (head == NULL) {
        printf("A linha está vazia.\n");
        return;
    }
    Estacao* temp = head;
    printf("Estações na linha:\n");
    while (temp != NULL) {
        printf("%s\n", temp->nome);
        temp = temp->proxima;
    }
}

int main() {
    Estacao* linha = NULL;
    int opcao;
    char nome[100];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar estação à linha\n");
        printf("2. Remover estação da linha\n");
        printf("3. Exibir estações na linha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Digite o nome da estação: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                adicionarEstacao(&linha, nome);
                break;
            case 2:
                printf("Digite o nome da estação a ser removida: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                removerEstacao(&linha, nome);
                break;
            case 3:
                exibirEstacoes(linha);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    while (linha != NULL) {
        Estacao* temp = linha;
        linha = linha->proxima;
        free(temp);
    }

    return 0;
}
