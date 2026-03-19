#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);

    int n, m; // количество вершин, количество дуг
    scanf("%d %d", &n, &m);

    int adjListSize[n + 1];
    int *adjList[n + 1];
    for (int i = 0; i <= n; i++) {
        adjListSize[i] = 0;
        adjList[i] = malloc(sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adjListSize[a]++;
        adjList[a] = realloc(adjList[a], adjListSize[a] * sizeof(int));
        adjList[a][adjListSize[a] - 1] = b;
    }

    int queue[n + 1];
    int visited[n + 1];
    int distant[n + 1];
    int front = 0, rear = 0;

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        distant[i] = -1;
    }

    distant[1] = 0;
    queue[rear] = 1;
    rear++;

    while (front != rear) {
        int a = queue[front];
        front++;
        visited[a] = 1;

        for (int i = 0; i < adjListSize[a]; i++) {
            int neighbor = adjList[a][i];
            if (distant[neighbor] == -1) {
                distant[neighbor] = distant[a] + 1;
                queue[rear] = neighbor;
                rear++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", distant[i]);
    }

    for (int i = 0; i <= n; i++) {
        free(adjList[i]);
    }

    return 0;
}
