#include <stdio.h>

int max(int maxDiff, int diff){
    if(maxDiff>diff){
        return maxDiff;
    }
    else{
        return diff;
    }
}

int main(){
    int n, w1, h1, w2, h2, volume, maxDiff=-999, currentHeight=0, currentV=0, diff=0;
    scanf("%d", &n);
    scanf("%d %d %d %d", &w1, &w2, &h1, &h2);
    int remain=w1*w1*h1;
    for(int i=1; i<=n; i++){
        scanf("%d", &currentV);
        if(currentHeight<h1){
            remain=w1*w1*(h1-currentHeight);
            if(currentV>remain){
                int remainCurrentV=currentV-remain;
                if(remainCurrentV>=w2*w2*h2){
                    diff= h1-currentHeight+h2;
                    currentHeight=h1+h2;                   
                    maxDiff= max(maxDiff, diff);
                    // printf("bigbig %d\n", diff);
                }
                else{
                    diff= (h1-currentHeight)+(remainCurrentV/(w2*w2));
                    // printf("bigtwo %d\n", diff);  
                    maxDiff= max(maxDiff, diff);                 
                    currentHeight=currentHeight+diff;
                }
            }
            else{
                diff=currentV/(w1*w1);
                maxDiff= max(maxDiff, diff);
                // printf("one %d\n", diff);                
                currentHeight= currentHeight+diff;
            }
        }
        else if(currentHeight<h1+h2){
            remain= w2*w2*(h1+h2-currentHeight);
            if(currentV>remain){
                diff= h1+h2-currentHeight;
                maxDiff= max(maxDiff, diff);
                // printf("twobig %d\n", diff);                
                currentHeight=h1+h2;
            }
            else{
                diff= currentV/(w2*w2);
                maxDiff= max(maxDiff, diff);
                // printf("two %d\n", diff);               
                currentHeight= currentHeight+diff;
            }
        }
        else{
            break;
        }
    }
    printf("%d\n", maxDiff);
    return 0;
}