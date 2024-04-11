#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

priority_queue<pair<int,int>> pq;
int n,m,k,a,b,d,x,ans=1e9;
vector<pair<int,int>> v[100005];
vector<int> treasure;
int arr1[100005];
int arr2[100005];

void dik1(int st){
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    int na,nb;

    while(!pq.empty()){
        tie(b,a)=pq.top();
        int sz=v[a].size();
        b=-b;
        pq.pop();

        if(arr1[a]<b) continue;
        arr1[a]=b;

        for(int i=0;i<sz;i++){
            tie(na,nb)=v[a][i];
            pq.push({-(nb+b),na});
        }
    }
}

void dik2(int st){
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    int na,nb;

    while(!pq.empty()){
        tie(b,a)=pq.top();
        int sz=v[a].size();
        b=-b;
        pq.pop();

        if(arr2[a]<b) continue;
        arr2[a]=b;

        for(int i=0;i<sz;i++){
            tie(na,nb)=v[a][i];
            pq.push({-(nb+b),na});
        }
    }
}

int main() {
    cin>>n>>m>>k;

    for(int i=0;i<k;i++){
        cin>>x;
        treasure.push_back(x);
    }

    for(int i=0;i<m;i++){
        cin>>a>>b>>d;
        v[a].push_back({b,d});
        v[b].push_back({a,d});
    }

    for(int i=0;i<n;i++){
        arr1[i]=1e9;
        arr2[i]=1e9;
    }

    dik1(n);
    dik2(1);

    for(int i=0;i<k;i++){
        if(arr1[i]==1e9||arr2[i]==1e9) continue;
        ans=min(arr1[treasure[i]]+arr2[treasure[i]],ans);
    }

    if(ans==1e9) cout<<-1;
    else cout<<ans;

    return 0;
}
