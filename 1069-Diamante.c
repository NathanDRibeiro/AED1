#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elementos{
    char data;
    struct Elemento* next;
} Elemento;

// função para empilhar
void push(Elemento **top, char c){
    
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo -> data = c;
    novo -> next = *top;
    *top = novo;
    
}

// função para desempilhar
char pop(Elemento **top){
    
    if(*top == NULL){
        return '\0';
    }
    Elemento *temp = *top;
    char c = temp -> data;
    *top = temp -> next;
    free(temp);
    return c;
}

// funçaõ que resolve um caso teste
int contaDiamante(char *linha){
    Elemento *stack = NULL;
    int diamantes = 0;
    for(int i = 0; linha[i] != '\0'; i++){
        
        if(linha[i] == '<'){
            push(&stack, '<');// empilha
        } else if(linha[i] == '>'){
            if(stack != NULL){ // há um '<' disponivel
                pop(&stack);
                diamantes++;
            }
        }
        
    }
    
    while(stack!= NULL) pop(&stack);
    
    return diamantes;
    
}



int main()
{   
    int N;
    scanf("%d", &N);
    getchar();
    
    for(int i =0; i < N; i++ ){
        char linha[1100];
        fgets(linha,sizeof(linha),stdin);
        
        linha[strcspn(linha,"\n")] = '\0';
        
        int resultado = contaDiamante(linha);
        printf("%d\n", resultado);
    }
    
    
    return 0;
}
