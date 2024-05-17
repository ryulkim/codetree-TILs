#include <iostream>
using namespace std;

int n,x,y;
long long ans=0;
char c;
bool arr[105][105];
bool chk[105][105][6];
int dr[6]={-1,0,1,0};
int dc[6]={0,1,0,-1};

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<n;
}


int main() {
    cin>>n;
    cin>>y>>x;
    x--;y--;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='#') arr[i][j]=1;
        }
    }

    int dir=1; //위,오른쪽,아래,왼쪽
    while(1){
        int nr=dr[dir]+y;
        int nc=dc[dir]+x;

        if(chk[y][x][dir]){
            ans=-1;
            break;
        }

        chk[y][x][dir]=1;

        if(!valid(nr,nc)) {
            ans++;
            break;
        }

        if(arr[nr][nc]==1) {
            dir=(dir+3)%4;
        }
        else{
            int temp_dir=(dir+1)%4;
            int rr=dr[temp_dir]+nr;
            int rc=dc[temp_dir]+nc;

            if(arr[rr][rc]==1){
                x=nc;
                y=nr;
                ans++;
            }
            else{
                dir=temp_dir;
                x=rc;
                y=rr;
                ans+=2;
            }
        }

    }

    cout<<ans;

    return 0;
}
