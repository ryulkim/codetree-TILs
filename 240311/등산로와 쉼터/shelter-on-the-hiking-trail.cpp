#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m,x,u,w;
    vector<int> v[5005];
    vector<int> h;
    priority_queue<pair<int,int>> pq;
    int arr[5005]={0,};
    cin>>n>>m;
    h.push_back(0);

    for(int i=1;i<=n;i++){
        cin>>x;
        h.push_back(x);
        pq.push({x,i});
    }

    for(int i=0;i<m;i++){
        cin>>u>>w;

        if(h[u]<h[w]){
            v[w].push_back(u);
        }
        else if(h[u]>h[w]){
            v[u].push_back(w);
        }
    }

    while(!pq.empty()){
        int t=pq.top().second;
        int sz=v[t].size();
        pq.pop();

        for(int i=0;i<sz;i++){
            arr[v[t][i]]=max(arr[t]+1,arr[v[t][i]]);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]+1<<'\n';
    }

    return 0;
}