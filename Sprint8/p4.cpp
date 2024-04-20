#include <iostream>
#include <vector>
using namespace std;

int n,q,x,a,b;
int arr[500005];

int main() {
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>x;
        arr[i]+=(arr[i-1]+x);
    }

    for(int i=0;i<q;i++){
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<'\n';
    }

    return 0;
}
