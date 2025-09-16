#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX];
bool visited[MAX];
int N;
void DFS(int start) {
    visited[start] = true;
    printf("%d ", start);
    for (int i = 0; i < N; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
bool isConnected() {
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    DFS(0);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    printf("Enter number of cities: ");
    scanf("%d", &N);
    printf("Enter adjacency matrix (row-wise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int startNode;
    printf("Enter starting node for DFS (0 to %d): ", N-1);
    scanf("%d", &startNode);
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    printf("Nodes reachable from node %d: ", startNode);
    DFS(startNode);
    printf("\n");
    if (isConnected()) {
        printf("The graph is connected (all nodes reachable from node 0).\n");
    } else {
        printf("The graph is NOT connected.\n");
    }
    return 0;
}