#include <stdio.h>
#include <string.h>

#define MAX 1000

int visited[MAX];
int adj[MAX][MAX];
int degree[MAX];
int edgesVisited;

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < degree[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            edgesVisited++; // contamos a aresta (v,u) uma vez
            dfs(u);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int S, N, M;
        scanf("%d %d %d", &S, &N, &M);

        // limpar estruturas
        for (int i = 0; i < N; i++) {
            visited[i] = 0;
            degree[i] = 0;
        }

        // ler as arestas
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            adj[u][degree[u]++] = v;
            adj[v][degree[v]++] = u;
        }

        edgesVisited = 0;
        dfs(S);

        // cada aresta precisa ser percorrida duas vezes
        printf("%d\n", edgesVisited * 2);
    }

    return 0;
}
