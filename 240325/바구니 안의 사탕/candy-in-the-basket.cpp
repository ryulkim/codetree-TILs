#include <iostream>
#include <algorithm>
#define SZ 1000005
using namespace std;

int n,k,candy,bucket,ans=0;
int arr[SZ];

void proc(){
    int sum=0;

    for(int i=0;i<=2*k;i++){
        if(i>SZ) {
            ans=sum;
            return;
        }
        sum+=arr[i];
    }

    int j=2*k;
    

    for(int i=0;i<SZ-2*k-5;i++){
        ans=max(ans,sum);
        //cout<<ans<<' ';

        sum-=arr[i];
        j++;
        sum+=arr[j];

        //cout<<arr[i]<<' '<<arr[j]<<'\n';
    }
}

int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>candy>>bucket;
        arr[bucket-1]+=candy;
    }

    proc();

    cout<<ans;

    return 0;
}