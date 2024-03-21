#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#define GSZ 250005
#define NSZ 100005
using namespace std;

int n,g,x;
unordered_set<int> u[GSZ];
vector<int> v[NSZ];
queue<int> q;

int main() {
    cin>>n>>g;

    for(int i=0;i<g;i++){
        cin>>x;
        int num;

        for(int j=0;j<x;j++){
            cin>>num;
            u[i].insert(num);
            v[num].push_back(i);
        }
    }

    q.push(1);
    int ans=1;

    while(!q.empty()){
        int a=q.front();
        int sz=v[a].size();
        ans++;
        q.pop();

        //a가 속한 그룹 탐색
        for(int i=0;i<a;i++){
            u[v[a][i]].erase(a);
            if(u[v[a][i]].size()==1) q.push(*u[v[a][i]].begin());
        }
    }

    cout<<ans;

    return 0;
}