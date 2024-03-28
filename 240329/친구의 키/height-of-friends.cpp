#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n,m,a,b;
vector<int> v[100005];
stack<int> st;
bool chk[100005];

void dfs(int x){
    for(int i=0;i<v[x].size();i++){
        if(!chk[v[x][i]]){
            chk[v[x][i]]=1;
            dfs(v[x][i]);
        }
    }

    st.push(x);
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!chk[i]){
            chk[i]=1;
            dfs(i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }

    return 0;
}