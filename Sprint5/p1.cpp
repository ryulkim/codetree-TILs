#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int h,w,a,b,na,nb;
int arr[505][505];
long long dp[505][505];
int indegree[505][505];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};
queue<pair<int, int>> q;

bool valid(int i, int j){
    return i>=0&&i<h&&j>=0&&j<w;
}

void proc(int r, int c){

    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            na=a+dr[i];
            nb=b+dc[i];
        
            if(valid(na,nb)&&arr[na][nb]>arr[a][b]){
                indegree[na][nb]--;
                dp[na][nb]+=dp[a][b];
                dp[na][nb]%=1000000007;

                if(!indegree[na][nb]){
                    q.push({na,nb});
                }
            }
        }
    }
}

int main() {
    cin>>h>>w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int k=0;k<4;k++){
                int a=i+dr[k];
                int b=j+dc[k];

                if(valid(a,b)&&arr[a][b]>arr[i][j]){
                    indegree[a][b]++;
                }
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!indegree[i][j]) q.push({i,j});
        }
    }

    dp[h-1][w-1]=1;

    proc(h-1,w-1);

    cout<<dp[0][0]<<'\n';

    return 0;
}
