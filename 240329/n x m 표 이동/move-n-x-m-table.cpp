#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int h,w;
int arr[505][505];
long long dp[505][505];

bool valid(int i, int j){
    return i>=0&&i<h&&j>=0&&j<w;
}

void proc(int a, int b){
    priority_queue<pair<int,int>> pq;
    pq.push({-a,-b});
    int r,c;
    int dr[5]={0,0,1,-1};
    int dc[5]={1,-1,0,0};
    dp[a][b]=1;

    while(!pq.empty()){
        tie(r,c)=pq.top();
        pq.pop();

        for(int i=0;i<4;i++){
            int nr=dr[i]-r;
            int nc=dc[i]-c;
            //cout<<"next: "<<nr<<' '<<nc<<'\n';
            if(valid(nr,nc)&&arr[-r][-c]>arr[nr][nc]){
                pq.push({-nr,-nc});
                dp[nr][nc]+=1;
            }
        }

        // for(int i=0;i<h;i++){
        //     for(int j=0;j<w;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
    }
}

int main() {
    cin>>h>>w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }

    proc(0,0);

    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    cout<<dp[h-1][w-1];


    return 0;
}