#include <iostream>
using namespace std;

int arr[25][25];
int dr[5]={0,1,1,1};
int dc[5]={1,0,-1,1};
int ar,ac;

bool valid(int i, int j){
    return i>=0&&i<19&&j>=0&&j<19;
}

bool direct(int d, int i, int j, int color){
    int num=1;
    for(int k=0;k<4;k++){
        if(valid(i+dr[d],j+dc[d])&&arr[i+dr[d]][j+dc[d]]!=color){
            return false;
        }
        i+=dr[d];
        j+=dc[d];
        num++;
    }
    if(num==5) return true;
    return false;
}

bool proc(int color){
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(arr[i][j]!=color) continue;
            for(int k=0;k<4;k++){
                if(direct(k,i,j,color)) {
                    ar=i+dr[k]*2+1; ac=j+dc[k]*2+1;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int ans=0;

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin>>arr[i][j];
        }
    }
    if(proc(1)){
        ans=1;
    }
    if(proc(2)){
        ans=2;
    }

    cout<<ans<<'\n';

    if(ans!=0){
        cout<<ar<<' '<<ac;
    }
    

    return 0;
}