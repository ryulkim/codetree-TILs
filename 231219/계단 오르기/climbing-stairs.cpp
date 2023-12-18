#include <iostream>
using namespace std;

int dp[1005];

int main() {
    int n;
    cin>>n;

    fill(dp, dp+1004, 100000);
    
    dp[2]=1;
    dp[3]=1;

    

    for(int i=2;i<=n-2;i++){
        if(dp[i]==100000) continue;
        dp[i+2]=min(dp[i+2],dp[i]+1);
        dp[i+3]=min(dp[i+3],dp[i]+1);
    }

    if(dp[n]==100000)cout<<0;
    else cout<<dp[n];

    return 0;
}