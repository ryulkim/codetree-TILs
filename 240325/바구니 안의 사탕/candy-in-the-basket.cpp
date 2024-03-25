#include <iostream>
#include <algorithm>
#define SZ 10000005
using namespace std;

int n,k,candy,bucket;
long long ans=0;
long long arr[SZ];

void proc(){
    long long sum=0;

    for(int i=0;i<=2*k;i++){
        if(i>=SZ) {
            ans=sum;
            return;
        }
        sum+=arr[i];
    }


    int j=2*k;
    

    for(int i=0;i<SZ-2*k;i++){
        ans=max(ans,sum);

        sum-=arr[i];
        j++;
        sum+=arr[j];
    }
}

int main() {
    cin>>n>>k;

    int sum=0;
    for(int i=0;i<n;i++){
        cin>>candy>>bucket;
        arr[bucket]+=candy;    
    }

    proc();

    cout<<ans;

    return 0;
}