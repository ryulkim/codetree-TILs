#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m;
int arr[305][305];
int temp[305][305];
int chk[305][305];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};


void erase(){
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(!arr[i][j]) continue;
            int cnt=0;
            for(int k=0;k<4;k++){
                if(!arr[i+dr[k]][j+dc[k]]) cnt++;
            }

            temp[i][j]=max(arr[i][j]-cnt,0);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=temp[i][j];
        }
    }

}

void bfs(int a, int b){
    
    queue<pair<int,int>> q;
    q.push({a,b});

    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nr=a+dr[i];
            int nc=b+dc[i];
            if(arr[nr][nc]!=0&&chk[nr][nc]==0){
                chk[nr][nc]=1;
                q.push({nr, nc});
            }
        }
    }
}

int proc(){
    int cnt=0;

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(arr[i][j]&&!chk[i][j]){
                if(cnt!=0) return 1;
                cnt++;
                bfs(i,j);
            }
        }
    }

    if(cnt==0) return 2;

    return 0;

}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int turn=0;

    while(true){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                chk[i][j]=0;
            }
        }
        
        int result=proc();
        
        if(result==1) {
            cout<<turn;
            break;
        }
        else if(result==2){
            cout<<0;
            break;
        }
        erase();
        turn++;
    }

    return 0;
}