#include <stdio.h>

int factorial(int num);
int fib(int num);

int main(){
    int total=1, n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        total=total*i;
    }
    printf("%d\n",total);
    printf("%d\n",factorial(n));
    printf("%d\n",fib(n));
    return 0;
}

int factorial(int num){
    if(num==1){
        return 1;
    }
    return factorial(num-1)*num;
}

int fib(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    return fib(num-1)+fib(num-2);
}