#include <stdio.h>

int main(){
    int a1, b1, c1, a2, b2, c2, n, optimalSolution=-2147483648;
    scanf("%d %d %d %d %d %d %d",&a1, &b1, &c1, &a2, &b2, &c2, &n);
    for(int i=0; i<=n; i++){
        int x1=i;
        int x2=(n-i);
        int current=a1*x1*x1+b1*x1+c1+a2*x2*x2+b2*x2+c2;
        if(current>optimalSolution){
            optimalSolution=current;
        }
    }
    printf("%d",optimalSolution);
    return 0;
}