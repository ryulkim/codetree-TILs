#include <iostream>
#include <vector>
#include <queue>
#define SZ 55
using namespace std;

int n,x,ans=0, st;
vector<int> v[SZ];
bool visit[SZ];
int par[SZ];

void bfs(int st){
    queue<int> q;
    q.push(st);
    visit[st]=1;

    while(!q.empty()){
        int a=q.front();
        int sz=v[a].size();
        q.pop();
        //cout<<a<<' ';
        if(a!=st&&sz==0&&a!=x) {
            //cout<<a<<' ';
            ans++;
        }

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
        par[i]=x;

        if(x==-1) {
            st=i;
            continue;
        }

        v[x].push_back(i);
    }

    cin>>x;
    v[x].clear();
    int p=par[x];
    int sz=v[p].size();

    for(int i=0;i<sz;i++){
        if(v[par[x]][i]==x){
            v[par[x]].erase(v[par[x]].begin()+i);
            break;
        }
    }

    bfs(st);

    cout<<ans;

    return 0;
}