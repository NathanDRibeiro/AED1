#include <stdio.h>
#include <stdbool.h>

bool verificaConjunto(int numeros[]) {
    bool vistos[10] = {false};

    for (int k = 0; k < 9; k++) {
        int num = numeros[k];
        if (num < 1 || num > 9 || vistos[num]) {
            return false;
        }
        vistos[num] = true;
    }

    for (int k = 1; k <= 9; k++) {
        if (!vistos[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    int num_instancias;
    scanf("%d", &num_instancias);

    for (int i = 1; i <= num_instancias; i++) {
        int grade[9][9];
        for (int linha = 0; linha < 9; linha++) {
            for (int coluna = 0; coluna < 9; coluna++) {
                scanf("%d", &grade[linha][coluna]);
            }
        }

        bool eh_valido = true;

        // Verificação de Linhas
        for (int linha = 0; linha < 9; linha++) {
            int valores_linha[9];
            for (int coluna = 0; coluna < 9; coluna++) {
                valores_linha[coluna] = grade[linha][coluna];
            }
            if (!verificaConjunto(valores_linha)) {
                eh_valido = false;
                break;
            }
        }

        if (!eh_valido) {
            printf("Instancia %d\n", i);
            printf("NAO\n\n");
            continue;
        }

        // Verificação de Colunas
        for (int coluna = 0; coluna < 9; coluna++) {
            int valores_coluna[9];
            for (int linha = 0; linha < 9; linha++) {
                valores_coluna[linha] = grade[linha][coluna];
            }
            if (!verificaConjunto(valores_coluna)) {
                eh_valido = false;
                break;
            }
        }

        if (!eh_valido) {
            printf("Instancia %d\n", i);
            printf("NAO\n\n");
            continue;
        }

        // Verificação de Blocos 3x3
        for (int inicio_linha_bloco = 0; inicio_linha_bloco < 9; inicio_linha_bloco += 3) {
            for (int inicio_coluna_bloco = 0; inicio_coluna_bloco < 9; inicio_coluna_bloco += 3) {
                int valores_bloco[9];
                int k = 0;

                for (int linha = inicio_linha_bloco; linha < inicio_linha_bloco + 3; linha++) {
                    for (int coluna = inicio_coluna_bloco; coluna < inicio_coluna_bloco + 3; coluna++) {
                        valores_bloco[k++] = grade[linha][coluna];
                    }
                }
                if (!verificaConjunto(valores_bloco)) {
                    eh_valido = false;
                    break;
                }
            }
            if (!eh_valido) {
                break;
            }
        }

        printf("Instancia %d\n", i);
        if (eh_valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
