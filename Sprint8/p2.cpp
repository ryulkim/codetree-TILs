#include <iostream>
#include <algorithm>
#define sz 1000
using namespace std;

int arr[sz+5][sz+5];
int x,y,n,ans=0;
int dr[6]={1,-1,0,0};
int dc[6]={0,0,1,-1};

bool valid(int i, int j){
    return i>=0&&i<=sz&&j>=0&&j<=sz;
}

int main() {
    cin>>n;

    for(int i=0;i<=sz;i++){
        fill(arr[i], arr[i]+1005, -1);
    }

    for(int i=0;i<n;i++){
        cin>>x>>y;
        arr[x][y]=0;

        for(int k=0;k<4;k++){
            int ni=x+dr[k];
            int nj=y+dc[k];

            if(valid(ni,nj)&&arr[ni][nj]!=-1) {
                arr[ni][nj]++;
                arr[x][y]++;
                if(arr[ni][nj]==3) ans++;
                else if(arr[ni][nj]==4) ans--;

                if(arr[x][y]==3) ans++;
                else if(arr[x][y]==4) ans--;
            }
        }

        cout<<ans<<'\n';
    }

    return 0;
}
