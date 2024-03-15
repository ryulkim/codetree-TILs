#include <iostream>
using namespace std;

int r,c;
char arr[20][20];
int ans=0;

int proc(int i, int j, char ch){
    int cnt=0;
    for(int a=i+1;a<r-1;a++){
        for(int b=j+1;b<c-1;b++){
            if(arr[a][b]!=ch){
                //cout<<a<<' '<<b<<'\n';
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    char start=arr[0][0];

    if(start!=arr[r-1][c-1]){
        for(int i=0;i<r-2;i++){
            for(int j=0;j<c-2;j++){
                if(arr[i][j]!=start){
                    //cout<<i<<' '<<j<<'\n';
                    ans+=proc(i,j, arr[i][j]);
                }
            }
        }
    }
    

    cout<<ans;

    return 0;
}