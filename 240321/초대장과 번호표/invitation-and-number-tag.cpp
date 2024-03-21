#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#define GSZ 250005
#define NSZ 100005
using namespace std;

int n,g,x;
unordered_set<int> u[GSZ];
bool invited[NSZ];
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
    invited[1]=true;
    int ans=0;

    while(!q.empty()){
        int a=q.front();
        int sz=v[a].size();
        ans++;
        q.pop();

        //a가 속한 그룹 탐색
        for(int i=0;i<sz;i++){
            u[v[a][i]].erase(a);
            if(u[v[a][i]].size()==1) {
                int p_num=(*u[v[a][i]].begin());
                if(!invited[p_num]){
                    invited[p_num]=true;
                    q.push(p_num);
                }
                
                
            }
        }
    }

    cout<<ans;

    return 0;
}