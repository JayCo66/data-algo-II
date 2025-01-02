//6620501419 Tanavich Kotcharint
//O(n)
#include <stdio.h>
#include <stdlib.h>

struct X{
    float Wt;
    float Val;
    float Scale;
    float num
};

void GreedyKnapsack(struct X arr[], int n, int W){
    int sumW = 0;
    float maxV = 0;
    for(int i=0; i<n && sumW < W; i++){
        if(sumW + arr[i].Wt <= W){
            arr[i].num = 1;
        }else{
            arr[i].num = (W-sumW)/arr[i].Wt;
        }
        sumW += arr[i].num * arr[i].Wt;
    }

    printf("The results of xi is: ");
    for(int i=0; i<n; i++){
        printf("%.2f ",arr[i].num);
        maxV += arr[i].num*arr[i].Val;
    }

    printf("\nMaximum value is: %.2f",maxV);
}

int main(){
    struct X arr[4];
    arr[0].Wt = 1;
    arr[1].Wt = 2;
    arr[2].Wt = 4;
    arr[3].Wt = 5;

    arr[0].Val = 5;
    arr[1].Val = 4;
    arr[2].Val = 8;
    arr[3].Val = 6;

    arr[0].Scale = arr[0].Val/arr[0].Wt;
    arr[1].Scale = arr[1].Val/arr[1].Wt;
    arr[2].Scale = arr[2].Val/arr[2].Wt;
    arr[3].Scale = arr[3].Val/arr[3].Wt;

    GreedyKnapsack(arr,4,6);


    return 0;
}
