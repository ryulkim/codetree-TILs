#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,a,b;
int indegree[1005];

priority_queue<pair<int,int>> pq;
vector<int> v[1005];
int cnt[1005];

void proc(int st){
    queue<int> q;
    bool visit[1005]={0,};
    int value=0;
    q.push(st);
    visit[st]=1;

    while(!q.empty()){
        int a=q.front();
        int sz=v[a].size();
        q.pop();

        for(int i=0;i<sz;i++){
            int num=v[a][i];
            
            if(!visit[num]){
                value++;
                q.push(num);
                visit[num]=1;
            }
        }
    }

    pq.push({value,-st});
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        proc(i);
    }

    int pre=pq.top().first;
    cout<<-pq.top().second<<' ';
    pq.pop();

    while(!pq.empty()){
        if(pre>pq.top().first){
            break;
        }
        cout<<-pq.top().second<<' ';
        pq.pop();
    }

    return 0;
}
