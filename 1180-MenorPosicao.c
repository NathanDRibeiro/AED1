#include <stdio.h>
 
int main() {
 
    int N, menorValor;
    scanf("%d",&N);
    
    int indice = 0;
    
    if(N > 1 && N < 1000){
    
        int X[N];

        for(int i = 0; i < N; i++){
            scanf("%d",&X[i]);
        }
    
        menorValor = X[0];
    
        for(int i = 0; i < N; i++){
            if( X[i] < menorValor){
                menorValor = X[i];
                indice = i;
            }
        }
    
        printf("Menor valor: %d\n", menorValor);
        printf("Posicao: %d\n", indice);
    
        } else{
            return 1;
        }
    
    return 0;
}
