#include <stdio.h>

int F(int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return F(n-1)+F(n-2);
    }
}

int main() {
    for(int i=0; i<100; i++){
        printf("%d ", F(i));
    }

    return 0;
}
