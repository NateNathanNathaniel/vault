#include<stdio.h>

float BMI(int w,int cm){
    float bmi= w/((cm/100.0)*(cm/100.0));
    return bmi;
}

int main () {
    int x, y;
    scanf("%d %d",&x,&y);
    float bmi=BMI(y,x);
    printf("%f",bmi);
    return 0;
}