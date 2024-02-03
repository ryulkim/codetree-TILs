#include <iostream>
#include <queue>
#include <tuple>
#define sz 30
using namespace std;

bool arr[sz][sz];
bool visited[sz][sz];
pair<int,int> dir[5]={{0,1},{0,-1},{1,0},{-1,0}};
int n;

int bfs(int i, int j){
    queue<pair<int, int>> q;
    int ans=0,a,b;

    q.push({i,j});
    visited[i][j]=1;

    while(!q.empty()){
        tie(a, b)=q.front();
        q.pop();
        ans++;

        for(int x=0;x<4;x++){
            int nr=a+dir[x].first;
            int nc=b+dir[x].second;

            if(nr<0||nc<0||nr>=n||nc>=n) continue;

            if(arr[nr][nc]&&!visited[nr][nc]) {
                q.push({nr,nc});
                visited[nr][nc]=1;
            }
        }
    }

    return ans;
}

int main() {
    
    priority_queue<int, vector<int>, greater<int>> ans;
    
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]&&!visited[i][j]) {
                int value= bfs(i,j);
                ans.push(value);
            }
        }
    }

    cout<<ans.size()<<'\n';

    while(!ans.empty()){
        cout<<ans.top()<<'\n';
        ans.pop();
    }

    return 0;
}
