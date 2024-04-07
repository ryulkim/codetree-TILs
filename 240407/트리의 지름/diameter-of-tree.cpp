#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define SZ 100005
using namespace std;

int n,a,b,c,x;
vector<pair<int,int>> v[SZ];
int ans=0, node;

void bfs(int st){
    queue<pair<int,int>> q;
    bool visit[SZ]={0,};

    q.push({st, 0});
    visit[st]=1;

    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();
        int sz=v[a].size();

        for(int i=0;i<sz;i++){
            tie(c,x)=v[a][i];
            if(!visit[c]){
                visit[c]=1;
                q.push({c,b+x});
                if(ans<b+x){
                    node=c;
                    ans=b+x;
                }
            }
        }
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    bfs(1);
    ans=0;
    bfs(node);

    cout<<ans;

    return 0;
}