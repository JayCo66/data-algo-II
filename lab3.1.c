//Quick Sort 6620501419
#include <stdio.h>

int level = 1;
int arr[] = {27,5,2,7,9,3,2,10};
int size = sizeof(arr)/sizeof(arr[0]);

void printArr(int A[],int s){
    for(int i=0; i<s; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int p = partition(array, low, high);
    printf("Rec : %d (Pivot Index = %d) = ",level,p);
    printArr(arr,size);
    level++;
    quickSort(array, low, p-1);
    quickSort(array, p+1, high);
  }
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int main(){
    printf("Given array is: ");
    printArr(arr,size);

    quickSort(arr,0,size-1);

    printf("Sorted array (Qucik Sort) :\n");
    printArr(arr,size);

    return 0;
}
