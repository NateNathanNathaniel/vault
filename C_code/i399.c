#include <stdio.h>

void sortsize(int* addr_1, int* addr_2, int* addr_3);
void swap(int* addr_1, int* addr_2);

int main(){
    int p1, p2, p3;
    scanf("%d %d %d",&p1,&p2,&p3);
    sortsize (&p1,&p2,&p3);
    // printf("%d %d %d\n",p1,p2,p3);
    if(p1==p3){
        printf("%d %d",3,p1);
    }
    else if(p1==p2){
        printf("%d %d %d",2,p2,p3);
    }
    else if(p2==p3){
        printf("%d %d %d",2,p1,p2);
    }
    else {
        printf("%d %d %d %d",1,p1,p2,p3);
    }
    return 0;
}

void sortsize(int* addr_1, int* addr_2, int* addr_3){
    if(*addr_1>=*addr_2&&*addr_1>=*addr_3){
        // printf("In case 1\n");
        if(*addr_2<*addr_3){
            swap(addr_2,addr_3);
        }
    }
    else if(*addr_2>=*addr_1&&*addr_2>=*addr_3){
        // printf("In case 2\n");
        swap(addr_2, addr_1);
        if(*addr_2<*addr_3){
            swap(addr_2,addr_3);
        }
    }
    else if(*addr_3>=*addr_2&&*addr_3>=*addr_1){
        // printf("In case 3\n");        
        swap(addr_3, addr_1);
        // printf("%d %d %d\n",*addr_1,*addr_2,*addr_3);
        if(*addr_2<*addr_3){
            // printf("in\n");
            swap(addr_2,addr_3);
        }
    }    
}

void swap(int* addr_1, int* addr_2){
    // printf("In swap,before,%d %d\n",*addr_1, *addr_2);
    int placeholder=*addr_1;
    *addr_1=*addr_2;
    *addr_2=placeholder;
    // printf("In swap,after,%d %d\n",*addr_1, *addr_2);   
}
