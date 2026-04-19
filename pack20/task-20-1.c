#include <stdio.h>
#include <stdlib.h>

// typedef struct {
//     int to;
// } Edge;

typedef struct {
    // int *to;
    int to;
    // int count;
} Graph;

// void add_edge(Graph *graph, int from, int to) {
//     graph[from].to[graph[from].count] = to;
//     graph[from].count++;
// }

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    Graph graph[n + 1];

    for (int i = 0; i < n + 1; i++) {
        // graph[i].to = malloc(sizeof(int) * (n + 1));
        // graph[i].count = 0;
        graph[i].to = -1;
    }

    for (int i = 0; i < m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        if (from <= to) {
            if (graph[from].to < to) graph[from].to = to;
        }

        // graph[from].to[graph[from].count] = to;
        // graph[from].count++;
        // add_edge(graph, from, to);
    }

    int ans[m + 2] = {};
    short check = 0;

    for (int i = 1; i < n + 1; i++) {
        if (graph[i].to != -1) {
            check = 1;
            ans[i] = 1;
            if (i >= graph[i].to) {
                ans[graph[i].to] = 1;
            }
            for (int j = i; j <= graph[i].to; j++) {
                ans[j] = 1;
            }
        }
    }

    if (check) {
        printf("YES\n");
    } else {
        printf("NO\n");
        return 0;
    }

    for (int i = 0; i < m + 2; i++) {
        if (ans[i] == 1) {
            printf("%d ", i);
        }
    }
}
