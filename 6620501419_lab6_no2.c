//6620501419 Tanavich Kotcharint 711
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int** MatrixChainOrder(int dims[],int n){
    int** m = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        m[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    for(int len=1; len<n; len++){
        for(int i=0; i<n-len; i++){
            int j=i+len;
            m[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int cost = m[i][k] + m[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                if(cost < m[i][j]){
                    m[i][j] = cost;
                }
            }
        }
    }
    return m;
}

int main(){
    int n;
    printf("Please input number of d :");
    scanf("%d",&n);
    
    int dims[n];
    for(int i=0; i<n; i++){
        printf("Enter d%d :",i);
        scanf("%d",&dims[i]);
    }

    int** C = MatrixChainOrder(dims,n);

    for(int i=0;i<n-1;i++){
        for(int k=0; k<i; k++){
            printf("\t");
        }
        for(int j=i; j<n-1; j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }

    printf("Minimum number of multiplications = %d",C[0][n-2]);
    
    for (int i = 0; i < n; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}