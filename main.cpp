#include <cstdio>
#include <cstdlib>

typedef struct Node{
    int valor;
    Node* proximo;
} Node;

Node* criar_no(int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->proximo = novo;
    return novo;
}

Node* inserirInicio(Node* lista, int valor) {
    Node *novo = criar_no(valor);

    if (lista == nullptr) {
        return novo;
    }

    Node *ultimo = lista;
    while (ultimo->proximo != lista) {
        ultimo = ultimo->proximo;
    }

    novo->proximo = lista;
    ultimo->proximo = novo;
    return novo;
}

void imprimirLista(Node* lista) {
    if (lista == nullptr) {
        printf("Lista vazia");
        return;
    }
    Node *primeiro = lista;
    printf("%d\n", primeiro->valor);
    lista = lista->proximo;
    while (lista != primeiro) {
        printf("%d\n", lista->valor);
        lista = lista->proximo;
    }
}

void liberarLista(Node* lista) {
    if (lista == nullptr) return;
    Node *proximo;
    Node *primeiro = lista;
    lista = lista->proximo;
    while (lista != primeiro) {
        proximo = lista->proximo;
        free(lista);
        lista = proximo;
    }

    free(primeiro);
}

Node* inserirFim(Node* lista, int valor) {
    Node *novo = criar_no(valor);
    if (lista == nullptr) {
        return novo;
    }

    Node *atual = lista;
    Node *primeiro = lista;
    atual = atual->proximo;
    while (atual->proximo != lista) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    novo->proximo = primeiro;
    return lista;
}

int main() {
    Node *lista = nullptr;

    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 30);
    lista = inserirFim(lista, 40);
    imprimirLista(lista);

    return 0;
}
