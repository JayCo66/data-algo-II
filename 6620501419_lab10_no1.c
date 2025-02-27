#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Edge {
    int s, d, w;
};

struct Edge G[] = {
    {1, 2, 10}, {1, 4, 5}, {2, 3, 1}, {2, 4, 2},
    {3, 5, 4}, {4, 2, 3}, {4, 3, 9}, {4, 5, 2},
    {5, 1, 7}, {5, 3, 6}
};

void BellmanFord(int s) {
    bool hasNegativeCycle = false;
    int d[6], p[6];
    int numVertices = 5;
    int numEdges = sizeof(G) / sizeof(G[0]);

    for (int i = 1; i <= numVertices; i++) {
        d[i] = INT_MAX;
        p[i] = -1;
    }
    d[s] = 0;

    printf("\nArray d =\n\n");
    printf("i\t1\t2\t3\t4\t5\n");

    for (int i = 1; i <= numVertices - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = G[j].s;
            int v = G[j].d;
            int w = G[j].w;
            if (d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }

        printf("%d\t", i);
        for (int k = 1; k <= numVertices; k++) {
            if (d[k] == INT_MAX)
                printf("9999\t");
            else
                printf("%d\t", d[k]);
        }
        printf("\n");
    }

    for (int j = 0; j < numEdges; j++) {
        int u = G[j].s;
        int v = G[j].d;
        int w = G[j].w;
        if (d[u] != INT_MAX && d[v] > d[u] + w) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Contain Negative cycle!!\n");
    } else {
        printf("Not contain Negative cycle\n");
    }
}

int main() {
    int s;
    printf("Enter initial vertex: ");
    scanf("%d", &s);

    if (s < 1 || s > 5) {
        printf("Invalid vertex. Please enter a number between 1 and 5.\n");
        return 1;
    }

    BellmanFord(s);
    return 0;
}
