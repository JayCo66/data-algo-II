#include <stdio.h>

char x[] = "AGGTAB";
char y[] = "GXTXAYB";
int xSize = sizeof(x)/sizeof(x[0])+1;
int ySize = sizeof(y)/sizeof(y[0])+1;

void printArr(int ArrA[][ySize]){
    printf("  * G X T X A Y B\n");
    for(int i=0; i<xSize-1; i++){
        for(int j=0; j<ySize; j++){
            if(i==0 && j==0){
                printf("* ");
            }else if(j==0){
                printf("%c ",x[i-1]);
            }else{
                printf("%d ",ArrA[i][j-1]);
            }
        }
        printf("\n");
    }
}

void LCS(int c[][ySize],int b[][ySize]){
    for(int i=0; i<xSize; i++){
        for(int j=0; j<ySize; j++){
            if(i==0 || j==0){
                c[i][j] = 0;
                b[i][j] = 0;
            }else if(x[i-1] == y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 3;
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 2;
            }
        }
    }
}

int findLCS(char lcs[], int b[][ySize]){
    int i = xSize-1;
    int j = ySize-1;
    int length = 0;

    while(i>0 && j>0){
        if(b[i][j] == 3){
            lcs[length] = y[j-1];
            length++;
            i--;
            j--;
        }else if(b[i][j] == 2){
            j--;
        }else if(b[i][j] == 1){
            i--;
        }
    }
    return length;
}

int main(){

    int c[xSize][ySize];
    int b[xSize][ySize];
    LCS(c,b);

    printf("=== Array c===\n");
    printArr(c);
    printf("\n");

    printf("=== Array b===\n");
    printArr(b);
    printf("\n");

    char lcs[ySize];

    int length = findLCS(lcs,b);
    printf("Length of LCS is %d = (Reverse)",length-1);
    for(int i=0; i<length; i++){
        printf("%c ",lcs[i]);
    }
}
