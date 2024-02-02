#include <iostream>
#include <queue>
#include <vector>
#define sz 100003
using namespace std;

vector<pair<int,int>> v[sz];

pair<int, int> bfs(int st){
    bool visit[sz]={0,};
    queue<pair<int,int>> q;
    q.push({st,0});
    visit[st]=1;
    int ans_a=st,ans_x=0;

    while(!q.empty()){
        int a=q.front().first;
        int x=q.front().second;
        q.pop();

        if(ans_x<x){
            ans_a=a;
            ans_x=x;
        }
        

        for(auto node: v[a]){
            int b=node.first;
            int r=node.second;

            if(!visit[b]){
                q.push({b,r+x});
                visit[b]=1;
            }
        }
    }

    return {ans_a,ans_x};

}

int main() {
    int n, a, b, c;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    pair<int, int> n1=bfs(1);
    pair<int, int> n2=bfs(n1.first);

    cout<<n2.second;


    return 0;
}
