#include <stdio.h>
int main (){
    int k, t, s, highScore=-1, highTime=0, failAmount=0, result;
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d %d", &t, &s);
        if(s>highScore){
            highScore = s;
            highTime = t;
        }
        else if(s==-1){
            failAmount ++;
        }
    }
    result= highScore-k-failAmount*2;
    if(result<0){
        result = 0;
    }
    printf("%d %d", result, highTime);
    return 0;
}