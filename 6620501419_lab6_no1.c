//6620501419 Tanavich Kotcharint 711
int max(int A,int B){
    return A>B ? A:B;
}

#include <stdio.h>
int main(){
    int n,W;
    printf("Enter n,W:");
    scanf("%d %d",&n,&W);
    int val[n], wt[n];

    for(int i=0; i<n; i++){
        printf("enter value & weight of item %d:",i+1);
        scanf("%d %d",&val[i],&wt[i]);
    }

    int K[n+1][W+1];
    for(int i=0; i<=n; i++){
        for(int w=0; w<=W; w++){
            if(i==0 || w==0){
                K[i][w] = 0;
            }else if(wt[i-1] <= w){
                K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
            }else{
                K[i][w] = K[i-1][w];
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            printf("%d\t",K[i][j]);
        }
        printf("\n");
    }

    int x[n];
    for(int i=0; i<n; i++){
        x[i] = 0;
    }

    int i=n,j=W;
    while(i>0 && j>0){
        if(K[i][j] == K[i-1][j]){
            x[i-1] = 0;
            i--;
        }else{
            x[i-1] = 1;
            j = j-wt[i-1];
            i--;
        }
    }

    int last1;
    printf("knapsack contain items: ");
    for(int j=n-1; j>=0; j--){
        if(x[j] == 1){
            last1 = j;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(x[i] == 1){
            printf("%d",i+1);

            if(i != last1){
                printf(",");
            }
        }
    }
    
    printf("\nMaximum value: %d",K[n][W]);

    return 0;
}