#include <stdio.h>
#include <string.h>

int main() {
    char expressao[1001];

    while (scanf("%s", expressao) != EOF) {
        int contadorParenteses = 0;

        for (int i = 0; i < strlen(expressao); i++) {
            if (expressao[i] == '(') {
                contadorParenteses++;
            } else if (expressao[i] == ')') {
                contadorParenteses--;
            }

            if (contadorParenteses < 0) {
                break;
            }
        }

        if (contadorParenteses == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
