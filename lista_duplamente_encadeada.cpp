#include <cstdio>
#include <cstdlib>

typedef struct Node {
    int valor;
    Node* prox;
    Node* prev;
} Node;

Node* criar_no(int valor);
Node* inserir_inicio(int valor);
Node* inserir_fim(int valor);
Node* procurar_no(int valor);
bool remover_no(int valor);
void imprimir_no(Node* p);
void imprimir_lista();
bool validar_lista();

Node* inicio = nullptr;
Node* fim = nullptr;

Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prev = nullptr;
    novo->prox = nullptr;

    return novo;
}

Node* inserir_inicio(int valor) {
    Node* novo = criar_no(valor);

    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    }
    else {
        novo->prox = inicio;
        inicio->prev = novo;
        inicio = novo;
    }

    return novo;
}

Node* inserir_fim(int valor) {
    Node* novo = criar_no(valor);

    if (fim == nullptr) {
        fim = novo;
        inicio = novo;
    }
    else {
        novo->prev = fim;
        fim->prox = novo;
        fim = novo;
    }

    return novo;
}

Node* procurar_no(int valor) {
    Node* p = inicio;

    while (p != nullptr) {
        if (p->valor == valor)
            return p;

        p = p->prox;
    }

    return nullptr;
}

bool remover_no(int valor) {
    if (inicio == nullptr)
        return false;

    Node* p = procurar_no(valor);
    if (p == nullptr)
        return false;

    if (p->prev != nullptr)
        p->prev->prox = p->prox;

    if (p->prox != nullptr)
        p->prox->prev = p->prev;

    if (p == inicio)
        inicio = p->prox;

    if (p == fim)
        fim = p->prev;

    free(p);
    return true;
}

void imprimir_no(Node* p) {
    if (p->prev != nullptr)
        printf("<->");
    else
        printf("[VAZIO] <-");

    printf(" [%d] ", p->valor);
}

void imprimir_lista() {
    Node* p = inicio;
    while (p != nullptr) {
        imprimir_no(p);

        p = p->prox;
    }

    printf("-> [VAZIO]");
}

bool validar_lista() {
    Node* p = inicio;
    while (p != nullptr) {
        if ((p->prev != nullptr) && (p->prox != nullptr) && !(p->prev->prox == p->prox->prev))
            return false;

        p = p->prox;
    }

    return true;
};

int main() {
    inserir_inicio(2);
    inserir_fim(3);
    inserir_inicio(1);
    inserir_fim(4);

    remover_no(3);

    imprimir_lista();

    if (validar_lista())
        printf("\nLista eh valida");
    else 
        printf("\nLista nao eh valida.");

    return 0;
}