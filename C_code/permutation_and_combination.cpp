#include <iostream>
#include <vector>
using namespace std;
void help(){
    cout << "0: quit" << endl;
    cout << "1: full permutation" << endl;
    cout << "2: permutation" << endl;
    cout << "3: combination" << endl;
    cout << "4: all combination" << endl;
    cout << "Please enter a command" << endl;
}
void full_permutation(int n);
void permutation(int n, int k);
void combination(int n, int k);
void all_combination(int n);
void dfsfp(vector<int> visited, vector<int> current, int step, int n);
void dfsp(vector<int> visited, vector<int> current, int step, int n, int k);
void dfsc(vector<int> current, int n, int k, int now_idx);

int main(){
    int command=0;
    while(1){
        help();
        cin >> command;
        if(command==0){
            break;
        }
        else if(command==1){
            int n=0;
            cout << "Please enter n: ";
            cin >> n;
            full_permutation(n);
        }
        else if(command==2){
            int n=0, k=0;
            cout << "Please enter n and k: ";
            cin >> n >> k;
            permutation(n,k);
        }
        else if(command==3){
            int n=0, k=0;
            cout << "Please enter n and k: ";
            cin >> n >> k;
            combination(n,k);
        }
        else if(command==4){
            int n=0;
            cout << "Please enter n: ";
            cin >> n;
            all_combination(n);
        }
    }

}

void full_permutation(int n){
    vector<int> visited(n+1);
    vector<int> current;
    dfsfp(visited, current, 1, n);
    cout << endl;
}

void dfsfp(vector<int> visited, vector<int> current, int step, int n){
    if(step==n+1){
        for(int i=0; i<current.size(); i++){
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            current.push_back(i);
            visited[i]=1;
            dfsfp(visited, current, step+1, n);
            current.pop_back();
            visited[i]=0;
        }
    }
    return;
}

void permutation(int n, int k){
    vector<int> visited(n+1);
    vector<int> current;
    dfsp(visited, current, 1, n, k);
    cout << endl;
}

void dfsp(vector<int> visited, vector<int> current, int step, int n, int k){
    if(step==k+1){
        for(int i=0; i<current.size(); i++){
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            current.push_back(i);
            visited[i]=1;
            dfsp(visited, current, step+1, n, k);
            current.pop_back();
            visited[i]=0;
        }
    }
    return;
}

void combination(int n, int k){
    vector<int> current;
    dfsc(current, n, k, 1);
    cout << endl;
}

void all_combination(int n){
    for(int k=0; k<=n; k++){
        vector<int> current;
        dfsc(current, n, k, 1);      
    }
    cout << endl;
}

void dfsc(vector<int> current, int n, int k, int now_idx){
    if(current.size()==k){
        for(int i=0; i<current.size(); i++){
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=now_idx; i<=n; i++){
        current.push_back(i);
        dfsc(current, n, k, i+1);
        current.pop_back();
    }
    return;
}