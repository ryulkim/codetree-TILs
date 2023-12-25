#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k,b,x;
    int arr[100004]={0,};
    cin>>n>>k>>b;

    for(int i=0;i<b;i++){
        cin>>x;
        arr[x]=1;
    }

    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        //cout<<arr[i]<<' ';
    }

    int m=100004;

    for(int i=1;i<n-k+2;i++){
        //cout<<i+k<<' '<<i<<' '<<arr[i+k]<<' '<<arr[i-1]<<'\n';
        m=min(m, arr[i+k-1]-arr[i-1]);
    }

    cout<<m;

    return 0;
}