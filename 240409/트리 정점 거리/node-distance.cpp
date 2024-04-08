#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define SZ 1005
using namespace std;

int n,m,a,b,c;
vector<pair<int,int>> v[SZ];

int bfs(int st){
    queue<pair<int,int>> q;
    q.push({st,0});
    bool visit[SZ]={0,};
    visit[st]=1;
    int x,y,nx,ny;

    while(!q.empty()){
        tie(x,y)=q.front();
        q.pop();
        int sz=v[x].size();

        if(x==b) return y;

        for(int i=0;i<sz;i++){
            tie(nx,ny)=v[x][i];
            if(!visit[nx]){
                visit[nx]=1;
                q.push({nx,ny+y});
            }
        }
    }

    return 0;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<bfs(a)<<'\n';
    }
    return 0;
}