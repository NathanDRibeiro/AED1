#include <stdio.h>

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        int fila[100];
        int inicio = 0, fim = n - 1;
        
        for (int i = 0; i < n; i++) {
            fila[i] = i + 1;
        }
        
        printf("Discarded cards:");
        
        int primeiro = 1;
        
        while (fim - inicio >= 1) {
            if (primeiro) {
                printf(" %d", fila[inicio]);
                primeiro = 0;
            } else {
                printf(", %d", fila[inicio]);
            }
            inicio++;
            
            fila[++fim] = fila[inicio];
            inicio++;
        }
        
        printf("\nRemaining card: %d\n", fila[inicio]);
    }
    
    return 0;
}
