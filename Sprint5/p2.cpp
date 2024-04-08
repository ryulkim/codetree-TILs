#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m,a,b;
int arr[305][305];
bool visit[305][305];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};

void erase(){
    int temp[305][305]={0,};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int a=i+dr[k];
                int b=j+dc[k];

                if(arr[i][j]&&!arr[a][b]){
                    temp[i][j]=max(temp[i][j]-1,0);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=temp[i][j];
        }
    }
}

void dfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){
        tie(a,b)=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int na=a+dr[k];
            int nb=b+dc[k];

            if(arr[na][nb]&&!visit[na][nb]){
                q.push({na,nb});
                visit[na][nb]=1;
            }
        }
    }
}

int proc(){

    int num=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]&&!visit[i][j]){
                dfs(i,j);
                num++;
            }
            if(num>1) return 1;
        }
    }

    if(num==0) return 2;

    return 0;

}

int main() {
    cin>>n>>m;
    int turn=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    while(1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visit[i][j]=0;
            }
        }
        turn++;
        erase();
        
        int result=proc();
        if(result==1){
            cout<<turn;
            break;
        }
        else if(result==2){
            cout<<0;
            break;
        }
        
    }

    return 0;
}
