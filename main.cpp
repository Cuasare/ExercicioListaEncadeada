#include <cstdio>
#include <cstdlib>

typedef struct Node {
    int valor;
    Node *proximo;
} Node;

Node *criar_no(int valor);
Node *inserir_inicio(Node *lista, int valor);
Node *inserir_fim(Node *lista, int valor);
Node *procurar_no(Node *lista, int valor);
bool remover_no(Node **lista, int valor);
void imprimir_lista(Node *lista);
void liberar_lista(Node **lista);

Node *criar_no(int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->proximo = novo;
    return novo;
}

Node *inserir_inicio(Node *lista, int valor) {
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

Node *inserir_fim(Node *lista, int valor) {
    Node *novo = criar_no(valor);

    if (lista == nullptr) {
        return novo;
    }

    Node *atual = lista;
    while (atual->proximo != lista) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    novo->proximo = lista;
    return lista;
}

Node *procurar_no(Node *lista, int valor) {
    if (lista == nullptr)
        return nullptr;

    Node *p = lista;
    do {
        if (p->valor == valor)
            return p;
        p = p->proximo;
    } while (p != lista);

    return nullptr;
}

bool remover_no(Node **lista, int valor) {
    if (*lista == nullptr)
        return false;

    Node *p = *lista;
    Node *anterior = nullptr;

    do {
        if (p->valor == valor) {
            if (anterior == nullptr) {
                Node *ultimo = *lista;
                while (ultimo->proximo != *lista) {
                    ultimo = ultimo->proximo;
                }

                if (*lista == (*lista)->proximo) {
                    free(*lista);
                    *lista = nullptr;
                    return true;
                }

                ultimo->proximo = (*lista)->proximo;
                *lista = (*lista)->proximo;
                free(p);
            } else {
                anterior->proximo = p->proximo;
                free(p);
            }

            return true;
        }

        anterior = p;
        p = p->proximo;
    } while (p != *lista);

    return false;
}

void imprimir_lista(Node *lista) {
    if (lista == nullptr) {
        printf("Lista vazia\n");
        return;
    }

    Node *p = lista;
    do {
        printf("[%d] -> ", p->valor);
        p = p->proximo;
    } while (p != lista);

    printf("[%d] -> ... (loop)\n", p->valor);
}

void liberar_lista(Node **lista) {
    if (*lista == nullptr)
        return;

    Node *proximo;
    Node *primeiro = *lista;
    Node *atual = (*lista)->proximo;

    while (atual != primeiro) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(primeiro);
    *lista = nullptr;
}

int main() {
    Node *lista = nullptr;

    lista = inserir_inicio(lista, 10);

    imprimir_lista(lista);

    liberar_lista(&lista);
    return 0;
}