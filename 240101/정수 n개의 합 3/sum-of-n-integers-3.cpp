#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    int arr[502][502]={0,};
    int sum[502][502]={0,};
    cin>>n>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    sum[0][0]=arr[0][0];

    for(int i=1;i<n;i++){
        sum[0][i]=sum[0][i-1]+arr[0][i];
    }

    for(int i=1;i<n;i++){
        sum[i][0]=sum[i-1][0]+arr[i][0];
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i-1][j-1];
            if(i>=k&&j>=k){
                ans=max(ans, sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k]);
            }
            
        }
    }

    cout<<ans;
    return 0;
}