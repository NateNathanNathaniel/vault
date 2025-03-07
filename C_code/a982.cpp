#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> maze(n, vector<char>(n));
    int dest_r= n-2;
    int dest_c= n-2;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char ch;
            cin >> ch;
            if(ch=='#'){
                maze[i][j]='#';
            }
            else if(ch=='.'){
                maze[i][j]='.';
            }
        }
    }

    queue<pair<pair<int,int>, int>> q;
    q.push({{1,1},1});
    maze[1][1]= '#';
    bool isFind=false;
    int ns[4][2]={{-1, 0},{1, 0},{0,1},{0,-1}};
    while(!q.empty()){
        int now_r=q.front().first.first;
        int now_c=q.front().first.second;
        int now_dist=q.front().second;
        q.pop();
        if(now_r==dest_r&&now_c==dest_c){
            isFind=true;
            cout << now_dist << endl;
            break;
        }
        for(int i=0; i<4; i++){
            int nR= now_r+ns[i][0];
            int nC= now_c+ns[i][1];
            if(nR>=n||nR<0||nC>=n||nC<0||maze[nR][nC]=='#'){
                continue;
            }
            q.push({{nR,nC},now_dist+1});
            maze[nR][nC]='#';
        }


    }
    if(isFind==false){
        cout << "No solution!" << endl;
    }
    return 0;
}   