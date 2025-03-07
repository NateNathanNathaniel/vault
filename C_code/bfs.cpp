#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int rows;
    cin >> rows;
    int des_x= rows-2;
    int des_y= rows-2;

    vector<vector<char>> maze(rows, vector<char>(rows));
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
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

    vector<vector<int>> queue;
    // vector<int> now;
    // now.push_back(1);
    // now.push_back(1);
    // now.push_back(1);
    queue.push_back({1,1,1});
    maze[1][1]='#';

    int flag=0;
    int next_step[4][2]={{-1, 0},{0, -1},{1, 0},{0, 1}};
    while(queue.size()>0){
        // vector<int> temp0= queue.front();
        int now_x= queue.front()[0];
        int now_y= queue.front()[1];
        int now_len= queue.front()[2];
        queue.erase(queue.begin());
        
        // cout << now_x << now_y << now_len << endl;
        if(now_x==des_x&&now_y==des_y){
            flag=1;
            cout << now_len << endl;
            break;
        }
        for(int i=0; i<4; i++){
            int next_x=now_x+next_step[i][0];
            int next_y=now_y+next_step[i][1];
            if(next_x<0||next_x>=rows||next_y<0||next_y>=rows||maze[next_x][next_y]!='.'){
                continue;
            }
            maze[next_x][next_y]='#';
            queue.push_back({next_x,next_y,now_len+1});
        }
    }

    if(flag==0){
        cout << "No solution!" << endl;
    }

    // cout << "\nmaze:" << endl;
    // for(int i=0; i<rows; i++){
    //     cout << maze[i] << endl;
    // }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <deque>
// using namespace std;

// int main() {
//     int rows;
//     cin >> rows;
//     cin.ignore();

//     // Destination point
//     int des_x = rows - 2;
//     int des_y = rows - 2;

//     vector<string> maze(rows);
//     for (int i = 0; i < rows; i++) {
//         getline(cin, maze[i]);
//     }

//     if (maze[1][1] == '#' || maze[des_x][des_y] == '#') {
//         cout << "No solution!" << endl;
//         return 0;
//     }

//     deque<vector<int>> queue;
//     queue.push_back({1, 1, 1});
//     maze[1][1] = '#'; // Mark as visited

//     int next_step[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//     bool found = false;

//     while (!queue.empty()) {
//         auto current = queue.front();
//         queue.pop_front();

//         int now_x = current[0];
//         int now_y = current[1];
//         int now_len = current[2];

//         if (now_x == des_x && now_y == des_y) {
//             found = true;
//             cout << now_len << endl;
//             break;
//         }

//         for (int i = 0; i < 4; i++) {
//             int next_x = now_x + next_step[i][0];
//             int next_y = now_y + next_step[i][1];

//             if (next_x < 0 || next_x >= rows || next_y < 0 || next_y >= rows || maze[next_x][next_y] == '#') {
//                 continue;
//             }

//             maze[next_x][next_y] = '#'; // Mark as visited
//             queue.push_back({next_x, next_y, now_len + 1});
//         }
//     }

//     if (!found) {
//         cout << "No solution!" << endl;
//     }

//     return 0;
// }
