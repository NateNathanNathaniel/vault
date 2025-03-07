#include <stdio.h>

int main(){
    int map[51][51], R, C, k, m;
    int next_step[4][2]={{-1,0},{0,-1},{1,0},{0,1}}; //up,left,down,right
    scanf("%d %d %d %d",&R, &C, &k, &m);
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            scanf("%d",&map[r][c]);
        }
    }
    for(int day=0; day<m; day++){
        int temp_map[51][51];
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                temp_map[r][c]=0;
            }
        }
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                for(int i=0;i<4;i++)
                {
                    int next_r=r+next_step[i][0];
                    int next_c=c+next_step[i][1];
                    if(next_r<0 || next_r>=R || next_c<0 || next_c>=C || map[next_r][next_c]==-1)
                    {
                        continue;
                    }
                    int shift=map[r][c]/k;
                    temp_map[next_r][next_c]+=shift;
                    temp_map[r][c]-=shift;
                    // 人口遷移
                }
            }
        }
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
               map[r][c]+=temp_map[r][c];
            }
        }
    }
    int most=-2147483648, least=2147483647;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(map[r][c]==-1){
                continue;
            }
            if(map[r][c]>most){
                most=map[r][c];
            }
            if(map[r][c]<least){
                least=map[r][c];
            }            
        }
    }  
    printf("%d\n%d", least, most);  
    return 0;
}