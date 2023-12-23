#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,q,x,a,b;
    int arr[1000002]={0,};
    cin>>n>>q;


    for(int i=0;i<n;i++){
        cin>>x;
        arr[x]=1;
    }

    for(int i=1;i<=1000000;i++){
        arr[i]+=arr[i-1];
    }

    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(a!=0) a--;
        cout<<arr[b]-arr[a]<<'\n';
    }

    return 0;
}