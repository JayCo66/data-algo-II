#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int G[5][5] = {{0,10,0,5,0},
             {0,0,1,2,0},
             {0,0,0,0,4},
             {0,3,9,0,2},
             {7,0,6,0,0}};

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < 5; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int src){
    int d[5];
    bool s[5];
    int p[5];
    
    for (int i = 0; i < 5; i++)
        d[i] = INT_MAX, s[i] = false, p[i] = -1;
        
        
    d[src] = 0;
    
    for (int count = 0; count < 5 - 1; count++) {
        
        int u = minDistance(d, s);
        s[u] = true;

        for (int v = 0; v < 5; v++){
             if (!s[v] && G[u][v] && d[u] != INT_MAX && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                p[v] = u;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i != src) {
            printf("%d -> %d : distance = %d\n", p[i]+1, i + 1, d[i]);
        }
    }
}

int main() {
    int s;
    printf("enter initial vertex: ");
    scanf("%d",&s);
    dijkstra(s-1);

    return 0;
}