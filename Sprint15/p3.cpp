#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,r1,r2,c1,c2;
int arr[105][105];
int dr[10]={-1,-2,-2,-1,1,2,2,1};
int dc[10]={-2,-1,1,2,2,1,-1,-2};

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<n;
}

void bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    int r,c;

    while(!q.empty()){
        tie(r,c)=q.front();
        q.pop();

        for(int k=0;k<8;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(!valid(nr,nc)) continue;

            if(arr[nr][nc]>arr[r][c]+1){
                arr[nr][nc]=arr[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
}

int main() {
    cin>>n;

    cin>>r1>>c1>>r2>>c2;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=1e9;
        }
    }

    arr[r1-1][c1-1]=0;

    bfs(r1-1,c1-1);

    if(arr[r2-1][c2-1]!=1e9) cout<<arr[r2-1][c2-1];
    else cout<<-1;

    return 0;
}
