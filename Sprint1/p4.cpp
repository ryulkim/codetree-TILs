#include <iostream>
#include <vector>
#include <queue>
#define sz 100003
using namespace std;

int n,m,a,b;
vector<int> v[sz];
int indgree[sz];
priority_queue<int,vector<int>, greater<int>> q;

void ans(){
    while(!q.empty()){
        int x=q.top();
        q.pop();

        cout<<x<<' ';

        for(auto num: v[x]){
            indgree[num]--;
            if(!indgree[num]){
                q.push(num);
            }
        }
    }
}


int main() {

    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        indgree[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!indgree[i]){
            q.push(i);
        }
    }

    ans();

    return 0;
}
