//6620501419 Tanavich Kotcharint
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    const int(*x)[3] = a;
    const int(*y)[3] = b;

    return (*x)[2] - (*y)[2];
}

void make_set(int parent[], int e){
    for (int i = 0; i < e; ++i) {
        parent[i] = i;
    }
}

int find_set(int parent[], int node) {
    if (parent[node] == node){
        return node;
    }

    return find_set(parent, parent[node]);
}

void union_set(int u, int v, int parent[], int n) {
    u = find_set(parent, u);
    v = find_set(parent, v);

    if (u != v) {
        parent[v] = u;
    }
}

void kruskalMST(int e, int edges[e][3]){
    qsort(edges, e, sizeof(edges[0]), compare);

    int parent[e];
    make_set(parent, e);

    int min_cost = 0;

    printf("\n\n===== MST =====\nEdge\tWeight\n");
    for (int i = 0; i < e; ++i){
        int u = find_set(parent, edges[i][0]);
        int v = find_set(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v) {
            union_set(u, v, parent, e);
            min_cost += w;
            printf("%d - %d\t %d\n",
                   edges[i][0], edges[i][1], w);
        }
    }
    printf("C = %d\n", min_cost);
}

int main(void){

    int V;
    int e;
    printf("Enter Number of Vertex:");
    scanf("%d", &V);
    printf("Enter Number of Edges:");
    scanf("%d", &e);

    int edges[e][3];

    for (int i = 0; i < e; ++i) {
        int u, v, w;
        printf("Edge %d u , v , w =",i);
        scanf("%d %d %d", &u, &v, &w);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    kruskalMST(e, edges);
    return 0;
}
