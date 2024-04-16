#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k,x,ans=0,temp=0;
vector<int> v;
int arr[20];

void proc(int l){
    if(l==n){
        int temp=0;
        for(int i=1;i<=k;i++){
            if(arr[i]>=m-1) temp++;
        }
        ans=max(ans,temp);
        return;
    }

    for(int i=1;i<=k;i++){
        arr[i]+=v[l];
        proc(l+1);
        arr[i]-=v[i];
    }
}

int main() {
    cin>>n>>m>>k;

    for(int i=0;i<m;i++){
        cin>>x;
        v.push_back(x);
    }

    proc(0);

    cout<<ans;

    return 0;
}