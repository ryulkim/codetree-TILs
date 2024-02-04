#include <iostream>
using namespace std;
int arr[20];
int n;
int ans=0;

bool valid(int lev,int num){
    for(int i=0;i<lev;i++){
        //같은 행
        if(arr[i]==num) return true;
        //대각선
        if(arr[i]==num-(lev-i)) return true;
        if(arr[i]==num+(lev-i)) return true;
    }
    return false;
}

void proc(int lev){
    if(lev==n) {
        ans++;

        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<' ';
        // }

        // cout<<'\n';
        return;
    }

    for(int i=1;i<=n;i++){
        if(valid(lev,i)) continue;
        arr[lev]=i;
        proc(lev+1);
    }
}

int main() {

    cin>>n;

    //arr[0]=1;
    proc(0);

    cout<<ans;

    return 0;
}
