#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int left, int right, int* arr);
void bubblesort(int* arr_copy, int array_size);

int main(){
    srand(time(NULL));
    int arr_size;
    scanf("%d",&arr_size);
    int* arr=(int*)malloc(arr_size*sizeof(int));
    int* arr_copy=(int*)malloc(arr_size*sizeof(int));
    for(int i=0;i<arr_size;i++)
    {
        arr[i]=(rand()%arr_size)+1;
        arr_copy[i]=arr[i];
    }

    // for(int i=0;i<arr_size;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    double start, duration;
    start= ((double)clock());
    quicksort(0,arr_size-1,arr);
    duration= ((double)clock()-start)/CLOCKS_PER_SEC;
    // for(int i=0;i<arr_size;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    printf("Quick sort took %f secs\n",duration);

    start= ((double)clock());
    bubblesort(arr_copy, arr_size);
    duration= ((double)clock()-start)/CLOCKS_PER_SEC;
    // for(int i=0;i<arr_size;i++)
    // {
    //     printf("%d ",arr_copy[i]);
    // }
    // printf("\n");
    printf("Bubble sort took %f secs\n",duration);
    return 0;
}

void quicksort(int left, int right, int* arr){
    if(left>right)
    {
        // printf("Oops !!! \nleft = %d, right = %d\n",left,right);
        return;
    }
    int pivot=left;
    int i=left;
    int j=right;
    while(i<j){
        while(j>i&&arr[j]>=arr[pivot]){
            j--;
        }
        while(j>i&&arr[i]<=arr[pivot]){
            i++;
        }    
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
    }
    int placeholder=arr[pivot];
    arr[pivot]=arr[i];
    arr[i]=placeholder;
    // printf("left = %d, right = %d\n",left,right);
    quicksort(left,i-1,arr);
    quicksort(i+1,right,arr);
    return;
}

void bubblesort(int* arr_copy, int array_size){
    for(int i=0; i<array_size-1; i++){
        for(int left=0; left<array_size-1; left++){
            if(arr_copy[left]>arr_copy[left+1]){
                int temp=arr_copy[left];
                arr_copy[left]=arr_copy[left+1];
                arr_copy[left+1]=temp;
            }
        }
    }
}