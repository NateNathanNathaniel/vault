#include <stdio.h>;
int main(){
    int n, x_prev, y_prev, x_now, y_now, max, min;
    scanf("%d",&n);
    scanf("%d %d",&x_prev, &y_prev);
    scanf("%d %d",&x_now, &y_now);
    int dis_x=x_now-x_prev;
    int dis_y=y_now-y_prev;
    if(dis_x<0){
        dis_x=-1*dis_x;
    }
    if(dis_y<0){
        dis_y=-1*dis_y;
    }
    int dis_now=dis_x+dis_y;
    x_prev=x_now;
    y_prev=y_now;   
    max=dis_now;
    min=dis_now;

    for(int i=0; i<n-2; i++){
        scanf("%d %d",&x_now, &y_now);
        dis_x=x_now-x_prev;
        dis_y=y_now-y_prev;
        if(dis_x<0){
            dis_x=-1*dis_x;
        }
        if(dis_y<0){
            dis_y=-1*dis_y;
        }
        dis_now=dis_x+dis_y;
        x_prev=x_now;
        y_prev=y_now;   
        if(dis_now>max){
            max=dis_now;
        }
        if(dis_now<min){
            min=dis_now;
        }        
    }

    printf("%d %d", max, min);

    return 0;
}