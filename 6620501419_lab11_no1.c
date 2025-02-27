//Tanavich Kotcharint 6620501419
#include <stdio.h>

#define INF 99999

void floydWarshall(int V, int G[][V]){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
        printf("D[%d]\n",k+1);
        for(int a=0; a<V; a++){
            for(int b=0; b<V; b++){
                if(G[a][b] > 10000){
                    printf("\tINF");
                }else{
                    printf("\t%d",G[a][b]);
                }
            }
            printf("\n");
        }
    }
}

int main(){
    int V,E;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);
    printf("Enter edges Cost (u,v,w)\n");

    int G[V][V];

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i == j){
                G[i][j] = 0;
            }else{
                G[i][j] = INF;
            }
        }
    }

    for(int i=0; i<E; i++){
        int u,v,w;
        scanf("%d %d %d",&u, &v, &w);
        G[u-1][v-1] = w;
    }
    floydWarshall(V,G);

    return 0;
}
