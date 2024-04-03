#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,a,b;
priority_queue<int> q;
vector<int> v[100005];
int indegree[100005];

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(-i);
        }
    }

    while(!q.empty()){
        int num=-q.top();
        int sz=v[num].size();
        q.pop();
        cout<<num<<' ';

        for(int i=0;i<sz;i++){
            int x=v[num][i];
            indegree[x]--;

            if(!indegree[x]) q.push(-x);
        }
    }


    return 0;
}