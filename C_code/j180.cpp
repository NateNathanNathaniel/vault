#include <iostream>
using namespace std;

int main(){
    int h, c;
    while(true){
        int days=0;
        cin >> h;
        if(h==-1){
            break;
        }
        cin >> c;
        int total=h*c;
        while(total>0){
            total=total-h;
            if(total%c==0){
                h=total/c;
            }
            else{
                h=total/c+1;
            }
            days++;
        }
        cout << days << endl;
    }
    return 0;
}