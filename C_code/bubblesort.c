#include <stdio.h>

int main(){
    int arr[10]={8, 100, 50, 22, 15, 6, 0, 1, 999,1000};
    int size=10;
    int count=0;
    int last_swap_index=size-1;
    for(int i=0; i<size-1; i++){

        int left=0;
        int new_last_swap_index=0;
        while(left<last_swap_index){
            count++;
            if(arr[left]>arr[left+1]){
                int placeholder=arr[left];
                arr[left]=arr[left+1];
                arr[left+1]=placeholder;
                new_last_swap_index=left;
            }
            left++;

        }
        last_swap_index=new_last_swap_index;
    }
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\ncheck %d times\n",count);
    return 0;
}