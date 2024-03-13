#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x, ans=0;
    vector<int> v;
    int dp[1005][5]={0,};
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    dp[0][0]=v[0];
    dp[1][0]=v[1];
    dp[1][1]=v[0]+v[1];

    for(int i=2;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j>3) continue;
            if(j==0) dp[i][j]=dp[i-2][j];
            else dp[i][j]=max(dp[i-2][j]+v[i], dp[i-1][j-1]+v[i]);
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=2;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    ans=max(dp[n-1][0],dp[n-1][1]);
    ans=max(ans,dp[n-1][2]);

    cout<<ans;


    return 0;
}