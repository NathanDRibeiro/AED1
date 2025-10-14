#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char expressao[1001];
    char pilha[1001];
    int topo;

    while (scanf("%s", expressao) != EOF) {
        topo = -1;
        bool estaCorreto = true;

        for (int i = 0; i < strlen(expressao); i++) {
            if (expressao[i] == '(') {
                topo++;
                pilha[topo] = '(';
            } else if (expressao[i] == ')') {
                if (topo >= 0) {
                    topo--;
                } else {
                    estaCorreto = false;
                    break;
                }
            }
        }

        if (estaCorreto && topo == -1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
