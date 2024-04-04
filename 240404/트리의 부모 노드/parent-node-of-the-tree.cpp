#include <iostream>
#include <vector>
#include <queue>
#define SZ 100005
using namespace std;

int n,u,w;
vector<int> v[SZ];
bool visit[SZ];
int par[SZ];
queue<int> q;

void proc(int st){
    q.push(st);
    visit[st]=1;

    while(!q.empty()){
        int a=q.front();
        q.pop();
        int sz=v[a].size();

        for(int i=0;i<sz;i++){
            int num=v[a][i];
            if(!visit[num]){
                q.push(num);
                visit[num]=1;
                par[num]=a;
            }
        }
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>u>>w;
        v[u].push_back(w);
        v[w].push_back(u);
    }

    proc(1);

    for(int i=2;i<=n;i++){
        cout<<par[i]<<'\n';
    }

    return 0;
}