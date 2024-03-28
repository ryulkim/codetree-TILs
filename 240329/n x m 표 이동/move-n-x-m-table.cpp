#include <iostream>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <set>
using namespace std;

int h,w,a,b;
int arr[505][505];
long long dp[505][505];
stack<pair<int,int>> re;
set<pair<int,int>> st;
vector<pair<int,int>> v[505][505];
bool visit[505][505];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};

bool valid(int i, int j){
    return i>=0&&i<h&&j>=0&&j<w;
}

void dfs(int x, int y){
    for(int i=0;i<v[x][y].size();i++){
        int nr=v[x][y][i].first;
        int nc=v[x][y][i].second;
        if(!visit[nr][nc]){
            visit[nr][nc]=1;
            dfs(nr,nc);
        }
    }
    re.push({x,y});
}

void proc(){

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int k=0;k<4;k++){
                int nr=dr[k]+i;
                int nc=dc[k]+j;
                //cout<<"next: "<<nr<<' '<<nc<<'\n';
                if(valid(nr,nc)&&arr[i][j]>arr[nr][nc]){
                    v[i][j].push_back({nr,nc});
                }
            }
        }
    }

}

int main() {
    cin>>h>>w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }

    proc();

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!visit[i][j]){
                visit[i][j]=1;
                dfs(i,j);
            }
        }
    }
    
    dp[0][0]=1;

    while(!re.empty()){
        tie(a,b)=re.top();
        re.pop();
        // cout<<a<<' '<<b<<'\n';

        for(int i=0;i<v[a][b].size();i++){
            int nr=v[a][b][i].first;
            int nc=v[a][b][i].second;
            dp[nr][nc]+=dp[a][b];
            dp[nr][nc]%=1000000007;
        }
    }

    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    cout<<dp[h-1][w-1];


    return 0;
}