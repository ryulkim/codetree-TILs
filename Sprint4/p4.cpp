#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define sz 1002
using namespace std;

int dis[sz];
bool chk[sz];
vector<pair<int,int>> v[sz];

void proc(int n){
    priority_queue<pair<int, int>> pq; //{dis, 정점}
    
    pq.push({0,n});
    int d,i;

    while(!pq.empty()){
        d=-pq.top().first;
        i=pq.top().second;
        pq.pop();
        
        if(d>dis[i]) continue;
        int len=v[i].size();
        dis[i]=d;
        //cout<<i<<" "<<d<<'\n';

        for(int j=0;j<len;j++){
            if(dis[v[i][j].first]>v[i][j].second+d){
                pq.push({-(v[i][j].second+d),v[i][j].first});
                
            }
        }
    }
}

int main() {
    int n,m,a,b,d,ans=0;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b>>d;
        v[b].push_back({a,d});
    }

    fill(dis, dis+sz, 1e9);
    proc(n);

    for(int i=1;i<n;i++){
        //if(dis[i]==1e9)continue;
        ans=max(dis[i], ans);
        //cout<<dis[i]<<' ';
    }

    cout<<ans;

    return 0;
}
