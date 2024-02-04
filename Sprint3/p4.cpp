#include <iostream>
#include <vector>
#include <queue>
#define sz 100002
using namespace std;

vector<int> v[sz];
int indegree[sz];
queue<int> q;

int main() {
    int n,m,a,b;
    
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()){
        int a=q.front();
        int len=v[a].size();
        q.pop();
        cout<<a<<' ';

        for(int i=0;i<len;i++){
            indegree[v[a][i]]--;
            if(!indegree[v[a][i]]) q.push(v[a][i]);
        }
    }


    return 0;
}
