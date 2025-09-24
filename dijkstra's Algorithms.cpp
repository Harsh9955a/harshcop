#include <stdio.h>
#include <limits.h>
#define MAX 100
int main() {
    int n, src;
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    // initialize distance and visited arrays
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    // main Dijkstra loop
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        // pick the unvisited node with smallest distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        visited[u] = 1;
        // update distances of neighbors
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // print result
    printf("\nVertex \t Distance from Source %d\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
    return 0;
}