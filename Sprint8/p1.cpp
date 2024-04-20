#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,r,c,ans=0;
int arr[105][105];
queue<pair<int,int>> q;
int dr[6]={1,-1,0,0};
int dc[6]={0,0,1,-1};

bool valid(int i, int j){
    return i>=0&&i<=102&&j>=0&&j<=102;
}

void bfs(){
    q.push({0,0});
    int i,j;

    while(!q.empty()){
        tie(i,j)=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];

            if(valid(ni,nj)&&arr[ni][nj]==0){
                arr[ni][nj]=2;
                q.push({ni,nj});
            }

        }
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>r>>c;

        arr[r][c]=1;
    }

    bfs();

    // for(int i=1;i<=100;i++){
    //     for(int j=1;j<=100;j++){
    //         cout<<arr[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(arr[i][j]!=1) continue;

            for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];

                if(valid(ni,nj)&&arr[ni][nj]==2){
                    ans++;
                }
            }
        }
    }

    cout<<ans;

    return 0;
}
