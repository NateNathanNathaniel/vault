#include <stdio.h>

int main () {
    int d1, d2;
    int array[6];
    for(int i=0; i<6; i++){
        array[i]=0;
    }
    for(int i=0; i<75; i++){
        scanf("%d %d", &d1, &d2);
        if(d2%2==0){
            array[d1-1]=((array[d1-1]+1)%10);
        }
        else{
            array[d1-1]=();
        }
    }
    for(int i=0; i<6; i++){
        printf("%d ",array[i]);
    }
    return 0;
}
