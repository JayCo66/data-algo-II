//Recursion 328033
//Iterative 315527
#include <stdio.h>

int PascalsTriangle (int n , int k){
    if(k==0 || k==n){
        return 1;
    }else {
        return PascalsTriangle(n-1,k-1) + PascalsTriangle(n-1,k);
    }
}

int main(){
for(int n=0; n<6; n++){
    for(int k=0; k<n+1; k++){
        printf("%d ",PascalsTriangle(n,k));
    }
    printf("\n");
}
return 0;
}
