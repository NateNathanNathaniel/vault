#include <stdio.h>

int main(){
    int n, x, d, y, hold, profit=0;
    scanf("%d %d",&n, &d);
    scanf("%d", &x);
    hold=1;
    for(int i=1; i<n; i++){
        scanf("%d",&y);        
        if(hold==1){
            if(y>=x+d){
                profit+=y-x;
                x=y;
                hold=0;
            }
        }
        else if(hold==0){
            if(y<=x-d){
                x=y;
                hold=1;
            }
        }
    }
    printf("%d",profit);
    return 0;
}