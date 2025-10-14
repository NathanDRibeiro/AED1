#include <stdio.h>
#include <stdbool.h>


int stack[1001], top;
int queue[1001], front, rear;
int pq[1001], tamPQ; // pq = Priority Queue

void stack_push(int x) { stack[++top] = x; }
int stack_pop() { return (top < 0) ? -1 : stack[top--]; }

void queue_push(int x) { queue[rear++] = x; }
int queue_pop() { return (front >= rear) ? -1 : queue[front++]; }

void pq_push(int x) { pq[tamPQ++] = x; }
int pq_pop() {
    if (tamPQ == 0) return -1;
    int maxVal = -1, maxIdx = -1;

    // Na fila de prioridade, o maior sempre sai
    for (int i = 0; i < tamPQ; i++) {
        if (pq[i] > maxVal) {
            maxVal = pq[i];
            maxIdx = i;
        }
    }

    //  remover o maior sem bagunçar o array.
    if (maxIdx != -1) {
        pq[maxIdx] = pq[--tamPQ];
    }
    return maxVal;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        // Zera tudo para o próximo caso de teste.
        top = -1;
        front = 0; rear = 0;
        tamPQ = 0;

        // A tática: partimos do princípio que todas as estruturas são possíveis.
        // Se alguma delas errar a previsão, ela é eliminada.
        bool ePilha = true;
        bool eFila = true;
        bool ePQ = true;

        for (int i = 0; i < n; i++) {
            int comando, valor;
            scanf("%d %d", &comando, &valor);

            if (comando == 1) {
                stack_push(valor);
                queue_push(valor);
                pq_push(valor);
            } else {
                if (ePilha && stack_pop() != valor) ePilha = false;
                if (eFila && queue_pop() != valor) eFila = false;
                if (ePQ && pq_pop() != valor) ePQ = false;
            }
        }

        //vamos ver quantas candidatas sobraram.
        int candidatas = ePilha + eFila + ePQ;

        if (candidatas == 0) {
            printf("impossible\n");
        } else if (candidatas > 1) {
            printf("not sure\n");
        } else {
            if (ePilha) printf("stack\n");
            else if (eFila) printf("queue\n");
            else printf("priority queue\n");
        }
    }
    return 0;
}
