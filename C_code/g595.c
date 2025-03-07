#include <stdio.h>

int main(){
    int array[100]={0};
    int n, totalCost=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&array[i]);
    }
    if(array[0]==0){
        totalCost+=array[1];
    }
    if(array[n-1]==0){
        totalCost+=array[n-2];
    }    
    for(int i=1; i<n-1; i++){
        if(array[i]==0){
            if(array[i-1]>=array[i+1]){
                totalCost+=array[i+1];
            }
            else{
                totalCost+=array[i-1];
            }
        }
    }
    printf("%d",totalCost);
    return 0;
}