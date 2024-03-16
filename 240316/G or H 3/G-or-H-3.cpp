#include <iostream>
#include <algorithm>
using namespace std;

int n,k,x,ans=0;
char c;
int arr[10005];

int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x>>c;
        int num=0;
        if(c=='G') num=1;
        else num=2;
        arr[x-1]=num;
    }

    for(int i=0;i<10000-k;i++){
        int num=0;
        for(int j=i;j<=i+k;j++){
            num+=arr[j];
        }
        ans=max(ans,num);
    }

    cout<<ans;

    return 0;
}