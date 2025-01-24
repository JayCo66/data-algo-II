#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void primMST(int nV, int G[nV][nV]){
    int d[nV], p[nV];
    bool inMST[nV];
    for(int i=0; i<nV; i++){
        d[i] = INT_MAX;
        inMST[i] = false;
    }
    d[0] = 0;
    p[0] = -1;
    for(int i=0; i<nV; i++){
        int u = minIndex(d,inMST,nV);
        inMST[u] = true;

        for(int j=0; j<nV; j++){
            if(G[u][j] && !inMST[j] && G[u][j] < d[j]){
                p[j] = u;
                d[j] = G[u][j];
            }
        }
    }
    printMST(p,nV,G);
}

int minIndex(int d[], bool inMST[],int nV){
   int min = INT_MAX, min_index;

    for (int i = 0; i < nV; i++){
        if (inMST[i] == false && d[i] < min){
            min = d[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[], int nV, int G[][nV]){
    int sumW = 0;
    printf("\n====MST====\n");
    printf("Edge \tWeight\n");

    for (int i = 1; i < nV; i++){
        printf("%d - %d \t%d \n", parent[i], i, G[i][parent[i]]);
        sumW += G[i][parent[i]];
    }
    printf("MST Weight = %d",sumW);
}

int main(){
    int Vertex, Edge;
    printf("Enter Number of Vertex:");
    scanf("%d",&Vertex);
    printf("Enter Number of Edges:");
    scanf("%d",&Edge);
    int Graph[Vertex][Vertex];
    int u,v,w;

    for (int i = 0; i < Vertex; i++) {
        for (int j = 0; j < Vertex; j++) {
            Graph[i][j] = 0;
        }
    }

    for(int i=0; i<Edge; i++){
        printf("Edge %d u , v , w = ",i+1);
        scanf("%d %d %d",&u,&v,&w);
        Graph[u][v] = w;
        Graph[v][u] = w;
    }
    primMST(Vertex,Graph);

return 0;
}
