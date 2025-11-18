#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

int main() {
    int N, M;
    int fila[MAX];
    int saiu[100001] = {0}; // Para marcar quem saiu (índice = identificador)
    
    // Lê quantidade inicial de pessoas
    scanf("%d", &N);
    
    // Lê os identificadores iniciais
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }
    
    // Lê quantidade de pessoas que saíram
    scanf("%d", &M);
    
    // Lê e marca quem saiu
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        saiu[id] = 1; // Marca que esta pessoa saiu
    }
    
    // Imprime apenas quem não saiu
    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");
    
    return 0;
}
