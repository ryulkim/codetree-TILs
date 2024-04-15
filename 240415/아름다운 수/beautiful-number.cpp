#include <iostream>
using namespace std;

int n;
int arr[15];
int ans=0;

void proc(int l,int num){
    if(l==n){
        if(num%arr[l-1]==0) {
            ans++;
        }
        return;
    }

    for(int i=1;i<=4;i++){
        if(l==0) {
            arr[l]=i;
            proc(l+1,1);
            continue;
        }
        if(arr[l-1]!=i&&num%arr[l-1]!=0) continue;
        arr[l]=i;
        if(arr[l-1]!=i){
            proc(l+1,1);
        }
        else{
            proc(l+1,num+1);
        }

    }
    return;
}

int main() {
    cin>>n;

    proc(0,0);

    cout<<ans;

    return 0;
}