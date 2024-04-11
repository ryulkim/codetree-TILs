#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,m,ans=0;
int arr[505][505];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};
queue<pair<int,int>> q;

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m;
}

int bfs(int a, int b){
    q.push({a,b});
    int na,nb;
    int result=0;
    bool visit[505][505]={0,};
    visit[a][b]=1;

    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();
        result++;

        for(int i=0;i<4;i++){
            na=dr[i]+a;
            nb=dc[i]+b;

            if(!valid(na,nb)||visit[na][nb]) continue;

            if(arr[na][nb]){
                visit[na][nb]=1;
                q.push({na,nb});
            }
            
            
        }
    }

    return result;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][j]=1;
                ans=max(ans,bfs(i,j));
                arr[i][j]=0;
            }
        }
    }

    cout<<ans;

    return 0;
}