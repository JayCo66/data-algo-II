#include <stdio.h>

int main(){
    int X[] = {5,10,20,30,30};
    int n = sizeof(X)/sizeof(X[0]);
    int cost = 0;

    while(n>1){
        int mergecost = X[0] + X[1];
        cost += mergecost;

        for(int i=2; i<n; i++){
            X[i-2] = X[i];
        }
        n -= 2;

        int pos = n;
        for(int i=0; i<n; i++){
            if (mergecost <= X[i]){
                pos = i;
                break;
            }
        }

        for(int i = n; i > pos; i--){
            X[i] = X[i-1];
        }
        X[pos] = mergecost;
        n++;
    }

    printf("total cost = %d", cost);
}