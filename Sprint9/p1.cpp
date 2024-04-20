#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int arr[505][505];
int check[505][505];
int n,m,arriveA,arriveB;
queue<pair<int,int>> q;
int dr[6]={0,0,1,-1};
int dc[6]={1,-1,0,0};

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m;
}

void bfs(){
    int a,b;
    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int na=a+dr[k];
            int nb=b+dc[k];

            if(na==arriveA&&nb==arriveB) continue;

            if(valid(na,nb)&&arr[na][nb]==1&&!check[na][nb]){
                check[na][nb]=check[a][b]+1;
                q.push({na,nb});
            }
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];

            if(arr[i][j]==2) {
                q.push({i,j});
                check[i][j]=0;
                arriveA=i;
                arriveB=j;
            }
        }
    }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j]&&arr[i][j]==1){
                cout<<-1<<' ';
            }
            else cout<<check[i][j]<<' ';

        }
        cout<<'\n';
    }

    return 0;
}
