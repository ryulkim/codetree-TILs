#include <iostream>
using namespace std;

int n,m;
long long ans=0;
long long dp[2005][2005];


int main() {
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        dp[0][i]=1;
        for(int j=i*2;j<=m;j++){
            dp[1][j]++;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            if(!dp[i][j]) continue;

            for(int k=j*2;k<=m;k++){
                dp[i+1][k]+=dp[i][j];
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=1000000007;
    }

    cout<<ans;

    return 0;
}
