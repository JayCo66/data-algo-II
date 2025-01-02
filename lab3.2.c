//Quick Sort 6620501419
#include <stdio.h>

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

int BinarySearch(int n, int min, int max){
    if(max < min){
        return -1;
    }
    int mid = (min+max)/2;

    if(arr[mid] > n){
        return BinarySearch(n, min, mid-1);
    }else if(arr[mid] < n){
        return BinarySearch(n, mid+1, max);
    }else{
        return mid;
    }
}

int main(){
    quickSort(arr,0,size-1);

    int n;
    printf("Enter n:");
    scanf("%d",&n);

    int r = BinarySearch(n,0,size-1);
    if(r != -1){
        printf("Found");
    }else{
        printf("Not Found");
    }

    return 0;
}
