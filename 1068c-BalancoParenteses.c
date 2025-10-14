#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct No {
    char caractere;
    struct No* proximo;
} No;

void push(No** topo_ref, char c) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        exit(1);
    }
    novo_no->caractere = c;
    novo_no->proximo = *topo_ref;
    *topo_ref = novo_no;
}

void pop(No** topo_ref) {
    if (*topo_ref == NULL) {
        return;
    }
    No* temp = *topo_ref;
    *topo_ref = (*topo_ref)->proximo;
    free(temp);
}

int main() {
    char expressao[1001];
    No* topo = NULL;

    while (scanf("%s", expressao) != EOF) {
        bool estaCorreto = true;

        for (int i = 0; i < strlen(expressao); i++) {
            if (expressao[i] == '(') {
                push(&topo, '(');
            } else if (expressao[i] == ')') {
                if (topo != NULL) {
                    pop(&topo);
                } else {
                    estaCorreto = false;
                    break;
                }
            }
        }

        if (estaCorreto && topo == NULL) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        while (topo != NULL) {
            pop(&topo);
        }
    }

    return 0;
}
