#include <stdio.h>

int main(){
    int arr[5]={1,2,3,4,5};
    printf("%d\n",arr);
    for(int i=0;i<5;i++){
        printf("%d %d %d\n",arr[i], &arr[i], *(&arr[i]));
    }
    return 0;
}