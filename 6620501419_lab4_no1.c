//6620501419 Tanavich Kotcharint 711
//O(n)
#include <stdio.h>
#include <stdlib.h>

struct activity{
    int id;
    int si;
    int fi;
};

int compare(const void* a, const void* b)
{
    return ((struct activity*)a)->fi - ((struct activity*)b)->fi;
}

void GreedyActivitySelect(struct activity arr[], int n){
    int j=0;
    printf("%d ",arr[j].id);
    for(int i=1; i<n; i++){
        if(arr[i].si >= arr[j].fi){
            printf("%d ",arr[i].id);
            j = i;
        }
    }
}

int main(){
    int n;
    printf("Input number of Activity (n) = ");
    scanf("%d",&n);
    struct activity data[n];
    int s, f;

    for(int i=0; i<n; i++){
            printf("Input Enter S and F of Activity %d = ",i+1);
            scanf("%d %d",&s,&f);
            data[i].id = i+1;
            data[i].si = s;
            data[i].fi = f;
    }

    qsort(data, n, sizeof(struct activity), compare);
    printf("Activities are selected n : ");
    GreedyActivitySelect(data,n);


return 0;
}
