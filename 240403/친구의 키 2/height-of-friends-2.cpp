#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,a,b;
vector<int> v[100005];
queue<int> q;
int indegree[100005];

bool proc(){
    int num=0;

    while(!q.empty()){
        num++;
        int a=q.front();
        int sz=v[a].size();
        q.pop();

        for(int i=0;i<sz;i++){
            int b=v[a][i];
            indegree[b]--;
            if(!indegree[b]){
                q.push(b);
            }
        }
    }

    if(num==n) return true;
    return false;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
        }
    }

    if(proc()){
        cout<<"Consistent";
    }
    else{
        cout<<"Inconsistent";
    }

    return 0;
}