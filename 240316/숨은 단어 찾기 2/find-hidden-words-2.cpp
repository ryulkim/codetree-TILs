#include <iostream>
using namespace std;

int n,m;
string s;
char arr[55][55];
int dr[10]={0,1,1,1,0,-1,-1,-1};
int dc[10]={1,1,0,-1,-1,-1,0,1};

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m;
}

int direct(int d, int i, int j){
    for(int i=0;i<2;i++){
        i+=dr[d];
        j+=dc[d];
        if(!valid(i,j)) return false;
        if(arr[i][j]!='E') return false;
    }
    return true;
}

int proc(){
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!='L') continue;
            for(int k=0;k<8;k++){
                if(direct(k, i, j)) {
                    //cout<<i<<' '<<j<<'\n';
                    num++;
                }
            }
        }
    }
    return num;
}


int main() {
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<proc();

    return 0;
}