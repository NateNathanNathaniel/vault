#include <stdio.h>

int main(){
    int a, b, n, howmany=0;
    scanf("%d %d %d",&a, &b, &n);
    for(int i=0; i<n; i++){
        int hasA=0, hasB=0;        
        while(1){
            int itemNo;
            scanf("%d",&itemNo);
            if(itemNo==0){
                break;
            }
            if(itemNo==a || itemNo==(-a)){
                hasA+=itemNo;
            }
            if(itemNo==b || itemNo==(-b)){
                hasB+=itemNo;
            }            
        }
        if(hasA>0&&hasB>0){
            howmany++;
        }
    }
    printf("%d",howmany);
    return 0;
}