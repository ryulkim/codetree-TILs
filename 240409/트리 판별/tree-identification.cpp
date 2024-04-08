#include <iostream>
#include <vector>
#include <queue>
#define SZ 10005
using namespace std;

int m,a,b, root, rnum=0, num=0, total=0;
int indegree[SZ];
bool visit[SZ];
bool check[SZ];
vector<int> v[SZ];
queue<int> q;

bool proc(){
    for(int i=0;i<SZ;i++){
        if(check[i]&&!indegree[i]){
            root=i;
            rnum++;
        }
    }

    if(rnum>1) return 0;

    q.push(root);
    num=1;
    visit[root]=1;

    while(!q.empty()){
        int a=q.front();
        int sz=v[a].size();
        q.pop();

        for(int i=0;i<sz;i++){
            int b=v[a][i];
            if(visit[b]) return 0;
            if(!visit[b]){
                visit[b]=1;
                q.push(b);
                num++;
            }
        }
    }

    //cout<<num<<total;
    if(num==total) return 1;
    return 0;
}

int main() {
    cin>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
        if(!check[a]) {
            check[a]=1;
            total++;
        }
        if(!check[b]) {
            check[b]=1;
            total++;
        }
    }


    cout<<proc();
    

    return 0;
}