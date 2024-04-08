#include <iostream>
#include <vector>
#include <queue>
#define SZ 55
using namespace std;

int n,x,ans=0;
vector<int> v[SZ];
bool visit[SZ];


void bfs(int st){
    queue<int> q;
    q.push(st);
    visit[st]=1;

    while(!q.empty()){
        int a=q.front();
        int sz=v[a].size();
        q.pop();
        
        if(a!=0&&sz==0) ans++;

        for(int i=0;i<sz;i++){
            int b=v[a][i];
            if(!visit[b]) {
                q.push(b);
                visit[b]=1;
            }
        }
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(x==-1) continue;
        v[i].push_back(x);
        v[x].push_back(i);
    }

    cin>>x;
    v[x].clear();

    bfs(0);

    cout<<ans;

    return 0;
}