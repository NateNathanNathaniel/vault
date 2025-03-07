#include <stdio.h>

void rofo(int* addr);
void rori(int* addr);

int main(){
    int dice[20][6];
    int mapping[20];
    int n, m, a, b;
    scanf("%d %d",&n, &m);
    for(int i=0; i<n; i++){
        dice[i][0]=4;
        dice[i][1]=3;
        dice[i][2]=1;
        dice[i][3]=6;
        dice[i][4]=5;
        dice[i][5]=2;  
        mapping[i]=i;          
    }
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        if(a>0&&b>0){
            int placeholder=mapping[b-1];
            mapping[b-1]=mapping[a-1];
            mapping[a-1]=placeholder;
        }
        else{
            int realDice=mapping[a-1];
            if(b==-1){
                rofo(dice[realDice]);
                // printf("rofo\n");
            }
            if(b==-2){
                rori(dice[realDice]);
                // printf("rori\n");                
            }
        }
    }
    int realDice= mapping[0];  

    printf("%d",dice[realDice][2]);
    for(int i=1; i<n; i++){
        realDice= mapping[i];          
        printf(" %d",dice[realDice][2]);
    }   
    return 0;
}

void rofo(int* addr){
    int temp[6];
    temp[0]=*(addr+2);
    temp[2]=*(addr+1);   
    temp[1]=*(addr+3);
    temp[3]=*addr; 
    *addr=temp[0];
    *(addr+1)=temp[1];    
    *(addr+2)=temp[2]; 
    *(addr+3)=temp[3];         
}
void rori(int* addr){
    int temp[6];
    temp[2]=*(addr+4);
    temp[3]=*(addr+5);   
    temp[4]=*(addr+3);
    temp[5]=*(addr+2); 
    *(addr+2)=temp[2];
    *(addr+3)=temp[3];    
    *(addr+4)=temp[4]; 
    *(addr+5)=temp[5];  
}