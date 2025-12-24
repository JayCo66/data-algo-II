#include <stdio.h>

int X[] = {5, 10, 20, 30, 30};
int n = sizeof(X) / sizeof(X[0]);

int optimalMerge(int X[], int n) {
    int totalCost = 0;

    while (n > 1) {
        int first = X[0];
        int second = X[1];
        int newSize = first + second;

        totalCost += newSize;
        
        int inserted = 0;
        int r = 2;
        
        for (int i = 0; i < n - 1; i++) {
            if (!inserted && (r == n || newSize < X[r])) {
                X[i] = newSize;
                inserted = 1;
            } else {
                X[i] = X[r];
                r++;
            }
        }
        n--;
    }

    return totalCost;
}

int main() {
    printf("Total Cost = %d", optimalMerge(X, n));
    return 0;
}