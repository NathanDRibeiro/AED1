#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Biblioteca para alocação dinâmica

bool verificaConjunto(int *numeros) {
    bool *vistos = (bool *)calloc(10, sizeof(bool));
    if (vistos == NULL) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        return false;
    }

    for (int k = 0; k < 9; k++) {
        int num = numeros[k];
        if (num < 1 || num > 9 || vistos[num]) {
            free(vistos); // Libera a memória antes de retornar
            return false;
        }
        vistos[num] = true;
    }

    free(vistos); // Libera a memória alocada
    return true;
}

int main() {
    int num_instancias;
    scanf("%d", &num_instancias);

    for (int i = 1; i <= num_instancias; i++) {
        // --- Alocação Dinâmica para a Grade 9x9 ---
        // Aloca um array de ponteiros para as linhas
        int **grade = (int **)malloc(9 * sizeof(int *));
        if (grade == NULL) return 1;

        //Para cada linha, aloca um array de inteiros para as colunas.
        for (int j = 0; j < 9; j++) {
            grade[j] = (int *)malloc(9 * sizeof(int));
            if (grade[j] == NULL) return 1;
        }

        for (int linha = 0; linha < 9; linha++) {
            for (int coluna = 0; coluna < 9; coluna++) {
                scanf("%d", &grade[linha][coluna]);
            }
        }

        bool eh_valido = true;

        int *valores_temp = (int *)malloc(9 * sizeof(int));
        if (valores_temp == NULL) return 1;


        // Verificação de Linhas
        for (int linha = 0; linha < 9; linha++) {
            for (int coluna = 0; coluna < 9; coluna++) {
                valores_temp[coluna] = grade[linha][coluna];
            }
            if (!verificaConjunto(valores_temp)) {
                eh_valido = false;
                break;
            }
        }

        // Verificação de Colunas
        if (eh_valido) {
            for (int coluna = 0; coluna < 9; coluna++) {
                for (int linha = 0; linha < 9; linha++) {
                    valores_temp[linha] = grade[linha][coluna];
                }
                if (!verificaConjunto(valores_temp)) {
                    eh_valido = false;
                    break;
                }
            }
        }

        // Verificação de Blocos 3x3
        if (eh_valido) {
            for (int inicio_linha_bloco = 0; eh_valido && inicio_linha_bloco < 9; inicio_linha_bloco += 3) {
                for (int inicio_coluna_bloco = 0; eh_valido && inicio_coluna_bloco < 9; inicio_coluna_bloco += 3) {
                    int k = 0;
                    for (int linha = inicio_linha_bloco; linha < inicio_linha_bloco + 3; linha++) {
                        for (int coluna = inicio_coluna_bloco; coluna < inicio_coluna_bloco + 3; coluna++) {
                            valores_temp[k++] = grade[linha][coluna];
                        }
                    }
                    if (!verificaConjunto(valores_temp)) {
                        eh_valido = false;
                    }
                }
            }
        }

        printf("Instancia %d\n", i);
        if (eh_valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        // Liberando memoria 
        free(valores_temp);

      
        // Libera cada uma das linhas da grade.
        for (int j = 0; j < 9; j++) {
            free(grade[j]);
        }
       // Libera o array de ponteiros que apontava para as linhas.
        free(grade);
    }

    return 0;
}
