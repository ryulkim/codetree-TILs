#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,m,ans=0;
int arr[505][505];
int visit[505][505];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};
queue<pair<int,int>> q;
int group=1;
int group_size[250005];

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m;
}

int bfs(int a, int b){
    q.push({a,b});
    int na,nb;
    int result=0;
    visit[a][b]=group;

    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();
        result++;

        for(int i=0;i<4;i++){
            na=dr[i]+a;
            nb=dc[i]+b;

            if(!valid(na,nb)||visit[na][nb]) continue;

            if(arr[na][nb]){
                visit[na][nb]=group;
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
            if(arr[i][j]==1&&!visit[i][j]){
                group_size[group]=bfs(i,j);
                group++;
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<visit[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<n;i++){
        bool check[250000]={0,};
        for(int j=0;j<m;j++){
            int sum=1;
            if(arr[i][j]==0){
                for(int k=0;k<4;k++){
                    int na=dr[k]+i;
                    int nb=dc[k]+j;

                    if(!valid(na,nb)||!arr[na][nb]||check[visit[na][na]]) continue;

                    if(!check[visit[na][nb]]){
                        //cout<<sum<<' '<<"gz"<<' '<<group_size[visit[na][nb]]<<'\n';
                        sum+=group_size[visit[na][nb]];
                        
                        check[visit[na][nb]]=1;
                    }
                }
                //cout<<"a: "<<i<<' '<<j<<' '<<sum<<'\n';
                ans=max(ans,sum);
            }
        }
    }



    cout<<ans;

    return 0;
}