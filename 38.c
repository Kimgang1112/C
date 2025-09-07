#include <stdio.h>

int adj[101][101];
int visited[101];
int n, m, infected;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) {
            infected++;   
            dfs(v);
        }
    }
}

int main(void) {
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;
    }
    infected = 0;
    dfs(1);
    printf("%d\n", infected);
    return 0;
}


